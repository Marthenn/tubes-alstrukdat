#ifndef DISPLAY_H
#define DISPLAY_H

#include "../parser/parser.h"
#include "../../adt/makanan/makanan.h"
#include "../../adt/listdineltype/listdineltype.h"
#include "../../adt/liststatik/liststatik.h"
#include "../../adt/prioqueue/prioqueue.h"

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
 * @param deliveryRecord Queue of foods in delivery
 */
void DisplayDelivery(ListStatik foods, PrioQueue deliveryRecord);

#endif