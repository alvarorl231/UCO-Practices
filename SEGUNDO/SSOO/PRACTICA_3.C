//                                                              PRACTICA 3
//                                                   Semaforos binarios y generales.

//INCLUDES BASICOS

#include <unistd.h>         //Básica
#include <pthread.h>        //Para las funciones de pthread y semaforos.

#include <stdlib.h>         //Para exit()

#include <errno.h>          //CONTROL DE ERRORES. printf("errno value %d",errno);
#include <stdio.h>          //perror("fork error"); 
#include <string.h>         //Para perror

//__________________________________________________________________________________________________________________________________________________________*/

//SEMAFOROS BINARIOS:

    //Declaración:
    pthread_mutex_t semaforo;                   //IMPORTANTE: HAN DE SER DECLARADOS EN LA ZONA GLOBAL!!!!
    //Declaración + inicaliación:
    pthread_mutex_t semaforo = PTHREAD_MUTEX_INITIALIZER; 

    //Incizializar el semaforo:
    int main()
    {
        .
        .
        pthread_mutex_init(&semaforo,NULL); //Se inizializa en el MAIN, con & y a NULL.
        .
        .
    }

    //Bloqueo y desbloqueo de semafóro para acceder a la ZONA CRÍTICA:    (elementos que queremos modificar de la ZONA GLOBAL)
    void * funcion((void * arg)
    {
        .
        .
        .
        if (pthread_mutex_lock(&semaforo)!= 0)                      //BLOQUEO DE SEMAFORO.
        {
            printf("Mutex_lock error..., errno value %d\n",errno);  //CONTROL DE ERRORES.
            perror("mutex lock error")
            pthread_exit(NULL);
        }
        // MODIFICANDO VARIABLES DE ZONA GLOBAL.....

        if (pthread_mutex_unlock(&semaforo)!= 0)                    /*DESBLOQUEO DE SEMAFORO. YA HEMOS MODIFICADO LAS VARIABLES DE
        .                                                            LA ZONA CRITICA Y DAMOS PERMISO A OTRAS HEBRAS QUE ENTREN.*/
        {
            printf("Mutex_lock error..., errno value %d\n",errno);  //CONTROL DE ERRORES.
            perror("mutex lock error")
            pthread_exit(NULL);
        }   
    }

//__________________________________________________________________________________________________________________________________________________________*/

//SEMAFOROS GENERALES:
#include <semaphore.h>
/*
El concepto es simple, es un semáforo que funciona con contadores.
Este contador será inicializado por el programador con el valor que desee, pero normalmente, 0 y 1.
Este semáforo trabaja con 2 opciones, wait y post. Es decir, wait (cont--) y post (cont++).
Wait funciona en el rango de cont<0. Es decir si mi contador vale -1, lo que haya debajo se pone en cola, es decir espera a que alguien lo ponga a 0.
Post funciona de forma que aumenta el contador. 
*/

    //Declaración:
    sem_t semaforo; //EN LA ZONA DE VARIABLES GLOBALES. 

    //Inicialización:
    sem_init(&semaforo, 0, 1); //Inicializamos semáforo, 0 significa que actuará en un mismo proceso, y 1 el valor que decementa e incrementa.



    //"Bloqueo:"
    sem_wait(&semaforo);

    //Esta función decrementa el contador asignado al incializar la variable y funciona tal que así:
    //Antes de wait y de post, cont = 1.
    sem_wait(&semaforo); cont = 0
    sem_post(&semaforo); cont = 1       //(esto es el desboqueo, más abajo explicado.)


    //En el caso de que:
    sem_init(&semaforo, 0, 0);

    sem_wait(&semaforo); cont = -1 
    /*    

    En este caso LO QUE HAYA DEBAJO DE ESTE SEMÁFORO NÓ SE EJECUTARÁ.  Ya que el semaforo solo actúa para cont>0. 

    Entonces lo que exista debajo de este semáforo sólo se ejecutará cuando este valga 0. Es decir, que desde otro lugar de tu código
    se le haga un sem_post(&semaforo) y entonces valga 0.

    Este semaforo inicializado con valo 0, es perfecto para la situación que explico en el ejemplo más adelante.
    
    */
    sem_post(&semaforo); cont = 0

    

    if (sem_wait(&semaforo) != 0)     //Decrementa el contador del semaforo.
    {
        printf("sem_wait error...\n");
        printf("errno value= %d definido como %s\n", errno, strerror(errno));   //CONTROL DE ERRORES
        pthread_exit(NULL);
    }


    //Desbloqueo:
    if (sem_post(&semaforo) != 0)   //Amenta el contador del semaforo.
    {
        printf("sem_post error...\n");
        printf("errno value= %d definido como %s\n", errno, strerror(errno));
        pthread_exit(NULL);
    }    


    //EJEMPLO: (DEMO 4) Ejercicio que suma SOLO los numeros pares.

sem_t s1; //Semáforo s1 para acceder a SC cuando el numero es impar. 
sem_t s2; //Semáforo s2 para acceder a SC cuando el numero es par. 
int num=0, suma=0; //Recurso compartido o sección crítica

void *p1(void * a)
{
    int i;
    for (i=1; i<=20; i++)
    {
        sem_wait (&s1); //1º ENTRADA: (si=1) cont =0, i=1. 2º ENTRADA: (s1 =1) cont =0 i=2(par).  ESTA LÍNEA SIEMPRE SE EJECUTARÁ.
        if ( (i%2)!= 0) 
        {
            num=i; //Seccion critica
            printf ("HILO1: Número impar %d. Desbloqueando a HILO 2\n", i); 
				sem_post (&s2); //1º ENTRADA: (s2=-1  por que en p2 hemos hecho wait, TODO SE HACE A LA VEZ) cont=0 (desbloqueamos el semaforo de p2)
        }
        else 
		  {
            sem_post (&s1); //1ºENTRADA (s1 =0 ) cont =1. (Ahora no entra a p2 por que al wait del semaforo 2 no le hemos hecho un post, entonces está en -1 y volvemos al bucle.)
		  }
    }
    pthread_exit(NULL); 
}

void *p2(void * a)
{
    int i;
    //Entre 1 y 20 hay 10 números impares, por tanto un bucle de 10 iteraciones
    for (i=0; i<10; i++) 
	 {
        sem_wait (&s2); //1º ENTRADA (s2=0) cont=-1. 1ºENTRADA desde P2: DESDE P1 ME HAN PUESTO A 0, entonces entro:
        printf ("HILO2: Suma actual = %d + %d = %d\n", suma, num, (suma+num));
        suma = suma+num; //Seccion critica
        sem_post (&s1); //1º ENTRADA (s1=0) cont=1. y entra de nuevo a p1
    }
    pthread_exit(NULL); 
}


int main() 
{
    int error1, error2;
    pthread_t h1, h2;
 
    sem_init(&s1, 0, 1); //Semáforo de impares inicializado a 1 
    sem_init(&s2, 0, 0); //Semáforo de pares inicializado a 0. Por si el primero que se ejecuta es p2,
                         //ya que debe esperar a que p1 le diga si el numero es par o impar.
    
    pthread_create(&h1, NULL, p1, NULL); 
    pthread_create(&h2, NULL, p2, NULL); 

    pthread_join (h1, NULL);
    pthread_join (h2, NULL);
    
    printf ("Main() - La suma es %d\n", suma);
    
	exit(EXIT_SUCCESS);
}
