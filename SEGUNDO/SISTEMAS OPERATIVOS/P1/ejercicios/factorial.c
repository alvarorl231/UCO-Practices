#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("./ejecutable numero\n");
        exit(EXIT_FAILURE);
    }

    int num=atoi(argv[1]);
    int aux=1;

    if(num < 0)
    {
        printf("Solo son válidos los números positivios.\n");
        exit(EXIT_FAILURE);
    }

    else if(num == 1 || num == 0)
    {
        printf("El factorial de %d es igual a 1\n.",num);
    }

    else
    {
        for(int i=1; i<=num; i++)
        {
            sleep(1);
            aux=aux*i;
        }
        printf("El factorial de %d es igual a %d\n",num,aux);
    } 
    exit(EXIT_SUCCESS);
}