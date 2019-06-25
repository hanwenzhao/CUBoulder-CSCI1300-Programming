#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdlib>


using namespace std;

int main(int argc, char **argv)
{
    opterr = 0;
    char *fileName = NULL;
    int c;
    char *offset = NULL;
    char flag;
    while((c = getopt (argc, argv, "e:d:f:")) != -1)
        switch(c)
        {
        case 'e':
            offset = optarg;
            flag = 'e';
            break;
        case 'd':
            offset = optarg;
            flag = 'd';
            break;
        case 'f':
            fileName = optarg;
            break;
        }

    ifstream inFile;
    string strLine;
    inFile.open(fileName);
    if(inFile.fail()){
        cout<<"File did not open."<<endl;
    }else{
        while(!inFile.eof()){
            getline(inFile, strLine);
            //cout<<strLine<<endl;
            //cout<<strLine.length() <<endl;
            for(int i = 0; i < strLine.length(); i++){
                //cout<<strLine[i]<<endl;
                int newLine[strLine.length()];
                if(flag == 'e'){
                        newLine[i] = strLine[i] + atoi(offset);
                        if(newLine[i] > 126)
                            newLine[i] = newLine[i] - 95;

                       cout<<char(newLine[i]);
                }
                if(flag == 'd'){
                        //cout<<c;
                        newLine[i] =strLine[i]  - atoi(offset);
                        if(newLine[i] < 32){
                            newLine[i] = newLine[i] + 95;
                        }

                       cout<<char(newLine[i]);
                }

            }
        }
    }
    inFile.close();
    //return 0;
}
