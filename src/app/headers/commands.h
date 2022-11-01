#ifndef COMMANDS_H
#define COMMANDS_H

/* ADT */
#include "../../adt/headers/map.h"
#include "../../adt/headers/simulator.h"
#include "../../adt/headers/stack.h"

/* APP */
#include "filereader.h"
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
 * @param undoRecord Stack of action that is done
 * @param redoRecord Stack of action that is undone
 */
void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods,PrioQueue *delivery, Stack *undoRecord, Stack *redoRecord);

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
 * @param buyFoods List of foods that can be get from buying
 * @param delivery The delivery status of the simulator
 * @param undoRecord Stack of action that is done
 * @param redoRecord Stack of action that is undone
 * 
 */
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType buyFoods, PrioQueue *delivery, Stack *undoRecord);

/**
 * @brief Go into the mix submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param mixFoods List of foods that can be get from mixing
 * @param undoRecord Stack of action that is done
 * 
 */
void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType mixFoods, Stack *undoRecord);

/**
 * @brief Go into the chop submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param chopFoods List of foods that can be get from chopping
 * @param undoRecord Stack of action that is done
 * 
 */
void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType chopFoods, Stack *undoRecord);

/**
 * @brief Go into the fry submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param fryFoods List of foods that can be get from frying
 * @param undoRecord Stack of action that is done
 * 
 */
void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType fryFoods, Stack *undoRecord);

/**
 * @brief Go into the boil submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param boilFoods List of foods that can be get from boiling
 * @param undoRecord Stack of action that is done
 * 
 */
void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType boilFoods, Stack *undoRecord);

/**
 * @brief move simulator
 * 
 * @param simulator Current simulator
 * @param map The map of the simulator
 * @param undoRecord Stack of action that is done
 * @param moveCode Code for whether moving east, west, north, or south
 * 
 */

void Move(Simulator *simulator, Map *map, int moveCode);

void Undo (Simulator* simulator, PrioQueue delivery, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoRecord, Stack *redoRecord);

void Redo (Simulator* simulator, PrioQueue delivery, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack);

void GetQueueChanges(PrioQueue *addChanges, PrioQueue *delChanges, PrioQueue prevQueue, PrioQueue currentQueue);

void UpdateStack(Simulator simulator, PrioQueue delivery, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *stack);

void UpdateInverse(Simulator simulator, Record inverseRecord, Stack *stack);

void GetQueueChanges(PrioQueue *addChanges, PrioQueue *delChanges, PrioQueue prevQueue, PrioQueue currentQueue);
#endif