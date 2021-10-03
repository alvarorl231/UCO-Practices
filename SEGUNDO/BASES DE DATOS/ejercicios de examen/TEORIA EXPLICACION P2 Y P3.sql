-- PRACTICA 2
/*

HAVING, funciona igual que el WHERE con la diferencia que en HAVING podemos usar FUNCIONES
Sirve para poner condiciones

HAVING COUNT()
HAVING AVG()
HAVING SUM()
HAVING MAX()
.
.
.

*/
--PRACTICA 3
/*

                                   IN, NOT IN, BETWEEN, ...
SELECT nombrecompleto FROM votantes WHERE localidad IN (1, 2, 3);

SELECT nombrecompleto FROM votantes WHERE estudiossuperiores IN ('Basicos','Superiores', 
'Doctorado');
SELECT nombrecompleto FROM votantes WHERE estudiossuperiores NOT IN ('Ninguno’);



                                    MANIPULACION DE CADENAS
    1. CONCATENACIÓN -- CONCAT('Ho','la') devuelve Hola
        CONCAT(cad1,cad2,cadn)
    
    2. POSICION DE LETRAS O ESPACIOS -- INSTR('Hola','o') devuelve 2   *IMPORTANTE*
        INSTR(cad1,cadAbuscar) INSTR(nombrecompleto,' ')
        
    3. SUBCADENAS -- SUBSTR('Hola',1,3) devuelve Hol  
                    SUBSTR('Hola',2,3) devuelve ola                     *IMPORTANTE*
        SUBSTR(cad,posIicio,Numero de caracteres a recoger)  
        JOSE PEREZ --> SUBSTR(nombrecompleto,1,4) = JOSE
        
    4. LONGITUD -- LENGTH('Hola') devuelve 4
        LENGTH(cad)


                                        DECODE (como un switch en c++)  *IMPORTANTE*
                                        
    DECODE(columna sobre la que hace el switch, primera condicion, lo que muestra, 
                                                segunda condiciom, lo que muestra,
                                                default)
                                                
SELECT nombrecompleto, DECODE(estudiossuperiores,'Basicos', 1500, 
                                                'Superiores',2000,
                                                'Doctorado', 2500, 
                                                1000) 
FROM votantes;


                                    ANY Y ALL
                                    
• ANY: compara los valores con cada valor devuelto por la subconsulta
• ALL: compara los valores con cada uno de los valores devueltos por la
subconsulta


SELECT nombre 
FROM localidades
WHERE numerohabitantes > ALL (SELECT numerohabitantes 
                                FROM localidades 
                                WHERE provincia=1);
*/
