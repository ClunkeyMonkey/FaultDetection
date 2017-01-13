#ifndef DATACOLLECT_H
#define DATACOLLECT_H
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

json* openJSON();
void readJSON(json* j);
void closeJSON(json* j);

#endif // DATACOLLECT_H
