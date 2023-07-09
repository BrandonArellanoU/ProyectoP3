/*Proyyecto de Programacion 1 Progreso 3
Crear una aplicacion que permita el manejo de los datos generados por un centro de maquinas durante cada turno de trabajo en empresa de fabricacion.
Considere 3 turnos diarios y calcule el turno donde se desperdicio menos materia prima.
Hecho por Brandon Arellano y Josue Riera 
Universidad de las Americas - Software 
*/

//Se agrega librerias que se puede utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Definición de la estructura "Mueble"
struct Mueble {
    char nombre_mueble[50];
    int cantidad_materia_prima;
    int cantidad_residuo;
};

int main(int argc, char const *argv[])
{
 //Se declaran variables
    int opcionesusu;
    int numero_maquinas;
    char maquina_n[30];
    float n_materia_prima;
    float n_uso_prima;
    int eliminar_item;
    int var1;
    int cantidad;
    FILE *arch;
    char lin [100];
    int contador;
    time_t time_now = time(NULL);
    struct tm *time_d = localtime(&tiempo_actual);

 //menu 
do{
   switch(opcionesusu){
    case 1:
    case 2:
    case 3:
    case 4:
    default: 

    
   }

}while(opcionesusu !=0);
 
    return 0;

}

