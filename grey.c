#include "imagem.h"

void Grey(Imagem *Foto){
	int aux;
	for (int i = 0; i < Foto->height; ++i){
		for (int j = 0; j  < Foto->width; j++){
		 aux = (Foto->p[i][j].r * 0.3 + Foto->p[i][j].g * 0.59 + Foto->p[i][j].b * 0.11);
		 Foto->p[i][j].r = aux;
		 Foto->p[i][j].g = aux;
		 Foto->p[i][j].b = aux;
		}

	}

}
