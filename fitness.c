#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "a4.h"
#include <time.h>
#include <assert.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  int i;
  double sum = 0;
  double final_sum = 0;
  for (i = 0; i < image_size; i++) {
    sum += ((A[i].r - B[i].r) * (A[i].r - B[i].r)) + ((A[i].g - B[i].g) * (A[i].g - B[i].g)) + ((A[i].b - B[i].b) * (A[i].b - B[i].b));
  }
  final_sum = sqrt(sum);
  return final_sum;
}


void comp_fitness_population(const PIXEL *image, Individual * individual , int population_size){
  int i;
  for (i = 0; i < population_size; i++) {
    individual[i].fitness = comp_distance(image, individual[i].image.data, individual[i].image.width * individual[i].image.height);
  }
}
