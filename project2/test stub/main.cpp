/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
#include <cstring>
#include <vector>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void prntAry(int [], int [], int, int);
void prntAry(string [], int [], int, int);
void selSrt(int [], int [], int);
void prntm(vector <int> vec);
void bublSrt(int [], int [], int );


void selSrt(vector<int>&);
bool binSrch(vector<int>, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE = 5;
    int values[SIZE] = {5, 4, 3, 2, 1};
    string names[SIZE] = {"five", "four", "three", "two", "one"};
    int stats[SIZE] = {50, 40, 30, 20, 10};
    int order[SIZE];
    
    //Sorted List
    bublSrt(values, order, SIZE);
    
    //Display the outputs
    prntAry(names, order, SIZE, 5); //sorted array
    prntAry(stats, order, SIZE, 5);
    
    int num = 1;
    cout << stats[order[num]] << endl;
    
    int val, index;
    vector<int> vec = {3, 0, 2, 1};
    selSrt(vec);
    prntm(vec);
    cin >> val;
    if (binSrch(vec, val, index) == true)
    {
        cout << "Element " << val << " found at index: " << index << ", value: " << vec[index] << endl;
    }
    else
    {
        cout << "Element " << val << " not found in the vector." << endl;
    }
    //Exit stage right or left!
    return 0;
}
void prntAry(int names[], int order[], int size, int length)
{
    for (int i = 0; i < size; i++)
    {
        cout << names[order[i]] << " "; //output array
        if ((i+1)%length == 0) //every length num of outputs
        {
            cout << endl; //newline
        }
    }
}
void prntAry(string names[], int order[], int size, int length)
{
    for (int i = 0; i < size; i++)
    {
        cout << names[order[i]] << " "; //output array
        if ((i+1)%length == 0) //every length num of outputs
        {
            cout << endl; //newline
        }
    }
}
void selSrt(int values[], int order[], int size)
{
    //initialize order array
    for (int i = 0; i < size; i++)
    {
        order[i] = i;
    }

    int temp;
    for (int i = 0; i < size; i++) //loop each i
    {
        for (int j = i + 1; j < size; j++) //loop through each after i
        {
            if (values[i] > values[j]) //if greater than next
            {
                temp = values[i]; //save first
                values[i] = values[j]; //switch first and last, new a[i] to compare to next j until ai is the smallest
                values[j] = temp; //set last to first

                //update order array
                temp = order[i]; //save first order
                order[i] = order[j]; //switch first and last order, new first order to compare to next orders
                order[j] = temp; //set last to first
            }
        }
    }
}
void bublSrt(int values[], int order[], int size)
{
    //initialize order array
    for (int i = 0; i < size; i++)
    {
        order[i] = i;
    }
    
    int temp; //store temporary
    bool cont; //bool to continue
    int n = size-1;
    do
    {
        cont = false; //dont continue if no swaps
        for (int i = 0; i < n; i++) //loop each i
        {
            if (values[i] > values[i+1]) //if greater than next
            {
                temp = values[i]; //save first
                values[i] = values[i+1]; //switch first and nest, new a[i] to compare to next j until ai is the smallest
                values[i+1] = temp; //set next to first
                //update order
                temp = order[i]; //save first
                order[i] = order[i+1]; //switch first and nest, new a[i] to compare to next j until ai is the smallest
                order[i+1] = temp; //set next to first
                cont = true; //continue
            }
        }
        n--; //last is largest
    } while (cont == true); //while still swaping
}


void selSrt(vector<int>& vec)
{
    int temp;
    for (int i = 0; i < vec.size(); i++) //loop each i until end of vector
    {
        for (int j = i+1; j < vec.size(); j++) //loop through each after i
        {
            if (vec[i] > vec[j]) //if less than next
            {
                temp = vec[i]; //save first
                vec[i] = vec[j]; //switch first and last, first to compare to next until first is the smallest
                vec[j] = temp; //set last to first
            }
        }
    }
}
void prntm(vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++) //loop through vector
    {
        cout << (i+1) << ": " << vec[i] << endl; //output list number and roll
    }
}
bool binSrch(vector<int> vec, int val, int& index)
{
    index = 0;
    int hind = vec.size() - 1; //high
    int lind = 0; //low
    int mind; //mid
    bool isFound = false;
    do
    {
        mind = (hind + lind) / 2; //mid
        if (vec[mind] == val) //if value equals middle value
        {
            index = mind; //save index
            isFound = true; //found
        }
        else if (vec[mind] < val) //if less
        {
            lind = mind + 1; //mid is new high
        }
        else //if greater
        {
            hind = mind - 1; //mid is new low
        }
    } while (lind <= hind); //until search finished
    return isFound; //not found
}
