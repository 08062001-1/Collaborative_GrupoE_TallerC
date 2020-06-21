#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Inicialización de metodos
//NUMEROS PRIMOS
void cousinNumbers();
void calculateCousinNumbers(int);
int isCousing(int);
//NUMEROS MAGICOS
void magicalNumber();
void vector(int numbers[], char chain[], int tamano);
int sortDescending(int numbers[], int tamano);
int sortAscending(int numbers[], int tamano);
int convertVector(int numbers[], int tamano);
int isMagicNumber(int numberD, int numberA, int number);

//metodos MAGICOS
void magicalNumber() {
    int number;
    int numbers[100];

    printf("Calcular si el Numero es Magico\n");
    printf("Digite el valor \n");
    scanf("%d", &number);

    char chain[100];
    sprintf(chain, "%d", number);
    int tamano=strlen(chain);

    vector(numbers, chain, tamano); //Agregar los digitos del número en un vector
    //Ordena los digitos del vector, lo vueve a convertir en cadena luego en numero y los resta
    if(isMagicNumber(sortDescending(numbers, tamano),sortAscending(numbers, tamano), number)){
        printf("El numero %d es un Número Magico\n", number);
    }else{
        printf("El numero %d No es un Número Magico\n", number);
    }
    getchar();

}

int isMagicNumber(int numberD, int numberA, int number){
    if((numberD-numberA)==number){
        return 1;
    }else{
        return 0;
    }
}

int convertVector(int numbers[], int tamano){
    char cadena[30]="";

    for(int i=0; i<tamano; i++){
        numbers[i];
        char convNum[10];
        sprintf(convNum, "%d", numbers[i]);
        strcat(cadena, convNum);
    }
    //  printf("%s\n",  cadena);
    int num = atoi(cadena);

    return num;
}

void vector(int numbers[], char chain[], int tamano){
    // printf("vector  \n");
    for (int i = 0; i <= tamano - 1; i++) {
        // printf("%c\t", chain[i]);
        int num = chain[i] - '0';
        numbers[i] = num;
        // printf("%d\t", numbers[i]);
    }
}

int sortAscending(int number[], int tamano) {
    //printf("ordenar \n");
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = i + 1; j < tamano; j++) {
            if (number[j] < number[i]) {
                int aux = number[j];
                number[j] = number[i];
                number[i] = aux;
            }
        }
    }
    return convertVector(number, tamano);;
}

int sortDescending(int numberA[], int tamano){
    // printf("ordenar \n");
    for (int i = 0; i < tamano-1; i++){
        for (int j = i + 1; j < tamano; j++){
            if(numberA[j]>numberA[i]){
                int aux= numberA[j];
                numberA[j]=numberA[i];
                numberA[i]= aux;
            }
        }
    }

    return convertVector(numberA, tamano);
}

//metodos primos
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
    getchar();
}

int isCousing(int number) {
    int cont = 2;
    int cousing = 1;
    while( cont <= number / 2 && cousing ){
        cousing = !( number % cont++ == 0 );
    }
    return cousing;
    getchar();
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
                magicalNumber();
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