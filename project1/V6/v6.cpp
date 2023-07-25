/* 
 * File:   v6.cpp
 * Author: knguyen
 * Purpose: Version 6 of text based simplified DnD game.
 * Convert pseudocode to code for fight mechanism, starting with health bar visuals and enemy rolls and attacks.
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
    
    char yn; //variable to store yes or no input
    
    ifstream in; //declare in stream
    ofstream out; //declare out stream
    
    string fname = "dndchr.dat"; //variable to store file name
    
    //character creation
    bool create = true; //bool for creation screen
    //variables to store stats
    int con = 0, //constitution
            dex = 0, //dexterity
            str = 0, //strength
            inte = 0, //intelligence
            clas = 0, //class
            hp = 0, //health points
            ac = 10, //armor class
            bns = 0; //attack bonus
    string name; //name
    
    //load saved character
    //prompt to use saved character
    cout << "Reload saved character? y/n" << endl;
    //store input
    cin >> yn;
    //conditional to load saved character
    if (yn == 'y' || yn == 'Y')
    {
        create = false; //toggle create screen
        //open file
        in.open(fname,ios::in);
        //check for file
        if (in.fail() == false) //if file can be found
        {
            //store input from file
            in >> con >> dex >> str >> inte >> clas >> hp >> ac >> bns; //int values
            in.ignore(); //ignore endl
            getline(in, name); //getline for string
        }
        else //if file cannot be found
        {   
            create = true;
            cout << endl << "Character file not found. Returning to creation screen." << endl;
        }
        //close file
        in.close();
    }
    
    //character creation screen
    if (create == true)
    {
        //character name
        do
        {
            //prompt input
            cout << "Enter character name." << endl;
            //store character name
            cin.ignore();
            getline(cin, name);
            //output name
            cout << name;
            //confirm name
            cout << endl << "Your character's name is " << name << ". Is this correct? y/n" << endl;
            cin >> yn;
        } while (yn != 'y' && yn != 'Y'); //confirm entry with do while
        
        //choose class
        do
        {
            //prompt input
            cout << endl << "Choose your class." << endl << "Select 0 for Fighter and 1 for Wizard." << endl
                    << "0: Fighter. 60 HP. +2 con +3 str, +2 attack bonus. Armor - 16 AC, limits dex." << endl
                    << "1: Wizard.  30 HP. +3 int +2 dex. Spells include Healing and Mage Armor - 18 AC." << endl;
            do
            {
                //store class
                cin >> clas;
                //output invalid message
                if (clas != 0 && clas != 1)
                {
                    cout << endl << "Invalid class. Reenter." << endl;
                }
            } while (clas != 0 && clas != 1); //validate entry with do while
            //confirm entry
            cout << "You selected " << ( (clas == 0)? "fighter" : "wizard" ) << "." << endl
                    << "Is this correct? y/n" << endl;
            //store input
            cin >> yn;
        } while (yn != 'y' && yn != 'Y'); //confirm entry with do while

        //set base stats based on class chosen
        //set fighter stats
        if (clas == 0)
        {
            con += 3, //constitution
            dex += 0, //dexterity
            str += 2, //strength
            inte += 0, //intelligence
            hp += 60, //health points
            ac += 6, //armor class
            bns += 2 + str; //attack bonus
        }
        //set wizard stats
        if (clas == 1)
        {
            con += 0, //constitution
            dex += 2, //dexterity
            str += 0, //strength
            inte += 3, //intelligence
            hp += 30, //health points
            ac += 0 + dex, //armor class
            bns += 0 + inte; //attack bonus
        }

        //choose stats
        //variable to store point pool, stat choice, point allocation input, end bool
        int pool = 5, //point pool
                pin, //store points entered
                remain = pool; //remaining points
        char ccho; //to store stat selection choice
        bool cend = false; //to end stat allocation
        do //do until exit confirmed
        { 
            //prompt input to assign points, displaying info
            cout << endl << "HP: " << hp << " AC: " << ac << " Attack bonus: " << bns << endl
                    << "con: " << con << " dex: " << dex << " str: " << str << " int: " << inte << endl
                    << "Points remaining: " << remain << endl
                    << "Select stat to assign points." << endl
                    << "1: con - 1 pt = +5 HP" << endl 
                    << "2: dex" << ( (clas == 0)? " - Fighter AC is capped." : " - 1 pt = +1 AC" ) << endl
                    << "3: str" << ( (clas == 0)? " - 1 pt = +1 attack bonus." : "" ) << endl
                    << "4: int" << ( (clas == 0)? "" : " - 1 pt = +1 spell bonus." ) << endl
                    << "Press x to finish." << endl;
            do
            {
                //store input char choice
                cin >> ccho;
                //output invalid message
                if (ccho != '1' && ccho != '2' && ccho != '3' && ccho != '4' && ccho != 'x' && ccho != 'X')
                {
                    cout << endl << "Invalid entry. Reenter." << endl;
                }
            } while (ccho != '1' && ccho != '2' && ccho != '3' && ccho != '4' && ccho != 'x' && ccho != 'X'); //validate with do while
            
            if (ccho == 'x' || ccho == 'X') //exit
            {
                //confirm exit
                cout << endl << "You have " << remain << " points remaining. Are you sure you want to exit? You cannot go back. y/n" << endl;
                cin >> yn;
                if (yn == 'y' || yn == 'Y')
                {
                    cend = true; //toggle exit
                }
            }
            else
            {
                do
                {
                    do
                    {
                        //prompt input
                        cout << endl << "Input number of points from " << 0 << " to " << remain << endl;
                        //store input
                        cin >> pin;
                        //output invalid message
                        if ( (pin < 0 || pin > remain) )
                        {
                            cout << endl << "Invalid entry. Reenter." << endl;
                        }
                    } while ( pin < 0 || pin > remain ); //validate input with do while
                    //confirm entry
                    cout << endl << pin << " points. Is this correct? y/n" << endl;
                    //store input
                    cin >> yn;
                } while (yn != 'y' && yn != 'Y'); //confirm entry with do while
                //update remaining points
                remain -= pin;
                //switch to update stats
                switch (ccho)
                {
                    case '1': con += pin; hp += 5 * pin; //update con and hp
                        break;
                    case '2': dex += pin; ac += ( (clas == 1)? pin : 0 ); //update dex and ac if wizard
                        break; 
                    case '3': str += pin; bns += ( (clas == 0)? pin : 0 ); //update str and bonus if fighter
                        break;
                    case '4': inte += pin; bns += ( (clas == 1)? pin : 0 ); //update str and bonus if wizard
                        break;
                    default: cout << endl << "switch error" << endl;
                }
            }
        } while (cend == false);
        
        //store character information in file
        //open file
        out.open(fname,ios::out);
        //output into file
        out << con << endl << dex << endl << str << endl << inte << endl << clas << endl << hp << endl << ac << endl << bns << endl << name;
        //close file
        out.close();       
    }
    
    //enemy stats
    //variables to store enemy stats
    string ename = "ogre";
    int ehp = 70, //health points
            eac = 15, //armor class
            ebns = 6, //attack bonus
            en = 2, //number of dice
            ed = 6; //dice sides
    
    //output beginning of fight
    cout << endl << "Ready?" << endl;
    cin >> yn;
    cout << endl << "Great." << endl
            << "..." << endl
            << "An " << ename << " appears.";
    
    //fight mechanics
    //variables to keep track of battle
    bool isD = false, //is dead
        iseD = false; //is enemy dead
    //variables for player
    int chp = hp, //current hp
        r20, //store roll for attack
        r20b, //store attack roll plus bonus
        rdmg, //store roll for damage
        act, //action choice
        turn = 1; //store turn
    //enemy variables
    int cehp = ehp, //current enemy hp
        ebar = ceil(static_cast<float>(ehp)/10), //number of health bars from enemy hp, rounding up decimal
        cebar, //store number of current health bars
        er20, //store roll for attack
        er20b, //store attack roll plus bonus
        erdmg; //store roll for damage
    float pct; //store percent
    while (isD == false && iseD == false) //while both are alive
    {
        //Display turn
        cout << endl << endl << endl << endl << endl << "Turn: " << turn << endl;
        
        //display enemy health percentage bar
        //store calculations
        pct = static_cast<float>(cehp)/static_cast<float>(ehp) * 100.0f; // health percentage
        cebar = ceil(static_cast<float>(cehp)/10); //current bars, rounding up decimal
        //start output
        cout << endl << "Enemy HP: [";
        //loop through current health bars
        for (int i = 1; i <= cebar; i++)
        {
            cout << "|";
        }
        //loop through depleted health bars
        for (int i = 1; i <= ( ebar - cebar ); i++)
        {
            cout << "_";
        }
        cout << "] " //end bar
                << fixed << showpoint << setprecision(2) << pct << " %" << endl; //output percent at 2 points
        
        //display player current / hp
        cout << "Player HP: " << chp << "/" << hp << endl;
        
        //enemy attack
        //output attack
        cout << endl << "The " << ename << " reaches out." << endl;
        er20 = rand()%20 +1; //roll for attack
        er20b = er20 + ebns; //attack roll plus bonus
        erdmg = ebns; //roll for damage + bonus
        for (int i = 1; i <= en; i++) //roll for damage for loop number of dice
        {
            erdmg += rand()%ed; // add roll
        }
        if (er20b > ac) //if roll > ac, hits
        {
            //output attack line, if natural 20 critical hit
            cout << endl << "The " << ename << " pummels you and " << ( (er20 == 20)? "crits!" : "hits.") << endl;
            //double damage if critical
            erdmg = (er20 == 20)? erdmg*2 : erdmg;
            //output damage done
            cout << "You take " << erdmg << " damage." << endl;
            //update player hp
            chp -= erdmg;
        }
        else
        {
            if (er20 == 1) //if natural roll is 1, critical failure
            {
                //output critical failure
                cout << endl << "Critical failure. The " << ename << " trips and hits itself, losing " << erdmg << " HP." << endl;
                //update enemy hp
                cehp -= erdmg;
            }
            else //else normal miss
            {
                //output dialogue
                cout << endl << "The " << ename << " misses." << endl << "It roars angrily." << endl;
            }
        }
        
        //player attack
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
        
        //if enemy dead
        if (cehp < 1)
        {
            cout << endl << "The " << ename << " has been slain." << endl;
            iseD = true;
        }
        //if you are dead
        if (chp < 1)
        {
            cout << endl << "YOU DIED" << endl;
            cout << endl << "You, " << name << ", have been slain." << endl << chp << " HP." << endl;
            isD = true;
        }
        
        //update turn
        turn ++;
    }  
    //exit
    return 0;
}