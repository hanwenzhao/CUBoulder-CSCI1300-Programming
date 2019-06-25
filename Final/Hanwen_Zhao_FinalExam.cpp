//Name: Hanwen Zhao
//Recitation: 106
//TA: Madhumitha

#include <iostream>
using namespace std;

//Question 1
class BugCollection  //bug collection class
{
private:    //variables to store number of each bug type
    int ants;
    int flies;
    int spiders;
public:
    BugCollection(int a, int f, int s)  //constructor
    {
        ants = a;
        flies = f;
        spiders = s;
    }
    void addBug(int bugType)  //add a bug to collection
    {
        //1 = ant, 2 = fly, 3 = spider
        if(bugType == 1){
            ants = ants + 1;
        }
        if(bugType == 2){
            flies = flies + 1;
        }
        if(bugType == 3){
            spiders = spiders + 1;
        }
    }
    void removeBug(int bugType)  //remove a bug from collection
    {
        if(bugType == 1){
            ants = ants - 1;
        }
        if(bugType == 2){
            flies = flies - 1;
        }
        if(bugType == 3){
            spiders = spiders - 1;
        }
    }
    void printBugCollection()  //print out the bug collection
    {
        cout<<"There are "<<ants<<" ants in the bug collection."<<endl;
        cout<<"There are "<<flies<<" flies in the bug collection."<<endl;
        cout<<"There are "<<spiders<<" spiders in the bug collection."<<endl;
    }
};

void findMinMax(int intArray[], int *maxVal, int *minVal)  //findminmax function
{
    for(int i = 0; i < 10; i++){    //find the maximum value in the array
        if(intArray[i] > *maxVal){
            *maxVal = intArray[i]; //if any number in array bigger than maxval, that number is the maxval
        }
    }
    for(int i = 0; i < 10; i++){    ////find the minimum value in the array
        if(intArray[i] < *minVal){
            *minVal = intArray[i]; //if any number in array smaller than maxval, that number is the minval
        }
    }
}

int main()
{
    //Question 1
    BugCollection myBugCollection(10,20,30);  //create a new bug collection called mybugcollection
    myBugCollection.addBug(1);  //add an ant to collection
    myBugCollection.addBug(2);  //add a fly to collection
    myBugCollection.addBug(3);  //add a spider to collection
    myBugCollection.removeBug(1);  //remove an ant to collection
    myBugCollection.removeBug(2);  //remove a fly to collection
    myBugCollection.removeBug(3);  //remove a spider to collection
    myBugCollection.printBugCollection(); //print out my collection

    //Question 2
    int minVal;
    int maxVal;
    int *ptrminVal = &minVal; //declare the pointer for minval

    int *ptrmaxVal = &maxVal; //declare the pointer for maxval

    int intArray[10] = {100, 2000, 40, -80, 10000, -999, 240, 3, -2, 10};  //hard-code the array
    findMinMax(intArray, ptrmaxVal, ptrminVal);  //call function
    cout<<"The minimum value is "<<minVal<<"."<<endl;  //print out the result
    cout<<"The maximum value is "<<maxVal<<"."<<endl;


    return 0;
}
