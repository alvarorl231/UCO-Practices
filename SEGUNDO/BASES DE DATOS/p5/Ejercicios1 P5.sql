/*1. Muestre el nombre de los presidentes de partidos que cumpla con la condici�n de que tanto
su nombre como sus dos apellidos terminan en �o�. En este ejercicio no podr� hacer uso del
comando WHERE.*/


/*2. Encuentre la suma total de los resultados de cada partido pol�tico en todos los resultados de
eventos. Deber� hacer uso solo de sentencias PL/SQL y solo una vez los comandos SELECT,
FROM, WHERE, JOIN. Se necesita flexibilidad en su soluci�n, es decir que deber� aceptar
nuevos partidos. Muestre la informaci�n con el siguiente formato.*/
select p.nombrecompleto, e.resultado
from partidos p,eventos_resultados e 
where p.idpartido=e.partido;

set serveroutput on;
DECLARE
    type tabla_hash is Table of FLOAT index by VARCHAR2(100);
    mitabla tabla_hash;
    CURSOR resultados IS select p.nombrecompleto, e.resultado
                            from partidos p,eventos_resultados e 
                            where p.idpartido=e.partido;
    nombre VARCHAR2(100);
    
BEGIN
    --Recorrer el curso agregandro los resultados en la tabla hash
    FOR resultado IN resultados LOOP
        IF mitabla.exists(resultado.nombrecompleto) THEN
            mitabla(resultado.nombrecompleto) := mitabla(resultado.nombrecompleto) + resultado.resultado;
        ELSE
            mitabla(resultado.nombrecompleto) := resultado.resultado;
        END IF;
    END LOOP;    
    --Recorrer la tabla hash y mostrar los resultados en pantalla (hecho)
    nombre := mitabla.FIRST;
    WHILE nombre is NOT NULL LOOP
        dbms_output.put_line(nombre||' => '||mitabla(nombre));
        nombre := mitabla.next(nombre);
    END LOOP;
END;
/*3. Obtener el nombre de todos los votantes cuyo DNI acaba igual que el identificador de su
localidad m�s 1. Es decir, el votante con DNI 30948214 debe mostrarse si pertenece a la
localidad n�mero 3.*/
set serveroutput on;
DECLARE
    numerodni votantes.dni%type;

    CURSOR c is select dni, localidad,nombrecompleto from votantes;

BEGIN
    for fila in c
    loop
        numerodni:=substr(fila.dni,-1,1);
        if numerodni=fila.localidad+1
            then 
            dbms_output.put_line(fila.nombrecompleto);
        end if;
    end loop;

END;


/*4. Mostrar los DNIs de los votantes en orden, indicando va antes que otro. El �ltimo DNI (el
m�s peque�o) se indicar� que es el m�s peque�o.*/

--Se puede hacer con Producto cartesiano

select dni from votantes order by dni desc;

set serveroutput on;
DECLARE
CURSOR dnis IS select dni from votantes order by dni desc;
dniAnterior votantes.dni%type;

BEGIN
    FOR unDni IN dnis LOOP
        dbms_output.put_line(dniAnterior||' antes '||unDni.dni); --FALLA POR QUE dniAnterior no vale nada
        dniAnterior := unDni.dni;
    END LOOP;
END;

-------- RESULTADO
set serveroutput on;
DECLARE
CURSOR dnis IS select dni from votantes order by dni desc;
dniAnterior votantes.dni%type;

BEGIN
    FOR unDni IN dnis LOOP
        if dniAnterior is NULL THEN
            dniAnterior := unDni.dni;
        ELSE
            dbms_output.put_line(dniAnterior||' antes '||unDni.dni);
            dniAnterior := unDni.dni;
        END IF;
    END LOOP;
    dbms_output.put_line(dniAnterior||' es el menor.');
END;