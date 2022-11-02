#include <stdio.h>
#include <stdlib.h>
#define N 10

float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];
float V5[N];
float V6[N];


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






void PrintVect(float vect[N], int a, int b ){
int i;
i=0;
while(a>=0 && i<b){
printf ("%f\n", vect[i+a]);
i=i+1;
}
}










void PrintRow( float mat[N][N], int c, int a, int b ){
int i;
i=0;
while(a>=0 && i<b){
printf ("%f\n", mat[i+a][i]);
i=i+1;
}
}












void MultEscalar( float vect[N], float vectres[N], float alfa ){
int i;
for(i=0;i<N;i++){
V4[i]=V1[i]*alfa;
printf ("%f\n", V4[i]);
}
}



float Scalar( float vect1[N], float vqct2[N] ){
int i;
for(i=0;i<N;i++){
V5[i]=V1[i]*V2[i];
printf ("%f\n", V5[i]);
}
}



float Magnitude( float vect[N] ){
int i;
for(i=0;i<N;i++){
V6[i]=V1[i]*V1[i];
printf ("%f\n", V6[i]);
}
}






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
MultEscalar(V1,V4,2.0);
printf ("---------------\n");
PrintRow(Mat,c,a,b);
printf ("---------------\n");
Scalar( V1, V2);
printf ("---------------\n");
Magnitude(V1);
}