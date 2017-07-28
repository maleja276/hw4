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

int i, j ,r0, r, rmax= 0;

int x0, y0; //Numeros aleatorios iniciales
int x, y, xmax, ymax;

//define matriz de datos

int **matriz= matrix(); 

n_aleatorios(matriz, &x0, &y0);

r0= radio(matriz, x0, y0);

rmax=r0;

xmax=x0;

ymax=y0;

double alfa;
float beta;
double a;
double b;
int pasos;
int r_def;
int x_def;
int y_def;
r_def=r0;

FILE *datos;

datos=fopen("datos.txt", "w+");


//numeros(matriz, x0, y0, &x, &y);

//r= radio(matriz, x, y);

//radio(matriz, x, y);

srand( time( NULL ) );
pasos=25;
for(i=0; i<150; i++)
{
	
	
	x= xmax +(rand() % (pasos+pasos)-pasos);
	y= ymax +(rand() % (pasos+pasos)-pasos);
	
	while(matriz[per_x(x)][per_y(y)]==1)
	{
		x=xmax + (rand() % (pasos+pasos)-pasos);
		y=ymax +(rand() % (pasos+pasos)-pasos);	
	}

	r = radio(matriz, x, y);
	a=r;
	b=rmax;
	
	if (rmax>r_def)
	{
		r_def=rmax;
		x_def=xmax;
		y_def=ymax;	
	}
	alfa=(a/b);

	if (a>b)
	{
		rmax=a;
		xmax=x;
		ymax=y;
			
	}
	
	

	else
	{	
		beta=drand48();
		if (beta<=alfa)
		{
			
				rmax=r;
				xmax=x;
				ymax=y; 
		}
	
		else
		{
			continue;		
		}
		
	}
	//printf("%d %d %d\n", rmax, xmax, ymax);
}

x_def=per_x(x_def);
y_def=per_y(y_def);

fprintf(datos,"%d %d %d\n", r_def, x_def, y_def);

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
	
	int num_fil= x0 + (rand() % (50+50)-50);
	int num_col= y0 +(rand() % (50+50)-50);
	
	while(matriz[per_x(num_fil)][per_y(num_col)]==1)
	{
		num_fil=x0 + (rand() % (50+50)-50);
		num_col=y0 +(rand() % (50+50)-50);	
	}
	
	j=num_fil;
	k=num_col;
	
	*a=j;
	*b=k;
}
int radio(int **matriz, int x, int y){

int end=0;
int r=0;
int i, j, k;

for (i=1; i<fil; i++){
	for (j=x-i; j<x+i; j++){
		for (k=y-i; k<y+i; k++){
			if (pow((pow(j-x,2)+pow(k-y,2)),0.5) <= i){
				if (matriz[per_x(j)][per_y(k)]==1){
					r=i;
					end=1;}
				}
				if (end==1){
					break;}
				}
			if(end==1){
				break;}
			}
		if(end==1){
			break;}
		}
return r;		
}

int per_x (int x){

	int a=x;
	if (x>=fil){
		a= x % fil;}
	
	else if (x<0){
		a= x+fil;}
	
return a;

}

int per_y (int y){
	
	int a=y;

	if (y>=col){
		a= y % col;}
	
	else if (y<0){
		a= y+col;}
	
return a;
}

