#ifndef DATACOLLECT_H
#define DATACOLLECT_H
#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

json openfile(char* loc);

#endif // DATACOLLECT_H
