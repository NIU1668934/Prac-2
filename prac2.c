#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5



float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];
float V5[N];
float V6[N];
float V7[N];


void InitData(){
int i,j;
srand(8824553);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}





//EXERICICI 1
void PrintVect(float vect[N], int a, int b ){
int i;
i=0;
for( i = 0; i < b; i++ ){
printf ("%f\n", vect[i+a]);
}
}



//EXERICICI 2

void PrintRow( float mat[N][N], int c, int a, int b ){
int i,j;
for( i = 0; i < b; i++ ){
printf ("%f\n", mat[i+a][c]);
}
}


//EXERICICI 3

void MultEscalar( float vect[N], float vectres[N], float alfa ){
int i;
for(i=0;i<N;i++){
V4[i]=V1[i]*alfa;
printf ("%f\n", V4[i]);
}
}


//EXERICICI 4

float Scalar( float vect1[N], float vqct2[N] ){
int i;
for(i=0;i<N;i++){
printf ("%f\n", V1[i]*V3[i]);
}
}


//EXERICICI 5
float Magnitude( float vect[N] ){
int i,a,b,mag;
a=V1[0]*V1[0];
b=V1[1]*V1[1];
mag= (a+b);
printf ("%lf\n", sqrt(mag));
return(0);
}


//EXERICICI 6*************************
int Ortogonal( float vect[N] ){
int suma,i;
for(i=0;i<N;i++){
suma=suma+(vect[i]);
}
}



//MAIN
int main(){
InitData();
int a,b,c;
printf("row: ");
scanf("%d", &c);
printf("from: ");
scanf("%d", &a);
printf("numel: ");
scanf("%d", &b);
PrintVect(V1,a,b);
printf ("---------------\n");
PrintRow(Mat,c,a,b);
printf ("---------------\n");
MultEscalar(V1,V4,2.0);
printf ("---------------\n");
Scalar(V1,V3);
printf ("---------------\n");
Magnitude(V1);

}