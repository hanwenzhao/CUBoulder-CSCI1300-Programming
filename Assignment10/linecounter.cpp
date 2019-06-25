#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char **argv)
{
    ifstream inFile;
    string strLine;
    int counter = 0;
    bool ignore = false;
    int done = 0;
    string filename[5] = {"main.cpp", "BankAccount.cpp", "BankAccount.h", "Accounts.h","Accounts.cpp"};
    for(int i=0; i<5;i++){
        cout<<"opening file "<<filename[i]<<endl;
        inFile.open(filename[i].c_str());
        if(inFile.fail()){
            cout<<"The file was not successfully opened"<<endl;
        }else{
            while(!inFile.eof()){
                getline(inFile, strLine);
                //cout<<strLine<<endl;
                done = 0;
                if(strLine == ""){
                    counter = counter + 0;
                    //cout<<"not count"<<endl;
                }else{
                    if(strLine.find_first_not_of("\t\n ") == string::npos){
                        counter = counter + 0;
                        //cout<<"not count"<<endl;
                        done = 1;
                    }
                    if(strLine.find("//") != string::npos){
                        if(strLine.substr(0,strLine.find("//",0)) == ""){
                            counter = counter + 0;
                            //cout<<"not count"<<endl;
                            done = 1;
                        }
                        if(strLine.substr(0,strLine.find("//",0)) != ""){
                            counter = counter + 1;
                            done = 1;
                        }
                    }
                    if(strLine.find("/*") != string::npos){
                        ignore = true;
                    }
                    if(ignore == true){
                        counter = counter + 0;
                        //cout<<"not count"<<endl;
                        done = 1;
                    }
                    if(strLine.find("*/") != string::npos){
                        ignore = false;
                        done = 1;
                    }

                    if(done != 1){
                        counter = counter + 1;
                    }
                }
            }
        }
        inFile.close();
    }
    cout<<"There are "<<counter<<" lines in the files."<<endl;
    return 0;
}
