#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){

FILE *datos;

int fil = 500;
int col=744;
int i, j = 0;

int **matriz= malloc(fil*col*sizeof(float)); 

datos = fopen("map_data.txt", "r");

for (i=0; i<fil;i++){
	matriz[i]=malloc(744*sizeof(int));
	}


for (i=0; i<fil;i++){
	for (j=0;j<col;j++)
		fscanf(datos, "%d", &matriz[i][j]);
}

for (i=0; i<fil;i++){
	for (j=0;j<col;j++)
		printf("%d\n", matriz[i][j]);
}

}








