/*1- Obtener el nombre de todos los votantes cuyo DNI acaba igual que el
identificador de su localidad más 1. Es decir, el votante con DNI 30948214 debe
mostrarse si pertenece a la localidad número 3.*/

select nombrecompleto, dni, substr(dni, -length(localidad)), localidad 
from votantes
where (substr(dni, -length(localidad)))=(localidad+1);


select nombrecompleto
from votantes
where (substr(dni, -length(localidad)))=(localidad+1);

/*2- Obtener el nombre de todos los votantes así como el nombre de la localidad en
la que viven teniendo en cuenta que todos los que sean de la provincia de
Córdoba (identificador de localidad 1, 2 y 3) se han mudado a Madrid.*/


/*3- Mostrar las siglas de aquellos partidos que han participado un mayor
número de veces en eventos.*/

--Eventos por partido
select partido, count(*)
from eventos_resultados
group by partido;

-- Maximo que ha participado en eventos
select max(count(*)) 
from eventos_resultados 
group by partido;

-- Hemos puesto un alias, ya que no entiende bien max(count(*)), entonces:

select max(participaciones)
from (select partido, count(*) participaciones
        from eventos_resultados
            group by partido)
group by partido;
            
--Tenemos el máximo de participaciones de cada partido que tenia que se igual al maixmo
select partido, count(*)
from eventos_resultados
group by partido
having count(*)=
                (select max(participaciones)
                from (select partido, count(*) participaciones
                from eventos_resultados
                group by partido));


--Final
select siglas 
from partidos
where idpartido in
(select partido
from eventos_resultados
group by partido
having count(*)=(select max(participaciones)
                from (select partido, 
                count(*) participaciones
                from eventos_resultados
                group by partido)));