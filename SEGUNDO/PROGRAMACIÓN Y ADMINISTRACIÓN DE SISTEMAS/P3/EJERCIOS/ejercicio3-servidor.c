/*
Servidor que lee de una cola abierta para lectura una cadena de caracteres y la
imprime por pantalla.

Lo hace mientras que el valor de esa cadena sea distinto a la palabra exit.
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>

#define SERVER_QUEUE  "/server_queue"
#define CLIENT_QUEUE  "/client_queue"
#define MAX_SIZE     1024
#define MSG_STOP     "exit"


//Prototipo de funcionn
void funcionLog(char *);
// Apuntador al fichero de log.  No se usa en este ejemplo, pero le servira en ejercicio resumen
FILE *fLog = NULL;

int main(int argc, char **argv)
{
	// Cola del servidor
	mqd_t colaServer;
	mqd_t colaClient;
	// Atributos de la cola
	struct mq_attr attr;
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
	// Cadena auxiliar para funcionLog()
	char msgserver[MAX_SIZE];
	// Entero que mide el tamaño de los mensajes.
    int caract = 0;
	// flag que indica cuando hay que parar. Se escribe palabra exit
	int must_stop = 0;
	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje
    // Nombre para la cola
    char serverQueueName[100];
    char clientQueueName[100];

    // Nombre para la cola. Al concatenar el login sera unica en un sistema compartido.
	sprintf(serverQueueName, "%s-%s", SERVER_QUEUE, getenv("USER"));
    printf ("[Servidor]: El nombre de la cola servidor es: %s\n", serverQueueName);

		// Para funcionLog()
		sprintf(msgserver,"[Servidor]: El nombre de la cola servidor es: %s\n", serverQueueName);
		funcionLog(msgserver);


	sprintf(clientQueueName, "%s-%s", CLIENT_QUEUE, getenv("USER"));
    printf ("[Servidor]: El nombre de la cola cliente es: %s\n", clientQueueName);

		// Para funcionLog()
		sprintf(msgserver,"[Servidor]: El nombre de la cola cliente es: %s\n", clientQueueName);
		funcionLog(msgserver);

	// Crear la cola de mensajes del servidor. La cola CLIENT_QUEUE le servira en ejercicio resumen
	colaServer = mq_open(serverQueueName, O_CREAT | O_RDONLY, 0644, &attr);
    //colaServer = mq_open(SERVER_QUEUE, O_CREAT | O_RDONLY, 0644, &attr);

	colaClient = mq_open(clientQueueName, O_CREAT | O_WRONLY, 0644, &attr);
    //colaClient = mq_open(SERVER_QUEUE, O_CREAT | O_WRONLY, 0644, &attr);


	if(colaServer == (mqd_t)-1 )
	{
   	perror("Error al abrir la cola1 del servidor");
      exit(-1);
	}
    printf ("[Servidor]: El descriptor de la cola servidor es: %d\n", (int) colaServer);

		// Para funcionLog()
		sprintf(msgserver,"[Servidor]: El descriptor de la cola servidor es: %d\n", (int) colaServer);
		funcionLog(msgserver);

    if(colaClient == (mqd_t)-1 )
	{
   	perror("Error al abrir la cola2 del servidor");
      exit(-1);
	}
    printf ("[Servidor]: El descriptor de la cola cliente es: %d\n", (int) colaClient);
		
		// Para funcionLog()
		sprintf(msgserver,"[Servidor]: El descriptor de la cola cliente es: %d\n", (int) colaClient);
		funcionLog(msgserver);

	do
	{
		// Número de bytes leidos
		ssize_t bytes_read;

		// Recibir el mensaje
		bytes_read = mq_receive(colaServer, buffer, MAX_SIZE, NULL);
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
			printf("Recibido el mensaje: %s\n", buffer);

			// Para funcionLog()
			sprintf(msgserver,"Recibido el mensaje: %s\n", buffer);
			funcionLog(msgserver);


			// Enviar mensaje con la longitud
			if(mq_send(colaClient, num_caract, MAX_SIZE, 0) != 0)
			{
				perror("Error al enviar el mensaje");

					// Para funcionLog()
					sprintf(msgserver,"Error al enviar el mensaje");
					funcionLog(msgserver);

				exit(-1);
			}    
			    
		}

	} while (!must_stop); 	// Iterar hasta que llegue el código de salida, es decir, la palabra exit

	// Cerrar la cola del servidor
	if(mq_close(colaServer) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del servidor.");

			// Para funcionLog()
			sprintf(msgserver,"Error al cerrar la cola del servidor.");
			funcionLog(msgserver);
		
		exit(-1);
	}

	//Cerrar la cola del cliente
	if(mq_close(colaClient) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del cliente.");

			// Para funcionLog()
			sprintf(msgserver,"Error al cerrar la cola del cliente.");
			funcionLog(msgserver);
		
		exit(-1);
	}


	// Eliminar la cola del servidor
	if(mq_unlink(serverQueueName) == (mqd_t)-1)
	{
		perror("Error al eliminar la cola del servidor.");

			// Para funcionLog()
			sprintf(msgserver,"Error al eliminar la cola del servidor.");
			funcionLog(msgserver);
		
		exit(-1);
	}

	//Eliminar la cola del cliente
	if(mq_unlink(clientQueueName) == (mqd_t)-1)
	{
		perror("Error al eliminar la cola del cliente.");

			// Para funcionLog()
			sprintf(msgserver,"Error al eliminar la cola del cliente.");
			funcionLog(msgserver);

		exit(-1);
	}

	return 0;
}

// Función auxiliar, escritura de un log.
void funcionLog(char *mensaje)
{
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;

	// Abrir el fichero
	sprintf(nombreFichero,"log-servidor.txt");
	if(fLog==NULL)
	{
		fLog = fopen(nombreFichero,"at");
		if(fLog==NULL)
		{
			perror("Error abriendo el fichero de log");
			exit(1);
		}
	}

	// Obtener la hora actual
	t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(mensajeAEscribir, 1000, "[%Y-%m-%d, %H:%M:%S]", p);

	// Vamos a incluir la hora y el mensaje que nos pasan
	sprintf(mensajeAEscribir, "%s ==> %s\n", mensajeAEscribir, mensaje);

	// Escribir finalmente en el fichero
	resultado = fputs(mensajeAEscribir,fLog);
	if (resultado < 0)
		perror("Error escribiendo en el fichero de log");

	fclose(fLog);
	fLog=NULL;
}
