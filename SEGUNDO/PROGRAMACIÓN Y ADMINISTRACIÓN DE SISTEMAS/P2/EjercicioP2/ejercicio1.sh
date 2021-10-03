#   Desarrollar un script en el que utilices los comandos grep y sed para formatear el fichero
# films.html que se proporciona. El fichero se encuentra en formato html, similar al que
# podriamos encontrar en una página como IMDB. El script deberá realizar las siguientes tareas:
#       1. Mostrar los datos de las peliculas en formato de texto plano similar al que se muestra en el
#   ejemplo siguiente.
#       2. Mostrar el titulo, el año y la valoración de las peliculas de los años 2000 (2000-2009).
#       3. Mostrar las peliculas en el mismo formato que se indicó en el punto 1 pero cambiando el
#   formato del número de valoraciones para que muestre los miles como “k”. Por ejemplo, en
#   lugar de 658000, se deberá mostrar 658k.
#       4. Añadir un punto final a las lineas que no lo tengan.
#       5. Mostrar una versión resumida en la que la sinopsis se limitará a 300 caracteres, mostrando
#   puntos suspensivos al final de la linea.


#!/bin/bash

#Mostramos lo pedido en el apartado 1) --> Muestro con el formato indicado y arrastro el modelo
echo -e "\n\t1) Mostrar pelis en el formato indicado"
sed -e 's/<p id=.director.>/Director: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/<.2>/Titulo: /g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e 's/<p>/Sinopsis: /g' -e 's/<p>/Sinopsis: /g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/(20/\n\tAño: 20/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' films.html


#Mostramos lo pedido en el apartado 2) --> Muestro solo las pedidas a través de un GREP
echo -e "\n\t2) Mostrar el título, el año y la valoración de las películas de los años 2000 (2000-2009)\n"
    sed -e 's/<p id=.director.>/Director: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/<.2>/Titulo: /g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e 's/<p>/Sinopsis: /g' -e 's/<p>/Sinopsis: /g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/(20/\n\tAño: 20/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' films.html | grep -B 1 -A 1 '200[0-9]'


#Mostramos lo pedido en el apartado 3) --> Cambio el formato de las valoraciones
echo -e "\n\n\t3)  Mostrar las películas formatadas como en 1) pero cambiando el formato del número de valoracionesde 658000 a 658k\n"
    sed -e 's/<p id=.director.>/Director: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/<.2>/Titulo: /g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e 's/<p>/Sinopsis: /g' -e 's/<p>/Sinopsis: /g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/(20/\n\tAño: 20/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' -e 's/\([[:digit:]]\{3\}\)\([[:digit:]]\{3\}\)/\1\k/g' films.html


#Mostramos lo pedido en el apartado 4) --> Añado un . a las líneas
echo -e "\n\n\t4) Añadir un punto al final de las líneas que no lo tengan.\n"
    sed -e 's/<p id=.director.>/Director: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/<.2>/Titulo: /g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e 's/<p>/Sinopsis: /g' -e 's/<p>/Sinopsis: /g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/(20/\n\tAño: 20/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' -e 's/$/\./g' films.html


#Mostramos lo pedido en el apartado 5) --> Añado ... cuando se superen el límite de carácteres.
echo -e "\n\n\t5) Mostrar una versión resumida en la que la sinopsis se limita a 300 caracteres\n"
    sed -e 's/<p id=.director.>/Director: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/<.2>/Titulo: /g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e 's/<p>/Sinopsis: /g' -e 's/<p>/Sinopsis: /g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/(20/\n\tAño: 20/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' films.html | sed -e 's/^\(.\{318\}\).*$/\1.../'