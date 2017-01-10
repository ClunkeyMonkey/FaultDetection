#include <iostream>
#include <fstream>
#include "json.hpp"
#include "datacollect.h"

using namespace std;
using json = nlohmann::json;

int main(){
    json j;
    char loc[80] = "C:/Users/caelanv/Documents/FaultDetection/FaultDetection/sample.json";

    j = openfile(loc);
    return 0;
}
