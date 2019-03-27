//*****Erol İlker ILGÜN 220206063
//*****Ahmet Cihat Bozkurt 220206021

#include "img_pro.h"
#include "my_header.h"

int main(int argc,char **argv){

unsigned char **img;
unsigned char **img2;
unsigned char **temp;
const int mask_size=atoi(argv[1]);
const int iter=atoi(argv[2]);
int NC,NR,i;
char *pgm_file;

if(argc!=4){
  printf("\n Usage: median_app [mask size] [iteration number] [Image file (*.pgm)] \n");
  printf("\n E.g.   median_app 3 2 test.pgm \n");
  exit(-1); }


if(mask_size!=3 && mask_size!=5 && mask_size!=7) {printf("\n mask size should be 3, 5 or 7\n"); exit(0);} //check if entered values are valid


pgm_file=argv[3];

img=pgm_file_to_img(pgm_file,&NC,&NR);
img2=alloc_img(NC,NR);
temp=alloc_img(NC,NR);
temp=img;
printf("**********the following chart is to see how pixel values are changing on some  pixels**********\n");
for(i=0;i<iter;i++){
temp=median_filter(temp,NC,NR,mask_size);
for(int j=10;j<150;j+=30){
printf("%dth iteration pixel[%d][%d]=%u    ",i+1,j,j, temp[j][j]);}printf("\n");
}

img2=temp;
img_to_pgm_file(img2,"median_filtered.pgm", NC,NR);
show_pgm_file("median_filtered.pgm");

free_img(img);
return(1);
}
