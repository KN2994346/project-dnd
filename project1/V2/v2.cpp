/* 
 * File:   v2.cpp
 * Author: knguyen
 * Purpose: Version 2 of text based simplified DnD game.
 * Outline logic with comments, pseudo code for character creation.
 * First struggle with do while loop logic for stat allocation.
 * Next is to determine logic for dice rolling mechanic.
 */
//sys lib
#include <iostream>
#include <fstream>   //File I/O
#include <iomanip>   //Format
#include <string>    //String
#include <cstdlib>   //Rand function
#include <ctime>     //Time to set random function seed
#include <cmath>     //For rounding capability

using namespace std;

//later add functions
//prototypes

int main(int argc, char** argv)
{
    //Seed rand with the current time
    srand(static_cast<unsigned int>(time(0)));
    
    //character creation menu
    
    //character name
    //variable to store character name
    //do
        //prompt input
        //store character name
        //output name
    //confirm name with do while y/n
    
    //choose class
    //variable to store class
    //do
        //prompt input, displaying info
            //choose 0 for fighter or 1 for wizard
            //0 Fighter 60 hp +2 con +3 str, +2 attack bonus, 16 armor (limits dex)
            //1 Wizard 30 hp +3 int +2 dex, able to heal and cast mage armor
        //do
            //store class
        //validate entry with if not 0 or 1 invalid and do while 0 or 1
    //confirm entry with do while y/n
 
    //set base stats based on class chosen
    //variables to store stats
        //if fighter 60 hp 16 ac +2 con +3 str +2 attack bonus
        //if wizard 30 hp 10 ac +3 int +2 dex
    
    //choose stats
    //variable to store point pool, stat choice, point allocation input, end bool
        //int point pool, point allocation, points remaining = pool
        //char choice
        //bool end
    //do
        //prompt input to assign points, displaying info
            //current hp, ac, stat bonuses, attack bonus, 5 points remaining
            //1 con (1 pt = +5 hp)
            //2 dex (1pt = +1 ac, if fighter display armor limitation)
            //3 str (if fighter display 1pt = 1 attack dmg)
            //4 int (if wizard display 1pt = 1 spell dmg)
        //do
            //store input char choice
            //select stat switch char
                //'1' con
                //'2' dex
                //'3' str
                //'4' int
                //'x' exit
                //default invalid retry
        //validate entry with do while not 1 to 4 or x
        //if x
            //confirm exit
                //display points remaining, are you sure? cannot go back y/n
                //if y end true
        //else
            //do
                //prompt input of points from remaining-pool to remaining
                //input points
                //if invalid invalid try again
            //validate entry with do while remaining-pool to points remaining
            //update remaining = pool - input
            //update stat += input switch char
                //'1' con += input hp += 5*input
                //'2' dex += input if wizard ac += input
                //'3' str += input
                //'4' int += input
                //default "error"
    //do while end is not true
        
    //store character information in file
    
    //enemy stats
    //variables to store enemy stats
        //ogre with fists 70 hp 15 ac 3 + 2d6 dmg per turn, 20 double special line, 1 dmg to self
    
    
    //fight mechanics
    //variables
        //bool isdead
        //bars = hp/10
        //current hp
        //current enemy hp
        //action choice
        //damage
    //while isDead is false
        //display health percentage bar
            //current bars = ceil current/10
            //cout << "enemy HP: [";
            //for (i = 1; i <= current bars; i++) cout << |
            //for (i = 1; i <= bars - current bars; i++) cout << "."
            //cout << |
            //cout setprecision typecast current/hp percent
        
        //action switch
        //roll d20, if hit, dmg ternary if 20 double, else if ternary 1 dmg to self
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
        
        //if enemy hp < 1 isdead true
    //if isdead is true
        //end screen congrats you won
    
    int nsides = 20; //number of sides
    int result = rand() % nsides +1; //random result
    
    //exit
    return 0;
}