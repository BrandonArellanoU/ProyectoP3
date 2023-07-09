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

int main(){
    // Abre el archivo "Datos.csv" en modo escritura y lectura
    FILE* archivo = fopen("Datos.csv", "w+");  
    if (archivo == NULL) {
        // Muestra un mensaje de error si no se puede abrir el archivo
        printf("Error al abrir el archivo.\n"); 
        return 1;
    }

    int flag = 1;
    // Variables utilizadas para diferentes seguimientos
    int mueble, mayorIn = 0, mayor = 0, cant, totalM = 0, totalR = 0;  
    // Arreglo de estructuras "Mueble" para almacenar los datos de los muebles
    struct Mueble muebles[3];  

    // Inicialización de los datos de los muebles
    strcpy(muebles[0].nombre_mueble, "Mueble1");
    muebles[0].cantidad_materia_prima = 10;
    muebles[0].cantidad_residuo = 2;
    strcpy(muebles[1].nombre_mueble, "Mueble2");
    muebles[1].cantidad_materia_prima = 15;
    muebles[1].cantidad_residuo = 5;
    strcpy(muebles[2].nombre_mueble, "Mueble3");
    muebles[2].cantidad_materia_prima = 20;
    muebles[2].cantidad_residuo = 7;

    // Llama a la función para escribir los datos de los muebles en el archivo
    EscribirMuebles(muebles, archivo);  
    // Obtiene la hora actual
    time_t tiempo = time(NULL);  
    // Descompone la hora en una estructura de tiempo
    struct tm* tiempo_descompuesto = localtime(&tiempo);  


 //menu 
do{
        int opcion;
        printf("Ingrese una opcion:\n");
        printf("1. Ver muebles\n");
        printf("2. Modificar datos muebles\n");
        printf("3. Ingresar datos de turnos\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
       switch(opcion){
        case 1:
        case 2:
        case 3:
        case 4:
        default: 

    
   }

}while(opcionesusu !=0);
    // Cierra el archivo
    fclose(archivo); 
return 0;
}

// Función para escribir los datos de los muebles en un archivo
void EscribirMuebles(struct Mueble *muebles, FILE *archivo)
{
    // Cierra el archivo
    fclose(archivo);    
    // Vuelve a abrir el archivo en modo escritura y lectura
    fopen("Datos.csv", "w+"); 
    // Establece la posición del puntero de archivo al principio del archivo
    fseek(archivo, 0, SEEK_SET); 

    // Escribe los datos de los muebles en el archivo, separados por punto y coma
    for (int i = 0; i < 3; i++)
    {
        fprintf(archivo, "%s;%d;%d\n", muebles[i].nombre_mueble, muebles[i].cantidad_materia_prima, muebles[i].cantidad_residuo);
    }
    // Limpia el búfer de salida para asegurar que los datos se escriban en el archivo
    fflush(archivo); 
}

