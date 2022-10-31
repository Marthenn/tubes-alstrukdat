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
#include "display.h"

/**
 * @brief Load the config files to simulator
 * 
 * @param simulator Simulator to be loaded
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param BuyFoods List of foods that can be get from buying
 * @param MixFoods List of foods that can be get from mixing
 * @param ChopFoods List of foods that can be get from chopping
 * @param FryFoods List of foods that can be get from frying
 * @param BoilFoods List of foods that can be get from boiling
 * 
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
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param BuyFoods List of foods that can be get from buying
 * @param delivery The delivery status of the simulator
 * 
 */
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods, PrioQueue *delivery);

/**
 * @brief Go into the mix submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param MixFoods List of foods that can be get from mixing
 * 
 */
void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType MixFoods);

/**
 * @brief Go into the chop submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param ChopFoods List of foods that can be get from chopping
 * 
 */
void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType ChopFoods);

/**
 * @brief Go into the fry submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param FryFoods List of foods that can be get from frying
 * 
 */
void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType FryFoods);

/**
 * @brief Go into the boil submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param BoilFoods List of foods that can be get from boiling
 * 
 */
void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BoilFoods);

#endif