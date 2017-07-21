#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159265358979323846

int convert(int i , int j);
void masas(double *matriz);
int tiempos(double *t, int index);
//double r (double *matriz1, int i0);

void dist(double *matriz1,double *r, int i0);

double aceleracionx (double *matriz1, double *ax, int i0);


void leapfrogx(double *x_n, double *vx_n, double *vx_half,double *ax,int n, int index, double *matriz1,double t);



void main(){
    FILE *file;
    file =fopen("coordinates.csv","r");
    int len =250;
    char line[len];
    char *almline=NULL; 
    const char *delimiter;
    delimiter=",";
    int i=0, j=0;
    int N=250*12;
    double t=0.00005;
    double G=2*pow(PI,2.0);
    double mat;
    double *matriz=malloc(80*sizeof(double));
    double *tiempo=malloc(N*sizeof(int));

    double *acx=malloc(N*sizeof(double));
	double *acy=malloc(N*sizeof(double));
	double *acz=malloc(N*sizeof(double));

	double *x_n= malloc((N)*sizeof(double));
	double *vx_n= malloc((N)*sizeof(double));
	double *vx_half=malloc((N)*sizeof(double));
 	
 	double *y_n= malloc((N)*sizeof(double));
	double *vy_n= malloc((N)*sizeof(double));
	double *vy_half=malloc((N)*sizeof(double));

	double *z_n= malloc((N)*sizeof(double));
	double *vz_n= malloc((N)*sizeof(double));
	double *vz_half=malloc((N)*sizeof(double));

	double *r=malloc((10)*sizeof(double));

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

    dist(matriz , r , 1);
    for (i=0; i<10;i++){
    	  printf("%e\n", r[i]);
   }    
    //printf("%e\n", matriz[convert(1,1)]);
    //printf("%e\n", matriz[convert(2,1)]);

    //for (i=0; i<10;i++){
    //	  printf("%e\n", matriz[i,1]);
    //}
    //masas(matriz);
    //for (i=0; i<10;i++){
    //	  printf("%e\n", matriz[i,1]);
    //}    

   	//int a=tiempos(tiempo,2500);
   	//printf("%d\n", a);
    
    //double a=matriz[convert(6,0)];
    //printf("%d\n", a)

    //double a=r(matriz, 2);
   	//printf("%e\n", a);

   	//double a=aceleracionx(matriz, acx, 2);
   	//printf("%e\n", a);

    //for(j=0;j<10;j++){
    //	if(j!=1){
    //		printf("%e\n", matriz[convert(j, 2)]);
    //	}

    //}
   
    /*Reccorro todos los intervalos temporales */
	/*for(i=0; i<N;i++)
	{
		
		leapfrogx(x_n,vx_n,vx_half,acx,N,i,matriz,t);
		leapfrogy(y_n,vy_n,vy_half,acy,N,i,matriz,t);
		leapfrogz(z_n,vz_n,vz_half,acz,N,i,matriz,t);
	}*/

 }

int convert(int i, int j)
{	
	return i*8 + j;
}

void masas(double *matriz){
	
	int i;
	double masasol=1.9891*pow(10,30);

	for(i=0;i<10;i++){
		matriz[i,1]=(matriz[convert(i,1)]/masasol);
		//printf ("%e,\n", arreglo[j]);
    }
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

void dist(double *matriz1, double *r , int i0){
	double x,y,z;
	int i;
	for(i=0;i<10;i++){
    	if(i!=i0){
    		x=(matriz1[convert(i0, 2)]-matriz1[convert(i, 2)]);
    		y=(matriz1[convert(i0, 3)]-matriz1[convert(i,3)]);
    		z=(matriz1[convert(i0, 4)]-matriz1[convert(i, 4)]);
    		r[i]=sqrt(pow(x,2.0)+pow(y,2.0)+pow(z,2.0));
    		
    	}
	else{
	r[i]=0;
	}
    
    }

}


/*double aceleracionx (double *matriz1, double *ax, int i0){
	int j;
	double r[10];
	double G=2*pow(PI,2.0);

	for(j=0;j<10;j++){
    	if(j!=i0){
    		r[j]=sqrt(pow((matriz1[convert(i0, 2)]-matriz1[convert(j, 2)]),2.0)+pow((matriz1[convert(i0, 3)]-matriz1[convert(j,3)]),2.0)+pow((matriz1[convert(i0, 4)]-matriz1[convert(j, 4)]),2.0));
    		//printf("%e\n", r[j]);
    		ax[j] = G* masas(matriz1,i0)* (matriz1[convert(i0, 2)]-matriz1[convert(j, 2)])/pow(r[j],3);
    		//printf("%e\n", ax[j]);
    	}
    
    }
    //return r[i0];
    return ax[i0];
}

double aceleraciony (double *matriz1, double *ay, int i0){
	int j;
	double r[10];
	double G=2*pow(PI,2.0);

	for(j=0;j<10;j++){
    	if(j!=i0){
    		r[j]=sqrt(pow((matriz1[convert(i0, 2)]-matriz1[convert(j, 2)]),2.0)+pow((matriz1[convert(i0, 3)]-matriz1[convert(j,3)]),2.0)+pow((matriz1[convert(i0, 4)]-matriz1[convert(j, 4)]),2.0));
    		//printf("%e\n", r[j]);
    		ay[j] = G* masas(matriz1,i0)* (matriz1[convert(i0, 3)]-matriz1[convert(j, 3)])/pow(r[j],3);
    		//printf("%e\n", ax[j]);
    	}
    
    }
    //return r[i0];
    return ay[i0];
}

double aceleracionz (double *matriz1, double *az, int i0){
	int j;
	double r[10];
	double G=2*pow(PI,2.0);

	for(j=0;j<10;j++){
    	if(j!=i0){
    		r[j]=sqrt(pow((matriz1[convert(i0, 2)]-matriz1[convert(j, 2)]),2.0)+pow((matriz1[convert(i0, 3)]-matriz1[convert(j,3)]),2.0)+pow((matriz1[convert(i0, 4)]-matriz1[convert(j, 4)]),2.0));
    		//printf("%e\n", r[j]);
    		az[j] = G* masas(matriz1,i0)* (matriz1[convert(i0, 4)]-matriz1[convert(j, 4)])/pow(r[j],3);
    		//printf("%e\n", ax[j]);
    	}
    
    }
    //return r[i0];
    return az[i0];
}

//n será N = 250*12
void leapfrogx(double *x_n, double *vx_n, double *vx_half,double *ax,int n, int index, double *matriz1,double t)
{ 
	int i;
	aceleracionx(matriz1, ax, i);

	for(i=1 ; i<n-1; i++)
	{
		
		vx_half[i] = vx_n[i] + 0.5*t*ax[i];
		x_n[i] =x_n[i]+t*vx_half[i];
	}
	
	aceleracionx(matriz1, ax, i);
	
	for(i=1 ; i<n-1; i++)
	{
		vx_n[i] = vx_half[i] + 0.5*t*ax[i];
	}
}

void leapfrogy(double *y_n, double *vy_n, double *vy_half,double *ay,int n, int index, double *matriz1,double t)
{ 
	int i;
	aceleraciony(matriz1, ay, i);

	for(i=1 ; i<n-1; i++)
	{
		
		vy_half[i] = vy_n[i] + 0.5*t*ay[i];
		y_n[i] =y_n[i]+t*vy_half[i];
	}
	
	aceleraciony(matriz1, ay, i);
	
	for(i=1 ; i<n-1; i++)
	{
		vy_n[i] = vy_half[i] + 0.5*t*ay[i];
	}
}

void leapfrogz(double *z_n, double *vz_n, double *vz_half,double *az,int n, int index, double *matriz1,double t)
{ 
	int i;
	
	aceleracionz(matriz1, az, i);

	for(i=1 ; i<n-1; i++)
	{
		vz_half[i] = vz_n[i] + 0.5*t*az[i];
		z_n[i] =z_n[i]+t*vz_half[i];
	}
	
	aceleracionz(matriz1, az, i);
	
	for(i=1 ; i<n-1; i++)
	{
		vz_n[i] = vz_half[i] + 0.5*t*az[i];
	}
}*/