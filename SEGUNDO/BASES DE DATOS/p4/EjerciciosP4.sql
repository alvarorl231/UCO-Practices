-- EJERCICIO 1 : Muestre por pantalla el clásico “Hola mundo”, pero además muestre la fecha actual.
set serveroutput on;
begin
    dbms_output.put_line('Hola mundo, son las ' || CURRENT_DATE);
end;


/* EJERCICIO 2: Muestre el primer APELLIDO y el DNI del votante más antiguo, su respuesta 
debe cumplir elformato: “APELLIDO, con dni DNI es el/la votante con más años.” La selección 
del primer apellido debe ser exclusivamente empleando PL/SQL.*/
set serveroutput on;
declare 
    v_nombre votantes.nombrecompleto%type;
    v_apellidos votantes.nombrecompleto%type;
    v_primerApellido VARCHAR(20);
    v_dni votantes.dni%type;

begin 
    select nombrecompleto, dni
    into v_nombre,v_dni
    from votantes
    where fechanacimiento=(select MIN(fechanacimiento) from votantes);
    v_apellidos := substr(v_nombre, instr(v_nombre,' ')+1);
    v_primerApellido := substr(v_apellidos, 1, instr(v_apellidos, ' ')-1);
    dbms_output.put_line(v_primerApellido||', con dni '||v_dni||' es el/la votante con mas años');
end;


/* EJERCICIO 3: Mostrar el nombre completo y el correo electrónico del votante con DNI 30983712,
mostrando la información como sigue. */
set serveroutput on;
declare 
    v_nombre votantes.nombrecompleto%type;
    v_email votantes.email%type;
begin
    select nombrecompleto, email
    into v_nombre, v_email
    from votantes
    where dni=30983712;
    dbms_output.put_line(v_nombre|| ' con correo: ' || v_email);
end;

/* EJERCICIO 4: El votante con DNI 30983712 desea que lo llamen Pepe en lugar de Jose. 
Sin embargo, este cambio no puede realizarse oficialmente en la base de datos puesto 
que no es su nombre real. Muestre el nombre completo de dicho votante pero apareciendo 
Pepe en lugar de Jose.*/
set serveroutput on;
declare
    v_apellidos votantes.nombrecompleto%type;
    v_nombre votantes.nombrecompleto%type:= 'Pepe';
begin
    select SUBSTR(nombrecompleto,5)
    into v_apellidos
    from votantes
    where dni=30983712;
    dbms_output.put_line(v_nombre||v_apellidos);
end;

/* EJERCICIO 5. Teniendo en cuenta a los votantes, diga cuántos años hay entre la persona 
de mayor edad con respecto a la de menos. Muestre además las fechas de nacimiento del par 
de personas.*/
set serveroutput on;
declare
    fechaMayor votantes.fechanacimiento%type;
    fechaMenor votantes.fechanacimiento%type;
    diferencia NUMBER;
begin
    select min(fechanacimiento), max(fechanacimiento), extract(year from (max(fechanacimiento)))-extract(year from (min(fechanacimiento)))
    into fechaMayor, fechaMenor, diferencia
    from votantes;
    dbms_output.put_line(fechaMayor);
    dbms_output.put_line(fechaMenor);
    dbms_output.put_line(diferencia);
end;

/*EJERCICIO 6. Muestre el nombre del partido y la certidumbre correspondiente que durante 
la consulta de datos obtuvieron un “Si” de respuesta y además tengan un valor de certidumbre
superior a la media de las certidumbres. En este ejercicio solo podrá realizar única consulta
sobre la tabla CONSULTAS_DATOS. Además a muestre la media redondeada a 3 cifras significativas
a modo de información. Muestre los datos como sigue ordenados según el valor de certidumbre.
*/

SELECT p.nombrecompleto,c.certidumbre
FROM consultas_datos c, partidos p
WHERE p.idpartido=c.partido AND c.respuesta='Si';


set serveroutput on;
declare
    CURSOR c1 IS SELECT p.nombrecompleto,c.certidumbre FROM consultas_datos c, partidos p
                    WHERE p.idpartido=c.partido;
                    
    CURSOR c2 IS SELECT p.nombrecompleto,c.certidumbre FROM consultas_datos c, partidos p
                    WHERE p.idpartido=c.partido AND c.respuesta='Si';                
                    
    suma FLOAT :=0;
    contador NUMBER :=0;
    media FLOAT :=0;
begin
    for fila in c1
    loop
        suma:= suma + fila.certidumbre;
        contador := contador+1;
    end loop;
    media:= suma/contador;
    media:=round(media,3);
    dbms_output.put_line('La media de la certidumbre es '||media);
    
    for fila in c2
    loop
        if fila.certidumbre > media
            then
            dbms_output.put_line(fila.nombrecompleto||' '||fila.certidumbre);
        end if;
    end loop;
end;
















