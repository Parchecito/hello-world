#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
    char nombre[2];
    int size;
    int job_size;
    int free_space;
    int job;
    int lock;
} particion;

void mostrarp(particion *f){
    int n=0;
    printf ("Particion\tSize\tJob size\tFree space\n");
    for(n=0;n<5;n++){
  	printf("    F%d     ",n+1);
    printf("     %d     ",f[n].size);
    printf(" %d\t \t ",f[n].job_size);
    printf("  %d \t ", f[n].free_space);
    if(f[n].lock) printf("     Reservado sistema\n");
    else printf("Listo para uso\n");
   }

}

int main(void){
  int n, job, r, aux;
  int jobs[5];
  particion F[5];
  srand(time(NULL));
  //Aqui se inician las particiones
  for(n=0;n<5;n++){
  	F[n].size=1000;
    if(n<2)F[n].job_size=1000;
    else F[n].job_size=0;
    if(n<2)F[n].free_space=0;
    else F[n].free_space=1000;
    if(n<2) F[n].lock=1;
    else F[n].lock=0;
   }

  //Esta funcion es solo para mostrar el contenido de cada partición
  mostrarp(F);
  printf("\n");

  /*for(n=0;n<5;n++){
  	printf("Particion: F%d ",n+1);
    printf("Size: %d ",F[n].size);
    printf("job size: %d ",F[n].job_size);
    printf("Free space: %d ", F[n].free_space);
    if(F[n].lock) printf("Reservado sistema\n");
    else printf("Listo para uso\n");
   }*/

   //Esta función es para iniciar cada trabajo

   for(job=0;job<5; job++){
   r=rand()%1000;
   if (r==0) r=100;
   if (r<20) r=r*50;
   jobs[job]=r;
   printf("job %d size %d \n",job+1,jobs[job]);
   }

    for(job=0; job<5; job++){
        for(n=2; n<5; n++){
            if(F[n].free_space>=jobs[job]){
                F[n].free_space=F[n].free_space-jobs[job];
                F[n].job_size=F[n].job_size+jobs[job];
                break;
            }
            else if (n==4){
                printf("Espacio insuficiente\n");
            }
        }
    }
    mostrarp(F);
    /*for(n=0;n<5;n++){
  	printf("Particion: F%d ",n+1);
    printf("Size: %d ",F[n].size);
    printf("job size: %d ",F[n].job_size);
    printf("Free space: %d ", F[n].free_space);
    if(F[n].lock) printf("Reservado sistema\n");
    else printf("Listo para uso\n");
   }*/

    getchar();
  /* for(job=0; job<5; job++){
        for(n=2; n<4; n++){
     		if(F[n].free_space<=F[n+1].free_space){
       			r=F[n].free_space;
       			aux=n;
       		}
     		else {
       			r=F[n+1].free_space;
       			aux=n+1;
       		}
     	}
        if(r>=(jobs[job])){
         	F[aux].free_space=(F[aux].free_space)-(jobs[job]);
         }
         else printf("Espacio insuficiente");
	}*/







}
