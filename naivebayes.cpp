#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <time.h>

using namespace std;

vector<double> trainTest(vector<double> sex, float tSize = 0.8) {
    vector<double> train;
    vector<double> test;

    srand(time(NULL));
};

int main(int argc, char* argv) {
    ifstream titanic;
    titanic.open("titanic_project.csv");
    string throwaway, pclass, survived, sex, age;
    vector<double> classVector(1000);
    vector<double> surVector(1000);
    vector<double> sexVector(1000);
    vector<double> ageVector(1000);
    string line;
    vector<double> train;
    vector<double> test;

    //milliseconds mil(1000);

    cout << "Good Morning World" << endl;

    if(!titanic.is_open()) {
        cout << "Error opening the file" << endl;
    }
    else {
        cout << "Success!" << endl;
    }

    getline(titanic, line);

    int num = 0;
    while (getline(titanic, line)) {
        getline(titanic, throwaway, ',');
        getline(titanic, pclass, ',');
        getline(titanic, survived, ',');
        getline(titanic, sex, ',');
        getline(titanic, age, '\n');

        classVector.at(num) = stof(pclass);
        surVector.at(num) = stof(survived);
        sexVector.at(num) = stof(sex);
        ageVector.at(num) = stof(age);

        num++;
    }

    sexVector.resize(num);
    double length = sexVector.size();

    int val1;
    for(int i = 0; i < classVector.size(); i++){
        cin >> val1;
        if(val1 > 0) {
            classVector.push_back(val1);
        }
    }
    //cout << classVector.size();



    //survivability based on sex, first 800 obs.
    //function()
    cout << "Survivability based on sex: ";
    cout << "";

}
