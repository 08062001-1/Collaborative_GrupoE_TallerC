#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define TAM 10000
/* INICIALIZACION DE METODOS */

//1.NumerosPrimos
void cousinNumbers();
void calculateCousinNumbers(int);
int isCousing(int);

//2. Numero Ególatra
void egotisticalNumber();
int processEgoistcalNumber(int number);
int isEgoistcalNumber(int number);

//3. Numeros Magicos
void magicalNumber();
void vector(int numbers[], char chain[], int tamano);
int sortDescending(int numbers[], int tamano);
int sortAscending(int numbers[], int tamano);
int convertVector(int numbers[], int tamano);
int isMagicNumber(int numberD, int numberA, int number);

//4. Calculo del IMC
void bodyMassIndex();
double calculateIMC(int weight, double height);
char * processIMC(int gender, double IMC);

//5.Suma de Digitos
void sumDigits();
void calculateSumDigits(int iniInterval, int endInterval, int exclusiveDigit);

//6. Serie Fibonacci
void calcFibonacciSerie(int number, char patron []);
void fibonacciSeries();

//7. Resultados de prueba
void test();
int calculateTest(char* chain);

/*---------- METODOS ----------*/

//1. Números Primos
bool validationReal( char number[]){
    for (int i = 0; i < strlen(number); ++i) {
        if (!(isdigit(number[i]))){
            printf("<----Ingresa solo numeros enteros positivos---->\n");
            return true;
        }
    }
    return false;
}

int validations(){
    char number [30];
    int valido=0;
    do {
        scanf("%s",number);
    }while (validationReal(number)==true);
    valido= atoi(number);
    return valido;
}

void cousinNumbers() {
    int number=0;
    printf("---Numeros Primos---\n");
    printf("Digite un numero: \n");
    fflush(stdin);
    number=validations();
    fflush(stdin);
    printf("Los numeros primos de acuerdo al valor %d, son: \n", number);
    calculateCousinNumbers(number);
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

//2. Número Ególatra
void egotisticalNumber() {
    int number;
    printf("Calculo de un Numero Egolatra \n");
    printf("Digite el numero entero a evaluar: \n");
    number = validations();

    if(isEgoistcalNumber( number)){
        printf("El numero %d es un Ególatra\n", number);
    }else{
        printf("El numero %d NO es un Ególatra\n", number);
    }
    getchar();

}

int processEgoistcalNumber(int number){
    int suma, num=0;
    char chain[100];
    sprintf(chain, "%d", number);
    for(int i = 0; i <= strlen(chain)-1; i++){
        num = chain[i] - '0';
        suma+= pow(num, strlen(chain));
    }
    return suma;
}

int isEgoistcalNumber(int number){
    if(processEgoistcalNumber(number) == number){
        return 1;
    }
    return 0;
}

//3. Números Magicos
bool validationRealMagico( char number[]){
    for (int i = 0; i < strlen(number); ++i) {
        if (!(number[0]==45||number[i]>=48&&number[i]<=57)){
            printf("<----Ingresa solo numeros enteros---->\n");
            return true;
        }
    }
    return false;
}

int validationMagico(){
    char number [30];
    int valid=0;
    do {
        scanf("%s",number);
    }while (validationRealMagico(number)==true);
    valid= atoi(number);
    return valid;
}

void magicalNumber() {
    int number;
    int numbers[100];

    printf("Calcular si el Numero es Magico\n");
    printf("Digite el valor \n");
    number=validationMagico();

    char chain[100];
    sprintf(chain, "%d", number);
    int tamano=strlen(chain);

    vector(numbers, chain, tamano); //Agregar los digitos del número en un vector
    if(isMagicNumber(sortDescending(numbers, tamano),sortAscending(numbers, tamano), number)){
        printf("El numero %d es un Número Magico\n", number);
    }else{
        printf("El numero %d No es un Número Magico\n", number);
    }
    getchar();

}
void vector(int numbers[], char chain[], int tamano){
    for (int i = 0; i <= tamano - 1; i++) {
        int num = chain[i] - '0';
        numbers[i] = num;
    }
}

int isMagicNumber(int numberD, int numberA, int number){
    if((numberD-numberA)==number){
        return 1;
    }else{
        return 0;
    }
}

int sortAscending(int number[], int tamano) {
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

int convertVector(int numbers[], int tamano){
    char cadena[30]="";
    for(int i=0; i<tamano; i++){
        numbers[i];
        char convNum[10];
        sprintf(convNum, "%d", numbers[i]);
        strcat(cadena, convNum);
    }
    int num = atoi(cadena);
    return num;
}

int sortDescending(int numberA[], int tamano){
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

//4. Calculo IMC
bool validacionReakGener( char number[]){
    for (int i = 0; i <strlen(number) ; ++i) {
        if (!(number[i]==49||number[i]==50)){
            printf("<---Digita solamente 1 o 2 ---->");
            return true;
        }
    }
    return false;
}

int validationGener(){
    char number [30];
    int value=0;
    do {
        scanf("%s",number);
    }while (validacionReakGener(number)==true);
    value=atoi(number);
    return  value;
}

void bodyMassIndex(){
    int weight, gender;
    double height;
    printf("Calculo del IMC\n");
    printf("Digite su peso en kg: \n");
    weight = validations();
    printf("Digite su estatura en cm: \n");
    height = validations();
    printf("Digite '1' si es Mujer o '2' si es Hombre: \n");

    gender=validationGener();
    printf("Su diagnostico es: %s\n", processIMC(gender, calculateIMC(weight, height)));
    getchar();
}

char* processIMC (int gender, double IMC){
    switch (gender){
        case 1:
            if(IMC < 16){
                return "Desnutrición";
            } else if ((IMC >= 16) && (IMC <= 20)){
                return "Bajo Peso";
            } else if ((IMC > 20) && (IMC <= 24)){
                return "Normal";
            } else if ((IMC > 24) && (IMC <= 29)){
                return "Sobrepeso";
            }else if((IMC > 29) && (IMC <= 34)){
                return "Obesidad";
            }else if((IMC > 34) && (IMC <= 39)){
                return "Obesidad Marcada";
            }else if(IMC > 39){
                return "Obesidad Morbida";
            }
            break;

        case 2:
            if(IMC < 17){
                return "Desnutricion";
            } else if ((IMC >= 17) && (IMC <= 20)){
                return "Bajo Peso";
            } else if ((IMC > 20) && (IMC <= 25)){
                return "Normal";
            } else if ((IMC > 25) && (IMC <= 30)){
                return "Sobrepeso";
            }else if((IMC > 30) && (IMC <= 35)){
                return "Obesidad";
            }else if((IMC > 35) && (IMC <= 40)){
                return "Obesidad Marcada";
            }else if(IMC > 40){
                return "Obesidad Morbida";
            }
            break;

        default:
            return "ERROR. Opcion no valida, intentelo nuevamente";

    }
}

double calculateIMC(int weigth, double height){
    return weigth/(pow((height*0.01),2));
}

//5.Suma de Digitos
void sumDigits(){
    int iniInterval=0;
    int endInterval=0;
    int exclusiveDigit=0;
    printf("<----Suma de digitos---->\n");
    printf("Ingresa el intervalo de inicio:\n");
    iniInterval=validations();
    fflush(stdin);
    printf("Ingresa el intervalo final:\n");
    endInterval=validations();
    fflush(stdin);
    printf("Digite el numero que desea excluir:\n");
    exclusiveDigit=validations();
    fflush(stdin);

    iniInterval<=endInterval?calculateSumDigits(iniInterval, endInterval, exclusiveDigit):printf("Lo siento el Intervalo Inicial debe ser menor\n");
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

//7. Resultados de la prueba
bool validationRealtest( char number[]){
    for (int i = 0; i < strlen(number); ++i) {
        if (!(number[i]==88||number[i]==79||number[i]==120||number[i]==111)){
            printf("<----Ingresa solo O || X---->\n");
            return true;
        }
    }
    return false;
}


void test (){
    printf("----Puntaje de prueba---- \n");
    char chain[30] ;
    printf("Digita la cadena por favor: \n");

    do {
        scanf("%s", chain);

    }while (validationRealtest(chain)==true);

    printf("El resultado de la prueba dada es: %d\n",calculateTest(chain));
    getchar();

}

int calculateTest(char* chain){
    int  sumaO=0, suma=0;
    char digitC;
    for(int i=0; i<strlen(chain); i++){
        digitC=chain[i];
        digitC=toupper(digitC);
        if(digitC=='O'){
            sumaO++;
        }else if(digitC=='X'){
            sumaO=0;
        }
        suma+=sumaO;
    }
    return suma;
}


void calcFibonacciSerie(int number, char patron []){
    char fib0[TAM] = "0";
    char fib1[TAM] = "1";

    printf("***** SERIE FIBONACCI *****\n");
    for (int i = 2; i <= number; i++) {
        char fibNuevo[TAM] = "";
        strcat(fibNuevo, fib1);
        strcat(fibNuevo, fib0);
        strcpy(fib0,fib1);
        strcpy(fib1,fibNuevo);
        printf("f(%d) = %s\n", i, fibNuevo);
    }

    char* secuence = patron;
    char* search = NULL;

    int cont = 0;
    search = strstr(fib1, secuence);
    while (search != NULL){
        cont++;
        search = strstr(search + 1, secuence);
    }
    printf("El patron %s esta %i veces en la serie %s\n", secuence, cont, fib1);
}

void fibonacciSeries(){
    int number;
    char patron[30];
    printf("Digite el numero de la Secuencia Fibonacci ha generar: ");
    number=validations();

    printf("Digite el patron ha buscar: ");
    do {
        scanf("%s",patron);

    }while (validationReal(patron)==true);
    printf("En el metodo para arrancar\n");

    calcFibonacciSerie(number, patron);
    getchar();
}

/*---------- MENU PRINCIPAL ----------*/
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
                egotisticalNumber();
                break;

            case 3:
                magicalNumber();
                break;

            case 4:
                bodyMassIndex();
                break;

            case 5:
                sumDigits();
                break;

            case 6:
                fibonacciSeries();
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