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

// Prototipo de la función para escribir los datos de los muebles en un archivo
void EscribirMuebles(struct Mueble* muebles, FILE* archivo);

int main(int argc, char const *argv[])
{
int main() {
    FILE* archivo = fopen("Datos.csv", "w+");
    if (archivo == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int flag = 1;
int mueble, mayorIn = 0, mayor = 0, cant, totalM = 0, totalR = 0;

    struct Mueble muebles[3];

strcpy(muebles[0].nombre_mueble, "Mueble1");
muebles[0].cantidad_materia_prima = 10;
muebles[0].cantidad_residuo = 2;
strcpy(muebles[1].nombre_mueble, "Mueble2");
muebles[1].cantidad_materia_prima = 15;
muebles[1].cantidad_residuo = 5;
strcpy(muebles[2].nombre_mueble, "Mueble3");
muebles[2].cantidad_materia_prima = 20;
muebles[2].cantidad_residuo = 7;
    
    EscribirMuebles(muebles, archivo);

    time_t tiempo = time(NULL);
struct tm* tiempo_descompuesto = localtime(&tiempo);



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

