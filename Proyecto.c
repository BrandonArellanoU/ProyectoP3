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

int main() {
    FILE* archivo = fopen("Datos.csv", "w+");  // Apertura del archivo "Datos.csv" en modo escritura y lectura

    if (archivo == NULL) {
        printf("Error opening the file.\n");  // Muestra un mensaje de error si no se puede abrir el archivo
        return 1;
    }

    int flag = 1;
    int mueble, mayorIn = 0, mayor = 0, cant, totalM = 0, totalR = 0;  // Variables utilizadas para diferentes seguimientos

    struct Mueble muebles[3];  // Arreglo de estructuras "Mueble" para almacenar los datos de los muebles

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

    EscribirMuebles(muebles, archivo);  // Llamada a la función para escribir los datos de los muebles en el archivo

    time_t tiempo = time(NULL);  // Obtiene la hora actual
    struct tm* tiempo_descompuesto = localtime(&tiempo);  // Descompone la hora en una estructura de tiempo

    do {
        int opcion;
        printf("Ingrese una opcion:\n");
        printf("1. Ver muebles\n");
        printf("2. Modificar datos muebles\n");
        printf("3. Ingresar datos de turnos\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);  // Lee la opción ingresada por el usuario

        switch (opcion) {
            case 1:
                system("cls");
                // Muestra en pantalla la información de los muebles almacenados en el arreglo "muebles"
                for (int i = 0; i < 3; i++) {
                    printf("Mueble %d: %s ocupa %d de materia prima y deja %d de residuo\n", i + 1, muebles[i].nombre_mueble, muebles[i].cantidad_materia_prima, muebles[i].cantidad_residuo);
                }
                printf("\n");
                break;

            case 2:
                system("cls");
                printf("Ingrese el numero del mueble a modificar (0 - 2)\n");
                scanf("%d", &mueble);
                printf("Ingrese el nuevo nombre del mueble: \n");
                scanf("%s", muebles[mueble].nombre_mueble);
                printf("Ingrese la cantidad de materia prima que gasta: \n");
                scanf("%d", &muebles[mueble].cantidad_materia_prima);
                printf("Ingrese la cantidad de residuo que genera: \n");
                scanf("%d", &muebles[mueble].cantidad_residuo);
                EscribirMuebles(muebles, archivo);  // Actualiza los datos de los muebles en el archivo
                system("cls");
                break;

            case 3:
                totalM = 0;
                totalR = 0;
                for (int i = 0; i < 3; i++) {
                    totalM = 0;
                    totalR = 0;
                    printf("Turno %d:\n", i + 1);
                    for (int j = 0; j < 3; j++) {
                        printf("Ingrese la cantidad de muebles '%s' que se hicieron: ", muebles[j].nombre_mueble);
                        scanf("%d", &cant);
                        totalM += cant * muebles[j].cantidad_materia_prima;
                        totalR += cant * muebles[j].cantidad_residuo;
                        if (mayor < totalR)
                        {
                            mayor = totalR;
                            mayorIn = i;
                        }
                    }
                    printf("El total de materia prima usada es: %d\nEl total de materia prima desperdiciada es: %d\n", totalM, totalR);
                    fprintf(archivo ,"Durante el turno %d el total de materia prima usada es: %d\nEl total de materia prima desperdiciada es: %d\n", i+1, totalM, totalR);
                }
                
                printf("El turno con más desperdicio fue el turno %d con %d de desperdicio\n", mayorIn+1, mayor);
                fprintf(archivo, "El turno con más desperdicio fue el turno %d con %d de desperdicio\n", mayorIn+1, mayor);

                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (flag);

    fclose(archivo);  // Cierra el archivo

    return 0;
}

// Función para escribir los datos de los muebles en un archivo
void EscribirMuebles(struct Mueble* muebles, FILE* archivo) {
    fclose(archivo);  // Cierra el archivo
    fopen("Datos.csv", "w+");  // Vuelve a abrir el archivo en modo escritura y lectura

    fseek(archivo, 0, SEEK_SET);  // Establece la posición del puntero de archivo al principio del archivo

    // Escribe los datos de los muebles en el archivo, separados por punto y coma
    for (int i = 0; i < 3; i++) {
        fprintf(archivo, "%s;%d;%d\n", muebles[i].nombre_mueble, muebles[i].cantidad_materia_prima, muebles[i].cantidad_residuo);
    }

    fflush(archivo);  // Limpia el búfer de salida para asegurar que los datos se escriban en el archivo
}

