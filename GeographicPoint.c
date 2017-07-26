#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Funciones Declaradas
int fil;
int col;
int **matrix(void);
void n_aleatorios(int **matriz, int *a, int *b);

//Main

void main(){

fil = 500;
col=744;
int i, j ,c = 0;
int x, y;

int **matriz= matrix(); 
n_aleatorios(matriz, &x, &y);
printf("%d %d\n", x, y);
}

//Lectura de datos

int **matrix(void){

	int i;
	int j;
	int **Matrix= malloc(fil*col*sizeof(int));
	FILE *datos;

	datos = fopen("map_data.txt", "r");

	for (i=0; i<fil;i++){
	Matrix[i]=malloc(col*sizeof(int));
	}


	for (i=0; i<fil;i++){
		for (j=0;j<col;j++)
			fscanf(datos, "%d", &Matrix[i][j]);
	}
	
	fclose(datos);
	return Matrix;
}
 
//Numeros Aleatorios

void n_aleatorios(int **matriz, int *a, int *b){  

	srand(time(NULL));

	int j=*a;
	int k=*b;
	
	int num_fil=rand() % (500+1);
	int num_col=rand() % (744+1);
	
	while(matriz[num_fil][num_col]==1)
	{
		num_fil=rand() % (500+1);
		num_col=rand() % (744+1);	
	}
	
	j=num_fil;
	k=num_col;
	
	*a=j;
	*b=k;
}



