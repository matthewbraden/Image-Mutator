#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"
#include <time.h>
#include <assert.h>

PIXEL *generate_random_image(int width, int height, int max_color){
  srand(time(NULL));
  PIXEL *data = (PIXEL*)malloc(sizeof(PIXEL));
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++){
      (data + width * j + i)->r = rand() % max_color + 1;
      (data + width * j + i)->g = rand() % max_color + 1;
      (data + width * j + i)->b = rand() % max_color + 1;
    }
  }
  return data;
}

Individual *generate_population(int population_size, int width, int height , int max_color){
  PPM_IMAGE *image = (PPM_IMAGE*)malloc(sizeof(PPM_IMAGE));
  Individual *individual = (Individual*)malloc(sizeof(Individual));
  int i = 0;

  while (i < population_size){
    image->width = width;
    image->height = height;
    image->max_color = max_color;
    image->data = generate_random_image(width, height, max_color);
    individual->image = *image;
    individual[i] = *individual;
    *image = image[i];
    i++;
  }
  free (individual);
  free (image);
  return individual;
}
