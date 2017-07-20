#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159265358979323846

int convert(int i , int j);
double masas(double *matriz1, int jindex);
int tiempos(double *t, int index);
//double r (double *arrayx, double *arrayy, double *arrayz, double *t)

double aceleracionx(double *t, double *arrayx, double *a);
double aceleraciony(double *t, double *arrayy, double *a);
double aceleracionz(double *t, double *arrayz, double *a);

void main(){
    FILE *file;
    file =fopen("coordinates.csv","r");
    int len =250;
    char line[len];
    char *almline=NULL;
    const char *delimiter;
    delimiter=",";
    int i=0, j=0;
    double G=2*pow(PI,2.0);
    double mat;
    double *matriz=malloc(80*sizeof(double));
    double *tiempo=malloc(250*12*sizeof(int));
    

    while(fgets(line,len,file)){
      //printf("line is %s", line);
      almline=strtok(line,delimiter);
      while(almline !=NULL){
        mat=atof(almline);
	
		//printf ("%e\n",matriz);
		matriz[i]=mat;
	  
		//printf("%e  %f %d \n",matriz[i], mat, i);
	
		almline=strtok(NULL,delimiter);
		i+=1;
      }
    }

    //double a=masas(matriz,2);
    //printf("%e\n", a);

   	//int a=tiempos(tiempo,2500);
   	//printf("%d\n", a);
    
    //double a=matriz[convert(6,0)];
    //printf("%d\n", a)

    //for(j=0;j<10;j++){
    //	if(j!=1){
    //		printf("%e\n", matriz[convert(j, 1)]);
    //	}

    //}
   
 }

int convert(int i, int j)
{	
	return i*8 + j;
}

double masas(double *matriz1, int jindex){
	int j;
	//int i;
	double arreglo[10];
	double masasol=1.9891*pow(10,30);

	for(j=0;j<10;j++){
		arreglo[j]=(matriz1[convert(j,1)]/masasol);
		//printf ("%e,\n", arreglo[j]);
    }
    return arreglo[jindex];
}

int tiempos(double *t, int index){

	int i;
	
	for(i=0; i<250*12; i++)
	{
		t[i]=i;
		//printf("%e\n", t[i]);
	}
	return t[index];

}


//double aceleracionx(double *arrayx, double *a)
//{	int i;
//	int j;
//	
//	for (j=1 ; j<10 ; j++)
//	{
//	a[j] = G* arrayx[i+1] -2*array[i]+ array[i-1]+B*(pow(array[i+1]-array[i],2)-pow(array[i]-array[i-1],2));
//	})



