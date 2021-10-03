/*1. Mostrar el nombre de pila (sin apellidos), nombre de localidad y nombre de comunidad de
los votantes pertenecientes a las localidades 1, 3 � 9. Personaliza el t�tulo de dichas
columnas.*/

--COGEMOS LA SUBACENA DESDE 1 HASTA DONDE ESTA EL ESPACIO)
SELECT nombrecompleto,SUBSTR(nombrecompleto,1, INSTR(nombrecompleto,' '))
FROM votantes;

SELECT SUBSTR(v.nombrecompleto,1, INSTR(v.nombrecompleto,' ')) as "Nombre de pila", l.nombre as "Nombre localidad", p.nombre "Nombre provincias"
FROM votantes v, localidades l, provincias p
WHERE v.localidad=l.idlocalidad
AND l.provincia=p.idprovincia
AND v.localidad IN (1,3,9);


/*2. Ordenar las localidades en base a su identificador de localidad, de manera que el resultado
quede as�:*/

SELECT l1.nombre || ' va antes que ' || l2.nombre as Ordenacion
FROM localidades l1, localidades l2
WHERE l2.idlocalidad=l1.idlocalidad+1;

/*3. Obtener el nombre de las localidades que tienen un n�mero de habitantes mayor que la
localidad del votante que es el segundo votante de m�s edad de entre todos los votantes
existentes en la base de datos*/

--OBTENEMOS EL SEGUNDO VOTANTE DE M�S EDAD
SELECT *
FROM votantes
WHERE fechanacimiento = (SELECT MIN (fechanacimiento)
                        FROM votantes 
                        WHERE fechanacimiento > (SELECT MIN(fechanacimiento) 
                                                FROM votantes));
                                                
SELECT numerohabitantes
FROM votantes, localidades 
WHERE idlocalidad=localidad
AND fechanacimiento = (SELECT MIN (fechanacimiento)
                        FROM votantes
                        WHERE fechanacimiento > (SELECT MIN(fechanacimiento) 
                                                FROM votantes));                                                
                        
-- FINAL                        
SELECT l.nombre
FROM localidades l
WHERE l.numerohabitantes>(SELECT numerohabitantes
FROM votantes, localidades 
WHERE idlocalidad=localidad
AND fechanacimiento = (SELECT MIN (fechanacimiento)
                        FROM votantes
                        WHERE fechanacimiento > (SELECT MIN(fechanacimiento) 
                                                FROM votantes)));
/*4. Mostrar el nombre completo de los votantes, n�mero de localidad a la que pertenecen y
�mayoria edad� (mostrar�: 'mayor edad' y 'menor edad' en lugar de su fecha de nacimiento
en funci�n de si son mayores de edad o no). Los resultados de esta consulta s�lo recoger�n a
los votantes de las localidades 2, 4 y 8 y quedar�n ordenados por la nueva columna de
�mayoria edad�.*/

SELECT nombrecompleto,localidad, fechanacimiento
FROM votantes 
WHERE localidad in (2,4,8);

SELECT nombrecompleto,sysdate, fechanacimiento, abs(sysdate-fechanacimiento)/365 as Diferencia--EXTRACT(YEAR FROM sysdate) - EXTRACT(YEAR FROM fechanacimiento) as Diferencia
FROM votantes
WHERE (abs(sysdate-fechanacimiento)/365)>=18;

SELECT 1
FROM votantes
WHERE (abs(sysdate-fechanacimiento)/365)>=18;
--no hay menoes de edad, lol
SELECT 0
FROM votantes
WHERE (abs(sysdate-fechanacimiento)/365)<18;

--SI EL DECODE DA 1 SE PONE MAYOR DE EDAD, SI NO PONE COMO MENOR DE EDAD QUE SER�A EL DEFAULT DE UN SWITCH
SELECT v1.nombrecompleto, v1.localidad, DECODE((SELECT 1 FROM votantes v2 WHERE v2.dni=v1.dni AND (abs(sysdate-v2.fechanacimiento)/365)>=18),1,'Mayor de edad','Menor de edad')
FROM votantes v1;                        

--RESULTADO

SELECT v1.nombrecompleto, v1.localidad, DECODE((SELECT 1 FROM votantes v2 WHERE v2.dni=v1.dni AND (abs(sysdate-v2.fechanacimiento)/365)>=18),1,'Mayor de edad','Menor de edad') as "Mayoria de edad"
FROM votantes v1
WHERE localidad in (2,4,8)
ORDER BY localidad;

/*5. Muestra el nombre de las localidades, su n�mero de habitantes y el nombre de la comunidad
a la que pertenecen. Se recoger�n s�lo aquellas localidades cuyo n�mero de provincia sea el
1, 2, o 3 y que tengan mayor n�mero de habitantes que alguna de las localidades de la
provincia n�mero 4.*/

/*
PARA COMPARAR UN DATO CON UN CONJUNTO DE DATOS
ANY ()
ALL ()
IN ()
NOT IN ()
*/

--RESUELTO
SELECT l.nombre, l.numerohabitantes, p.nombre
FROM localidades l, provincias p
WHERE l.provincia=p.idprovincia 
AND l.provincia IN (1,2,3)
AND l.numerohabitantes > ANY (SELECT l.numerohabitantes    
                            FROM localidades l
                            WHERE l.provincia='4') ;

/*6. Obtener el nombre de los votantes cuya participaci�n ha sido menor que la media de
participaciones de todos los votantes a pesar de encontrarse en situaci�n laboral de 'Activo'.*/

--MEDIA
SELECT AVG(COUNT(c.votante))
FROM consultas c
GROUP BY c.votante;

--RESULTADO
SELECT v.nombrecompleto
FROM votantes v, consultas c
WHERE c.votante=v.dni
HAVING COUNT(c.votante)<(SELECT AVG(COUNT(c.votante))FROM consultas c GROUP BY c.votante) 
GROUP BY v.nombrecompleto;


/*7. Mostrar el nombre de las localidades ordenadas de mayor a menor nivel de
estudiosSuperiores medio de sus votantes.*/

SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
FROM votantes;

--RESULTADO
SELECT l.nombre, v.estudiossuperiores, V.NOMBRECOMPLETO           --SE ME REPITEN Y NO LO ENTIENDO
FROM localidades l, votantes v
WHERE l.idlocalidad=v.localidad
AND (SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
        FROM votantes) 
            > 
            (DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
OR (SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
        FROM votantes) 
            < 
            (DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
ORDER BY (DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3)) desc
;



/*8. Mostrar aquellas localidades cuyos votantes tienen un nivel de estudiosSuperiores medio
mayor que todas las medias de estudiosSuperiores de las provincias.*/

SELECT DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3), provincia
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad;

--MEDIA EN PROVINCIA
SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3)) Media, provincia
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad
GROUP BY l.provincia;

--MEDIA EN LOCALIDAD
SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3)) Media, localidad
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad
GROUP BY localidad;

--RESUELTO
SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3)) Media, l.nombre
FROM votantes v, localidades l, provincias p
WHERE v.localidad=l.idlocalidad AND l.provincia=p.idprovincia
GROUP BY l.nombre
HAVING (AVG(DECODE
            (estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3)))
                            > 
            any (SELECT AVG(DECODE(estudiosSuperiores, 'Ninguno',0, 'Basicos',1, 'Superiores',2,'Doctorado',3))
                 FROM votantes v, localidades l
                 WHERE v.localidad=l.idlocalidad
                 GROUP BY l.provincia);
                 
                 