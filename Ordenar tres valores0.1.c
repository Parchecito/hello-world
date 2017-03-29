#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int cadena_a_numero(char *cadena, long long int *a);
void intercambio_de_valor(long long int *a, long long int *b);

int main(void){
	long long int aux=0,a,b,c;
	/*long long int es un tipo de variable que guarda enteros de largo rango*/
	char numero[21];
	printf("Bienvenido. Este programa recoge tres valores y posteriormente\nlos ordena de menor a mayor y de mayor a menor.\nLos valores deben ser numeros enteros positivos o negativos dentro\ndel rango de 9223372036854775807 a -9223372036854775807.\n\tPresione cualquier tecla para continuar...");
	getchar();
	system("cls");
	printf("Introduzca el primer valor: ");
	scanf("%s",&numero);
	system("cls");
	fflush(stdin);
	/*Estas estructuras While se van a repetir hasta que el usuario introduzca la entrada de forma correcta
	En la condición coloqué !cadena_a_numero ya que si la función tiene algun problema leyendo la cadena va a soltar un valor FALSE
	haciendo que el while se repita*/
	while(!cadena_a_numero(numero, &a)){
		printf("\tEntrada No valida\n\tIntroduzca el primer valor:");
		scanf("%s",&numero);
		system("cls");
		fflush(stdin);
	}
	printf("Introduzca el segundo valor:");
	scanf("%s",&numero);
	system("cls");
	fflush(stdin);
	while(!cadena_a_numero(numero, &b)){
		printf("\tEntrada No valida\n\tIntroduzca el segundo valor:");
		scanf("%s",&numero);
		system("cls");
		fflush(stdin);
	}
	printf("Introduzca el tercer valor:");
	scanf("%s",&numero);
	system("cls");
	fflush(stdin);
	while(!cadena_a_numero(numero, &c)){
		printf("\tEntrada No valida\n\tIntroduzca el tercer valor:");
		scanf("%s",&numero);
		system("cls");
		fflush(stdin);
	}
	/* Hice una función para intercambiar los valores de las variables en caso de que una sea mayor que la otra, de este modo
	no tengo que escribir las lineas una y otra vez.
	Para la resolución de este problema yo decidi que a debe guardar el numero mayor, b el numero medio y c el menor.
	Eso queda enteramente a sus criterios como programadores, pero tengan cuidado con los siguientes pasos*/
	if(b>a)intercambio_de_valor(&a,&b);
	if(c>a)intercambio_de_valor(&c,&a);
	/*Como "a" es la variable que debe guardar el numero mayor, las declaraciones anteriores lo que hacen es verificar si "b" o "c" tienen
	valores mayores que "a". En caso de ser así van a cambiar los valores para que "a" quede con el mayor*/
	if(c>b)intercambio_de_valor(&c,&b);
	/*finalmente como la variable "c" debe guardar el numero menor y "b" el numero medio comparé ambos valores para que en caso de que c>b entonces los
	valores se cambien*/
	printf("Valores ordenados de mayor a menor: %lli * %lli * %lli \n",a,b,c);
	printf("Valores ordenados de menor a mayor: %lli * %lli * %lli ",c,b,a);
	getchar();
	return TRUE;
}
/*esta función lee una cadena de caracteres y un numero x, convierte la cadena y la guarda en el numero x.
Si la conversión se logra con exito devuelve un valor TRUE, para que los while que estan en el main dejen de hacer loop.
En caso contrario devuelve un FALSE para que los while pidan de nuevo la entrada de un numero*/
int cadena_a_numero(char *cadena, long long int *a){
	int aux=0;
	long long int suma=0,aux2=1;
	aux=strlen(cadena)-1;
	/*este while toma cada caracter de la cadena y lo va sumando para obtener el numero deseado. Recuerden la descomposición de numeros.
	Por ejemplo: 123 = 1x100+2x10+3x1 */
	while(aux>=0){
		if(!isdigit(cadena[aux])&&(aux!=0||cadena[aux]!='-')) return FALSE;
        /*Me voy a detener un poco en este punto, la función "isdigit" lee un caracter, si el caracter es un numero regresa TRUE, si no regresa FALSE.
        Es decir, si el caracter es un numero la función continua con su buen trabajo, y si no manda todo al carajo.
        La unica excepcion a esta regla será cuando Solo el primer valor de la cadena( la posición [0]) tenga el signo "-"*/
        if(cadena[aux]=='-')break;
        /*Ahora se preguntarán, ¿para que pusiste la excepción al caracter "-" pero ahora le montas un break? ¿tu eres marico?
        No señores, todo tiene su explicación.*/
		suma=suma+(cadena[aux--]-48)*aux2;
		aux2*=10;
		if(suma<0){
			printf("Dominio fuera de rango \nPor favor introduzca un numero en el rango de\n 9223372036854775807 a -9223372036854775807\n");
			return FALSE;
		}
	}
	if(cadena[0]=='-')suma*=(-1);
	/*He aqui nos encontramos de nuevo con nuestro amigo el señor "-". Como acote antes la función va sumando los numeros de la cadena... pero
	¿Que pasa si el numero es negativo? pues muy sencillo, solo tengo que multiplicar ese numero por menos 1.
	Ejemplo: -123 = (1x100+2x10+3x1)x(-1)
	Ahora, para que era la excepcion del "-" y el break del bloque anterior, pues fijense, yo no quiero que cuando la función lea el caracter "-"
	se vuelva loca y lo mande todo al carajo, pero tampoco quiero que tome el "valor" que tiene ese signo y lo sume al numero x.
	Por eso añadi un break para que la ejecución salte directamente al paso anterior.
	Viste que todo tiene explicación Pajuo! */
	*a=suma;
	return TRUE;
}
//esta es la función que intercambia los valores
void intercambio_de_valor(long long int *a, long long int *b){
    long long aux;
    aux=*b;
    *b=*a;
    *a=aux;
}
//Marico el que lo lea
