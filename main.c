/*
Instituto Nacional Superior del Profesorado T�cnico - Universidad Tecnol�gica Nacional
Carrera: Inform�tica Aplicada
Asignatura: Programaci�n
Alumna: Carla Carolina Vasquez de Carvalho

Funciones - (uso de punteros 'pointers' en C) -
EJERCITACI�N (Level 1):
3. Crear una funci�n que calcule la temperatura media de un d�a a partir
de la temperatura m�xima y m�nima. Crear un programa principal, que
utilizando la funci�n anterior, vaya pidiendo la temperatura m�xima y
m�nima de cada d�a y vaya mostrando la media. El programa pedir� el
n�mero de d�as que se van a introducir.
*/
#include <stdio.h>
#include <stdlib.h>
# define p printf
# define s scanf

//Prototipos >>

void ingresarDatos (float*, float*, float*);
void calcularPromedioTemp (float**, float**, float**);
void exhibirDatos (float***);

//Funciona principal >>

int main(void)
{
    printf("\n\n\n ----  CALCULANDO TEMPERATURA M%cDIA ----\n\n\n", 144);

    int cantDias = 0;
    float tempMax = 0.0, tempMin = 0, tempMedia = 0.0;

    p("Por favor, ingrese la cantidad de d%cas: ", 161);
    s("%d", &cantDias);

    for(cantDias; cantDias > 0 ; cantDias--)
    {
        ingresarDatos(&tempMax, &tempMin, &tempMedia); // El ampersand enví ala dirección de memoria de la variable.
    }

    p("\n\nFIN DE EJECUCI%cN\n\n",224);
    return 0;
}

void ingresarDatos(float *tempMax, float *tempMin, float *tempMedia) // Estas son las variables punteros que reciben la dirección de memoria de la función main.
{
    p("\nIngrese la temperatura m%cxima: ",160);
    s("%f", tempMax);

    p("Ingrese la temperatura m%cnima: ", 161);
    s("%f", tempMin);

    calcularPromedioTemp(&tempMax, &tempMin, &tempMedia); // se envía nuevamente la dirección de memória de las variables a la función calcularPromedio.
}

void calcularPromedioTemp(float **tempMax, float **tempMin, float **tempMedia) // Estas son otras variables punteros que reciben las direcciones de memória. 
{
    **tempMedia = (**tempMax + (**tempMin)) / 2; //El doble asterico es para desreferenciarlas (acceder al contenido a partir de la direcciónde memória).
    exhibirDatos(&tempMedia);
}

void exhibirDatos (float ***tempMedia) // Esta variable es un puntero a otro puntero que apunta a otro puntero. 
{
    p("\n\n\tLa temperatura media es de: %.2f\n", ***tempMedia);//El triple asterico es para desreferenciarla.
    p("\n----------------------------------------------\n\n");
}
