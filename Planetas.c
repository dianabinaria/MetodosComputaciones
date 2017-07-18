#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*struct my_record {
   char name;
   float masa;
   float pox;
   float poy;
   float poz;
   float velx;
   float vely;
   float velz;
  
};

int main(void) {
  
  FILE* my_file = fopen("coordinates.csv","r");
  struct my_record records[10];
  size_t count = 0;
  for (; count < sizeof(records); ++count)
{
    double got = fscanf(my_file, "%c,%f", &records[count].name, &records[count].masa);
    if (got != 2) break; // wrong number of tokens - maybe end of file
    printf("%e",got);
}
//for (size_t i = 0; i < count; i++) {
//       printf("%c,%f\n", records[i].name, records[i].masa);
//   }
 
  fclose(my_file);
  return 0;
}
*/



double *main(void){
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
	  
	//printf("%e \t",matriz[i]);
	
	almline=strtok(NULL,delimiter);
	j+=1;
      }
      //printf("\n");
      i+=1;
    }
    return matriz;

    
}
