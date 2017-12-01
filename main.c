#include "imagem.h"

int main(int argc, char *argv[])
{
	int i,j,th,decrementation;

	FILE *file;
	file = fopen(argv[2],"w");
	if (file == NULL)
	printf("fail"); 

	Imagem *img2,*img3,*img;
	Imagem *aux = rimg(argv[1]);
	Grey(aux);
	img2 = gauss_filter(aux,7);
	img3 = Sobel(img2);
	fimg (img2); 
	img = gauss_filter(img3,3);
	printf("Choose otsu decrementation value: ");
	scanf(" %d",&decrementation);
	th = Otsu(img)-decrementation;
	binarization(img,th);
	printf("Começando a transformada\n"); 
	Circle **Hough = HTransform(img); 
	fimg (img); 
	printf("\nIndo pra segunda transformada\n");
	Eye *Olho = calloc(1,sizeof *Olho);
	Eye_fill(Olho,Hough[0]);
	int *xy = Limits(Olho);
	Imagem *img4 = rimg(argv[1]);     
	StripImage(img4,xy);
	Grey(img4);
	cimg (img4);
	fimg(img4);
	img4 = rimg(argv[1]);
	printf("Filling eye\n"); 
	Eye_fill(Olho,Hough[0]);
	printf("Reddening Eye\n"); 
	red_fill(Olho,img4);
	printf("Image Complete, proceeding to write\n"); 
	wimg(file,img4); 
	free(Olho);
	fimg(img4); 
	fclose(file); 
	return 0;
}
