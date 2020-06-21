#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Inicialización de metodos
void cousinNumbers();
void calculateCousinNumbers(int);
int isCousing(int);

//metodos
void cousinNumbers() {
    int number;
    printf("Calculate Cousin Numbers \n");
    printf("Digite el valor:\n");
    //scanf("%i", &number);

    if(scanf("%i", &number) != 1 || number<0 ) {
        printf("Caracter no válido, por favor digite un entero\n");
    }else{
        printf("Los numeros primos de acuerdo al valor %d, son: \n", number);
        calculateCousinNumbers(number);
    }
    getchar();
}

void calculateCousinNumbers(int number) {
    int cont;
    for ( cont = number; cont >= 1 ; cont-- ){
        if( isCousing( cont ) ){
            printf("%d,\t",cont);
        }
    }
    printf("\n");
}

int isCousing(int number) {
    int cont = 2;
    int cousing = 1;
    while( cont <= number / 2 && cousing ){
        cousing = !( number % cont++ == 0 );
    }
    return cousing;
}
//terminar metodos primos

void calcPrimeNumbers(){
    printf("Selecciono la opcion 1\n");
    getchar();
}

void calcEgotisticalNumber(){
    printf("Selecciono la opcion 2\n");
    getchar();
}

void calcMagicNumber(){
    printf("Selecciono la opcion 3\n");
    getchar();
}

void calcIMC(){
    printf("Selecciono la opcion 4\n");
    getchar();
}

void calcSumOfDigits(){
    printf("Selecciono la opcion 5\n");
    getchar();
}

void calcFibonacciSequence(){
    printf("Selecciono la opcion 6\n");
    getchar();
}

void calcTestScore(){
    printf("Selecciono la opcion 7\n");
    getchar();
}

void mainMenu(){
    int option;
    char temp[10];

    char *mainMenu = "<<<<< MENU PRINCIPAL >>>>>\n\n"
                     "1. Numeros Primos\n"
                     "2. Numero Egolatra\n"
                     "3. Numero Magico\n"
                     "4. Indice de Masa Corporal\n"
                     "5. Suma de Digitos\n"
                     "6. Secuencia Fibonacci\n"
                     "7. Puntaje de una Prueba\n"
                     "8. SALIR\n";

    do{
        printf(mainMenu);
        fgets(temp, 5, stdin);
        strtok(temp, "\n");
        option = atoi(temp);

        switch(option){

            case 1:
                cousinNumbers();
                break;

            case 2:
                calcEgotisticalNumber();
                break;

            case 3:
                calcMagicNumber();
                break;

            case 4:
                calcIMC();
                break;

            case 5:
                calcSumOfDigits();
                break;

            case 6:
                calcFibonacciSequence();
                break;

            case 7:
                calcTestScore();
                break;

            case 8:
                break;

            default:
                printf("ERROR. Opcion no valida, intentelo nuevamente\n");
                break;

        }
    }while(option != 8);
}

int main(int argc, char** argv) {

    mainMenu();

    return 0;
}