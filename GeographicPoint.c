#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Funciones Declaradas
int fil;
int col;
int **matrix(void);
void n_aleatorios(int **matriz, int *a, int *b);
void numeros(int **matriz, int x0, int y0, int *a, int*b);
int radio(int **matriz, int x, int y);
int per_x (int x);
int per_y (int y);


//Main

void main(){

fil = 500;
col=744;

int i, j ,r0, r= 0;

int x0, y0; //Numeros aleatorios iniciales
int x, y;

//define matriz de datos

int **matriz= matrix(); 

n_aleatorios(matriz, &x0, &y0);

r0= radio(matriz, x0, y0);

numeros(matriz, x0, y0, &x, &y);

r= radio(matriz, x, y);

printf("%d\n", r);

}

//Lectura de datos

int **matrix(void){

	int i;
	int j;
	int **Matrix= malloc(fil*sizeof(int*));
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
	
	int num_fil=rand() % (fil);
	int num_col=rand() % (col);
	
	while(matriz[num_fil][num_col]==1)
	{
		num_fil=rand() % (fil);
		num_col=rand() % (col);	
	}
	
	j=num_fil;
	k=num_col;
	
	*a=j;
	*b=k;
}
void numeros(int **matriz, int x0, int y0, int *a, int*b){  

	srand(time(NULL));

	int j=*a;
	int k=*b;
	
	int num_fil= x0 + (rand() % (fil+50)-50);
	int num_col= y0 +(rand() % (col+50)-50);
	
	while(matriz[per_y(num_fil)][per_x(num_col)]==1)
	{
		num_fil=x0 + (rand() % (fil+50)-50);
		num_col=y0 +(rand() % (col+50)-50);	
	}
	
	j=num_fil;
	k=num_col;
	
	*a=j;
	*b=k;
}
int radio(int **matriz, int x, int y){

	int i;
	int a;
	int r1;
	int r2;
	int r3;
	int r4;
	
for (i=1;i<fil;i++)
{
	r1=i;

	if (matriz[per_y(y)][per_x(x+i)]==1)
	{
		break;
			
	}
}
	
for (i=1;i<fil;i++)
{
	r2=i;

	if (matriz[per_y(y)][per_x(x-i)]==1)
	{
		break;
			
	}
}
	

for (i=1;i<fil;i++)
{
	r3=i;

	if (matriz[per_y(y+i)][per_x(x)]==1)
	{
		break;
			
	}
}

for (i=1;i<fil;i++)
{
	r4=i;
	if (matriz[per_y(y-i)][per_x(x)]==1)
	{
		break;
			
	}
}

int r;
r=0;
	
if (r1>r){

	r=r1;
}

if (r2<r){

	r=r2;
}

if (r3<r){

	r=r3;
}	

if (r4<r){

	r=r4;
}

return r;	
}

int per_x (int x){

	int a=x;
	if (x>=col){
		a= x % col;}
	
	else if (x<0){
		a= x+col;}
	
return a;

}

int per_y (int y){	
	int a=y;
	if (y>fil){
		a= y % fil;}
	
	else if (y<0){
		a= y+fil;}
	
return a;
}

