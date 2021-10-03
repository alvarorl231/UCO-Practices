select * from provincias, localidades where localidades.provincia=provincias.idprovincia;

select * from provincias, localidades, votantes where localidades.idlocalidad=votantes.localidad and localidades.provincia=provincias.idprovincia;

select * from provincias, localidades, votantes where localidades.idlocalidad=votantes.localidad and localidades.provincia=provincias.idprovincia and provincias.idprovincia='1';

select * from provincias, localidades, votantes where localidades.idlocalidad=votantes.localidad and localidades.provincia=provincias.idprovincia and provincias.idprovincia='1' or provincias.idprovincia='2'; //mal;


select v.nombrecompleto, v.localidad, l.localidad, l.idprovincia, l.nombre ....... //alias;


select numerohabitantes from localidades order by numerohabitantes desc;


select * from localidades;

select sum(numerohabitantes) from localidades;

select max(numerohabitantes) from localidades;

select count(*) from localidades;

select count(*) from localidades where provincia='1';

select provincia, sum(numerohabitantes)from localidades group by provincia;

select provincias.nombre, sum(localidades.numerohabitantes)from localidades, provincias where provincias.idprovincia=localidades.provincia group by provincias.nombre;

select provincias.nombre, sum(localidades.numerohabitantes)from localidades, provincias where provincias.idprovincia=localidades.provincia having sum(localidades.numerohabitantes)>'1000000' group by provincias.nombre;

