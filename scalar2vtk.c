#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Use the same parameter set used in the simulation of the microstructure*/
#define Nx 50
#define Ny 50
#define Nz 50
/*The following three parameters depends on the output data file from the main simulation of the microstructure; make sure the corresponding data files exist otherwise one might get segmentation fault*/
#define initial_time 0 /*The first data file to be read and the corresponding post processing to be done*/
#define time_skip 1000 /* Intervals after which the successive data files are to be read*/
#define final_time 99000 /*The last data file to be read*/

int main(){
  FILE *fpr, *fpw1, *fpw2;
  char filename[30];
  
  int i,j,k,t;
  
  double ***comp = (double***)malloc(Nx*sizeof(double**));
   
  for(i=0;i<Nx;i++){
   comp[i]=(double**)malloc(Ny*sizeof(double*));
   for(j=0;j<Ny;j++){
     comp[i][j] = (double*)malloc(Nz*sizeof(double));
  }
  }
  t=initial_time;
  do{
  sprintf(filename,"saves/Phi%06d.dat",t);
  fpr=fopen(filename,"r"); 
  
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
      fscanf(fpr,"%d,%d,%d,%lf\n",&i, &j, &k, &comp[i][j][k]);
    }
      fscanf(fpr,"\n");
  }
      fscanf(fpr,"\n");
  }
     fclose(fpr);
     
    
    
     sprintf(filename, "saves_vtk/Phi%06d.vtk",t);
     fpw2 = fopen(filename,"w");
     fprintf(fpw2,"# vtk DataFile Version 2.0\n");
     fprintf(fpw2, "Volume example\n");
     fprintf(fpw2, "ASCII\n");
     fprintf(fpw2, "DATASET STRUCTURED_POINTS\n");
     fprintf(fpw2, "DIMENSIONS %d %d %d\n", Nx,Ny,Nz);
     fprintf(fpw2, "ORIGIN %d %d %d\n", 0,0,0);
     fprintf(fpw2, "SPACING %d %d %d\n", 1,1,1);
     fprintf(fpw2, "POINT_DATA %d\n", (Nx*Ny*Nz));
     fprintf(fpw2,"SCALARS COMP float 1\n");
     fprintf(fpw2, "LOOKUP_TABLE default\n");
    for(k=0;k<Nz;k++){
     for(j=0;j<Ny;j++){
      for(i=0;i<Nx;i++){
       fprintf(fpw2,"%lf\t", comp[i][j][k]);
      }
       fprintf(fpw2,"\n");
      }
    } 
    fclose(fpw2);
   t += time_skip;
  }while(t<=final_time);
    
   }
