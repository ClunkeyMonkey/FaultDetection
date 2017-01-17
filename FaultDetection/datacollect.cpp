#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

json* openJSON(){
    json* j = new json;
    ifstream i;
    while (!i.is_open()){
        i.open("C:/JSONTest.json", ios::in);
    }
    i >> j[0];
    i.close();
    return j;
}

void readJSON(json* j){
    cout << j[0]["result"]["results"][0]["subDayStat"]["stats"][1].dump(4);
    cout << ",\n";
    cout << j[0]["result"]["results"][0]["subDayStat"]["stats"][2].dump(4) << endl;
}

void closeJSON(json* j){
    delete j;
}

int getLastBlock(json* j){
    int i = 0;  //will result in index of the last block, once loop finished
    json::iterator it = j[0]["result"]["results"][0]["subDayStat"]["stats"].end();
    it--;
    json temp = *it;
    while(temp != j[0]["result"]["results"][0]["subDayStat"]["stats"][i]){
        i++;
    }
    return i;
}

float* get_t1m(json* j){
    int* p = NULL;
    cout << j->dump(1) << endl;
    return p;
}

float* get_t1a(json* j){
    int l = getLastBlock(j);    //holds the last block in the log
    int i = 1;                  //holds current index
    int val = (l + 1 - ((j[0]["result"]["results"][0]["subDayStat"]["stats"][l]["lt"].get<int>() - j[0]["result"]["results"][0]["subDayStat"]["stats"][1]["lt"].get<int>())/21600000)) / 2;
    float* t1a = new float[val + 1];
    t1a[val] = 0;
    int count = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1a"] != NULL){
            if (i < 1000){
                cout << i << "\t\t" << j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1a"] << "\t" << j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["lt"] << endl;
            } else {
                cout << i << "\t" << j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1a"] << "\t" << j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["lt"] <<  endl;
            }
            count++;
        }
    }
    cout << count << ',' << val << endl;
    return t1a;
}

float* get_t1x(json* j){
    int* p = NULL;
    cout << j->dump(1) << endl;
    return p;
}
