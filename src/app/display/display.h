#ifndef DISPLAY_H
#define DISPLAY_H

/* ADT */
#include "../../adt/makanan/makanan.h"
#include "../../adt/listdineltype/listdineltype.h"
#include "../../adt/liststatik/liststatik.h"
#include "../../adt/prioqueue/prioqueue.h"
#include "../../adt/simulator/simulator.h"

/* APP */
#include "../parser/parser.h"


/**
 * @brief Get the Makanan From Id identifier
 * 
 * @param foods List of foods available
 * @param id The id identifier
 * @return Makanan object from foods list
 */
Makanan GetMakananFromId(ListStatik foods, int id);

/**
 * @brief Display splash scren
 * 
 */
void SplashScreen();

/**
 * @brief Display the start scren with available commands
 * 
 */
void StartScreen();

/**
 * @brief Display the help screen
 * 
 */
void Help();

/**
 * @brief Demand the user to input a command
 * 
 */
void EnterCommand();

/**
 * @brief Display the buy menu
 * 
 * @param BuyFoods List of all the foods that can be get from buying
 */
void BuyMenu(ListDinElType BuyFoods);

/**
 * @brief Display the mix menu
 * 
 * @param MixFoods List of all the foods that can be get from mixing
 */
void MixMenu(ListDinElType MixFoods);

/**
 * @brief Display the chop menu
 * 
 * @param ChopFoods List of all the foods that can be get from chopping
 */
void ChopMenu(ListDinElType ChopFoods);

/**
 * @brief Display the fry menu
 * 
 * @param FryFoods List of all the foods that can be get from frying
 */
void FryMenu(ListDinElType FryFoods);

/**
 * @brief Display the boil menu
 * 
 * @param BoilFoods List of all the foods that can be get from boiling
 */
void BoilMenu(ListDinElType BoilFoods);

/**
 * @brief Display the cookbook menu
 * 
 * @param foods List of foods available
 * @param recipes list of all the recipes available
 * @param mixFoods list of all the foods that can be get from mixing
 * @param chopFoods list of all the foods that can be get from chopping
 * @param fryFoods list of all the foods that can be get from frying
 * @param boilFoods list of all the foods that can be get from boiling
 */
void CookBook(ListStatik foods, ListStatik recipes, ListDinElType mixFoods, ListDinElType chopFoods, ListDinElType fryFoods, ListDinElType boilFoods);

/**
 * @brief Go into the boil submenu if possible
 * 
 * @param foods List of foods available
 */
void Catalog(ListStatik foods);

/**
 * @brief Display the current status of foods in delivery
 * 
 * @param foods List of foods available
 * @param simulator The simulator object
 */
void DisplayDelivery(ListStatik foods, Simulator simulator);

/**
 * @brief Display the current inventory of the simulator
 * 
 * @param foods List of foods available
 * @param simulator The simulator object
 */
void DisplayInventory(ListStatik foods, Simulator simulator);

/**
 * @brief Display the current status of simulator's kulkas
 * 
 * @param foods List of foods available
 * @param simulator The simulator object
 */
void DisplayKulkas(ListStatik foods, Simulator simulator);

void DisplayNotif(Simulator simulator);

/**
 * @brief Get the union recipes set of food's descendants if it isn't exists in inventory. Return set of itself otherwise.
 * 
 * @param simulator The simulator object
 * @param now List of all foods
 * @param isChildRequired true if food requires its children
 */
Set getResepBertingkat(Simulator simulator, Tree food, boolean* isChildRequired);

/**
 * @brief Display recommended foods to the screen
 * 
 * @param simulator The simulator object
 * @param foods List of all foods
 * @param recipes List of all recipes
 */
void DisplayRekomendasi(Simulator simulator, ListStatik foods, ListStatik recipes);

#endif