//                                                              PRACTICA 1
//                                                        Procesos Padres e Hijos.

//INCLUDES BASICOS

#include <sys/types.h>      //Ambas para fork, getpid, etc... // man fork
#include <unistd.h>         

#include <sys/wait.h>       //Para wait()  TRUCO: man wait (WIFEXITED -> WEXISTATUS // WIFSIGNALED --> WETERMSIG)

#include <stdlib.h>         //Para exit()

#include <errno.h>          //CONTROL DE ERRORES. printf("errno value %d",errno);
#include <stdio.h>          //perror("fork error"); 
#include <string.h>         //Para perror


//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//fork()

pid_t pid, hijo_pid;        //Declaración.

pid=fork();                 //Crear hijos

int status;
hijo_pid=wait(&status);     //Recoger a los hijos. En el padre. || Control de errores del wait, (WIFEXITED -> WEXISTATUS // WIFSIGNALED --> WETERMSIG)

//Si queremos mas de un hijo con hacer un for y el fork dentro bastaría.

//CONTROL DE ERRORES, IF(PID=-1) ERROR // IF (PID =0) HIJO // ELSE PADRE        O IF, O SWITCH, IGUAL DE VALIDOS Y BIEN HECHOS.
    

//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//ejecutables, familia excev()
execlp(argv[1],"gnome-calculator",NULL); //Abrir calculadora de linux, nombre pasado por parametro

execvp(argv[2],argv+2);      //Abrir lo que haya en argv[2] (gedit) el vector argv+2, es decir abrir con gedit todo lo que haya despues de argv[2].

execl ("factorial", "factorial",argv[1], NULL); //Abrimos un ejecutable (factorial o si cambiasemos el nombre a.out) y le pasamos como argumento argv[1].


//-------------------------------------------------------------------------------------------------------------------------------------------------------//
//Señales
#include <signal.h>

//Ejemplo de alarma
void AlarmaRing(int sigo)      //Función que impondrá el funcionamiento de mi captación de señales
{
    printf("RING\n");
    return;
}

void timer(int nsecs)       //Función que simplemente llama a alarm con x segundos.
{
	alarm(nsecs);
	pause();
}

int main()
{
    if(signal(SIGALRM,AlarmaRing)==SIG_ERR)     //Señal con SIGALARM, es decir detecta/capta señales de alarma y funciona como AlarmRing.
    {           
        perror("Signal error");                                 //Control de errores.
        printf("Error en signal, errno value=%d\n",errno);
        exit(EXIT_FAILURE);
    }
}
// SIGUSR1 (captación de señal con funcionamiento a gusto del programador)
//Ejemplo de SIGUSR1
int main()
{
    .
    .
    .

    signal(SIGUSR1,tratarSennal); //Capta señales y se comporta como tratarSennal.
    .
    .
    .
    //En el padre:
    kill(pid,SIGUSR1); //pid --> (es decir, el hijo es el encargado de hacer esto).
}

void tratarSennal(int signo)
{
    if(signo == SIGUSR1)
    {
        printf("[%d] Hola que tal soy SIGUSR1\n",getpid());
    }
}