#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Use the same parameter set used in the simulation of the microstructure*/
#define Nx 80
#define Ny 80
#define Nz 79
/*The following three parameters depends on the output data file from the main simulation of the microstructure; make sure the corresponding data files exist otherwise one might get segmentation fault*/
#define initial_time 0 /*The first data file to be read and the corresponding post processing to be done*/
#define time_skip 1000 /* Intervals after which the successive data files are to be read*/
#define final_time 99000 /*The last data file to be read*/

int main()
{
  FILE *fpr, *fpw1, *fpw2;
  char filename[30];
  //char d1[30], d2[30], d3[30], d4[30], d5[30], d6[30], d7[30], d8[30], d9[30], d10[30];
  
  int i,j,k,t;
  
  double ***comp = (double***)malloc(Nx*sizeof(double**));
   
  for(i=0;i<Nx;i++){
   comp[i]=(double**)malloc(Ny*sizeof(double*));
   for(j=0;j<Ny;j++){
     comp[i][j] = (double*)malloc(Nz*sizeof(double));
  }
 }
  
  sprintf(filename,"vcm.vtk");
  fpr=fopen(filename,"r");   
  
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  fscanf(fpr, "%*[^\n]\n");
  
  for(k=0;k<Nz;k++){
     for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++){
		fscanf(fpr,"%lf\t", &comp[i][j][k]);
		}
       fscanf(fpr,"\n");
      }
    } 
    fclose(fpr);
   
    
  sprintf(filename, "80x80x80/vcm.txt");
  fpw2 = fopen(filename,"w");
     
   for(i=0;i<Nx;i++){
	  for(j=0;j<Ny;j++){
		 for(k=0;k<Nz;k++){
		 fprintf(fpw2,"%d %d %d %lf\n",i, j, k, comp[i][j][k]);
		 }
    //  fprintf(fpw2,"\n");
	  }
     // fprintf(fpw2,"\n");
	}
     fclose(fpw2);
 
  
    
   }
