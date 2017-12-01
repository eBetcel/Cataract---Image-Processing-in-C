#include "imagem.h"

Imagem *gauss_filter(Imagem *Foto,unsigned int repeats) 
{
	int filter[5][5] = {{2,4,5,4,2},{4,9,12,9,4},{5,12,15,12,5},{4,9,12,9,4},{2,4,5,4,2}};  	
	int aux = 0, div = 0,i,j,k,l;
	int g_aux;
	Imagem *Gauss;
	Gauss = malloc(sizeof  (Imagem));
	Gauss->p = malloc(Foto->height * sizeof(Pixel*));
	for (i = 0; i < Foto->height; ++i) 
	{
		Gauss->p[i] = malloc(Foto->width * sizeof(Pixel));	
	}
	strcpy(Gauss->header,Foto->header);
	Gauss->height = Foto->height;
	Gauss->width = Foto->width;
	Gauss->max = Foto->max;
	for (i = 0; i < Foto->height; ++i) 
	{
   
	 
 		for (j = 0; j < Foto->width; ++j) 
 		{
 			for (k = -2; k <= 2; ++k) 
 			{
 				for (l = -2; l <= 2; ++l) 
 				{
					if((i+k < 0) || (j+l < 0) || (i+k >= Foto->height || l+k >= Foto-> width ))
			   		{
						continue;
			  		}
	       		 		 
 					aux += Foto->p[i+k][j+l].r * filter[k+2][l+2];	
					div += filter[k+2][l+2];
 				}
 			}
			g_aux = aux/div;
			aux = 0;
			div = 0;
		
			Gauss->p[i][j].r = g_aux;
			Gauss->p[i][j].g = g_aux;
			Gauss->p[i][j].b = g_aux;
 		}
	}
 
	fimg(Foto);
	if(repeats == 0) 
		return Gauss;
	
	else if (repeats > 0) 
	{
		return gauss_filter(Gauss,--repeats); 
	} 
}
