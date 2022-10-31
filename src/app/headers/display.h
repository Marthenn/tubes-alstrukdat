#ifndef DISPLAY_H
#define DISPLAY_H

#include "parser.h"
#include "../../adt/headers/listdineltype.h"

/**
 * @brief Display a cat meowing splash scren
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

#endif