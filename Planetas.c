#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int convert(int i , int j);

double aceleracion ();
double velocidad ();


void main(){
    FILE *file;
    file =fopen("coordinates.csv","r");
    int len =250;
    char line[len];
    char *almline=NULL;
    const char *delimiter;
    delimiter=",";
    int i=0, j=0;
    double mat;
    double *matriz=malloc(80*sizeof(double));
    

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
    //double a=matriz[convert(6,0)];
    for(j=0;j<10;j++){
    	if(j!=1){
    		printf("%e\n", matriz[convert(j, 2)]);
    	}

    }
   
 }

int convert(int i, int j)
{	
	return i*8 + j;
}	
 