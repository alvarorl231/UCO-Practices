--                                  RELACIÓN 2
/*2- Obtener el nombre de todos los votantes así como el nombre de la localidad en
la que viven teniendo en cuenta que todos los que sean de la provincia de
Córdoba (identificador de localidad 1, 2 y 3) se han mudado a Madrid.
Finalmente, mostrar el numero de votantes que son de Madrid con un mensaje
como sigue:*/

set serveroutput on;
DECLARE
    CURSOR c IS select v.nombrecompleto,v.localidad, l.nombre from votantes v, localidades l
                where v.localidad=l.idlocalidad;
    contador number:=0;

BEGIN 
    for fila in c
    loop
        if fila.localidad=1 or fila.localidad=2 or fila.localidad=3
            then
            dbms_output.put_line(fila.nombrecompleto||'es de Madrid');
            contador:=contador+1;
        else
            dbms_output.put_line(fila.nombrecompleto||'es de '||fila.nombre);
            if fila.localidad=9
                then 
                contador:=contador+1;
                end if;
        end if;
    end loop;
    dbms_output.put_line('Hay un total de '||contador||' votantes de Madrid');
END;


/*4- Obtener el DNI del votante y el numero de veces que dicho votante ha
participado en una consulta, mostrando el resultado de manera descendente
en cuanto a número de participaciones. Sólo se mostrarán aquellos votantes
cuya participación ha sido mayor que la media de participaciones de todos los
votantes.*/


select votante, count(votante) as contador from consultas
group by votante order by count(votante)desc;
select avg(count(votante)) from consultas
group by votante;

set serveroutput on;
DECLARE
    CURSOR c is select votante, count(votante) as contador from consultas
group by votante order by count(votante)desc;

    suma float:=0;
    cont number :=0;
    media float :=0;

BEGIN
    for fila in c
    loop
        suma:=suma+fila.contador;
        cont:=cont+1;
    end loop;
    media:=suma/cont;
    dbms_output.put_line(media);

    for fila in c
    loop 
        if fila.contador > media
            then
             dbms_output.put_line(fila.votante||' ha participado '||fila.contador||' veces');
        end if;
    end loop;
END;





