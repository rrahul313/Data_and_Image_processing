#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Use the same parameter set used in the simulation of the microstructure*/
#define Nx 50
#define Ny 50
#define Nx_tile 150
#define Ny_tile 150
#define Nz_max 150
/*The following three parameters depends on the output data file from the main simulation of the microstructure; make sure the corresponding data files exist otherwise one might get segmentation fault*/
#define initial_time 6000 /*The first data file to be read and the corresponding post processing to be done*/
#define time_skip 6000 /* Intervals after which the successive data files are to be read*/
#define final_time 594000 /*The last data file to be read*/
#define no_of_iter 4000
int main()
{
  FILE *fpr1, *fpr2, *fpr3, *fpw3, *fpw4, *fpw5;
  char filename[30], dim[10];
  //char d1[30], d2[30], d3[30], d4[30], d5[30], d6[30], d7[30], d8[30], d9[30], d10[30];
  
  int i,j,k,t,Nx_file, Ny_file, Nz;
   
    double ***comp = (double***)malloc(Nx*sizeof(double**));

  double ***comp1 = (double***)malloc(Nx*sizeof(double**));
   double ***comp2 = (double***)malloc(Nx*sizeof(double**));
   double ***comp3 = (double***)malloc(Nx*sizeof(double**));
   
   double ***comp1_tile = (double***)malloc(Nx_tile*sizeof(double**));
   double ***comp2_tile = (double***)malloc(Nx_tile*sizeof(double**));
   double ***comp3_tile = (double***)malloc(Nx_tile*sizeof(double**));
   
  for(i=0;i<Nx;i++){
   comp[i]=(double**)malloc(Ny*sizeof(double*));
   comp1[i]=(double**)malloc(Ny*sizeof(double*));
   comp2[i]=(double**)malloc(Ny*sizeof(double*));
   comp3[i]=(double**)malloc(Ny*sizeof(double*));
   for(j=0;j<Ny;j++){
     comp[i][j] = (double*)malloc(Nz_max*sizeof(double));
     comp1[i][j] = (double*)malloc(Nz_max*sizeof(double));
     comp2[i][j] = (double*)malloc(Nz_max*sizeof(double));
     comp3[i][j] = (double*)malloc(Nz_max*sizeof(double));    
  }
 }
 
 for(i=0;i<Nx_tile;i++){
   comp1_tile[i]=(double**)malloc(Ny_tile*sizeof(double*));
   comp2_tile[i]=(double**)malloc(Ny_tile*sizeof(double*));
   comp3_tile[i]=(double**)malloc(Ny_tile*sizeof(double*));
   for(j=0;j<Ny_tile;j++){   
     comp1_tile[i][j] = (double*)malloc(Nz_max*sizeof(double));
     comp2_tile[i][j] = (double*)malloc(Nz_max*sizeof(double));
     comp3_tile[i][j] = (double*)malloc(Nz_max*sizeof(double));    
 }
}
  t=initial_time;
 //Nz=18;
  do{  
  sprintf(filename,"saves_1/conc_%d.vtk",t);
  fpr1=fopen(filename,"r");   
  
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%s %d %d %d\n", &dim[10], &Nx_file, &Ny_file, &Nz);
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  fscanf(fpr1, "%*[^\n]\n");
  
  for(k=0;k<Nz;k++){
     for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++){
		fscanf(fpr1,"%lf\t", &comp1[i][j][k]);
		}
       fscanf(fpr1,"\n");
      }
    } 
    fclose(fpr1);
   
   sprintf(filename,"saves_2/conc_%d.vtk",t);
  fpr2=fopen(filename,"r");   
  
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  fscanf(fpr2, "%*[^\n]\n");
  
  for(k=0;k<Nz;k++){
     for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++){
		fscanf(fpr2,"%lf\t", &comp2[i][j][k]);
		}
       fscanf(fpr2,"\n");
      }
    } 
    fclose(fpr2);
    
    sprintf(filename,"saves_3/conc_%d.vtk",t);
  fpr3=fopen(filename,"r");   
  
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  fscanf(fpr3, "%*[^\n]\n");
  
  for(k=0;k<Nz;k++){
     for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++){
		fscanf(fpr3,"%lf\t", &comp3[i][j][k]);
		}
       fscanf(fpr3,"\n");
      }
    } 
    fclose(fpr3);
    
   for(k=0;k<Nz;k++){ 
	  for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++){	
			comp1_tile[i][j][k] = comp1[i][j][k];
			comp2_tile[i][j][k] = comp2[i][j][k];
			comp3_tile[i][j][k] = comp3[i][j][k];
		}
			for(i=Nx;i<2*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-Nx][j][k];
			comp2_tile[i][j][k] = comp2[i-Nx][j][k];
			comp3_tile[i][j][k] = comp3[i-Nx][j][k];
		}
			for(i=2*Nx;i<3*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-2*Nx][j][k];
			comp2_tile[i][j][k] = comp2[i-2*Nx][j][k];
			comp3_tile[i][j][k] = comp3[i-2*Nx][j][k];
		}
	}
	  for(j=Ny;j<2*Ny;j++){
		for(i=0;i<Nx;i++){	
			comp1_tile[i][j][k] = comp1[i][j-Ny][k];
			comp2_tile[i][j][k] = comp2[i][j-Ny][k];
			comp3_tile[i][j][k] = comp3[i][j-Ny][k];
		}
		for(i=Nx;i<2*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-Nx][j-Ny][k];
			comp2_tile[i][j][k] = comp2[i-Nx][j-Ny][k];
			comp3_tile[i][j][k] = comp3[i-Nx][j-Ny][k];
		}
		for(i=2*Nx;i<3*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-2*Nx][j-Ny][k];
			comp2_tile[i][j][k] = comp2[i-2*Nx][j-Ny][k];
			comp3_tile[i][j][k] = comp3[i-2*Nx][j-Ny][k];
		}
	}
	  for(j=2*Ny;j<3*Ny;j++){
		for(i=0;i<Nx;i++){	
			comp1_tile[i][j][k] = comp1[i][j-2*Ny][k];
			comp2_tile[i][j][k] = comp2[i][j-2*Ny][k];
			comp3_tile[i][j][k] = comp3[i][j-2*Ny][k];
		}
		for(i=Nx;i<2*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-Nx][j-2*Ny][k];
			comp2_tile[i][j][k] = comp2[i-Nx][j-2*Ny][k];
			comp3_tile[i][j][k] = comp3[i-Nx][j-2*Ny][k];
		}		  
		for(i=2*Nx;i<3*Nx;i++){	
			comp1_tile[i][j][k] = comp1[i-2*Nx][j-2*Ny][k];
			comp2_tile[i][j][k] = comp2[i-2*Nx][j-2*Ny][k];
			comp3_tile[i][j][k] = comp3[i-2*Nx][j-2*Ny][k];
		}
	}
} 
    
    sprintf(filename, "saves_1/conc_tile_%d.vtk",t);
     fpw3 = fopen(filename,"w");
     fprintf(fpw3,"# vtk DataFile Version 2.0\n");
     fprintf(fpw3, "Volume example\n");
     fprintf(fpw3, "ASCII\n");
     fprintf(fpw3, "DATASET STRUCTURED_POINTS\n");
     fprintf(fpw3, "DIMENSIONS %d %d %d\n", Nx_tile,Ny_tile,Nz);
     fprintf(fpw3, "ORIGIN %d %d %d\n", 0,0,0);
     fprintf(fpw3, "SPACING %d %d %d\n", 1,1,1);
     fprintf(fpw3, "POINT_DATA %d\n", ((Nx_tile)*(Ny_tile)*(Nz)));
     fprintf(fpw3,"SCALARS CONC float 1\n");
     fprintf(fpw3, "LOOKUP_TABLE default\n");
    for(k=0;k<Nz;k++){
     for(j=0;j<Ny_tile;j++){
      for(i=0;i<Nx_tile;i++){
       fprintf(fpw3,"%lf\t", comp1_tile[i][j][k]);
      }
       fprintf(fpw3,"\n");
      }
    } 
    fclose(fpw3);  
    
    		    /*Output in vtk format for Paraview*/
    
    sprintf(filename, "saves_2/conc_tile_%d.vtk",t);
     fpw4 = fopen(filename,"w");
     fprintf(fpw4,"# vtk DataFile Version 2.0\n");
     fprintf(fpw4, "Volume example\n");
     fprintf(fpw4, "ASCII\n");
     fprintf(fpw4, "DATASET STRUCTURED_POINTS\n");
     fprintf(fpw4, "DIMENSIONS %d %d %d\n",Nx_tile,Ny_tile,Nz);
     fprintf(fpw4, "ORIGIN %d %d %d\n", 0,0,0);
     fprintf(fpw4, "SPACING %d %d %d\n", 1,1,1);
     fprintf(fpw4, "POINT_DATA %d\n", ((Nx_tile)*(Ny_tile)*(Nz)));
     fprintf(fpw4,"SCALARS CONC float 1\n");
     fprintf(fpw4, "LOOKUP_TABLE default\n");
    for(k=0;k<Nz;k++){
     for(j=0;j<Ny_tile;j++){
      for(i=0;i<Nx_tile;i++){
       fprintf(fpw4,"%lf\t", comp2_tile[i][j][k]);
      }
       fprintf(fpw4,"\n");
      }
    } 
    fclose(fpw4);
        
     		    /*Output in vtk format for Paraview*/
    
    sprintf(filename, "saves_3/conc_tile_%d.vtk",t);
     fpw5 = fopen(filename,"w");
     fprintf(fpw5,"# vtk DataFile Version 2.0\n");
     fprintf(fpw5, "Volume example\n");
     fprintf(fpw5, "ASCII\n");
     fprintf(fpw5, "DATASET STRUCTURED_POINTS\n");
     fprintf(fpw5, "DIMENSIONS %d %d %d\n", Nx_tile,Ny_tile,Nz);
     fprintf(fpw5, "ORIGIN %d %d %d\n", 0,0,0);
     fprintf(fpw5, "SPACING %d %d %d\n", 1,1,1);
     fprintf(fpw5, "POINT_DATA %d\n", ((Nx_tile)*(Ny_tile)*(Nz)));
     fprintf(fpw5,"SCALARS CONC float 1\n");
     fprintf(fpw5, "LOOKUP_TABLE default\n");
    for(k=0;k<Nz;k++){
     for(j=0;j<Ny_tile;j++){
      for(i=0;i<Nx_tile;i++){
       fprintf(fpw5,"%lf\t", comp3_tile[i][j][k]);
      }
       fprintf(fpw5,"\n");
      }
    } 
 
  t += time_skip;
 /* if(t%no_of_iter==0){
  Nz++;
	} */
	
	printf("%s\t%d\n", dim,Nz);
  }while(t<=final_time);
    
    for(i=0;i<Nx;i++){
  for(j=0;j<Ny;j++){
	  free(comp[i][j]);
	  free(comp1[i][j]);
	  free(comp2[i][j]);
	  free(comp3[i][j]);
  }
  free(comp[i]);
    free(comp1[i]);
  free(comp2[i]);
  free(comp3[i]);
}
free(comp);
free(comp1);
free(comp2);
free(comp3);

    for(i=0;i<Nx_tile;i++){
  for(j=0;j<Ny_tile;j++){
	  
	  free(comp1_tile[i][j]);
	  free(comp2_tile[i][j]);
	  free(comp3_tile[i][j]);
  }
 
    free(comp1_tile[i]);
  free(comp2_tile[i]);
  free(comp3_tile[i]);
}

free(comp1_tile);
free(comp2_tile);
free(comp3_tile);

    
   }
