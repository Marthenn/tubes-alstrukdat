#ifndef COMMANDS_H
#define COMMANDS_H

/* ADT */
#include "../../adt/map/map.h"
#include "../../adt/simulator/simulator.h"
#include "../../adt/stack/stack.h"
#include "../../adt/waktu/waktu.h"
#include "../../adt/map/map.h"

/* APP */
#include "../filereader/filereader.h"
#include "../display/display.h"

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
void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* ingredients, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods, Stack *undoRecord, Stack *redoRecord);

/**
 * @brief Go into the buy submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param recipes List of recipes available
 * @param map The map of the simulator
 * @param ingredients set of needed ingredients for all foods
 * @param buyFoods List of foods that can be get from buying
 * @param undoRecord Stack of action that is done
 * @param redoRecord Stack of action that is undone
 * 
 */
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType buyFoods, Stack *undoRecord, boolean *success);

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
void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType mixFoods, Stack *undoRecord, boolean *success);

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
void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType chopFoods, Stack *undoRecord, boolean *success);

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
void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType fryFoods, Stack *undoRecord, boolean *success);

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
void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType boilFoods, Stack *undoRecord, boolean *success);

/**
 * @brief Go into the kulkas submenu if possible
 * 
 * @param simulator Current simulator
 * @param foods List of foods available
 * @param map The map of the simulator
 * @param success 
 */
void Kulkas(Simulator* simulator, ListStatik foods, Map map, boolean *success);

/**
 * @brief Check if the food can be put into the kulkas at specific coordinate
 * 
 * @param sim Current simulator
 * @param food The food to be put
 * @param X Horizontal Coordinate
 * @param Y Vertical Coordinate
 * @param rotated Is the food rotated 90 degree
 * @return boolean 
 */
boolean CheckSizeKulkas(Simulator sim, Makanan food, int X, int Y, boolean rotated);

/**
 * @brief move simulator
 * 
 * @param simulator Current simulator
 * @param map The map of the simulator
 * @param undoRecord Stack of action that is done
 * @param moveCode Code for whether moving east, west, north, or south
 * 
 */

void Move(Simulator *simulator, Map *map, int moveCode, ListStatik foods, boolean *success);

void resetState(Simulator* simulator, Record record, Map *map, ListStatik foods);

void Undo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map, ListStatik foods);

void Redo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map, ListStatik foods);

void GetListChanges(Simulator *simulator, ListDinElType *addChanges, ListDinElType *delChanges, ListDinElType prevListRef, ListDinElType currentListRef);

void GetQueueChanges(PrioQueue *addChanges, PrioQueue *delChanges, PrioQueue prevQueue, PrioQueue currentQueue);

void UpdateStack(Simulator *simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *stack, Waktu timeRecord, Point locRecord, ListDinElType kulkasRecord);

void UpdateInverse(Simulator *simulator, Record inverseRecord, Stack *stack, Waktu timeRecord, Point locRecord);
#endif