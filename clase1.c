#include <stdio.h>
#include <string.h>

void main() {
    int opcion=0, encontrado, posicion;
    char nombre[20], nombre2[20];
    FILE* file;
    file = fopen("nombres.bin","wb+");
    if (file == NULL) {
        printf("Error al crear el archivo.\n");
        } else {
    printf("Archivo creado.\n");
}

    printf("\nMenu:");
    printf("\n1.Carga de datos");
    printf("\n0.Salir");
    printf("\nElija una opcion:");
    scanf("%d",&opcion);

while (getchar() != '\n');



do
    {
        opcion=menu();
        switch (opcion)
        {
            case 1: 
                printf("\nIngrese el nombre: ");
                fgets(nombre, sizeof(nombre),stdin);
                nombre[strcspn(nombre, "\n")] = 0; //esto limpia el buffer 

                fseek(file, 0, SEEK_END); //mover el puntero al final del archivo
                fwrite(&nombre, sizeof(nombre), 1,file);

                printf("\nNombre agregado correctamente\n");
                fclose(file);

                    break; 
            case 2:
                rewind(file);
                while(fread(&nombre, sizeof (nombre),1,file) !=0){
                    printf("%s \n", nombre);
                }
                break;
            case 3:
                
                rewind(file);

                printf("\nIngrese el nombre: ");
                fgets(nombre, sizeof(nombre),stdin);
                nombre[strcspn(nombre, "\n")] = 0;

                while(fread(&nombre2, sizeof (nombre2),1,file) !=0){
                    if (strstr(nombre2,nombre) != NULL){
                        printf("\n Se encontro el nombre %s",nombre);
                        encontrado=1;
                        break;
                    }
                }
                if (encontrado !=1){
                    printf("\nNo se encontro el nombre");
                }
                //pedir un nombre
                //recorrer el archivo y comparar con el nombre 
                //devolver nombre y posicion o no encontrado

                break;
        }
        while(opcion != 0);

        fclose(file;)
        return;
}





