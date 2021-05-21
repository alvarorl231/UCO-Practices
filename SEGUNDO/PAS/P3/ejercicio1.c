#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <getopt.h>
/* Libraries for structs passwd and group */
#include <pwd.h>
#include <grp.h>
/* Library to use strtok */
#include <string.h>
/* Library for getlogin() */
#include <unistd.h>

void MensajeAyuda();


int main (int argc, char **argv)
{
	int c;

  /* Estructura a utilizar por getoptlong */
  static struct option long_options[] =
  {
    /* Opciones que no van a actuar sobre un flag */
    /* "opcion", recibe o no un argumento, 0,
       identificador de la opción */
    {"user",	 required_argument,	   0, 'u'},
    {"group",  required_argument,	   0, 'g'},
    {"active",  no_argument, 0, 'a'},
    {"maingroup",  no_argument, 0, 'm'},
    {"allgroups",	no_argument, 0, 's'},
    {"help",	no_argument, 0, 'h'},
    /* Necesario para indicar el final de las opciones */
    {0, 0, 0, 0}
  };

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	char *uvalue = NULL;
	char *gvalue = NULL;
    int aflag = 0;
	int mflag = 0;
    int sflag = 0;
    int hflag = 0;
    char line[50];
    char *groupName = NULL;
    FILE *group_file;

    
/* Variables de entorno
  char *lang = "LANG";
  char *home = "HOME";
  char *value;
*/

  // Declaracion de las estructuras que almacenaran la informarcion de un usuario y de un grupo
  struct passwd *pw;
  struct group *gr;
  char *lgn; //login 
  int uid;
  int guid;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;

    // Para cuando solo sea el ejecutable
    if(argc == 1)
    {
        lgn = getenv("USER");
        pw = getpwnam(lgn);

        printf("Usuario:\n");
        printf("Nombre: %s\n", pw->pw_gecos); 
        printf("Login: %s\n", pw->pw_name);
        printf("Password: %s\n", pw->pw_passwd);
        printf("UID: %d\n", pw->pw_uid);
        printf("Home: %s\n", pw->pw_dir);
        printf("Shell: %s\n", pw->pw_shell);
        printf("Número de grupo principal: %d\n", pw->pw_gid);   
    }



	/* Deshabilitar la impresión de errores por defecto */
	/* opterr=0; */
	while ((c = getopt_long (argc, argv, "u:g:amsh", long_options, &option_index))!=-1)
	{
		/* El usuario ha terminado de introducir opciones */
		if (c == -1)
			break;
		switch (c)
		{
        case 'u':
                printf("\t\t\t'Opción -u, --user'\n");
                uvalue = optarg; //En optarg se guarda el valor del argumento requerido
		        lgn = uvalue;

                if (isdigit(*lgn))
                {
                uid = atoi(lgn);

                    if ((pw = getpwuid(uid)) == NULL) 
                    {
                        fprintf(stderr, "La opción --user sólo puede acompañar un nombre o UID válidos.\n");
                        MensajeAyuda();
                        exit(1);
                    }
                    //Aqui ya se dispone de la estructura que contiene informacion del usuario
                    printf("Usuario:\n");
                    printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
                    printf("Login: %s\n", pw->pw_name);
                    printf("Password: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Shell: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);
                }
                else
                {
                    if ((pw = getpwnam(lgn)) == NULL) 
                    {
                        fprintf(stderr, "La opción --user sólo puede acompañar un nombre o UID válidos.\n");
                        MensajeAyuda();
                        exit(1);
                    }
                    printf("Usuario:\n");
                    printf("Nombre: %s\n", pw->pw_gecos);
                    printf("Login: %s\n", pw->pw_name);
                    printf("Password: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Shell: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);
                }
            break;

        case 'g':
                printf("\t\t\t'Opción -g, --group'\n");
                gvalue = optarg; //En optarg se guarda el valor del argumento requerido
		        lgn = gvalue;

                if (isdigit(*lgn))
                {
                guid = atoi(lgn);
  
                    if ((gr = getgrgid(guid)) == NULL) 
                    {
                        fprintf(stderr, "La opción --group sólo puede acompañar un nombre o GID válidos.\n");
                        MensajeAyuda();
                        exit(1);
                    }
                    printf("Grupo:\n");
                    printf("Nombre: %s\n", gr->gr_name);
                    printf("Password: %s\n", gr->gr_passwd);
                    printf("GID: %d\n", gr->gr_gid);
                    printf("Miembros Secundarios: %s\n", *(gr->gr_mem));
                }
                else
                {
                    if ((gr = getgrnam(lgn)) == NULL) 
                    {
                        fprintf(stderr, "La opción --group sólo puede acompañar un nombre o GID válidos.\n");
                        MensajeAyuda();
                        exit(1);
                    }
                    printf("Grupo:\n")  ;                 
                    printf("Nombre: %s\n", gr->gr_name);
                    printf("Password: %s\n", gr->gr_passwd);
                    printf("GID: %d\n", gr->gr_gid);
                    printf("Miembros Secundarios: %s\n", *(gr->gr_mem));
                }
            break;

            case 'a':
                printf("\t\t\t'Opción -a, --active'\n");
                aflag = 1; 

                if ((lgn = getenv("USER")) == NULL || (pw = getpwnam(lgn)) == NULL) 
                {
                        fprintf(stderr, "La opción --active no puede acompañar ningún argumento.\n");
                        MensajeAyuda();
                        exit(1);
                }
                    printf("Usuario:\n");
                    printf("Nombre: %s\n", pw->pw_gecos); 
                    printf("Login: %s\n", pw->pw_name);
                    printf("Password: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Shell: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);   
            break;


            case 'm':
                printf("\n\t\t\tOpcion --maingroup\n");
                mflag = 1;

                if (aflag==1){
                    if ((lgn = getenv("USER")) == NULL || (pw = getpwnam(lgn)) == NULL) 
                    {
                        fprintf(stderr, "La opción --maingroup sólo puede acompañar a --user o --active.\n");
                        MensajeAyuda();
                        exit(1);
                    }
                    gr= getgrgid(pw->pw_gid);
                        printf("Grupo:\n")  ;                 
                        printf("Nombre: %s\n", gr->gr_name);
                        printf("Password: %s\n", gr->gr_passwd);
                        printf("GID: %d\n", gr->gr_gid);
                        printf("Miembros Secundarios: %s\n", *(gr->gr_mem));
                }
                else if( uvalue!=NULL){

                    if (isdigit(*lgn)){
                        uid = atoi(lgn); 

                        if ((pw = getpwuid(uid)) == NULL) 
                        {
                            fprintf(stderr, "Fallo al obtener información de usuario.\n");
                            exit(1);
                        }
                    }

                    else{

                        if ((pw = getpwnam(lgn)) == NULL) 
                        {
                        fprintf(stderr, "La opción --maingroup sólo puede acompañar a --user o --active.\n");
                        MensajeAyuda();
                        exit(1);
                        }
                    }  

                    gr= getgrgid(pw->pw_gid);
                        printf("Grupo:\n")  ;                 
                        printf("Nombre: %s\n", gr->gr_name);
                        printf("Password: %s\n", gr->gr_passwd);
                        printf("GID: %d\n", gr->gr_gid);
                        printf("Miembros Secundarios: %s\n", *(gr->gr_mem));
                }

                else{
                    printf("La opcion -m debe usarse con --active o --user\n");
                }
            break;

            case 's':
                printf("\t\t\t'Opción -s, --allgroups'\n");
                
	            group_file = fopen("/etc/group", "r");

                while((fgets(line, 50, group_file)) != NULL) 
                {
                    groupName = strtok(line, ":");
                    gr = getgrnam(groupName);
                        printf("Grupo:\n")  ;                 
                        printf("Nombre: %s\n", gr->gr_name);
                        printf("Password: %s\n", gr->gr_passwd);
                        printf("GID: %d\n", gr->gr_gid);
                        printf("Miembros Secundarios: %s\n", *(gr->gr_mem));
                    printf("\n");
                }
                fclose(group_file);

            break;


        case 'h':
            MensajeAyuda();
        break;

			default:
				abort ();
		}
	}
}

void MensajeAyuda()
{
    printf("Uso del programa: ejercicio1 [opciones]\n");
    printf("Opciones:\n");
    printf("-h, --help\t\t\tImprimir esta ayuda.\n");
    printf("-u, --user (<nombre>|<uid>)\tInformación sobre el usuario.\n");
    printf("-a, --active\t\t\tInformación sobre el usuario activo actual.\n");
    printf("-m, --maingroup\t\t\tAdemás de info de usuario, imprimir la info de su grupo principal\n");
    printf("-g, --group (<nombre>|<gid>)\tInformación sobre el grupo.\n");
    printf("-s, --allgroups\t\t\tMuestra info de todos los grupos del sistema.\n");
}