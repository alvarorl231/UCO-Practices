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
    // Entero que mide el tamaño de los mensajes.
	char caracteres[MAX_SIZE];
    // Nombre para la cola
    char serverQueueName[100];
    char clientQueueName[100];

	// Abrir la cola del servidor.
	// No es necesario crearla si se lanza primero el servidor, sino el programa no funciona.

    // Nombre para la cola. Al concatenar el login sera unica en un sistema compartido.
	sprintf(serverQueueName, "%s-%s", SERVER_QUEUE, getenv("USER"));
    printf ("[Cliente]: El nombre de la cola es: %s\n", serverQueueName);

	sprintf(clientQueueName, "%s-%s", CLIENT_QUEUE, getenv("USER"));
    printf ("[Cliente]: El nombre de la cola es: %s\n", clientQueueName);

    // Cola del servidor, en la que vamos a escribir para leer en servidor.
    colaServer = mq_open(serverQueueName, O_WRONLY);
    //colaServer = mq_open(SERVER_QUEUE, O_WRONLY);

    // Cola del cliente, en la que vamos a leer lo que desde servidor se mande.
    colaClient = mq_open(clientQueueName, O_RDONLY);
    //colaClient = mq_open(CLIENT_QUEUE, O_RDONLY);

	if(colaServer == (mqd_t)-1 )
	{
      perror("Error al abrir la cola del servidor");
      exit(-1);
	}
    printf ("[Cliente]: El descriptor de la cola es: %d\n", (int) colaServer);

	if(colaClient == (mqd_t)-1 )
	{
      perror("Error al abrir la cola del servidor");
      exit(-1);
	}
    printf ("[Cliente]: El descriptor de la cola es: %d\n", (int) colaClient);



	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	do
	{
		printf("> ");

		/* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
		It stops when either (n-1) characters are read, the newline character is read,
		or the end-of-file is reached, whichever comes first.
		Automáticamente fgets inserta el fin de cadena '\0'
		*/
		fgets(buffer, MAX_SIZE, stdin);

		// Enviar y comprobar si el mensaje se manda
		if(mq_send(colaServer, buffer, MAX_SIZE, 0) != 0)
		{
			perror("Error al enviar el mensaje");
			exit(-1);
		}

        // Número de bytes leidos
		ssize_t bytes_read;

		// Recibir el mensaje
		bytes_read = mq_receive(colaClient, caracteres, MAX_SIZE, NULL);
		// Comprar que la recepción es correcta (bytes leidos no son negativos)
		if(bytes_read < 0)
		{
			perror("Error al recibir el mensaje");
			exit(-1);
		}

		printf("Número de caracteres recibidos: %s\n", caracteres);


	// Iterar hasta escribir el código de salida
	}while (strncmp(buffer, MSG_STOP, strlen(MSG_STOP)));

	/*Cerrar la cola del servidor
	if(mq_close(colaServer) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}
	*/

	return 0;
}