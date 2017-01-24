#ifndef DATACOLLECT_H
#define DATACOLLECT_H
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

json* openJSON();
void readJSON(json* j);
void closeJSON(json* j);

int getLastDay(json* j);
int getLastBlock(json* j, int day);
int getLastEvent(json* j, int day);

float* get_t1a(json* j, int l, int val, int day = 0);
int* get_t1m(json* j, int l, int val, int day = 0);
int* get_t1x(json* j, int l, int val, int day = 0);
int* get_pa(json* j, int l, int val, int day = 0);
int* get_cmt(json* j, int l, int val, int day = 0);
int* get_t2a(json* j, int l, int val, int day = 0);
int* get_t2x(json* j, int l, int val, int day = 0);
int* get_do(json* j, int l, int val, int day = 0);
int* get_dos(json* j, int l, int val, int day = 0);
int* get_lt(json* j, int l, int val, int day = 0);
int* get_rt(json* j, int l, int val, int day = 0);

int* get_cmp(json* j, int l, int val, int day = 0);
int* get_cnp(json* j, int l, int val, int day = 0);
int* get_ep(json* j, int l, int val, int day = 0);
int* get_l1p(json* j, int l, int val, int day = 0);
int* get_ltPow(json* j, int l, int val, int day = 0);
int* get_rtPow(json* j, int l, int val, int day = 0);

int findEventCount(json* j, int l, int day);
int* get_et(json* j, int l, int val, int day);
int* get_ltEvent(json* j, int l, int val, int day);

json* get_data(json* j);

#endif // DATACOLLECT_H
