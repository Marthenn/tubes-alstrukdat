/* File : filereader.h */

#ifndef __FILEREADER_H__
#define __FILEREADER_H__

// C libraries
#include <stdio.h>
// headers
#include "charmachine.h"
#include "wordmachine.h"

//implementation
#include "../implementasi/wordmachine.c"

#define FOOD_CONFIG_PATH ".../config/food_config.txt"
#define RECIPE_CONFIG_PATH ".../config/recipe_config.txt"
#define MAP_CONFIG_PATH ".../config/map_config.txt"

void ReadFoodConfig();
void ReadRecipeConfig();
void ReadMapConfig();
void ReadAllConfig();

#endif