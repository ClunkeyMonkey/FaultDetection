#ifndef DATACOLLECT_H
#define DATACOLLECT_H
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

json* openJSON();
void readJSON(json* j);
void closeJSON(json* j);

int getLastBlock(json* j);

float* get_t1m(json* j);
float* get_t1a(json* j);
float* get_t1x(json* j);



#endif // DATACOLLECT_H
