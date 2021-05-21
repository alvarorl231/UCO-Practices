#include <stdio.h>
#include <stdlib.h> //exit, rand, srand
#include <unistd.h> //pipe, close, fork, usleep, read, write, getpid, getppid
#include <sys/wait.h> //wait
#include <errno.h> //Control de errores
#include <string.h> //strerror
#include <time.h> //Para la semilla del generador de aleatorios

int main()
{
	// Para realizar el fork
	pid_t pid;
	int flag, status;
	// Para controlar los valores devueltos por las funciones (control de errores)
	float resultado;
	// Lo que vamos a leer y escribir de la tubería
	float numeroAleatorio;
    // Lo que vamos a usar para sumar los números
    float suma=0.0;
	// Descriptores de los dos extremos de la tubería
	int fileDes[2];
	// Iterador
	int i=0;

	// Creamos la tubería
	resultado = pipe(fileDes);
	if(resultado==-1)
	{
		printf("\nERROR al crear la tubería.\n");
		exit(1);
	}
	
	pid = fork();

	switch (pid)
	{
		case -1:
			printf ("No se ha podido crear el proceso hijo...\n");
			exit(EXIT_FAILURE);
        break;

		case 0:
			printf ("[HIJO]: Mi PID es %d y mi PPID es %d\n", getpid(), getppid());
			
			close(fileDes[1]);
	
			for(i=0; i<3; i++)
			{
                if(i==2)
                {
				    resultado = read( fileDes[0], &suma, sizeof(float));
                    printf("[HIJO]: La suma de ambos números es %f\n",suma);

                }
                else
                {
                    //Recibimos un mensaje a través de la cola
                    resultado = read( fileDes[0], &numeroAleatorio, sizeof(float));
                    
                    // Imprimimos el campo que viene en la tubería
                    printf("[HIJO]: Leo el número aleatorio %f de la tubería.\n", numeroAleatorio);
                }

                if(resultado != sizeof(float))
                {
                    printf("\n[HIJO]: ERROR al leer de la tubería...\n");
                    exit(EXIT_FAILURE);
                }

            }		

			// Cerrar el extremo que he usado
			printf("[HIJO]: Tubería cerrada ...\n");
			close(fileDes[0]);
		break;

        default:
			printf ("[PADRE]: Mi PID es %d y el PID de mi hijo es %d \n", getpid(), pid);
			
			close(fileDes[0]);
				
			srand48(time(NULL));

            for (int i=0; i<3; i++){
                if(i==2) //Para enviar el resultado por la tubería
                {
				    resultado = write( fileDes[1], &suma, sizeof(float));
                }
                else
                {
                    numeroAleatorio = drand48()* (99.0); //Número aleatorio entre 0 y 4999
				
				    printf("[PADRE]: Escribo el número aleatorio %f en la tubería...\n", numeroAleatorio);
                    suma=suma+numeroAleatorio;

				    // Mandamos el mensaje
				    resultado = write( fileDes[1], &numeroAleatorio, sizeof(float));
                }

				if(resultado != sizeof(float))
				{
					printf("\n[PADRE]: ERROR al escribir en la tubería...\n");
					exit(EXIT_FAILURE);
				}

			}
			
			// Cerrar el extremo que he usado
			close(fileDes[1]);
			printf("[PADRE]: Tubería cerrada...\n");
			
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