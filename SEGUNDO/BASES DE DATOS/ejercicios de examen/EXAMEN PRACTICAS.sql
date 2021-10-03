/*Ejercicio 1
Se desea visualizar el número de votantes de cada localidad respecto a su
situación laboral. Muestra el número total de votantes de cada localidad en una
columna. En las otras columnas debe aparecer el número total de votantes de
esa localidad según su situación laboral: parado, activo, estudiante o jubilado.*/

select localidad, count (*) total,
    sum(decode(situacionlaboral, 'Activo', 1,0))Activos,
    sum(decode(situacionlaboral, 'Parado', 1,0))Parados,
    sum(decode(situacionlaboral, 'Jubilado', 1,0))Jubilados,
    sum(decode(situacionlaboral, 'Estudiante', 1,0))Estudiantes
from votantes
group by localidad order by localidad asc;

/*Ejercicio 2
Muestra el nombre de los votantes cuya longitud del primer nombre sea menor
que el ID de la localidad a la que pertenecen y junto a ella muestra la diferencia
de edad (en años) entre la persona más joven y más mayor de su localidad. Cada
columna se llamará “Nombre” y “Diferencia” respectivamente. [Nota: en caso
de no usar EXTRACT simplemente se restan las fechas y se divide entre 365 y es
igual de válido].*/

select v.nombrecompleto as nombre, 
    (select distinct trunc(abs(sysdate-min(va.fechanacimiento))/360-abs(sysdate-max(va.fechanacimiento))/360)
    from votantes va 
    where va.localidad=v.localidad) as diferencia
from votantes v
where length(substr(v.nombrecompleto,1,instr(v.nombrecompleto,' ')-1))<v.localidad;


/*Ejercicio 3
Se desea visualizar de cada DNI de un votante las veces que ha realizado una
consulta cuya respuesta haya sido “Si” y las veces que ha realizado una consulta
cuya respuesta haya sido “No”, así como la media de certidumbres totales para
cada votante en las consultas que éste haya realizado. Sólo se puede usar una
vez: SELECT y FROM.*/

set serveroutput on;
DECLARE
    cursor c is select c.votante, count (*) total, 
                sum(decode(cd.respuesta, 'Si', 1,0))Si,  
                sum(decode(cd.respuesta, 'No', 1,0))No,   
                round(sum(cd.certidumbre)/count (*),2) media
            from consultas c, consultas_datos cd
            where c.idconsulta = cd.consulta
            group by c.votante;
BEGIN 
    for fila in c loop
        dbms_output.put_line (fila.votante || ' ha realizado '|| fila.Si || ' con respuesta Si y '|| fila.No ||' con respuesta No' || ' y una media de 0' || fila.media);
    end loop;
END;


/*Ejercicio 4
[Ejercicio Eliminatorio] ¿Cuál fue el partido que los ciudadanos fueron
consultados un mayor número de veces? Sólo se puede usar una vez: SELECT,
FROM, WHERE y JOIN. Resultado: “Partido Socialista Obrero Español?18”
*/

set serveroutput on;
DECLARE
    cursor c is select p.nombrecompleto, count(cd.partido) conteo   
                from partidos p, consultas_datos cd   
                where p.idpartido = cd.partido   
                group by p.nombrecompleto order by count(cd.partido)desc;   
    maximo int := 0;    
    nombre_partido partidos.nombrecompleto%type;
BEGIN 
    for fila in c loop
        if fila.conteo > maximo  then
            maximo := fila.conteo;
            nombre_partido := fila.nombrecompleto ;
        end if;
    end loop;
    dbms_output.put_line(nombre_partido || '-->' || maximo);
END;

/*Ejercicio 5
Crea una restricción para que no se inserten emails inválidos. Los emails de los
votantes deben tener antes del @ uno o más caracteres. Entre el @ y el . debe
haber uno o más caracteres (asumiendo que solo puede haber un . en el email)
y que después del . haya al menos dos caracteres*/
ALTER TABLE VOTANTES
ADD CONSTRAINT email_constraint CHECK(email like '%_@_%.__%');

