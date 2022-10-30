#ifndef COMMANDS_H
#define COMMANDS_H

#include "filereader.h"
#include "parser.h"
#include "../../adt/headers/map.h"
#include "../../adt/headers/liststatik.h"
#include "../../adt/headers/simulator.h"

/**
 * @brief Load the config files to simulator
 * 
 * @param map
 * @param foods 
 * @param recipes 
 */
void Start(Map* map, ListStatik* foods,  ListStatik* recipes, Word* name);

/**
 * @brief Exit the simulator
 * 
 */
void Exit();

/**
 * @brief Go into the buy submenu if possible
 * 
 */
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes);

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