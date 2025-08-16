// implementar un codigo que pida al usuario un numero y determine si es par o impar 
#include <stdio.h>

int main(){
    int numero;

    printf("Ingrese un numero:");
    scanf("%d", &numero);

    if (numero % 2 ==0){

        printf("\nEl numero %d es par\n",numero);
    }
    else {
        printf("\nEl numero %d es impar\n",numero);
    }
    return 0; 


}








