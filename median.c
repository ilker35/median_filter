//*****Erol İlker ILGÜN 220206063
//*****Ahmet Cihat Bozkurt 220206021

#include "img_pro.h"

void bubble_sort(int list[],int n);

unsigned char **median_filter(unsigned char **image, int NC, int NR,const int mask_size){

unsigned char **image_out;
int i,j,k,l,index,NC2,NR2;
index=0;
int fil=(mask_size*mask_size);				//filters index
int filter[fil];					//filter
int start;

if(mask_size==3)start=1;	//finding the starting point according to mask size
if(mask_size==5)start=2;
if(mask_size==7)start=3;

image_out=alloc_img(NC,NR);

     				 
for(i=start;i<NR-start;i++){			
		for(j=start;j<NC-start;j++){
			for(k=i-start;k<i+start+1;k++){		//filling mask
				for(l=j-start;l<j+start+1;l++){
				filter[index++]=image[k][l];
				
				}
			}index=0;
			bubble_sort(filter,fil);	//sort filter array
			image_out[i][j]=filter[fil/2+1];	//assign filters median value to the pixel
					
		}
	}


return(image_out);

}

void bubble_sort(int list[],int n){
int c,d,t;
for(c=0;c<(n-1);c++){
	for(d=0;d<n-c-1;d++){
	if(list[d]>list[d+1]){
	t=list[d];
	list[d]=list[d+1];
	list[d+1]=t;	
	}
	}
}
}
