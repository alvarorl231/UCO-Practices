/*1. Obtener el DNI de todos los votantes que tengan dos 6s 
en su tel�fono pero contemplar que no tienen m�s de tres*/

SELECT dni
FROM votantes
WHERE telefono LIKE'%6%6%' 
AND telefono NOT LIKE '%6%6%6%';

/*2. Obtener el DNI de todos los votantes que tengan tres 6s en su tel�fono 
pero contemplar que no tienen m�s de tres, dos de ellos deben estar juntos*/

SELECT dni
FROM votantes
WHERE telefono LIKE'%66%6%' OR telefono LIKE '%6%66%' 
AND telefono NOT LIKE '%6%6%6%6%';

/*3. Mostrar aquella localidad cuyo n�mero de habitantes acaba igual que su n�mero
de provincia, mostrando tambi�n el nombre de la provincia a la que pertenece*/

SELECT l.nombre "Localidad",p.nombre "Provincia"
FROM localidades l,provincias p
WHERE l.provincia=p.idprovincia
AND  SUBSTR(l.numerohabitantes,-1,1)= p.idprovincia;


select l.numerohabitantes, SUBSTR(l.numerohabitantes,-1,1), p.idprovincia
from localidades l,provincias p
where l.provincia=p.idprovincia;


/*4. Mostrar el nombre completo de los votantes cuyo tel�fono acaba igual que su dni*/
SELECT nombrecompleto
FROM votantes
WHERE SUBSTR(telefono,-1,1)=SUBSTR(dni,-1,1);






