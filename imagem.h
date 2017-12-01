#ifndef Imagem_h
#define Imagem_h


#ifndef libs_h
#define libs_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#endif

#define ushort unsigned short
#define uchar unsigned char
//Define a struct das cores, com 3 inteiros unsigned
typedef struct{
	unsigned char r,g,b;
}Pixel;
//Define a struct para os pixels
typedef struct {
	Pixel **p;
	int width,height,max;
	char header[2];
	int histogram[256]; 
}Imagem;

typedef struct{
  int a,b,r;
}Circle;
typedef struct{
  ushort x[361] ;
  ushort y[361] ;
}Eye;

void AccumCircle(Circle *Circulo,int a,int b, int r);

void cimg (Imagem *img);

void red_fill(Eye *Olho,Imagem *img);

void Eye_fill(Eye *Olho,Circle *Circulo);

double *preCalcCos();

double *preCalcSin(); 

char *stripFilepath(char *filepath);

char *outFilepath(char *folder, char *filename, char *toCat, char *format);

Imagem *rimg(char * name); //Função de leitura
Imagem *rpbm(char * name);
void Grey(Imagem *Foto); //Função para transformar em tons de cinza

Imagem *gauss_filter(Imagem *Foto,unsigned int repeats); //Função para o filtro de gauss
             // repeats definem a quantidade de vezes que o filtro será aplicado. iteraçoes = repeats+1

Imagem *Sobel (Imagem *Foto);

int Otsu(Imagem *img); // Func de threshold por histogram

void binarization(Imagem *img,unsigned int th); // Conversão para pbm antes da wpbm

void wimg(FILE  *file, Imagem *img);//Função de escrita

void wpbm(FILE *file,Imagem *img); // Escrita em pbm 

Circle **HTransform(Imagem *img); 

Circle **AllocateCircles(int amount);

Eye **AllocateEye(int amount);

int *Limits(Eye *Olho);

void StripImage(Imagem *img,int *xy);

unsigned int ***CreateAcumulator(int height,int width, int radius);

void fimg (Imagem *read);

void fACCU (unsigned int ***accu,int h,int w); // free acumulator
#endif
