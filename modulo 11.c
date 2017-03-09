#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cartodig(char *c, int n){
	if(c[n]=='0') return 0;
	else if (c[n]=='1') return 1;
	else if (c[n]=='2') return 2;
	else if (c[n]=='3') return 3;
	else if (c[n]=='4') return 4;
	else if (c[n]=='5') return 5;
	else if (c[n]=='6') return 6;
	else if (c[n]=='7') return 7;
	else if (c[n]=='8') return 8;
	else if (c[n]=='9') return 9;
	return NULL;
}

int main(void){
	char code[10];
	int aux,aux2,sum,ponderado=2;
	printf("Introduzca un codigo numerico (digitos min 5, max 8):  ");
	scanf("%s",code);
	fflush(stdin);
	aux=strlen(code);
	printf("Largo:%d\n",aux);
	if(aux<5||aux>8) return printf("Entrada no valida");
	for(--aux;aux>=0;aux--){
		if(isdigit(code[aux])) aux2=cartodig(code,aux);
		else printf("Entrada no valida");
		sum+=(ponderado*aux2);
		printf("Digito:%d Ponderado:%d Suma:%d\n",aux2,ponderado,sum);
		if(++ponderado>7) ponderado=2;
	}
	aux=sum%11;
	printf("%d mod 11: %d\n",sum,aux);
	aux2=strlen(code);
	if(aux==10)code[aux2]='A';
	else code[aux2]=aux+48;
	printf("El codigo completo es: %s, el caracter de control es %d",code,aux);
}
