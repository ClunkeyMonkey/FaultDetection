#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

json openJSON(){
    json j;
    ifstream i;
    while (!i.is_open()){
        i.open("C:/Users/caelanv/Documents/FaultDetection/FaultDetection/sample.json", ios::in);
    }
    i >> j;
    i.close();
    return j;
}
