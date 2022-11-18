#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512



float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];
float V5[N]; 
float V6[N];

//Practica 2 Mouad El Messaouri i Pau Vidal

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





//EXERICICI 1 Funció que mostri per pantalla un cert nombre d’elements (numel) d’un vector a partir d’una posició donada (from)
void PrintVect(float vect[N], int a, int b ){
int i;
for( i = 0; i < b; i++ ){
printf ("%f\n", vect[i+a]);
}
}



//EXERICICI 2  Funció que mostri per pantalla un cert nombre d’elements (numel) d’una fila (row)d’una matriu a partir d’una posició donada (from).

void PrintRow( float mat[N][N], int c, int a, int b ){
int i;
for( i = 0; i < b; i++ ){
printf ("%f\n", mat[c][i+a]);
}
}


//EXERICICI 3 Calculaa la multiplicació d’un escalar per un vector

void MultEscalar( float vect[N], float vectres[N], float alfa ){
int i;
for(i=0;i<N;i++){
vectres[i]=vect[i]*alfa;
}
}


//EXERICICI 4 Calculaa el producte escalar (o punt) de dos vectors.

float Scalar( float vect1[N], float vect2[N] ){
	float scalar = 0.0;
	for (int i=0; i<N; i++)
	scalar+=vect1[i]*vect2[i];
	
	return scalar;
;
}



//EXERICICI 5 Calcula la magnitud d’un vector.
float Magnitude( float vect[N] ){
int i,a,b;
float mag;

for (int i=0; i<N; i++){
	mag+=(vect[i]*vect[i]);
}
	return mag;
}

//EXERICICI 6 Determina si dos vectors són ortogonals.
int Ortogonal( float vect[N], float vect2[N] ){
float suma;
suma=Scalar(vect, vect2);
if ( suma == 0.0){
		return 1;
}
	else{
		return 0;
}
}
//EXERCICI 7 Calcula el vector projecció d’un vector sobre un altre.
void Projection( float vect1[N], float vect2[N], float vectres[N]){
MultEscalar(vect2,  vectres, (Scalar(vect1, vect2) / (Magnitude(vect2))));
}

//EXERCICI 8 Calcula la Infini-norma d’una matriu.
float Infininorm( float M[N][N] ){
int i,j;
float max;
max=0.0;
for(i=0;i<N;i++){
float suma=0.0;
  for(j=0;j<N;j++){
  suma+=fabs(M[i][j]);
  if (suma>max);
  max=suma;
}
}
return max;
}

//EXERCICI 9 Calcula la norma-ú d’una matriu.
float Onenorm( float M[N][N] ){
int i,j;
float max;
max=0.0;
for(j=0;j<N;j++){
float suma=0.0;
  for(i=0;i<N;i++){
  suma+=fabs(M[i][j]);
  if (suma>max);
  max=suma;
}
}
return max;
}



//EXERCICI 10 Calcula la norma de Frobenius d’una matriu.
float NormFrobenius( float M[N][N] ){
float sum = 0.0;
float res;
int i,j;
for (i = 0; i < N; i++){
for (j = 0; j < N; j++){
sum += pow(M[i][j], 2);
}
}
res = sqrt(sum);
return res;
}

//EXERCICI 11 Determina si una matriu és o no Diagonal Dominant.
int DiagonalDom( float M[N][N] ){
int i,j;
float suma=0.0;
for (i=0;i<N;i++){
for (j=0;i<N;i++)
if (i!=j);
suma += fabs(M[i][j]);

if (fabs(M[i][i]<suma)){
return 0;
}
else{
return 1;
}
}
}

int main(){
InitData();

//A
printf("\n\nA: \n");
printf("\n0-9 V1: \n");
PrintVect(V1,0,10);
printf("\n0-9 V2: \n");
PrintVect(V2,0,10);
printf("\n0-9 V3: \n");
PrintVect(V3,0,10);

printf("\n256-265 V1: \n");
PrintVect(V1,256,10);
printf("\n256-265 V2: \n");
PrintVect(V2,256,10);
printf("\n256-265 V3: \n");
PrintVect(V3,256,10);

printf("\n\n0-9 fila 0 de MatDD: \n");
PrintRow(MatDD,0,0,10);
printf("\n90-99 fila 100 de MatDD: \n");
PrintRow(MatDD,100,90,10);

//B
printf("\n\nB: \n");
printf("\n\nInfini-norma de la matriu Mat: ");
float res1B;
res1B = Infininorm(Mat);
printf("%f", res1B);
printf("\nNorma-u de la matriu Mat: ");
float res2B;
res2B = Onenorm(Mat);
printf("%f", res2B);
printf("\nNorma de Frobenius de la matriu Mat: ");
float res3B;
res3B = NormFrobenius (Mat);
printf("%f", res3B);
printf("\nLa matriu Mat es diagonal dominant? (0=no, 1=si) ");
int res4B;
res4B = DiagonalDom(Mat);
printf("%d", res4B);

printf("\n\nInfini-norma de la matriu MatDD: ");
float res5B;
res5B = Infininorm(MatDD);
printf("%f", res5B);
printf("\nNorma-u de la matriu MatDD: ");
float res6B;
res6B = Onenorm(MatDD);
printf("%f", res6B);
printf("\nNorma de Frobenius de la matriu MatDD: ");
float res7B;
res7B = NormFrobenius (MatDD);
printf("%f", res7B);
printf("\nLa matriu MatDD es diagonal dominant? (0=no, 1=si) ");
int res8B;
res8B = DiagonalDom(MatDD);
printf("%d", res8B);

//C
printf("\n\nC: \n");
printf("\nV1xV2: ");
float res1c;
res1c=Scalar(V1,V2);
printf("%f",res1c);
printf("\nV1xV3: ");
float res2c;
res2c=Scalar(V1,V3);
printf("%f",res2c);
printf("\nV2xV3: ");
float res3c;
res3c=Scalar(V2,V3);
printf("%f",res3c);

//D
printf("\n\nD: \n");
printf("\nV1: ");
float res1d;
res1d=Magnitude(V1);
printf("%f",res1d);
printf("\nV2: ");
float res2d;
res2d=Magnitude(V2);
printf("%f",res2d);
printf("\nV3: ");
float res3d;
res3d=Magnitude(V3);
printf("%f",res3d);

//E
printf("\n\nE: \n");
printf("\nOrtogonals V1 i V2? (0=no, 1=si): ");
int res1e;
res1e=Ortogonal(V1,V2);
printf("%d", res1e);
printf("\nOrtogonals V1 i V3? (0=no, 1=si): ");
int res2e;
res2e=Ortogonal(V1,V3);
printf("%d", res2e);
printf("\nOrtogonals V2 i V3? (0=no, 1=si): ");
int res3e;
res3e=Ortogonal(V2,V3);
printf("%d", res3e);

//F
printf("\n\nF: \n");
MultEscalar(V3,V4,2);
printf("\n\n0-9 del vector resultant: \n");
PrintVect(V4,0,10);
printf("\n256-265 del vector resultant: \n");
PrintVect(V4,256,10);

//G
printf("\n\nG: \n");
printf("\n\nV2 sobre V3: \n");
Projection(V2,V3,V5);
PrintVect(V5,0,10);
printf("\nV1 sobre V2: \n");
Projection(V1,V2,V6);
PrintVect(V6,0,10);

return 0;
}