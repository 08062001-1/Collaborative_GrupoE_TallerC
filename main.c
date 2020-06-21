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
//SUMA DE DIGITOS - Metodo Iniciales
void sumDigits();
void calculateSumDigits(int iniInterval, int endInterval, int exclusiveDigit);

//RESULTADOS DE PRUEBA
void test();
int calculateTest(char* chain);

//Metodos Resultado prueba
void test (){
    char* chain;
    printf("Por favor dijite la cadena:\n");
    fgets(&chain, 30, stdin);

    printf("El resultado de la prueba dada es: %d",calculateTest(&chain));
    getchar();

}

int calculateTest(char* chain){
    int contX, contO, sumaO=0, suma=0;
    char digitC;
    for(int i=0; i<strlen(chain)-1; i++){
        digitC=chain[i];
        digitC=toupper(digitC);
        if(digitC=='O'){
            sumaO++;
        }else if(digitC=='X'){
            sumaO=0;
        }
        suma+=sumaO;
    }
    // printf("Resultado Pruba: %d", suma);
    return suma;
}
//termian metodos Resulatdo prueba



//SUMA DE DIGITOS
void sumDigits(){
    int iniInterval=0;
    int endInterval=0;
    int exclusiveDigit=0;
    printf("Suma de digitos\n");
    printf("Digite el intervalo de Inicio:\n");
    scanf("%d", &iniInterval);
    printf("Digite el intervalo Final:\n");
    scanf("%d", &endInterval);
    printf("Digite el numero que desea excluir:\n");
    scanf("%d", &exclusiveDigit);
    fflush(stdin);

    //calculateSumDigits(iniInterval, endInterval, exclusiveDigit);
    iniInterval<=endInterval?calculateSumDigits(iniInterval, endInterval, exclusiveDigit):printf("Lo siento el Intervalo Inicial debe ser menor");
getchar();
}

void calculateSumDigits(int iniInterval, int endInterval, int exclusiveDigit){
    char* numberC;
    int cont=0, suma=0;
    for(int i=iniInterval; i<=endInterval; i++){
        sprintf(numberC, "%d", i);
        for(int j=0; strlen(numberC)>j; j++){
            int chainConv = numberC[j] - '0';
            if(chainConv==exclusiveDigit){
                cont++;
            }else{
                suma+=chainConv;
            }
        }
    }


    printf("\nLos intervalos %d y %d sin tener en cuenta el %d, la suma sería %d y no se tuvieron en cuenta %d digitos\n",
           iniInterval, endInterval, exclusiveDigit, suma, cont );
}

//termina metodos suma de digitos

//metodos Numeros MAGICOS
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


void calcEgotisticalNumber(){
    printf("Selecciono la opcion 2\n");
    getchar();
}


void calcIMC(){
    printf("Selecciono la opcion 4\n");
    getchar();
}


void calcFibonacciSequence(){
    printf("Selecciono la opcion 6\n");
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
                sumDigits();
                break;

            case 6:
                calcFibonacciSequence();
                break;

            case 7:
                test();
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