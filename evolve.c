#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"
#include <time.h>
#include <assert.h>

/*This comnpare function is fount through the website address
https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm*/
int cmpfunc (const void * a, const void * b) {
 return ( *(int*)a - *(int*)b );
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations , int population_size , double rate){

  Individual *new_population = generate_population(population_size, image->width, image->height, image->max_color);

  comp_fitness_population(image->data, new_population, population_size);
  qsort(new_population, population_size, sizeof(Individual), cmpfunc);
  int i = 1;
  while (i < num_generations){
    crossover(new_population, population_size);
    mutate_population(new_population, population_size - 1, rate);
    comp_fitness_population(image->data, new_population, population_size);
    qsort(new_population, population_size, sizeof(Individual), cmpfunc);
    i++;
  }

  PPM_IMAGE *image2 = (PPM_IMAGE*)malloc(sizeof(PPM_IMAGE));
  image2->data = new_population[0].image.data;
  image2->width = new_population[0].image.width;
  image2->height = new_population[0].image.height;
  image2->max_color = new_population[0].image.max_color;
  i = population_size - 1;
  while (i >= 1){
    free_image(&((new_population+i)->image));
    i--;
  }
  free (new_population);
  return image2;
}

void free_image(PPM_IMAGE *p){
  free(p->data);
}
