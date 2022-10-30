#ifndef COMMANDS_H
#define COMMANDS_H

/* ADT */
#include "../../adt/headers/liststatik.h"
#include "../../adt/headers/listdineltype.h"
#include "../../adt/headers/map.h"
#include "../../adt/headers/simulator.h"

/* APP */
#include "filereader.h"
#include "parser.h"

/**
 * @brief Load the config files to simulator
 * 
 * @param map
 * @param foods 
 * @param recipes 
 */
void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* BuyFoods, ListDinElType* MixFoods, ListDinElType* ChopFoods, ListDinElType* FryFoods, ListDinElType* BoilFoods);

/**
 * @brief Exit the simulator
 * 
 */
void Exit();

/**
 * @brief Go into the buy submenu if possible
 * 
 */
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods);

/**
 * @brief Go into the mix submenu if possible
 * 
 */
void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes);

/**
 * @brief Go into the chop submenu if possible
 * 
 */
void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes);

/**
 * @brief Go into the fry submenu if possible
 * 
 */
void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes);

/**
 * @brief Go into the boil submenu if possible
 * 
 */
void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes);

#endif