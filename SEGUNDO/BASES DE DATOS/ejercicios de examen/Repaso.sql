/*              REPASO                  */

/*1. Se desea visualizar el número de votantes de cada localidad respecto a su situacion laboral.
Muestra el número total de votantes de cada localidad en una columna. En las otras columnas debe
aparecer el número total de votantes de esa localidad según su situación laboral: parado, activo,
estudiante o jubilado*/

select count(dni)
from votantes
where situacionlaboral='Parado'; 
-- Una vez tengo esto me lo llevo al select grande y 
-- relaciono el select de fuera con el de dentro.

select v.localidad localidades, count(v.dni)as "GENTExLOCALIDAD",
        (select count(dni)
    from votantes
    where situacionlaboral='Parado' and localidad=v.localidad) Parados,
        (select count(dni)
    from votantes
    where situacionlaboral='Activo' and localidad=v.localidad) Activos,
        (select count(dni)
    from votantes
    where situacionlaboral='Estudiante' and localidad=v.localidad) Estudiantes,
        (select count(dni)
    from votantes
    where situacionlaboral='Jubilado' and localidad=v.localidad) Jubilados
    
from votantes v
group by v.localidad
order by v.localidad;

/*3. ¿Cuál fue el partido que los ciudadanos fueron consultados un mayor
número de veces? Sólo puede usar una vez: SELECT, FROM, WHERE y JOIN*/

SELECT cd.consulta, cd.partido, p.nombrecompleto
FROM consultas_datos cd, partidos p
WHERE cd.partido=p.idpartido;

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










