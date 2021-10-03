/*1- Obtener el nombre de todos los votantes cuyo DNI acaba igual que el
identificador de su localidad más 1. Es decir, el votante con DNI 30948214 debe
mostrarse si pertenece a la localidad número 3.*/

SELECT dni,substr(dni,-1,1)   --SUBSTR (CADENA,POSICION,LONGITUD)   (-1 es el último,-2 el penultimo, ect..)
FROM votantes;

select nombrecompleto
from votantes
where substr(dni,-1,1)=localidad+1;

/*2- Obtener el nombre de todos los votantes así como el nombre de la localidad en
la que viven teniendo en cuenta que todos los que sean de la provincia de
Córdoba (identificador de localidad 1, 2 y 3) se han mudado a Madrid.*/

SELECT v.nombrecompleto,l.nombre
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad;

SELECT v.nombrecompleto, DECODE(l.nombre,'Cordoba','Madrid','Baena','Madrid','Montilla','Madrid',l.nombre)
--DECODE(SOBRE QUE COLUMNA,NOMBRE,CAMBIAR POR, NOMBRE, CAMBIAR POR,....)
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad
ORDER BY (DECODE(l.nombre,'Cordoba','Madrid','Baena','Madrid','Montilla','Madrid',l.nombre)) desc;


--Nombre de votantes y nombre de localidad de los votantes que vivan en la provincia de cordoba
SELECT nombrecompleto, l.nombre
FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad
AND l.provincia=(SELECT idprovincia FROM provincias where nombre='CÃ³rdoba');
-- ó AND l.provincia=1;


/*3- Mostrar	las	siglas	de	aquellos	partidos que han	participado	un	mayor	
número	de	veces	en	eventos.*/

SELECT p.siglas
FROM partidos p, eventos_resultados e
WHERE (p.idpartido = e.partido)
GROUP BY p.siglas
HAVING COUNT(e.partido)=(SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido);

--Obtener el mayor numero de veces que ha participado un partido en un evento
SELECT MAX(COUNT(partido))
FROM eventos_resultados
GROUP BY partido;

--Obtener el ID del partido que ha	participado	un	mayor número de	veces
SELECT partido
FROM eventos_resultados
HAVING COUNT(partido)=(SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido)
GROUP BY partido;

SELECT MAX(COUNT(partido))
FROM eventos_resultados
GROUP BY partido;


/*7- Obtener el nombre de los votantes cuya participación ha sido mayor que la
media de participaciones de todos los votantes.*/

SELECT v.nombrecompleto
FROM votantes v, consultas c
WHERE c.votante=v.dni
HAVING (count(votante)) > (select avg(count(votante)) from consultas group by votante)
GROUP BY v.nombrecompleto
;

select avg(count(votante))
from consultas
group by votante;

