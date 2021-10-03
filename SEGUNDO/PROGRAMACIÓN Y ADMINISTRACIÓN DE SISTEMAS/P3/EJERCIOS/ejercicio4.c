#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#include <mqueue.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h> 

#define QUEUE  "/queue"
#define MAX_SIZE     1024
#define MSG_STOP     "exit"

int main(int argc, char **argv)
{
	// Para realizar el fork
	pid_t pid;
	int flag, status;
    
	// Cola
	mqd_t cola;
	// Atributos de la cola
	struct mq_attr attr;
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
	// Entero que mide el tamaño de los mensajes.
    int caract = 0;
    char caracteres[MAX_SIZE];
	// flag que indica cuando hay que parar. Se escribe palabra exit
	int must_stop = 0;
	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje
    // Nombre para la cola
    char QueueName[100];
    // Nombre para la cola. Al concatenar el login sera unica en un sistema compartido.
    sprintf(QueueName, "%s-%s", QUEUE, getenv("USER"));


	pid = fork();

	switch (pid)
	{
		case -1:
			printf ("No se ha podido crear el proceso hijo...\n");
			exit(EXIT_FAILURE);
        break;

		case 0:
			printf ("[HIJO]: Mi PID es %d y mi PPID es %d\n", getpid(), getppid());

	        /* Apertura de la cola
			   O_CREAT: si no existe, se crea
			   O_RDWR: lectura/escritura
			   O_RDONLY: solo lectura
			   O_WRONLY: solo escritura
			   0644: permisos rw-r--r--
			         permisos de lectura y escritura para el propietario, y de sólo lectura para el grupo y para otros
			   attr: estructura con atributos para la cola  */

            // Crear la cola de mensajes del servidor.
            cola = mq_open(QueueName, O_RDWR);

            if(cola == (mqd_t)-1 )
            {
            perror("[HIJO]: Error al abrir la cola.");
            exit(-1);
            }
            printf ("[HIJO]: El descriptor de la cola es: %d\n", (int) cola);


            do
            {
                    
                printf("[HIJO]: > ");

                /* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
                It stops when either (n-1) characters are read, the newline character is read,
                or the end-of-file is reached, whichever comes first.
                Automáticamente fgets inserta el fin de cadena '\0'*/
                
                fgets(buffer, MAX_SIZE, stdin);


                // Comprobar el fin del bucle
                if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
                {
                    if(mq_send(cola, buffer, MAX_SIZE, 0) != 0)
                    {
                        perror("[HIJO]: Error al enviar el mensaje.");
                        exit(-1);
                    }            
                    must_stop = 1;
                }	

                else
                {
                    // Enviar y comprobar si el mensaje se manda
                    if(mq_send(cola, buffer, MAX_SIZE, 0) != 0)
                    {
                        perror("[HIJO]: Error al enviar el mensaje.");
                        exit(-1);
                    }

                    // Número de bytes leidos
                    ssize_t bytes_read;

                    // Recibir el mensaje
                    bytes_read = mq_receive(cola, caracteres, MAX_SIZE, NULL);
                    // Comprar que la recepción es correcta (bytes leidos no son negativos)
                    if(bytes_read < 0)
                    {
                        perror("[HIJO]: Error al recibir el mensaje.");
                        exit(-1);
                    }

                    printf("[HIJO]: Número de caracteres recibidos: %s\n", caracteres);
                }

            // Iterar hasta escribir el código de salida
            }while (!must_stop);

            if(mq_close(cola) == -1)
			{
				perror("[HIJO]: Error cerrando la cola");
				exit(-1);
			}

            printf("[HIJO]: Cola cerrada.\n");
				exit(0);

		break;


        default:
			printf ("[PADRE]: Mi PID es %d y el PID de mi hijo es %d \n", getpid(), pid);
			

            printf ("[PADRE]: El nombre de la cola  es: %s\n", QueueName);
            // Crear la cola de mensajes del servidor.
            cola = mq_open(QueueName, O_CREAT | O_RDWR, 0644, &attr);
            //colaServer = mq_open(QUEUE, O_CREAT | O_RDWR, 0644, &attr);

            if(cola == (mqd_t)-1 )
            {
                perror("[PADRE]:Error al abrir la cola.");
                exit(-1);
            }
            printf ("[PADRE]: El descriptor de la cola es: %d\n", (int) cola);


            do
            {
                // Número de bytes leidos
                ssize_t bytes_read;

                // Recibir el mensaje
                bytes_read = mq_receive(cola, buffer, MAX_SIZE, NULL);
                // Comprar que la recepción es correcta (bytes leidos no son negativos)
                if(bytes_read < 0)
                {
                    perror("Error al recibir el mensaje");
                    exit(-1);
                }
                // Cerrar la cadena
                //buffer[bytes_read] = '\0';

                // Contar número de caracteres en un mensaje.
                caract = strlen(buffer); 
                caract = caract -1;

                // Paso de INT a CHAR []
                char num_caract[MAX_SIZE];
                sprintf(num_caract, "%d", caract);

                // Comprobar el fin del bucle
                if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
                {
                    must_stop = 1;
                }
                else
                {
                    printf("[PADRE]: Recibido el mensaje: %s\n", buffer);

                    // Enviar mensaje con la longitud
                    if(mq_send(cola, num_caract, MAX_SIZE, 0) != 0)
                    {
                        perror("[PADRE]:Error al enviar el mensaje");
                        exit(-1);
                    }    
                        
                }

            } while (!must_stop); 	// Iterar hasta que llegue el código de salida, es decir, la palabra exit

            // Cerrar la cola del servidor
            if(mq_close(cola) == (mqd_t)-1)
            {
                perror("[PADRE]:Error al cerrar la cola del servidor.");
                exit(-1);
            }

            // Eliminar la cola del servidor
            if(mq_unlink(QueueName) == (mqd_t)-1)
            {
                perror("[PADRE]:Error al eliminar la cola del servidor.");
                exit(-1);
            }  


			/*Espera del padre a los hijos*/
	        while ( (flag=wait(&status)) > 0 ) 
	        {
		        if (WIFEXITED(status)) {
			        printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)flag, WEXITSTATUS(status));
		        } 
		        else if (WIFSIGNALED(status)) {  //Para seniales como las de finalizar o matar
			        printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
		        } 		
	        }
	        if (flag==(pid_t)-1 && errno==ECHILD)
	        {
		        printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
	        }
	        else
	        {
		        printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
		        exit(EXIT_FAILURE);
	        }			 
	    
        }

	exit(EXIT_SUCCESS);
}
