#ifndef EXAMEN
#define EXAMEN

#define LENGTH 100
struct datos
{
   int codigo;
   char nombre[LENGTH];
   float pesoKg;  //ej. 56.8  
   float alturaM; //ej. 1.65     
};


void ejercicio1(int nEle, struct datos* Vector, int criterio);
void ordenaBurbuja(int n,struct datos *Vector,float (*funaux)(float,float));
float ascendente(float peso,float altura);
//INCLUYE AQUI LOS PROTOTIPOS DE TUS FUNCIONES

#endif
