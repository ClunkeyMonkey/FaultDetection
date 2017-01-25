#ifndef TEMPERATUREANALYSIS_H
#define TEMPERATUREANALYSIS_H
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void get_Dt1a (json* j);
void get_Dt1m (json* j);
void get_Dt1x (json* j);
void get_Dt2a (json* j);
void get_Dt2x (json* j);

void get_Dt(json* j);

#endif // TEMPERATUREANALYSIS_H
