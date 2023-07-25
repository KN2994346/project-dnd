/* 
 * File:   v4.cpp
 * Author: knguyen
 * Purpose: Version 4 of text based simplified DnD game.
 * Testing file i/o
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
    
    //test file i/o
    //declare streams
    fstream in,
            out;
    
    /*
    //output into file
    //initialize output streams
    out.open("dndchar.dat",ios::out);
    //declare variables
    int o1 = 1,
            o2 = 2,
            o3 = 3;
    //output into file
    out << o1 << o2 << o3;
    //close file
    out.close();
    */
    /*
    //input from file
    //check if file exists
    string chkfl = "dndchar.dat"; //search for file name
    fstream exst(chkfl);
    if (exst) //exists
    {  
    }
    else
    {   
    }
    */
    /*in.open("dndchar.dat",ios::in);
    //variables to store input
    char i1,
            i2,
            i3;
    //store input from file
    in >> i1 >> i2 >> i3;
    //convert char to int
    int one = i1-'0';
    //output to confirm results
    cout << i1 << endl << i2 << endl << i3 << endl;
    //test calculation
    int calc = one*5;
    //output result
    cout << calc;
    //close file
    in.close();
    */
    
    //character creation menu
    //move variables to store stats here
    //bool create true
    //variable to store input
    //prompt to use saved character
    //store input
    //if y
        //create = false
        //check file
        //if file exists
        //file input
        //else cout no file, returning to creation screen, create = true
    
    //if create true
    //character creation
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
        //if fighter 60 hp 16 ac +2 con +3 str +2 attack bonus total = str+2
        //if wizard 30 hp 10 ac +3 int +2 dex attack bonus total = int
    
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
    
    //output an ogre appears
    
    //fight mechanics
    //variables
        //bool isdead, loss
        //bars = hp/10
        //current hp
        //current enemy hp
        //action choice
        //damage
    //while isDead is false or loss is false
        //display enemy health percentage bar
            //current bars = ceil current/10
            //float percent hp = cur/hp*100;
            //cout << "enemy HP: [";
            //for (i = 1; i <= current bars; i++) cout << |
            //for (i = 1; i <= bars - current bars; i++) cout << "."
            //cout << |
            //cout setprecision typecast percent 
        
        //display player current / hp
        
        //enemy attack
        //output the ogre reaches out
        //roll d20 = rand() % 20
        //preroll damage 2d6 +3
                //if roll + bonus > player ac
                    //ternary 20 it hits vs it crits
                    //ternary 20 dmg double
                    //the orge does dmg
                    //player hp adjustment 
                //else
                    //if 1 critical failure the orge did dmg to itself 
                        //enemy hp adjustment
                    //else it missed
        
        //action switch
        //if fighter
            //var to store berserk = false, count = 0
            //if berserk = true count --, cout berserk active you have count rounds after this one remaining
            //prompt action choice
            //variable to store input choice
            //display menu
            /*
              * 1 greatsword 1d12 + str
              * 2 longbow 1d12 + str
              * 3 dual handaxe 2d6 + str
              * 4 dual scimitar 2d6 + str
              * 5 no roll berserk double damage next three turns
             */
            //store choice
            //switch choice
                //1 greatsword : num = 1 sides = 12 name = greatsword
                //2 long bow damage roll = rand() % 12 +1;
                //3 dual handaxe :
                //4 dual scimitar damage roll = rand() % 6 +1 + rand() % 6 +1;
                //5 berserk berserk = true count += 3
            //if 5 You spent your action to activate berserk. you have count rounds remaining
            //else
                //output you raise your weapon name
                //pre roll damage
                //if berserk true double dmg
                //if count = 0 berserk = false
                //press enter to roll, you rolled a
                //roll d20 = rand() % 20
                //output you rolled a
                //if roll + bonus > enemy ac
                    //ternary 20 you hit vs you crit
                    //enter to roll for damage
                    //output you rolled
                    //tenary 20 dmg double
                    //you did dmg
                    //enemy hp adjustment 
                //else
                    //if 1 critical failure you did dmg to yourself 
                        //hp adjustment
                    //else you missed
    
        //if wizard
            //var to store armor = false, count = 0
            //if armor = true count --, cout armor active you have 18 ac for count rounds after this one
            //prompt action choice
            //variable to store input choice
            //display menu
            /*
              * 1 3d6 fireball wizard
              * 2 4d4 magic missiles wizard
              * 3 no roll heal 2d6 + int
              * 4 no roll mage armor 18 ac next three turns
             */
            //store choice
            //switch choice
                //1 fireball : num = 3 sides = 6 name = fireball
                //2 magic missiles 4d4
                //heal 2d6
                //4 mage armor armor = true count += 3
            //if armor true ac = 18
            //if 4 You spent your action to activate armor. your ac is 18. you have count rounds remaining
            //else if 3 you cast heal, roll to heal, adjust hp
                //else
                //output you cast spell name
                //pre roll damage
                //if count = 0 berserk = false
                //press enter to roll, you rolled a
                //roll d20 = rand() % 20
                //output you rolled a
                //if roll + bonus > enemy ac
                    //ternary 20 you hit vs you crit
                    //enter to roll for damage
                    //output you rolled
                    //tenary 20 dmg double
                    //you did dmg
                    //enemy hp adjustment 
                //else
                    //if 1 critical failure you did dmg to yourself 
                        //hp adjustment
                    //else you missed
        
        //if enemy hp < 1 output slain, isdead true
        //if you hp < 1 putput slain, loss true
    //if isdead is true
        //end screen congrats you won
    //if loss true
        //end screen you died
    //exit
    return 0;
}