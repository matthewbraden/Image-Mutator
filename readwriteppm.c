#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"
#include <time.h>
#include <assert.h>

PPM_IMAGE *read_ppm(const char *file_name){
  FILE *fp = fopen (file_name,"r");
  PPM_IMAGE *image = (PPM_IMAGE*)malloc(sizeof(PPM_IMAGE));
  char character[4];
  int i, j;
  image->data = (PIXEL*)malloc(image->height * image->width * sizeof(PIXEL));
  fscanf(fp, "%c%c", &character[0], &character[1]);
  fscanf(fp, "%d %d\n", &(image->width), &(image->height));
  fscanf(fp, "%d\n", &(image->max_color));
  for (i = 0; i < image->height; i++){
    for (j = 0; j < image->width; j++){
      fscanf(fp, "%c %c %c ", &((image->data + image->width*i +j)->r), &((image->data + image->width*i +j)->g), &((image->data + image->width*i +j)->b));
    }
  }
  fclose (fp);
  return image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){
  FILE *fp = fopen(file_name,"w");
  int i, j;
  fprintf(fp, "P3\n");
  fprintf(fp, "%d %d\n", image->width, image->height);
  fprintf(fp, "%d\n", image->max_color);
  for (i = 0; i < image->height; i++){
    for (j = 0; j < image->width; j++){
      fprintf(fp, "%c %c %c ", ((image->data + image->width*i +j)->r), ((image->data + image->width*i +j)->g), ((image->data + image->width*i +j)->b));
    }
    if(fprintf(fp, "\n") != 1){
    }
  }
  fclose (fp);
}
