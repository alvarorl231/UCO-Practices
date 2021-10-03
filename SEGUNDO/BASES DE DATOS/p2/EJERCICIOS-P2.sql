/*1- Obtener el nombre de todos los votantes cuyo segundo apellido acaba en “n”.*/

SELECT NOMBRECOMPLETO FROM VOTANTES WHERE NOMBRECOMPLETO LIKE '%n';

/*2- Obtener el DNI de todos los votantes que tengan al menos tres 5s en su DNI.*/

SELECT DNI FROM VOTANTES WHERE DNI LIKE '%5%5%5%';

/*3- Obtener el nombre de aquellos votantes cuya fecha de nacimiento sea posterior al 1 de Enero de 1990.*/

SELECT NOMBRECOMPLETO FROM VOTANTES WHERE FECHANACIMIENTO>'01/01/90';

/*4- Obtener el nombre del votante y el nombre de la localidad de aquellos votantes que han ejercido el voto en una localidad que tiene más de 300000 habitantes.*/

SELECT v.NOMBRECOMPLETO, l.NOMBRE 
FROM VOTANTES v, LOCALIDADES l
WHERE v.LOCALIDAD=l.IDLOCALIDAD AND l.NUMEROHABITANTES>'300000';

/*5- Obtener el nombre del votante y el nombre de la comunidad de aquellos votantes que han ejercido el voto en una localidad que tiene más de 300000 habitantes.*/

SELECT V.NOMBRECOMPLETO, P.COMUNIDAD
FROM VOTANTES V, LOCALIDADES L, PROVINCIAS P
WHERE V.LOCALIDAD=L.IDLOCALIDAD AND L.PROVINCIA=P.IDPROVINCIA AND L.NUMEROHABITANTES>'300000';

/*6- Obtener el identificador del partido y el número de datos o consultas que se tiene para dicho partido de entre todos los partidos sobre los que se han realizado alguna consulta.*/

SELECT PARTIDO, COUNT(PARTIDO) "conteo"
FROM CONSULTAS_DATOS
GROUP BY PARTIDO;

/*7- Mostrar el identificador de partido y el número de consultas realizadas para cada partido.*/

SELECT PARTIDO, COUNT(CONSULTA)
FROM CONSULTAS_DATOS
GROUP BY PARTIDO;

/*8- Mostrar el nombre del partido político sobre el que se han realizado más de 10 consultas.*/

SELECT P.NOMBRECOMPLETO
FROM PARTIDOS P, CONSULTAS_DATOS CD
WHERE P.IDPARTIDO=CD.PARTIDO
GROUP BY P.NOMBRECOMPLETO
HAVING COUNT(CD.PARTIDO)>'10'
ORDER BY P.NOMBRECOMPLETO;

/*9- Mostrar el nombre del partido y el número de consultas realizadas para aquellos partidos que aparecen en más de 10 consultas.*/
SELECT P.NOMBRECOMPLETO, COUNT(CD.PARTIDO) "Conteo"
FROM PARTIDOS P, CONSULTAS_DATOS CD
WHERE P.IDPARTIDO=CD.PARTIDO
GROUP BY P.NOMBRECOMPLETO
HAVING COUNT(CD.PARTIDO)>'10'
ORDER BY P.NOMBRECOMPLETO;


/*10- Mostrar el nombre de los partidos y el número de consultas realizadas para cada partido considerando sólo aquellas consultas en las que el encuestado ha
contestado afirmativamente a votar a dicho partido y con una certidumbre por encima del 80%, es decir, 0.8.*/
SELECT P.NOMBRECOMPLETO, COUNT(CD.PARTIDO) "Conteo"
FROM CONSULTAS_DATOS CD,PARTIDOS P 
WHERE P.IDPARTIDO=CD.PARTIDO
AND CD.RESPUESTA='Si' AND CD.CERTIDUMBRE>'0,8'
GROUP BY P.NOMBRECOMPLETO;


