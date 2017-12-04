#include "imagem.h"
//Recebe o arquivo de entrada
Imagem *rimg(char * name){

    int i = 0, j = 0;
    Imagem *read;
    read = malloc(sizeof *read); 
    char dump[100];

    FILE *file;
	//Abre o arquivo de entrada com permissão de leitura
	file = fopen(name, "r");
//Teste de leitura
	if (file == NULL){
       		printf("Falha ao abrir arquivo");
	}

	else{
        	fscanf(file,"%s",read->header);
	//Verifica se o header é o P3 (ASCII)
        if(strcmp(read->header, "P3")){
        printf("Header incorreto");
        }
	
        else{
		//Ignora o header para leitura dos valores
		fgets(dump,sizeof dump-1,file);
		fgets(dump,sizeof dump-1,file);
		//Faz leitura da altura, largura e máximo de cores por pixel
		fscanf(file, "%d %d %d\n", &read->width, &read->height, &read->max);
		//Aloca dinamicamente a memória necessária para os ponteiros da struct de cores
		read->p = malloc(read->height * sizeof (Pixel*));
		//Aloca a memória para todos os pixels
		for (i = 0; i < read->height; ++i){
	                read->p[i] = malloc(read->width * sizeof (Pixel));
		}
		//Efetua a leitura das cores dos pixels e armazena na variável
		for (i = 0; i < read->height; ++i){
                	for (j = 0; j < read->width; ++j)
                	{
				int r,g,b;
                    		fscanf(file, "%i%i%i",&r, &g,&b);
                    		read->p[i][j].r = r;
		    		read->p[i][j].g = g;
		    		read->p[i][j].b = b;   
                	}
		}
            }
		//Fecha o arquivo 
        	fclose(file);
	}


    return read;
}  
//Recebe o arquivo de entrada
Imagem *rpbm(char * name)
{

    int i = 0, j = 0;
    Imagem *read;
    read = malloc(sizeof *read); 
    char dump[100];

    FILE *file;
//Abre o arquivo de entrada com permissão de leitura
    file = fopen(name, "r");
//Teste de leitura
    if (file == NULL){
        printf("Falha ao abrir arquivo");
    }

    else{
        fscanf(file,"%s",read->header);
//Verifica se o header é o P3 (ASCII)
        if(strcmp(read->header, "P1")){
        printf("Header incorreto");
        }
	
        else{
//Faz leitura da altura, largura e máximo de cores por pixel
            fscanf(file, "%d %d \n", &read->width, &read->height);
//Aloca dinamicamente a memória necessária para os ponteiros da struct de cores
            read->p = malloc(read->height * sizeof (Pixel*));
//Aloca a memória para todos os pixels
            for (i = 0; i < read->height; ++i){
                read->p[i] = malloc(read->width * sizeof (Pixel));
            }
//Efetua a leitura das cores dos pixels e armazena na variável
            for (i = 0; i < read->height; ++i){
                for (j = 0; j < read->width; ++j){
			int r,g,b;
                    fscanf(file, "%i",&r);
                    read->p[i][j].r = r;
                }
            }
//Fecha o arquivo aberto
            }
        fclose(file);
    }


    return read;
}  
