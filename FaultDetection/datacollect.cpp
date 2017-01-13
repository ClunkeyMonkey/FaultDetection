#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

json* openJSON(){
    json* j = new json;
    ifstream i;
    while (!i.is_open()){
        i.open("C:/Users/caelanv/Documents/FaultDetection/FaultDetection/sample.json", ios::in);
    }
    i >> j[0];
    i.close();
    return j;
}

void readJSON(json* j){
    cout << j[0].dump(4) << endl;
}

void closeJSON(json* j){
    delete j;
}
