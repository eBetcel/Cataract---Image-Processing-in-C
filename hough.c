#include "imagem.h"
#define ARR(i,j,k) accu[i*w*accu_r+j*accu_r+k]  
Circle **HTransform(Imagem *img)
{ 
	int i,j,k,x,y,t,a,b,count = 0;
	int w = img->width, h = img->height;
	int th = 360;
	int mvalue[10],max[10][3];
 	mvalue[0] = 0;
	max[0][0] = 0;
 
	int rmax = sqrt(img->height*img->height+img->width*img->width)/4.0;
	int rmin = 70, accu_r = rmax-rmin+1, rfor = 0;
	unsigned int *accu = calloc(w*h*accu_r,sizeof(unsigned int)); 
	mvalue[0] = 0;
	Circle **Vec = AllocateCircles(10);
	memset(accu,0,h*w*accu_r); 
 
	double *sin = preCalcSin();
	double *cos = preCalcCos();  
	printf("Acumulador Inicializado com sucesso\n");
	for (y = 50; y < img->height-160; ++y){ 
		printf("Valor de y =  %d\n  ",y);	
		for (x = img->width/5; x < w - (w/5) ; ++x){
			if(img->p[y][x].r == 0){
      				for (rfor = rmin; rfor <= rmax; rfor = rfor +5){
     					for (t = 0; t <= th; t = t+15){
   	  					a = x - rfor * cos[t] ;
     						b = y - rfor *sin[t] ;	
          
	   					if((a >= 0 && a < img->height) && (b >= 0 && b < img->height)){ 
               						ARR(b,a,rfor-rmin)+= 1; 
							if(mvalue[0] < ARR(b,a,rfor-rmin)/* accu[b][a][rfor-rmin]*/){
		 						if(a < w/4 || b < 100)
			 						continue;
		 						if(count != 9)
		  						count++;		 
		       						if(count > 1);
		  						if(max[0][2] != rfor)
		 						{
			 						for(i = count; i > 0; --i){
		  	 							mvalue[i] = mvalue[i-1];
		  	 							max[i][0] = max[i-1][0];
		  	  							max[i][1] = max[i-1][1];
		  	  							max[i][2] = max[i-1][2];
			  						}	  
		 						}
		 	 
							 	mvalue[0] = ARR(b,a,rfor-rmin);
								max[0][0] = a;
								max[0][1] = b;
								max[0][2] = rfor;
		  
							}
         
            					}      
         				}	
       				}	 
      			}
   		}
 	}
	
	printf("\n%d\n",mvalue[0]);
	
	for (int i = 0; i <10; ++i) 
	{
		printf("%d %d %d\n",max[i][0],max[i][1],max[i][2]); 
	} 

	AccumCircle(Vec[0],max[0][0],max[0][1],max[0][2]);
	free(accu); 
	return Vec; 
}
