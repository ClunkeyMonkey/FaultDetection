#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

json openfile(char * loc){
    json j;
    ifstream i;
    while (!i.is_open()){
        i.open(loc, ios::in);
    }
    i >> j;
    i.close();
    return j;
}
