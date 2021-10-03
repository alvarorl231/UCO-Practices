/*1- Obtener el nombre de todos los votantes cuyo DNI acaba igual que el
identificador de su localidad más 1. Es decir, el votante con DNI 30948214 debe
mostrarse si pertenece a la localidad número 3.*/
select nombrecompleto
from votantes
where substr(dni,-1,1)=localidad+1;

/*2- Obtener el nombre de todos los votantes así como el nombre de la localidad en
la que viven teniendo en cuenta que todos los que sean de la provincia de
Córdoba (identificador de localidad 1, 2 y 3) se han mudado a Madrid.*/

SELECT v.nombrecompleto,l.nombre
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad;

SELECT v.nombrecompleto, DECODE(l.nombre,'Cordoba','Madrid','Baena','Madrid','Montilla','Madrid',l.nombre) as nombre
--DECODE(SOBRE QUE COLUMNA,NOMBRE,CAMBIAR POR, NOMBRE, CAMBIAR POR,....)
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad
ORDER BY nombre desc;

/*3- Mostrar	las	siglas	de	aquellos	partidos que han	participado	un	mayor	
número	de	veces	en	eventos.*/

--Obtener el mayor numero de veces que ha participado un partido en un evento
SELECT MAX(COUNT(partido))
FROM eventos_resultados
GROUP BY partido;

--Obtener el ID del partido que ha	participado	un	mayor número de	veces
SELECT partido
FROM eventos_resultados
HAVING COUNT(partido)=(SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido)
GROUP BY partido;

--RESULTADO
SELECT p.siglas
FROM partidos p, eventos_resultados e
WHERE (p.idpartido = e.partido)
GROUP BY p.siglas
HAVING COUNT(e.partido)=(SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido);

/*4- Obtener el DNI del segundo votante de más edad de entre todos los votantes
existentes en la base de datos.*/
SELECT v.dni, v.fechanacimiento
FROM votantes v
ORDER BY v.fechanacimiento asc;

--DNI DEL MÁS VIEJO
SELECT v.dni
FROM votantes v
WHERE (SELECT MIN(v.fechanacimiento)
FROM votantes v) = v.fechanacimiento;

-- FECHA DEL SEGUNDO MÁS VIEJO, COGE LA MÍNIMA DENTRO DE LAS MAYORES, OSEA EL SEGUNDO MAYOR
SELECT MIN(v.fechanacimiento)
FROM votantes v
WHERE v.fechanacimiento > (SELECT MIN(v.fechanacimiento)
FROM votantes v);

--RESULTADO
SELECT v.dni
FROM votantes v
WHERE v.fechanacimiento= (SELECT MIN(v.fechanacimiento) FROM votantes v WHERE v.fechanacimiento 
> (SELECT MIN(v.fechanacimiento) FROM votantes v));

/*5- Obtener el DNI del votante y el numero de veces que dicho votante ha
participado en una consulta, mostrando el resultado de manera descendente
en cuanto a número de participaciones.*/

SELECT c.votante, COUNT(c.votante) as Participaciones 
FROM consultas c, votantes v
WHERE v.dni=c.votante
GROUP BY c.votante
ORDER BY Participaciones desc;

/*6- Obtener el DNI del votante y el numero de veces que dicho votante ha
participado en una consulta, mostrando el resultado de manera descendente
en cuanto a número de participaciones. Sólo se mostrarán aquellos votantes
cuya participación ha sido mayor que la media de participaciones de todos los
votantes.*/

SELECT c.votante, COUNT(c.votante)
FROM consultas c, votantes v
WHERE (SELECT AVG(c.evento)FROM consultas c, votantes v WHERE c.votante=v.dni) > (SELECT );

SELECT AVG(c.evento)
FROM consultas c, votantes v
WHERE c.votante=v.dni;

--RESULTADO
SELECT c.votante, count(c.votante) as Participaciones
FROM votantes v, consultas c
WHERE v.dni = c.votante
GROUP BY c.votante
HAVING COUNT (c.votante) > (SELECT AVG(COUNT(c.votante)) 
                            FROM votantes v, consultas c
                            WHERE v.dni=c.votante
                            GROUP BY c.votante)
ORDER BY Participaciones desc;

/*7- Obtener el nombre de los votantes cuya participación ha sido mayor que la
media de participaciones de todos los votantes.*/

--media
select avg(count(votante))
from consultas
group by votante;

--resultado
SELECT v.nombrecompleto
FROM votantes v, consultas c
WHERE c.votante=v.dni
HAVING (count(votante)) > (select avg(count(votante)) from consultas group by votante)
GROUP BY v.nombrecompleto
;

/*8- Obtener el DNI del votante y el numero de veces que dicho votante ha
participado en una consulta, mostrando el resultado de manera descendente
en cuanto a número de participaciones y no mostrando los resultados del
segundo votante de más edad.*/

SELECT c.votante, COUNT(c.votante)
FROM votantes v, consultas c
WHERE v.dni=c.votante
GROUP BY c.votante
ORDER BY COUNT(c.votante) desc;

--SEGUNDO MÁS VIEJO
SELECT v.dni
FROM votantes v
WHERE v.fechanacimiento= (SELECT MIN(v.fechanacimiento) FROM votantes v WHERE v.fechanacimiento 
> (SELECT MIN(v.fechanacimiento) FROM votantes v));

--RESULTADO
SELECT c.votante, COUNT(c.votante)
FROM votantes v, consultas c
WHERE v.dni=c.votante
AND (v.dni NOT LIKE (SELECT v.dni FROM votantes v WHERE v.fechanacimiento= (SELECT MIN(v.fechanacimiento) FROM votantes v WHERE v.fechanacimiento 
> (SELECT MIN(v.fechanacimiento) FROM votantes v))))
GROUP BY c.votante
ORDER BY COUNT(c.votante) desc;