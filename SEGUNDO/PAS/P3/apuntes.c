APUNTES PRÁCTICA 3

gcc -> compilador c
man -> instrucciones comando
gcc programa.c -> ejecutable a.out
gcc programa.c -o programa.exe -> ejecutable programa.exe
gcc -g programa.c -o programa.exe -> seguir el programa
gcc -g programa.c -o programa.exe -O3 -> mayor rendimiento
-g -> opción binaria
programa.c -> Argumento posicional (va el primero)
-o programa.exe -> opción con argumento separado
-O3 -> opción con argumento junto


#include <unistd.h>

int getopt( int argc, char * const argv[], const char * optstring);
extern chahr *optarg;
extern int opterr


//EJEMPLO-GETOPT.C
./a.out -b -> activa b
./a.out -a -> activa a
./a.out -a -b -> activa a y b 
./a.out -ab -> activa a y b 
./a.out -a -cargumento -b 

 while ((c = getopt(argc, argv, "abc:")) != -1) {
     Las opciones que se nos presentan es a b c, y c: significa que espera un argumento.

 Cuando se active cada una de ellas, activaremos su flag: aflag=true
 Sin embargo, c que recibe argumento cvalue= optarg guardandolo ahí;
 Si recibe ? significa que ha deteptado un error
    optopt == c (falta un argumento)
    no exite lo que ha entrado es desconocida


    for (index = optind; index < argc; index++)
        printf("Argumento \"%s\" de la línea de comandos que NO ES UNA "
               "OPCIÓN.\n\n",
               argv[index]);

Va a meter las variables que no son opciones al final del argv que no son opciones

    if (cvalue == NULL)
        cvalue = "ValorPorDefecto";

Si no se introduce el valor de c se mete por ValorPorDefecto


opterr: da una salida de erorr por ssi misma. 




getopt_long no es de POSIX

#include <getopt.h>

int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex(NULL));

//EJEMPLO-GETOPTLONG.C
    creamos nosotros las opciones largas a partir de la struct, lo demas
    es igual que en la anterior


VARIABLES DE ENTORNO
env            -> muestra las variables de entorno en terminal
echo $LANG      -> muestra la variable por pantalla
export LANG=en_GB.      -> modifica la variable entorno



//GETENV

#include <stdlib.h>

//EJEMPLO-GETENV.C






INFORMACIÓN DE USUARIOS Y GRUPOS

#include <pwd.h> 
#include <grp.h>

//obtener info de usuarioa  partir de --..
struct passwd *getpwuid(uid_t uid);
struct passwd *getpwnam(const char *name);

struct group *getgrgid (gid_t gid);
struct group *getgrnam(const char *name);
