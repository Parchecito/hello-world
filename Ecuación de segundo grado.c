#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0


int cadena_a_numero(char *cadena, long long int *a);

int main(void){
    long long int aux=0,a,b,c,g;
    float x1,x2,aux1;
	char numero[21];
	printf("Introduzca el primer valor: ");
	scanf("%s",&numero);
	system("cls");
	fflush(stdin);
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

	g=b*b-4*a*c;
	if(a==0){
        if(b!=0){
            printf("Esto no es una ecuación de segundo grado\n");
            x1=-c/(float)b;
            printf("X=%f",x1);
            getchar();
            return FALSE;
        }
        else printf("Esto no es una ecuación");
        getchar();
        return FALSE;
	}

	if(g>=0){
        x1=(-b+sqrt(g))/(2*a);
        x2=-(b+sqrt(g))/(2*a);
        printf("las soluciones son X1=%f  X2=%f",x1,x2);
	}
	else{
        x1=-b/(float)(2*a);
        x2=sqrt(-g)/(2*a);
        printf("las soluciones son X1=%f+%fi  X2=%f-%fi",x1,x2,x1,x2);
	}
	getchar();
	return FALSE;

}

int cadena_a_numero(char *cadena, long long int *a){
	int aux=0;
	long int suma=0,aux2=1;
	aux=strlen(cadena)-1;
	while(aux>=0){
		if(!isdigit(cadena[aux])&&(aux!=0||cadena[aux]!='-')) return FALSE;
        if(cadena[aux]=='-')break;
		suma=suma+(cadena[aux--]-48)*aux2;
		aux2*=10;
		if(suma<0){
			printf("Dominio fuera de rango \nPor favor introduzca un numero en el rango de\n 2,147,483,647 a -2,147,483,647\n");
			return FALSE;
		}
	}
	if(cadena[0]=='-')suma*=(-1);
	*a=suma;
	return TRUE;
}
