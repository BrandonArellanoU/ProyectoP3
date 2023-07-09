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
        //retorna el valor de 1 
        return 1;
    }
    //inicializa la flag en 1
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
        // declaracion de la funcion opcion
        int opcion;
        //imprimimos las opciones del menu
        printf("Ingrese una opcion:\n");
        printf("1. Ver muebles\n");
        printf("2. Modificar datos muebles\n");
        printf("3. Ingresar datos de turnos\n");
        printf("4. Salir\n");
        //leemos la opcion
        scanf("%d", &opcion);
        //hacemos un switch para las opciones 
        switch(opcion){
        case 1:
            //limpiamos la pantalla 
            system("cls");
            // Muestra en pantalla la información de los muebles almacenados en el arreglo "muebles"
            for (int i = 0; i < 3; i++)
            {
                //imprimimos la informacion
                printf("Mueble %d: %s ocupa %d de materia prima y deja %d de residuo\n", i + 1, muebles[i].nombre_mueble, muebles[i].cantidad_materia_prima, muebles[i].cantidad_residuo);
            }
            printf("\n");
            break;
        case 2:
            //limpiamos la pantalla
            system("cls");
            //imprimimos y solicitamos la informacion 
            printf("Ingrese el numero del mueble a modificar (1 - 3)\n");
            scanf("%d", &mueble);
            printf("Ingrese el nuevo nombre del mueble: \n");
            scanf("%s", muebles[mueble].nombre_mueble);
            printf("Ingrese la cantidad de materia prima que gasta: \n");
            scanf("%d", &muebles[mueble].cantidad_materia_prima);
            printf("Ingrese la cantidad de residuo que genera: \n");
            scanf("%d", &muebles[mueble].cantidad_residuo);
            //llamamos a la funcion y enviamos parametros
            EscribirMuebles(muebles, archivo);
            //limpamos la pantalla
            system("cls");
            break;
        case 3:
            //inicializamos las variables 
            totalM = 0;
            totalR = 0;
            //usamos un for para imprimir
            for (int i = 0; i < 3; i++)
            {
                totalM = 0;
                totalR = 0;
                printf("Turno %d:\n", i + 1);
                //for anidado para llenar las opciones 
                for (int j = 0; j < 3; j++)
                {
                    //imprimimos y solicitamos la informacion
                    printf("Ingrese la cantidad de muebles '%s' que se hicieron: ", muebles[j].nombre_mueble);
                    scanf("%d", &cant);
                    //recorre en el array
                    totalM += cant * muebles[j].cantidad_materia_prima;
                    totalR += cant * muebles[j].cantidad_residuo;
                    //usamos una condicional 
                    if (mayor < totalR)
                    {
                        mayor = totalR;
                        mayorIn = i;
                    }
                }
                //imprimimos la informacion
                printf("El total de materia prima usada es: %d\nEl total de materia prima desperdiciada es: %d\n", totalM, totalR);
                //imprimimos en el archivo
                fprintf(archivo, "Durante el turno %d el total de materia prima usada es: %d\nEl total de materia prima desperdiciada es: %d\n", i + 1, totalM, totalR);
            }
            //imprime la informacion
            printf("El turno con más desperdicio fue el turno %d con %d de desperdicio\n", mayorIn + 1, mayor);
            //imprime en el archivo
            fprintf(archivo, "El turno con más desperdicio fue el turno %d con %d de desperdicio\n", mayorIn + 1, mayor);
            //termina su ejecucion
            break;
        case 4:
            //cambia el valor de la flag para que termien el buble
            flag = 0;
            break;
        default:
            //imprime si escogemos una opcion incorrecta
            printf("Opcion no valida\n");
            break;
   }
}while(opcionesusu !=0);
    // Cierra el archivo
    fclose(archivo); 
//no retorna nada
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
        //imprime en el archivo
        fprintf(archivo, "%s;%d;%d\n", muebles[i].nombre_mueble, muebles[i].cantidad_materia_prima, muebles[i].cantidad_residuo);
    }
    // Limpia el búfer de salida para asegurar que los datos se escriban en el archivo
    fflush(archivo); 
}

