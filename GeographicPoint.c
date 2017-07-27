#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Funciones Declaradas
int fil;
int col;
int **matrix(void);
void n_aleatorios(int **matriz, int *a, int *b);
int radio(int **matriz, int x, int y);

//Main

void main(){

fil = 500;
col=744;

int i, j ,c = 0;

int x0, y0; //Numeros aleatorios

//define matriz de datos

int **matriz= matrix(); 

n_aleatorios(matriz, &x0, &y0);
c= radio(matriz, x0, y0);

printf("%d %d\n", x0, y0);
printf("%d\n", c);
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

int radio(int **matriz, int x, int y){

	int i;
	int r1;
	int r2;
	int r3;
	int r4;
	
for (i=1;i<500;i++)
{
	r1=i;
	if (matriz[x+i][y]==1)
	{
		break;
			
	}
}
	
for (i=1;i<500;i++)
{
	r2=i;
	if (matriz[x-i][y]==1)
	{
		break;
			
	}
}
	

for (i=1;i<500;i++)
{
	r3=i;
	if (matriz[x][y+i]==1)
	{
		break;
			
	}
}

for (i=1;i<500;i++)
{
	r4=i;
	if (matriz[x][y-i]==1)
	{
		break;
			
	}
}


int r;
r=0;
	
if (r1>r){

	r=r1;
}

if (r2>r){

	r=r2;
}

if (r3>r){

	r=r3;
}	

if (r4>r){

	r=r4;
}

return r;	
}


