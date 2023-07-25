/* 
 * File:   v7.cpp
 * Author: knguyen
 * Purpose: Version 7 of text based simplified DnD game.
 * Completed converting pseudocode to code for fight mechanism, for both fighter and wizard. Tested and adjusted player experience, debugged missing calculations. Debugging char input.
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
            hp = 0, //health points
            ac = 10, //armor class
            bns = 0; //attack bonus
    char clas = 0; //class
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
            //verify choice
            cout << endl << "You selected " << name << endl
                    << "Do you want to continue as " << name << "? y/n" << endl;
            //store input
            cin >> yn;
            //if not yes
            if (yn != 'y' && yn != 'Y')
            {
                create = true; //toggle character creation
            }
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
        //inform player
        cout << endl << "Creating character." << endl << endl;
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
                    << "0: Fighter. 60 HP. +2 con +3 str, +2 attack bonus. Armor - 16 AC, limits dex. Berserk - double damage, 3 rounds." << endl
                    << "1: Wizard.  30 HP. +3 int +2 dex. Spells include Healing, and Mage Armor - 20 AC, 3 rounds." << endl;
            do
            {
                //store class
                cin >> clas;
                //output invalid message
                if (clas != '0' && clas != '1')
                {
                    cout << endl << "Invalid class. Reenter." << endl;
                }
            } while (clas != '0' && clas != '1'); //validate entry with do while
            //confirm entry
            cout << "You selected " << ( (clas == '0')? "fighter" : "wizard" ) << "." << endl
                    << "Is this correct? y/n" << endl;
            //store input
            cin >> yn;
        } while (yn != 'y' && yn != 'Y'); //confirm entry with do while

        //set base stats based on class chosen
        //set fighter stats
        if (clas == '0')
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
        if (clas == '1')
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
        char cpin; //store points earned as char to avoid cin error
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
                    << "2: dex" << ( (clas == '0')? " - Fighter AC is capped." : " - 1 pt = +1 AC" ) << endl
                    << "3: str" << ( (clas == '0')? " - 1 pt = +1 attack bonus." : "" ) << endl
                    << "4: int" << ( (clas == '0')? "" : " - 1 pt = +1 spell bonus." ) << endl
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
                        //store char input
                        cin >> cpin;
                        pin = cpin - '0'; //clean and convert char to int
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
                    case '2': dex += pin; ac += ( (clas == '1')? pin : 0 ); //update dex and ac if wizard
                        break; 
                    case '3': str += pin; bns += ( (clas == '0')? pin : 0 ); //update str and bonus if fighter
                        break;
                    case '4': inte += pin; bns += ( (clas == '1')? pin : 0 ); //update str and bonus if wizard
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
    //prompt continue
    cout << endl << endl << "Press any key to continue." << endl;
    //enter to continue
    cin >> yn;
        
    //fight mechanics
    //variables to keep track of battle
    bool isD = false, //is dead
        iseD = false; //is enemy dead
    //variables for player
    int chp = hp, //current hp
        r20, //store roll for attack
        r20b, //store attack roll plus bonus
        rdmg, //store roll for damage
        dmg, //store total damage
        n, //number of dice
        d, //number of sides
        turn = 1, //store turn
        pupcnt = 0; //store powerup count
    char act; //action choice
    bool pup = false; //power up bool
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
        //Mark new turn
        cout << "_________________________________";
        
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
        
        //display turn
        cout << "Turn: " << turn << endl;
                
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
            cout << endl << "The " << ename << " pummels " << name << " and " << ( (er20 == 20)? "crits! " : "hits. ");
            //double damage if critical
            erdmg = (er20 == 20)? erdmg*2 : erdmg;
            //output damage done
            cout << name << " takes " << erdmg << " damage." << endl;
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
                cout << endl << "The " << ename << " misses. It roars angrily." << endl;
            }
        }
        
        //player attack
        //begin output
        cout << endl << "Your turn. Press any key to continue." << endl;
        //enter to continue
        cin >> yn;
        //action switch
        //if fighter
        if (clas == '0')
        {
            if (pup == true) //if powerup is active
            {
                pupcnt--; //decrease count per round
                cout << endl << "Berserk active. You have double damage for " << pupcnt << " rounds after this one remaining." << endl; //inform player
            }
            //prompt action choice
            cout << endl << "Choose an action." << endl;
            //display menu
            cout << "1: greatsword 1d12 + " << bns << endl
                    << "2: longbow 1d12 + " << bns << endl
                    << "3: dual handaxe 2d6 + " << bns << endl
                    << "4: dual scimitar 2d6 + " << bns << endl
                    << "5: Berserk - double damage for the next three turns" << endl;
            //store choice
            do
            {
                //store action
                cin >> act;
                if (act < '1' || act > '5')
                {
                    //invalid message
                    cout << endl << "Invalid entry. Reenter." << endl;
                }
            } while (act < '1' || act > '5'); //validate input
            //switch choice
            switch (act)
            {
                //weapons, number of dice and sides
                case '1':
                    n = 1;
                    d = 12;
                    cout << endl << "You raise your greatsword." << endl;
                    break;
                case '2':
                    n = 1;
                    d = 12;
                    cout << endl << "You aim your longbow." << endl;
                    break;    
                case '3':
                    n = 2;
                    d = 6;
                    cout << endl << "You spin your handaxes." << endl;
                    break;
                case '4':
                    n = 2;
                    d = 6;
                    cout << endl << "You flash your scimitars." << endl;
                    break;
                case '5': //berserk
                    pup = true;
                    pupcnt = 3;
                    cout << endl << "Your eyes flash as you activate Berserk." << endl
                            << "You spent your action. You have " << pupcnt << " rounds remaining.";
                    break;
                default: cout << "switch error";
            }
            if (act >= '1' && act <= '4')
            {
                //roll to attack
                //prompt roll
                cout << endl << "Press any key to roll the d20." << endl;
                //enter for "roll"
                cin >> yn;
                //roll for attack
                r20 = rand()%20 +1;
                r20b = r20 + bns; //attack roll plus bonus
                //output roll
                cout << endl << "You rolled a natural " << r20;
                //switch output depending on natural roll
                switch (r20)
                {
                    case 1: cout << ". Critical failure."; break;
                    case 20: cout << ". Critical hit - Double damage. Attack bonus: " << bns << ". Your total is " << r20b << "."; break;
                    default: cout << ". Attack bonus: " << bns << ". Your total is " << r20b << ".";
                }
                
                //prompt damage roll
                cout << endl << "Press any key to roll for damage - " << n << "d" << d << endl;
                //enter for "roll"
                cin >> yn;
                for (int i = 1; i <= n; i++) //roll for damage for loop number of dice
                {
                    rdmg = rand()%d +1; //damage roll
                    cout << "You rolled a " << rdmg << ". ";
                    dmg += rdmg; //add to total damage
                }
                dmg += bns; //total roll for damage + bonus
                cout << "Attack bonus: " << bns << ". ";
                //if berserk is on
                if (pup == true)
                {
                    cout << "Berserk: Double damage.";
                    dmg *= 2; //double damage
                }
                //if count reaches zero
                if (pupcnt == 0)
                {
                    pup = false; //toggle berserk off
                }
                //double damage if critical
                dmg = (r20 == 20)? dmg*2 : dmg;
                //output total damage
                cout << endl << dmg << " damage total." << endl;
                
                if (r20b > eac) //if roll > ac, hits
                {
                    //output attack line, if natural 20 critical hit
                    cout << endl << "Success. " << name << " lands a blow on the " << ename << " and " << ( (r20 == 20)? "crits!" : "hits.") << endl;
                    //output damage done
                    cout << "The " << ename << " takes " << dmg << " damage." << endl;
                    //update player hp
                    cehp -= dmg;
                }
                else
                {
                    if (r20 == 1) //if natural roll is 1, critical failure
                    {
                        //output critical failure
                        cout << endl << "Critical failure. " << name << " trips and stabs themself, losing " << dmg << " HP." << endl;
                        //update enemy hp
                        chp -= dmg;
                    }
                    else //else normal miss
                    {
                        //output dialogue
                        cout << endl << name << " leaps forward and misses. You do no damage." << endl;
                    }
                }
            }
        }
        
        //if wizard
        if (clas == '1')
        {
            if (pup == true) //if powerup is active
            {
                ac = 20;
                cout << endl << "Mage Armor active. You have " << ac << "AC for " << pupcnt << " rounds after this one remaining." << endl; //inform player
                pupcnt--; //decrease count per round
                //if count reaches zero
                if (pupcnt == 0)
                {
                    pup = false; //toggle armor off
                }
            }
            
            //prompt action choice
            cout << endl << "Choose an action." << endl;
            //display menu
            cout << "1: fireball 3d6 + " << bns << endl
                    << "2: magic missiles 4d4 + " << bns << endl
                    << "3: heal 2d6 + " << bns << endl
                    << "4: mage armor - 20 AC for the next three turns" << endl;
            //store choice
            do
            {
                //store action
                cin >> act;
                if (act < '1' || act > '4')
                {
                    //invalid message
                    cout << endl << "Invalid entry. Reenter." << endl;
                }
            } while (act < '1' || act > '4'); //validate input
            //switch choice
            switch (act)
            {
                //weapons, number of dice and sides
                case '1':
                    n = 3;
                    d = 6;
                    cout << endl << "You cast fireball. It launches across the field." << endl;
                    break;
                case '2':
                    n = 4;
                    d = 4;
                    cout << endl << "You fire magic missiles." << endl;
                    break;    
                case '3':
                    n = 2;
                    d = 6;
                    cout << endl << "You cast a healing spell." << endl;
                    break;
                case '4': //mage armor
                    pup = true;
                    pupcnt = 3;
                    cout << endl << "The air shimmers as you activate Mage Armor." << endl
                            << "You spent your action. You have " << pupcnt << " rounds remaining.";
                    break;
                default: cout << "switch error";
            }
            
           //execute actions with rolls
            if (act == '1' || act == '2')
            {
                //roll to attack
                //prompt roll
                cout << endl << "Press any key to roll the d20." << endl;
                //enter for "roll"
                cin >> yn;
                //roll for attack
                r20 = rand()%20 +1;
                r20b = r20 + bns; //attack roll plus bonus
                //output roll
                cout << endl << "You rolled a natural " << r20;
                //switch output depending on natural roll
                switch (r20)
                {
                    case 1: cout << ". Critical failure."; break;
                    case 20: cout << ". Critical hit - Double damage. Spell bonus: " << bns << ". Your total is " << r20b << "."; break;
                    default: cout << ". Spell bonus: " << bns << ". Your total is " << r20b << ".";
                }
                
                //prompt damage roll
                cout << endl << "Press any key to roll for damage - " << n << "d" << d << endl;
                //enter for "roll"
                cin >> yn;
                for (int i = 1; i <= n; i++) //roll for damage for loop number of dice
                {
                    rdmg = rand()%d +1; //damage roll
                    cout << "You rolled a " << rdmg << ". ";
                    dmg += rdmg; //add to total damage
                }
                dmg += bns; //total roll for damage + bonus
                cout << "Spell bonus: " << bns << ". ";
                //double damage if critical
                dmg = (r20 == 20)? dmg*2 : dmg;
                //output total damage
                cout << endl << dmg << " damage total." << endl;
                
                if (r20b > eac) //if roll > ac, hits
                {
                    //output attack line, if natural 20 critical hit
                    cout << endl << "Success. " << name << "'s spell lands a blow on the " << ename << " and " << ( (r20 == 20)? "crits!" : "hits.") << endl;
                    //output damage done
                    cout << "The " << ename << " takes " << dmg << " damage." << endl;
                    //update player hp
                    cehp -= dmg;
                }
                else
                {
                    if (r20 == 1) //if natural roll is 1, critical failure
                    {
                        //output critical failure
                        cout << endl << "Critical failure. " << name << " loses concentration and turns a toe into a frog, losing " << dmg << " HP." << endl;
                        //update enemy hp
                        chp -= dmg;
                    }
                    else //else normal miss
                    {
                        //output dialogue
                        cout << endl << name << "'s spell misfires. You do no damage." << endl;
                    }
                }
            }
            else if (act == '3') //else if 3 you cast heal, roll to heal, adjust hp
            {
                //prompt healing roll
                cout << endl << "Press any key to heal " << n << "d" << d << " health points. " << endl;
                //enter for "roll"
                cin >> yn;
                for (int i = 1; i <= n; i++) //roll for healing points for loop number of dice
                {
                    rdmg = rand()%d +1; //healing roll using same damage variable
                    cout << "You rolled a " << rdmg << ". ";
                    dmg += rdmg; //add to total healing points
                }
                dmg += bns; //total roll for healing points + bonus
                cout << "Spell bonus: " << bns << ". ";
                //output total healing points
                cout << endl << "You regained " << dmg << " HP total." << endl;
                //update hp
                chp += dmg;
                if (chp > hp) //if healing points lead to current hp exceeding max hp
                {
                    chp = hp; //set equal to max hp
                }
            }
        }
        
        //prompt continue
        cout << endl << "Press any key to continue." << endl;
        //enter to continue
        cin >> yn;
        
        //update turn
        turn ++;
        //reset damage
        dmg = 0;
        
        //if enemy dead
        if (cehp < 1)
        {
            cout << endl << "Enemy HP: " << cehp << ". Success!" << endl
                    << endl << "The " << ename << " has been slain." << endl
                    << "Your name, " << name << ", will be memorialized in ballads far and wide." << endl;
            iseD = true;
        }
        //if you are dead
        if (chp < 1)
        {
            cout << endl << "YOU DIED" << endl;
            cout << endl << "You, " << name << ", have been slain. Your final attack injured the " << ename << ", but did not slay it." << endl
                    << "Your journey has come to an end." << endl << chp << " HP." << endl;
            isD = true;
        }
        //if both dead
        if (chp < 1 && cehp < 1)
        {
            cout << name << " ended the " << ename << "'s reign of terror, at the cost of their own life." << endl;
        }    
    }  
    //exit
    return 0;
}