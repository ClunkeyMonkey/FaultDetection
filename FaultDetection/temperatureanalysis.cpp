#include "json.hpp"
#include <math.h>

using namespace std;
using json = nlohmann::json;

void get_Dt1a(json* j){
    int i = 0;

    j[0]["logs"]["Dt1a"] = {0.0};

    for (i = 1; i < j[0]["logs"]["len"].get<int>(); i++){
        j[0]["logs"]["Dt1a"] += (round((j[0]["logs"]["t1a"][i].get<float>() - j[0]["logs"]["t1a"][i - 1].get<float>()) * 10))/10.0;
    }
}
void get_Dt1m(json* j){
    int i = 0;

    j[0]["logs"]["Dt1m"] = {0.0};

    for (i = 1; i < j[0]["logs"]["len"].get<int>(); i++){
        j[0]["logs"]["Dt1m"] += (round((j[0]["logs"]["t1m"][i].get<float>() - j[0]["logs"]["t1m"][i - 1].get<float>()) * 10))/10.0;
    }
}
void get_Dt1x(json* j){
    int i = 0;

    j[0]["logs"]["Dt1x"] = {0.0};

    for (i = 1; i < j[0]["logs"]["len"].get<int>(); i++){
        j[0]["logs"]["Dt1x"] += (round((j[0]["logs"]["t1x"][i].get<float>() - j[0]["logs"]["t1x"][i - 1].get<float>()) * 10))/10.0;
    }
}
void get_Dt2a(json* j){
    int i = 0;

    j[0]["logs"]["Dt2a"] = {0.0};

    for (i = 1; i < j[0]["logs"]["len"].get<int>(); i++){
        j[0]["logs"]["Dt2a"] += (round((j[0]["logs"]["t2a"][i].get<float>() - j[0]["logs"]["t2a"][i - 1].get<float>()) * 10))/10.0;
    }
}
void get_Dt2x(json* j){
    int i = 0;

    j[0]["logs"]["Dt2x"] = {0.0};

    for (i = 1; i < j[0]["logs"]["len"].get<int>(); i++){
        j[0]["logs"]["Dt2x"] += (round((j[0]["logs"]["t2x"][i].get<float>() - j[0]["logs"]["t2x"][i - 1].get<float>()) * 10))/10.0;
    }
}

void get_Dt(json* j){
    get_Dt1a(j);
    get_Dt1m(j);
    get_Dt1x(j);
    get_Dt2a(j);
    get_Dt2x(j);
}
