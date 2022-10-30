#ifndef DISPLAY_H
#define DISPLAY_H

#include "parser.h"

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
 * @param map 
 */
void BuyMenu(ListStatik foods, ListStatik recipes);

#endif