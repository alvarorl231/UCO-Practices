/*
    PRACTICA 6
*/
truncate table audit_table; --borra los datos de una tabla

CREATE TABLE "AUDIT_TABLE" ("DATOS" VARCHAR2(100 BYTE), "TABLA" VARCHAR2(100 BYTE) );

--drop table audit_table;

--EJERCICIO 1
create trigger ejercicio1_1
before update on eventos
for each row
begin
    insert into audit_table (datos,tabla) values (:old.nombre||', '||:new.nombre,'eventos');
    dbms_output.put_line('Actualizado!');
end;

update eventos set nombre='Cordoba' where idevento=6;
update eventos set nombre='Betis' where idevento=9;

--ejercicio 4 practica 6
alter table votantes
add constraint constraintPEPE
check(telefono<799999999 and telefono>600000000);

insert into votantes values(12345678,'Rafael Barbudo Lunar', 'Superiores', 'Activo', 'i22balur@uco.es', 0, date '1994-08-22', 98765431);

--ejercicio 5 practica 6
ALTER TABLE eventos
DISABLE CONSTRAINT CK_NOMBRE;
alter table eventos
add constraint tipoevento 
check((upper(substr(tipo,1,1)) like substr(tipo,1,1)) and (tipo like '%s'));

update eventos set tipo='Europeass' where idevento=1;