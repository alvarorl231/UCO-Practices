                        --       EJERCICIOS DE EXAMEN            --
                        
/* Ejercicio 1. (2 puntos).
Se desea realizar un análisis de la relación existente entre el nivel
de estudios de los votantes y su situación laboral. Para ello se solicita realizar una
consulta SQL que muestre, para cada tipo de estudios superiores, cuantos votantes en
total tienen dicho nivel de estudios y, de todos estos, cuantos estan parados, cuantos
activos, cuantos son estudiantes y cuantos estn jubilados. El resultado deberá
contener, únicamente seis columnas diferentes (el nombre de las columnas debe ser
este y no otro): estudiossuperiores, total, parado, activo, estudiante, jubilado.
El resultado debe ordenarse de manera descendente en cuanto al numero de votantes
que hay en cada categoria de estudios superiores. Por ejemplo, un registro
correspondiente a estudios básicos indicará que hay 8 votantes con esos niveles de
estudios, de los que 2 son parados, 3 son activos, 2 son estudiantes y 1 es jubilado. */

--conseguimos el numero de parados,para contemplarlo como columna
select count(situacionlaboral) parado
from votantes
where situacionlaboral='Parado'
group by situacionlaboral;
--numero de activos
select count(situacionlaboral) activo
from votantes
where situacionlaboral='Activo'
group by situacionlaboral;
--numero de estudiantes
select count(situacionlaboral) as estudiante
from votantes
where situacionlaboral='Estudiante'
group by situacionlaboral;
--y los jubilados
select count(situacionlaboral) as jubilado
from votantes
where situacionlaboral='Jubilado'
group by situacionlaboral;

--mostramos las columnas a partir de los select de abajo
select v.estudiossuperiores, count(v.estudiossuperiores) total,
--en el and de la consulta siguiente, realizamos v.estudiossuperiores ya que es cuestion de 
--lo que estamos agrupando en el select global, con el select de consulta
        (select count(situacionlaboral) 
        from votantes
        where situacionlaboral='Parado' and v.estudiossuperiores=estudiossuperiores) parado,
        (select count(situacionlaboral) 
        from votantes
        where situacionlaboral='Activo' and v.estudiossuperiores=estudiossuperiores) activo,
        (select count(situacionlaboral) 
        from votantes
        where situacionlaboral='Estudiante' and v.estudiossuperiores=estudiossuperiores) estudiante,
        (select count(situacionlaboral) 
        from votantes
        where situacionlaboral='Jubilado' and v.estudiossuperiores=estudiossuperiores) jubilado
from votantes v
group by v.estudiossuperiores
order by total desc;


--Profesor
SELECT v.estudiossuperiores,count(dni) total,
       (select count(dni)
            from votantes
            where situacionlaboral='Parado' and estudiossuperiores=v.estudiossuperiores) parado,
        (select count(dni)
            from votantes
            where situacionlaboral='Activo' and estudiossuperiores=v.estudiossuperiores) activo,
        (select count(dni)
            from votantes
            where situacionlaboral='Estudiante' and estudiossuperiores=v.estudiossuperiores) estudiante,
        (select count(dni)
            from votantes
            where situacionlaboral='Jubilado' and estudiossuperiores=v.estudiossuperiores) jubilado
FROM votantes v
GROUP BY v.estudiossuperiores;


/* Ejercicio 2 (2 puntos).
Se desea obtener información sobre los votantes de una serie de 
localidades. En esta ocasión, sólo tendremos en cuenta aquellos votantes cuyo primer 
nombre tenga una longitud menor que el identificador de su localidad (por ejemplo, el 
votante Juan se tomará si su id de localidad es mayor que 4). Se solicita realizar una 
consulta SQL que obtenga el nombre de la localidad, el número de votantes de dicha 
localidad que cumplan el requisito anterior, y la diferencia en años existente entre el
votante más joven y más viejo de cada localidad. Recordad que sólo deberán 
considerarse votantes cuya longitud del primer nombre sea inferior al identificador 
de la localidad en la que vive. E1 resultado debera contener únicamente tres columnas 
diferentes (el nombre de las columnas debe ser este y no otro): nombreLocalidad, 
total, diferencia. El resultado debe ordenarse alfabéticamente por el nombre de la 
localidad. Nota: para calcular la diferencia en años, consideraremos que todos los años tiene 365 dias.
tiene 365 dias. */

-- Empiezo comparando la longitud del nombre y el id localidad
select length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1)) long_nombre, localidad
from votantes;

-- Nombres, localidades y edades, para echar un vistazo de como quedará el resultado.
select nombrecompleto, localidad, length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1)) long_nombre,
     extract(year from(fechanacimiento)) "edad"
from votantes
where localidad>length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1));

-- Diferencia de edades agrupadas por localidades, solo para probar funcionamiento.
select extract(year from(max(fechanacimiento))) - extract(year from(min(fechanacimiento))) "dierencia"
from votantes
group by localidad;

-- Muestro la localidad y que edad tiene cada uno, solo necesito eliminar 
-- la columna mayor y menor y obtengo el resultado.
select l.nombre "nombreLocalidad", count(l.nombre) as "total",
    extract(year from(max(v.fechanacimiento))) "mayor",
    extract(year from(min(v.fechanacimiento))) "menor",
    extract(year from(max(v.fechanacimiento))) - extract(year from(min(v.fechanacimiento))) "diferencia"
from localidades l, votantes v
where v.localidad=l.idlocalidad
and localidad > length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1))
group by l.nombre
order by l.nombre;

-- SOLUCIÓN MÍA, Álvaro Roldán Lucena
-- ENTIENDO QUE QUIERE LA DIFERENCIA DE EDAD DE SOLO LOS QUE
-- CUMPLEN EL REQUISITO DE LA LONGITUD DEL NOMBRE < ID LOCALIDAD
select l.nombre "nombreLocalidad", count(l.nombre) as "total",extract(year from(max(fechanacimiento))) - extract(year from(min(fechanacimiento))) "diferencia"
from localidades l, votantes v
where v.localidad=l.idlocalidad
and localidad > length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1))
group by l.nombre
order by l.nombre;


-- SOLUCIÓN ÁNGEL ACADEMIA
-- MUESTRA LA DIFERENCIA DE EDAD DE TODAS LAS LOCALIDADES,
-- INCLUYENDO LAS QUE NO CUMPLEN EL REQUISITO
select l.nombre nombrelocalidad,
        (select count(dni)
        from votantes
        where length(substr(nombrecompleto,1,instr(nombrecompleto,' ')-1)) < localidad 
                and localidad=l.idlocalidad) total,
        (select trunc((max(fechanacimiento) - min(fechanacimiento))/365,0)
        from votantes
        where localidad=l.idlocalidad) diferencia
from localidades l
order by l.nombre;


/* Ejercicio 3 (2.5 puntos).
Se desea realizar un análisis de los sueldos que hay que pagar 
en total a los votantes según su situación laboral. En esta ocasión, se desea realizar el 
estudio sobre aquellos votantes que han realizado un menor número de consultas. 
Considerando sólo dichos votantes, y sabiendo que los parados y estudiantes cobran 
100 euros, y los activos y jubilados cobran 1500 euros, se desea organizar la 
información de la siguiente manera: cada registro corresponderá a un nivel de estudios 
diferente, y para cada nivel de estudios, se deberá mostrar lo que hay que pagar en 
total a todos los parados, jubilados, estudiantes y activos de cada nivel de estudios. 
Importante considerar solo aquellos votantes que han realizado un menor número 
de consultas.Para ello se solicita realizar una consulta SQL. El resultado deberá 
contener, únicamente, cinco columnas diferentes (el nombre de las columnas debe 
ser este y no otro): estudiossuperiores, sueldosparodos, sueldosactivos, 
sueldosestudiontes, sueldosjubilados. A modo de ejemplo, el registro de los estudios 
superiores básicos tendrá un sueldo total de 100 para parados, 3000 para activos, 100 
para estudiantes y 0 para jubilados.*/

select min(count(votante))from consultas group by votante;
--consulta en la que nos muestra las personas con la condicion (menor n consultas)
select votante
from consultas
having count(votante)=(select min(count(votante))from consultas group by votante)
group by votante;

--sueldo parados que cumplen la condicion (menor numero de consultas)
select dni, count(dni)*100
from votantes
where dni in (select votante
                from consultas
                having count(votante)=(select min(count(votante))from consultas group by votante)
                group by votante)
and situacionlaboral='Parado'
group by dni;

--Resultado aplicando las condiciones segun situacion laboral
select v.estudiossuperiores, 
        (select count(situacionlaboral)*100 
        from votantes 
        where dni in (select votante
                from consultas
                having count(votante)=(select min(count(votante))from consultas group by votante)
                group by votante) 
        and situacionlaboral='Parado' and v.estudiossuperiores=estudiossuperiores
        ) "sueldosparados",
        (select count(situacionlaboral)*1500
        from votantes 
        where dni in (select votante
                from consultas
                having count(votante)=(select min(count(votante))from consultas group by votante)
                group by votante) 
        and situacionlaboral='Activo' and v.estudiossuperiores=estudiossuperiores
        ) "sueldosactivos",
        (select count(situacionlaboral)*100 
        from votantes 
        where dni in (select votante
                from consultas
                having count(votante)=(select min(count(votante))from consultas group by votante)
                group by votante) 
        and situacionlaboral='Estudiante' and v.estudiossuperiores=estudiossuperiores
        ) "sueldosestudiantes",
                (select count(situacionlaboral)*1500 
        from votantes 
        where dni in (select votante
                from consultas
                having count(votante)=(select min(count(votante))from consultas group by votante)
                group by votante) 
        and situacionlaboral='Jubilado' and v.estudiossuperiores=estudiossuperiores
        ) "sueldosjubilados"            
from votantes v
group by v.estudiossuperiores;


--Profesor
select v.estudiossuperiores,
        (select count(situacionlaboral)*100
        from votantes
        where dni in (select votante
                        from consultas
                        group by votante
                        having count(votante) = (select min(count(votante))
                        from consultas
                        group by votante))
            and estudiossuperiores=v.estudiossuperiores and situacionlaboral='Parado') sueldosparados,
        (select count(situacionlaboral)*1500
        from votantes
        where dni in (select votante
                        from consultas
                        group by votante
                        having count(votante) = (select min(count(votante))
                        from consultas
                        group by votante))
            and estudiossuperiores=v.estudiossuperiores and situacionlaboral='Activo') sueldosactivos,
        (select count(situacionlaboral)*100
        from votantes
        where dni in (select votante
                        from consultas
                        group by votante
                        having count(votante) = (select min(count(votante))
                        from consultas
                        group by votante))
            and estudiossuperiores=v.estudiossuperiores and situacionlaboral='Estudiante') sueldosestudiantes,
        (select count(situacionlaboral)*1500
        from votantes
        where dni in (select votante
                        from consultas
                        group by votante
                        having count(votante) = (select min(count(votante))
                        from consultas
                        group by votante))
            and estudiossuperiores=v.estudiossuperiores and situacionlaboral='Jubilado') sueldosjubilados
from votantes v
group by v.estudiossuperiores;

/*Ejercicio 4 (3.5 puntos).
Crea un procedimiento PL/SQL que inserte la información necesaria en la tabla jovenes 
a partir de la tabla votantes. Un votante se incluirá en la nueva tabla únicamente si 
nació con posterioridad al 01/01/90. El campo sueldo se pondrá en base a su situación 
laboral siendo 500 para parados, 1000 para estudiantes, 1500 para personas activas, 
2000 si son jubilados. El procedimiento deberá mostrar por pantalla cuantos votantes 
se han insertado de cada tipo (parados, activos, estudiantes, jubilados), cuanto (dinero 
se necesita cada mes para pagar las nóminas y cual es el salario medio de los votantes 
introducidos. Por ejemplo, si se insertan 1 persona estudiante y 3 jubilados, entonces se
necesitará 7000 euros y el solario medio será de 1750 euros.*/

/*
create trigger ejer_examen
before update on jovenes
for each row
begin
    insert into audit_table (datos,tabla) values (:old.sueldo||', '||:new.sueldo,'jovenes');
    dbms_output.put_line('Actualizado!');
end;

update jovenes set sueldo = '1500000' where dni = '44826745';
*/

-- IDEA PARA EL CURSOR
select dni, estudiossuperiores, situacionlaboral, extract(year from (fechanacimiento)) año
from votantes
where fechanacimiento > '01/01/90';

-- MÍO
set serveroutput on;


--Eliminamos la tabla si existiese.
drop table jovenes;

--Creamos la tabla con la forma y datos de la tabla votantes.
create table jovenes as select dni,nombrecompleto nombre,fechanacimiento fecha,estudiossuperiores estudios,situacionlaboral situacion from votantes;

--Creamos la columna SUELDO tipo numero.
alter table jovenes add sueldo NUMBER;

/* SI NO HICIESE SELECT ....., Y QUISIERA BORRAR ALGUNA COLUMNA, HARÍA ESTO:
alter table jovenes drop column email;
alter table jovenes drop column telefono;
alter table jovenes drop column localidad;
*/

--Borramos de la tabla jovenes toda la gente que no cumple ese requisito.
delete from jovenes where fecha < '01/01/90';

DECLARE
    cursor jovenes is (select dni, estudiossuperiores, situacionlaboral
                        from votantes
                        where fechanacimiento > '01/01/90');
    suma FLOAT:=0;
    
    contPara FLOAT:=0;
    contAct FLOAT:=0;
    contEst FLOAT:=0;
    cont FLOAT:=0;
    
BEGIN 
    for fila in jovenes
    loop
        if fila.situacionlaboral = 'Parado'
            then
            suma:=suma+500;            
            contPara:=contPara+1;
            --Actualizamos la columna SUELDO y relacionamos el cursor y nuestra tabla.
            update jovenes set sueldo = 500 where dni = fila.dni;
        elsif fila.situacionlaboral = 'Activo'
            then
            suma:=suma+1500;
            contAct:=contAct+1;
            --Actualizamos la columna SUELDO y relacionamos el cursor y nuestra tabla.
            update jovenes set sueldo = 1500 where dni = fila.dni;
        elsif fila.situacionlaboral = 'Estudiante'
            then
            suma:=suma+1000;
            contEst:=contEst+1;
            --Actualizamos la columna SUELDO y relacionamos el cursor y nuestra tabla.
            update jovenes set sueldo = 1000 where dni = fila.dni;
        end if;
    end loop;
    cont:=contPara+contEst+contAct;
    dbms_output.put_line('Se insertan '||contEst||' estudiantes '||contAct||' activos y '||contPara||' parados. No hay jubilados.');
    dbms_output.put_line('Entonces se necesitarán '||suma||' euros y el salario medio será de '||round((suma/cont),2)||' euros.');    
END;


ALTER TABLE jovenes
ADD CONSTRAINT sueldo_comprobacion
CHECK(sueldo>='500' and sueldo<='2000');

update jovenes set sueldo='5000' where dni='44826745';

CREATE OR REPLACE TRIGGER t1
BEFORE INSERT OR UPDATE ON jovenes
FOR EACH ROW
DECLARE
    aux jovenes.dni%type;
BEGIN
    select dni into aux
    from jovenes
    where dni=:new.dni;
        if aux IS NOT NULL THEN
            dbms_output.put_line('Eres bobo');
            rollback;
    end if;
end;

insert into jovenes values('44826745','OJETON PELUDON','30/07/92','Basicos','Activo','1500');

-- PROFESOR
set serveroutput on;
DECLARE

    cursor jovenes is select nombrecompleto,situacionlaboral    
                        from votantes   
                        where fechanacimiento > '01/01/90';
    
    contParados int :=0;   
    contActivos int :=0;    
    contEstudiantes int :=0;    
    contJubilados int :=0;    
    sueldoParado int :=0;    
    sueldoActivo int :=0;    
    sueldoEstudiante int :=0;    
    mediaSueldos float :=0;   
    sumaCont int := 0;   
    total int :=0;
    
BEGIN

    for fila in jovenes loop
        if fila.situacionlaboral = 'Estudiante' then
            contEstudiantes := contEstudiantes + 1;
            sueldoEstudiante := sueldoEstudiante + 1000;
            
        elsif fila.situacionlaboral = 'Parado' then
            contParados := contParados + 1;
            sueldoParado := sueldoParado + 500;
            
        elsif fila.situacionlaboral = 'Activo' then
            contActivos := contActivos + 1;
            sueldoActivo := sueldoActivo + 1500;
            
        end if;
    end loop;
    
    sumaCont := contEstudiantes + contParados + contActivos;
    total := (sueldoParado + sueldoActivo + sueldoEstudiante);
    mediaSueldos := round(total/sumaCont);
    
    dbms_output.put_line ('Se han insertado ' || contEstudiantes ||' estudiantes, '|| contParados || ' parados,' ||contActivos||' activos' );
    dbms_output.put_line ('entonces se nececesitara '||total|| ' euros y la media sera de ' || mediaSueldos);
END;

/* Ejercicio de Mapas:
Imprimir la sumade todas las certidumbres de los 
partidos en cuyas consultas han obtenido Si.*/

set serveroutput on;
DECLARE
    type hash_map is table of CONSULTAS_DATOS.certidumbre%type index by PARTIDOS.nombrecompleto%type;
    mapa hash_map;
    key partidos.nombrecompleto%TYPE;
    
    CURSOR c IS SELECT p.nombrecompleto, c.certidumbre
                FROM partidos p, consultas_datos c
                WHERE p.idpartido=c.partido and c.respuesta='Si';
BEGIN 
    --LO PRIMERO ES CARGAR LA TABLA DE DATOS
    FOR fila IN c LOOP
        IF mapa.exists(fila.nombrecompleto) THEN
            mapa(fila.nombrecompleto) := mapa(fila.nombrecompleto) + fila.certidumbre;
        ELSE
            mapa(fila.nombrecompleto) := fila.certidumbre;
        END IF;
    END LOOP;  
    
   --RECORREMOS LA TABLA E IMPRIMIMOS
    key:=mapa.FIRST;
    WHILE key IS NOT NULL LOOP
        dbms_output.put_line(key||' --> '||mapa(key));
        key:=mapa.NEXT(key);
    END LOOP;
END;



