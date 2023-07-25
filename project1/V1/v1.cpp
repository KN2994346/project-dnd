/* 
 * File:   v1.cpp
 * Author: knguyen
 * Purpose: Version 1 of text based simplified DnD game.
 * Base idea, planning program according to checklist and exploring possible future expansions.
 * Exploring random numbers and how to use random numbers.
 * Determining game mechanics, very light pseudo code.
 * Testing random number generation to check if boundary numbers 1 and 20 show up, and that no numbers less than 1 or greater than 20 are output.
 */
//sys lib
#include <iostream>
#include <fstream>   //File I/O
#include <iomanip>   //Format
#include <string>    //String
#include <cstdlib>   //Rand function
#include <ctime>     //Time to set random function seed
//cmath?

using namespace std;

//later add functions
//prototypes

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); //Seed rand with the current time
    
    //future: utilize functions, arrays
    //character creation switch menu, validate do while
    //enter character name
    //choose class fighter mage
        //Fighter 60 hp ac +2 con +3 str, 16 armor (limits dex) +2 attack proficiency
        //Wizard 30 hp ac +3 int +2 dex
    //choose stats from 5 point pool, modifiers of  to -5, hp 10 ac
        //con (1 pt = 5 hp) dex (1pt = 1 ac, not for fighter ) str (1pt = 1 attack dmg) int (1pt = 1 spell dmg) //future: wis cha modifiers
    //when done store character information in file
    
    //choose enemy. fight one enemy for now, //future: array choose enemies
        //ogre with fists 70 hp 15 ac 3 + 2d6 dmg per turn, 20 double special line, 1 dmg to self
    
    //fight mechanics
    //while isDead is false
    //display health percentage bar typecast output percent for loop ticks |||||||||||||....|
    //if hit, dmg ternary if 20 double, else if ternary 1 dmg to self
    //if 20 and dead special ending
    //! switch action, action proficiency bonus, about 5-15 dmg to enemy per turn, 5-10 turns
         /*
          * fighter +2 attack
          * 1d12 + str greatsword, longbow
          * 2d6 + str dual handaxe, dual scimitar
          * berserk double damage next three turns
          * 
          * wizard
          * 3d6 fireball wizard
          * 3d4 +2 magic missiles wizard
          * heal 2d6 + int
          * mage armor 18 ac next three turns
                * future: add more actions: if success then output special line(array of strings?) and then attack
                * observe weakness double dmg to next attack wis
                * distract opponent use one action for chance to attack twice cha
         */
    //end screen //future add replay
    
    //testing random dice roll, must use cstdlib and ctime
    int nsides = 20; //number of sides
    int result = 0; //store result
    for (int i = 1; i <= 20; i++) //loop 20 results, to test how rand works
    {
        cout << rand() << endl; //rand is a large number
        //calculate and store random result
        result = rand() % nsides +1; //%nsides because remainder is always between 0 and nsides-1, add one becuase starts at 0
        cout << result << endl; //output result
    }
    //exit
    return 0;
}