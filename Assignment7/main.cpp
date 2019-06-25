#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cmath>

using namespace std;


double football(double p,double a,double y,double t,double i){
	double completions_per_attempt = p/a;
	double yards_per_attempt = y/a;
	double touchdowns_per_attempt = t/a;
	double intercepts_per_attempt = i/a;
	double C = (completions_per_attempt - 0.30) * 5;
	double Y = (yards_per_attempt - 3) * 0.25;
	double T = touchdowns_per_attempt * 20;
	double I = 2.375 - (intercepts_per_attempt * 25);


	if (C < 0){
		C = 0;
	}
	if (Y < 0){
		Y = 0;
	}
	if (T < 0){
		T = 0;
	}
	if (I < 0){
		I = 0;
	}

	if (C > 2.375){
		C = 2.375;
	}
	if (Y > 2.375){
		Y = 2.375;
	}
	if (T > 2.375){
		T = 2.375;
	}
	if (I > 2.375){
		I = 2.375;
	}


	double passingRate = (C + Y + T + I)/6 * 100;

	return passingRate;
}

int cycling(int m, int b, double v, int d){
    double g = 9.8;
    double k = 0.18;
    double cr = 0.001;
    double iE = 0;
    int mm = 1;
    double t = (d * 1000) / v;
    int tm = round(t/60);
    int x = tm;
    while(x !=0){
        double cf = rand()% 50 + 50;
        double cfd = cf/100;
        double pa = k * cfd * pow(v,3);
        double pr = cr * g * (m + b) * v;
        double ps = round(pa + pr);
        double Et = round(ps *60);
        x = x -1;
        iE = iE+ Et;
        cout<<"At the "<<mm<<" minutes. The energy total so far is "<<iE<<" J."<<endl;
        mm = mm + 1;
    }
    double aE =iE/tm;
    cout<<"The average energy is "<<aE<<" kJ."<<endl;
    return 0;
}


int main(int argc, char *argv[])
{
	double p = 0;
	double a = 0;
	double y = 0;
	double t = 0;
	double i = 0;

	double m = 0;
	double b = 0;
	double v = 0;
	double d = 0;
	int option_char;
	int footballfunction = 0;
	int cyclingfunction = 0;
	opterr = 0;

	while ((option_char = getopt(argc,argv,"fp:a:y:t:i:cm:b:v:d:")) != -1){
            if (option_char == 'f'){
                footballfunction = 1;
            }
            if (option_char == 'c'){
                cyclingfunction = 1;
            }
            if (option_char == 'p'){
                p = atoi(optarg);
            }
            if (option_char == 'a'){
                a = atoi(optarg);
            }
            if (option_char == 'y'){
                y = atoi(optarg);
            }
            if (option_char == 't'){
                t = atoi(optarg);
            }
            if (option_char == 'i'){
                i = atoi(optarg);
            }
            if (option_char == 'm'){
                m = atoi(optarg);
            }
            if (option_char == 'b'){
                b = atoi(optarg);
            }
            if (option_char == 'v'){
                v = atoi(optarg);
            }
            if (option_char == 'd'){
                d = atoi(optarg);
            }
        }
    if (cyclingfunction == 1){
        cycling(m,b,v,d);
    }
    if (footballfunction == 1){
        double passingRate = football(p,a,y,t,i);
        if (passingRate <= 85){
            cout<<"Rating "<<passingRate<<", this is poor."<<endl;
        }
        if (passingRate > 85 && passingRate <= 90){
            cout<<"Rating "<<passingRate<<", this is mediocre."<<endl;
        }
        if (passingRate >90 && passingRate <= 95){
            cout<<"Rating "<<passingRate<<", this is good."<<endl;
        }
        if (passingRate > 95){
            cout<<"Rating "<<passingRate<<", this is great."<<endl;
        }

    }
	return 0;
}
