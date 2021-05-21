/*
Cliente que envia por una cola abierta para escritura una cadena de caracteres
recogida por teclado, mientras que el valor de esa cadena sea distinto a la palabra exit
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


//Prototipo de funcion
void funcionLog(char *);
// Apuntador al fichero de log.
FILE *fLog = NULL;

int main(int argc, char **argv)
{
	// Cola del servidor
	mqd_t colaServer;
	mqd_t colaClient;
	// Atributos de la cola
	struct mq_attr attr;
	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
    // Cadena que mide el tamaño de los mensajes.
	char caracteres[MAX_SIZE];
	// flag que indica cuando hay que parar. Se escribe palabra exit
	int must_stop = 0;
	// Cadena auxiliar para funcionLog()
	char msgclient[MAX_SIZE];
    // Nombre para la cola
    char serverQueueName[100];
    char clientQueueName[100];

	// Abrir la cola del servidor.
	// No es necesario crearla si se lanza primero el servidor, sino el programa no funciona.

    // Nombre para la cola. Al concatenar el login sera unica en un sistema compartido.
	sprintf(serverQueueName, "%s-%s", SERVER_QUEUE, getenv("USER"));
    printf ("[Cliente]: El nombre de la cola servidor es: %s\n", serverQueueName);

		// Para funcionLog()
		sprintf(msgclient,"[Cliente]: El nombre de la cola servidor es: %s\n", serverQueueName);
		funcionLog(msgclient);

	sprintf(clientQueueName, "%s-%s", CLIENT_QUEUE, getenv("USER"));
    printf ("[Cliente]: El nombre de la cola cliente es: %s\n", clientQueueName);

		// Para funcionLog()
		sprintf(msgclient,"[Cliente]: El nombre de la cola cliente es: %s\n", clientQueueName);
		funcionLog(msgclient);

    // Cola del servidor, en la que vamos a escribir para leer en servidor.
    colaServer = mq_open(serverQueueName, O_WRONLY);
    //colaServer = mq_open(SERVER_QUEUE, O_WRONLY);

    // Cola del cliente, en la que vamos a leer lo que desde servidor se mande.
    colaClient = mq_open(clientQueueName, O_RDONLY);
    //colaClient = mq_open(CLIENT_QUEUE, O_RDONLY);

	if(colaServer == (mqd_t)-1 )
	{
      perror("Error al abrir la cola del servidor.");

		// Para funcionLog()
		sprintf(msgclient,"Error al abrir la cola del servidor.");
		funcionLog(msgclient);
	  
      exit(-1);
	}
    printf ("[Cliente]: El descriptor de la cola servidor es: %d\n", (int) colaServer);

		// Para funcionLog()
		sprintf(msgclient,"[Cliente]: El descriptor de la cola servidor es: %d\n", (int) colaServer);
		funcionLog(msgclient);

	if(colaClient == (mqd_t)-1 )
	{
      perror("Error al abrir la cola del cliente.");

		// Para funcionLog()
		sprintf(msgclient,"Error al abrir la cola del cliente.");
		funcionLog(msgclient);

      exit(-1);
	}
    printf ("[Cliente]: El descriptor de la cola cliente es: %d\n", (int) colaClient);

		// Para funcionLog()
		sprintf(msgclient,"[Cliente]: El descriptor de la cola cliente es: %d\n", (int) colaClient);
		funcionLog(msgclient);


	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);

		// Para funcionLog()
		sprintf(msgclient,"Mandando mensajes al servidor (escribir \"%s\" para parar):", MSG_STOP);
		funcionLog(msgclient);

	do
	{
			
		printf("> ");

		/* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
		It stops when either (n-1) characters are read, the newline character is read,
		or the end-of-file is reached, whichever comes first.
		Automáticamente fgets inserta el fin de cadena '\0'
		*/
		fgets(buffer, MAX_SIZE, stdin);


		// Comprobar el fin del bucle
		if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
		{
			if(mq_send(colaServer, buffer, MAX_SIZE, 0) != 0)
			{
				perror("Error al enviar el mensaje.");

					// Para funcionLog()
					sprintf(msgclient,"Error al enviar el mensaje.");
					funcionLog(msgclient);
			
				exit(-1);
			}            
			must_stop = 1;
        }		
		else
		{
			// Enviar y comprobar si el mensaje se manda
			if(mq_send(colaServer, buffer, MAX_SIZE, 0) != 0)
			{
				perror("Error al enviar el mensaje.");

					// Para funcionLog()
					sprintf(msgclient,"Error al enviar el mensaje.");
					funcionLog(msgclient);
				
				exit(-1);
			}

				// Para funcionLog()
				sprintf(msgclient,"> %s", buffer);
				funcionLog(msgclient);


			// Número de bytes leidos
			ssize_t bytes_read;

			// Recibir el mensaje
			bytes_read = mq_receive(colaClient, caracteres, MAX_SIZE, NULL);
			// Comprar que la recepción es correcta (bytes leidos no son negativos)
			if(bytes_read < 0)
			{
				perror("Error al recibir el mensaje.");

					// Para funcionLog()
					sprintf(msgclient,"Error al recibir el mensaje.");
					funcionLog(msgclient);
				
				exit(-1);
			}

			printf("Número de caracteres recibidos: %s\n", caracteres);

				// Para funcionLog()
				sprintf(msgclient,"Número de caracteres recibidos: %s", caracteres);
				funcionLog(msgclient);
		}
	// Iterar hasta escribir el código de salida
	}while (!must_stop);

	
	//Cerrar la cola del cliente
	if(mq_close(colaClient) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del cliente.");

			// Para funcionLog()
			sprintf(msgclient,"Error al cerrar la cola del cliente.");
			funcionLog(msgclient);
		
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
	sprintf(nombreFichero,"log-cliente.txt");
	if(fLog==NULL)
	{
		fLog = fopen(nombreFichero,"at");
		if(fLog==NULL)
		{
			perror("Error abriendo el fichero de log");
			funcionLog("Error al abrir la cola del cliente.");
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