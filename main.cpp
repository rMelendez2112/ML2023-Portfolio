#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


int sum(vector<double> rm, vector<double> medv, double len){
    double rmSum, medvSum;

    for(int i = 0; i < len; i++) {
        rmSum += rm[i];
    }

    for(int j = 0; j < len; j++) {
        medvSum += medv[j];
    }

    cout << "Room sum: " << rmSum << endl;
    cout << "Median Home Value sum: " << medvSum << endl;
    cout << "__________" << endl;
}

int mean(vector<double> rm, vector<double> medv, double len){
    double rmSum, medvSum, rmMean, medvMean;

    for(int i = 0; i < len; i++) {
        rmSum += rm[i];
    }

    for(int j = 0; j < len; j++) {
        medvSum += medv[j];
    }

    rmMean = rmSum / len;
    medvMean = medvSum / len;

    cout << "Mean of Room: " << rmMean << endl;
    cout << "Mean of Median Home Value: " << medvMean << endl;
    cout << "__________" << endl;
}

int median(vector<double> rm, vector<double> medv, double len) {
    int temp = 0;

    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(rm[i] > rm[j]) {
                temp = rm[i];
                rm[i] = rm[j];
                rm[j] = temp;
            }
        }
    }

    temp = 0;
    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(medv[i] > medv[j]) {
                temp = medv[i];
                medv[i] = medv[j];
                medv[j] = temp;
            }
        }
    }


    cout << "Median of Room: " << rm[len/2] << endl;
    cout << "Median of Median Home Value: " << medv[len/2] << endl;
    cout << "__________" << endl;
}

int range(vector<double> rm, vector<double> medv, double len) {
    double rmRange, medvRange;
    int temp = 0;

    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(rm[i] > rm[j]) {
                temp = rm[i];
                rm[i] = rm[j];
                rm[j] = temp;
            }
        }
    }

    temp = 0;
    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(medv[i] > medv[j]) {
                temp = medv[i];
                medv[i] = medv[j];
                medv[j] = temp;
            }
        }
    }

    rmRange = rm[0] - rm[len];
    medvRange = medv[0] = medv[len];
    cout << "Range of Room: " << rmRange << endl;
    cout << "Range of Median Home Vale: " << medvRange << endl;
    cout << "__________" << endl;

}

int rmStats(vector<double> rm, double len) {
    double rmSum, rmMean, rmRange;

    for(int i = 0; i < len; i++) {
        rmSum += rm[i];
    }

    rmMean = rmSum / len;

    int temp = 0;
    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(rm[i] > rm[j]) {
                temp = rm[i];
                rm[i] = rm[j];
                rm[j] = temp;
            }
        }
    }

    rmRange = rm[0] - rm[len];

    cout << "Room sum: " << rmSum << endl;
    cout << "Mean of Room: " << rmMean << endl;
    cout << "Median of Room: " << rm[len/2] << endl;
    cout << "Range of Room: " << rmRange << endl;
    cout << "__________" << endl;
}

int medvStats(vector<double> medv, double len) {
    double medvSum, medvMean, medvRange;

    for(int i = 0; i < len; i++) {
        medvSum += medv[i];
    }

    medvMean = medvSum / len;

    int temp = 0;
    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(medv[i] > medv[j]) {
                temp = medv[i];
                medv[i] = medv[j];
                medv[j] = temp;
            }
        }
    }

    medvRange = medv[0] - medv[len];

    cout << "Median Home Value sum: " << medvSum << endl;
    cout << "Mean of Median Home Value: " << medvMean << endl;
    cout << "Median of Median Home Value: " << medv[len/2] << endl;
    cout << "Range of Median Home Value: " << medvRange << endl;
    cout << "__________" << endl;
}

double covariance(vector<double> rm, vector<double> medv, double len) {
    double rmSum, rmMean, rmRange;
    for(int i = 0; i < len; i++) {
        rmSum += rm[i];
    }
    rmMean = rmSum / len;

    double medvSum, medvMean, medvRange;
    for(int i = 0; i < len; i++) {
        medvSum += medv[i];
    }
    medvMean = medvSum / len;

    double cov = ( (rmSum - rmMean) * (medvSum - medvMean) ) / (len - 1);
    return cov;
}

int correlation(vector<double> rm, vector<double> medv, double len) {
    double rmSum, rmMean, rmRange;
    for(int i = 0; i < len; i++) {
        rmSum += rm[i];
    }
    rmMean = rmSum / len;

    double medvSum, medvMean, medvRange;
    for(int i = 0; i < len; i++) {
        medvSum += medv[i];
    }
    medvMean = medvSum / len;

    //new array to solve st deviation
    vector<double> rmArr(len);
    double rmNewSum;
    for(int i = 0; i < len; i++) {
        rmArr[i] = rm[i] - rmMean;
        rmNewSum += rmArr[i];
    }

    double rmNewMean = rmNewSum / len;


    vector<double> medvArr(len);
    double medvNewSum;
    for(int i = 0; i < len; i++) {
        medvArr[i] = medv[i] - medvMean;
        medvNewSum += medvArr[i];
    }

    double medvNewMean = medvNewSum / len;

    double cov = covariance(rm, medv, len);
    double rmStd = sqrt(rmNewMean);
    double medvStd = sqrt(medvNewMean);

    double corr = cov / (rmStd * medvStd);
    return corr;
}

int main(int argc, char* argv)
{
    ifstream boston;
    boston.open("Boston.csv");
    string rm, medv;
    vector<double> rmVector(1000);
    vector<double> medvVector(1000);
    string line;

    cout << "Good Morning World" << endl;

    if(!boston.is_open()) {
        cout << "Error opening the file" << endl;
    }
    else {
        cout << "Success!" << endl;
    }

    getline(boston, line);

    int num = 0;
    while (getline(boston, line)) {
        getline(boston, rm, ',');
        getline(boston, medv, '\n');

        rmVector.at(num) = stof(rm);
        medvVector.at(num) = stof(medv);
        num++;
    }

    rmVector.resize(num);
    medvVector.resize(num);
    double length = rmVector.size();

    cout << "length: " << length << endl;
    boston.close();
    cout << "Total Records: " << num << endl;

    cout << "Room Stats: \n" << rmStats(rmVector, length) << endl;
    cout << "Median Home Value Stats: \n" <<  medvStats(medvVector, length) << endl;
    cout << "Covariance: " << covariance(rmVector, medvVector, length) << endl;
    cout << "Correlation: " << correlation(rmVector, medvVector, length) << endl;

	return 0;
}
