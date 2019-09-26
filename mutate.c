#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "a4.h"

void mutate(Individual *individual , double rate){
  int height = individual->image.height;
  int width = individual->image.width;
  int n = height * width;
  int function = (int) (rate / (100 * n));
  int randP, randR, randG, randB;
  int i;
  for (i = 0; i <= function; i++){
    randP = rand() % 256;
    randR = rand() % 256;
    randG = rand() % 256;
    randB = rand() % 256;
    individual->image.data[randP].r = randR;
    individual->image.data[randP].g = randG;
    individual->image.data[randP].b = randB;
  }
}

void mutate_population(Individual *individual , int population_size , double rate){
  int index = (population_size / 4);
  int i;
  for (i = index; i <= population_size; i++){
    mutate(&individual[i], rate);
  }
}
