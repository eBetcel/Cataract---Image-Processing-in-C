#include "imagem.h"
void wimg(FILE *file,Imagem *img)
{
    int i, j;
//Imprime no arquivo o cabeçalho: header, largura, altura e pxl max
    fprintf(file,"%s\n%i %i\n%i\n",img->header,img->width,img->height,img->max);
//Imprime no arquivo os pixels
	for (i = 0; i < img->height; ++i)
	{
        	for (j = 0; j < img->width; ++j)
        	{
            		fprintf(file,"%d\n%d\n%d\n",img->p[i][j].r,img->p[i][j].g,img->p[i][j].b);
        	}
    	}
}

void wpbm(FILE *file, Imagem *img)
{
	int i, j;
//Imprime no arquivo o cabeçalho: header, largura, altura e pxl max
	fprintf(file,"%s\n%d %d\n","P1",img->width,img->height);
//Imprime no arquivo os pixels
	for (i = 0; i < img->height; ++i)
	{
        	for (j = 0; j < img->width; ++j)
        	{
        		fprintf(file,"%i\n",img->p[i][j].r);
        	}
    	}
}

void binarization(Imagem *img,unsigned int th)
{
	int i,j;
	for (i=0;i < img->height;i++)
	{
		for (j=0; j< img->width; j++)
		{ 
            		if(img->p[i][j].r < th  )
            		{
            			img->p[i][j].r = 1;  
            		} 
            
			else if (img->p[i][j].r >= th) 
            		{
            			img->p[i][j].r = 0;  
            		}
        	}
   	}       
}

void AccumCircle(Circle *Circulo,int a,int b, int r)
{
	Circulo->a = (int) a;
	Circulo->b = (int) b;
	Circulo->r = (int) r;
}

void Eye_fill(Eye *Olho,Circle *Circulo)  
{
	for (int i = 0; i <=360; ++i) 
 	{
		Olho->x[i]  = Circulo->a + Circulo->r * cos(i * M_PI/180);
		Olho->y[i]  = Circulo->b + Circulo->r * sin(i * M_PI/180);  
	}
}

int *Limits(Eye *Olho)
{
	int *xy,maxx = 0,minx = 100000,maxy = 0,miny = 1000000;
	xy = calloc(4,sizeof(int));
	for (int i = 0; i <= 360; ++i) 
	{
		if(Olho->x[i] > maxx)
			maxx = Olho->x[i];
		if(Olho->x[i] < minx)
			minx = Olho->x[i];
		if(Olho->y[i] > maxy)
			maxy = Olho->y[i];
		if(Olho->y[i] < miny)
			miny = Olho->y[i];
	}
	
	xy[0] = minx;
	xy[1] = maxx;
	xy[2] = miny;
	xy[3] = maxy;
	return xy;
}

void StripImage(Imagem *img,int *xy)
{
	double raio = (xy[2]-xy[3])/2;
	double cx = (xy[1]+xy[0])/2;
	double cy = (xy[2]+xy[3])/2;

	for (int i = 0; i < img->height; ++i) 
	{
		for (int j = 0; j < img->width; ++j) 
			{
			if((i-cy)*(i-cy) + (j-cx)*(j-cx) > raio*raio )
			{
				img->p[i][j].r = 0;
				img->p[i][j].g = 0;
				img->p[i][j].b = 0;
			}
 		}
	}
}

void red_fill(Eye *Olho,Imagem *img)
{
	for (int i = 0; i <=360; ++i) 
	{
		if((Olho->y[i] >= 0 && Olho->y[i] < img->height) && (Olho->x[i] >= 0 && Olho->x[i] < img->width)) 
		{
			img->p[Olho->y[i]][Olho->x[i]].r = 255;   	
			img->p[Olho->y[i]][Olho->x[i]].g = 10;   	
			img->p[Olho->y[i]][Olho->x[i]].b = 10;   	
		}
	}
}

double *preCalcSin()
{
	double *Sin = malloc(361 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
		Sin[i] = sin(i*M_PI/180) ; 
	}
	return(Sin); 
}

double *preCalcCos()
{
	double *Cos = malloc(361 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
		Cos[i] = cos(i*M_PI/180) ; 
	}
	return(Cos); 
}

Circle **AllocateCircles(int amount)
{
	Circle **Circulo = calloc(amount,sizeof(Circle*));
	for (int i = 0; i < amount; ++i) 
	{
		Circulo[i] = calloc(1,sizeof(Circle));	
	}
	
	return Circulo;
}

Eye **AllocateEye(int amount)
{
	Eye **olho = calloc(amount,sizeof(Eye*));
	for (int i = 0; i < amount; ++i) 
	{
		olho[i] = calloc(1,sizeof(Eye));	
	}
	return olho;
}

void fimg (Imagem *read)
{
	int i;
	for (i = 0; i < read->height; ++i)
	{
       		free(read->p[i]);
    	}
        free (read->p);
	free(read); 
}

void cimg (Imagem *img)
{
	int i, j, pcount = 0, ccount = 0;
	for (i=0;i<img->height;i++){
		for (j=0;j<img->width;j++){
			if (img->p[i][j].r != 0){
				pcount++;
				if (img->p[i][j].r < 160 && img->p[i][j].r > 80){
					ccount++;
				}
			}		
		}
	}

	float diag;

	diag = ccount*100/pcount;
	
	printf ("A pupila está %.2f%% comprometida\n", diag);
	if (diag > 40)
	{
		printf ("O paciente apresenta catarata\n");
	}
	else{
		printf ("O paciente nao apresenta catarata\n");
	}
}








