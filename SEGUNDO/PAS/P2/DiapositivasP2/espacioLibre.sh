#!/bin/bash
df | sed -r -n -e '2,$s/^([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)$/El fichero de bloques \1, montado en \6, tiene usados \3 bloques de un total de \2 (porcentaje de \5)./p'

df | grep --color -E '^[a-Z0-9/\:]+ +[0-9]+ +[0-9]+ +[0-9]+ +[0-9]+% +[0-9a-Z/]+$'
df | sed -r -n -e '2,$s/(^[a-Z0-9/\:]+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +([0-9a-Z/]+)$/El fichero de bloques \1, montado en \6, tiene usados \3 bloques de un total de \2 (porcentaje de \5)./p'