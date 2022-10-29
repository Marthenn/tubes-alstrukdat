#ifndef COMMANDS_H
#define COMMANDS_H

#include "filereader.h"
#include "parser.h"
#include "../../adt/headers/map.h"
#include "../../adt/headers/liststatik.h"

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

#endif