//Name: Hanwen Zhao
//TA Madhumitha Soundararajan
//Recitation 106
//Assignment 8
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

class Treasure{  //Treasure class
public:
    int h = 0;
    int w = 0;
    int value = 0;
    bool condition = false; //means has not been found
};

int main()
{
    srand (time(NULL)); //real random number
    cout<<"Welcome to the T R E A S U R E  H U N T!"<<endl;

    cout<<"How vast is your treasure hunt? (Enter an integer for the size of the board.): "<<endl;
    int boardSize;
    cin>>boardSize;  //user input the board size
    //cout<<"The board size is "<<boardSize<<"."<<endl; //debug staff
    cout<<"How many treasure are there? (Enter an integer for the number of treasures.): "<<endl;
    int numberofTreasure;  //the number of treasure
    cin>>numberofTreasure;
    int treasureLeft = numberofTreasure; //record the number of treasure left
    int score = 0; //initialize the score
    //cout<<"The number of treasure is "<<numberofTreasure<<"."<<endl; //debug staff

    cout<<"Let the search begin!"<<endl;

    Treasure *myTreasure = new Treasure[numberofTreasure];  //c
/*********************Assign the value to treasures*******************************/
    while(true){
        for(int n = 0; n < numberofTreasure;){
            int h_n = rand()% boardSize + 1;
            int w_n = rand()% boardSize + 1;
            int value_n = rand()% 100 + 1;
            bool different = false;
            /****************cheating staff*********************/
            //cout<<"new h is "<<h_n<<endl; //debug staff
            //cout<<"new w is "<<w_n<<endl; //debug staff
            //cout<<"new value is "<<value_n<<endl; //debug staff
            /***************************************************/
            for(int i = 0; i < numberofTreasure;i++){
                if(myTreasure[i].h == h_n && myTreasure[i].w == w_n){
                    different = true;
                }
            }
            if(different == false){   //if the coordinates is not equal to other coordinates, assign it to treasure
                myTreasure[n].h = h_n;
                myTreasure[n].w = w_n;
                myTreasure[n].value = value_n;
            }else{     //if it equal to some treasure's coordinate, redo it
                n = n - 1;
            }
            n = n + 1;
        }
        break;
    }
/*********************************************************************************/
    while(true){
        string userInput1;
        string userInput2;
        bool foundTreasure = false;   //treasure has not been found
        cout<<"Enter your guess (Enter two integers for the treasure's location) "<<endl;
        cin>>userInput1;
        if(userInput1 == "quit"){  //if user enter "quit", quit the game
            break;
        }
        cin>>userInput2;
        if(userInput2 == "quit"){
            break;
        }
        int input1 = atoi(userInput1.c_str());  //if user did not enter "quit", convert string to integer
        int input2 = atoi(userInput2.c_str());
        //cout<<"The first input is "<<input1<<"."<<endl; //debug staff
        //cout<<"The second input is "<<input2<<"."<<endl; //debug staff

        if(input1 > boardSize || input2 > boardSize){   //if the input greater than board size, say "out of bounds."
            cout<<"Out of Bounds!"<<endl;
            foundTreasure = true;   //if it is out of bounds, assume it find the treasure, so it won't decrease the value
        }else{
            for(int i = 0; i < numberofTreasure;i++){
                if(myTreasure[i].h == input1 && myTreasure[i].w == input2){ //if the input equal to one of the treasure's coordinate
                        if(myTreasure[i].condition == true){  //if the treasure already been found, there is nothing there
                            foundTreasure = false;
                        }else{
                            score = score + myTreasure[i].value; //if the user find the treasure, add the value to score
                            myTreasure[i].condition = true;
                            foundTreasure = true;
                            treasureLeft = treasureLeft - 1;
                            cout<<"Treasure Found! Points awarded: "<<myTreasure[i].value<<"."<<" Total points: "<<score<<"."<<" Yay, "<<treasureLeft<<" treasures left."<<endl;
                            myTreasure[i].value = 0; //set the value to zero
                        }
                }
            }
        }
        if(foundTreasure == false){ //if user did not find the treasure, decrease the value of all treasures
            cout<<"Nothing there! 10% deducted from remaining treasures points."<<endl;
            for(int i = 0; i < numberofTreasure;i++){
            myTreasure[i].value = myTreasure[i].value * 0.9;
            }
        }
        if(treasureLeft == 0){ //if all treasures have been found, print the final score
            cout<<"Congratulations! You won the game with "<<score<<" points."<<endl;
            break;
        }
    }
    return 0;
}
