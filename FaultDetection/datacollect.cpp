#include "json.hpp"
#include <fstream>
#include <iostream>
#include <math.h>

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
    cout << j[0].dump(4) << endl;
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
int getLastDay(json* j){
    int i = 0;  //will result in index of the last block, once loop finished
    json::iterator it = j[0]["result"]["results"].end();
    it--;
    json temp = *it;
    while(temp != j[0]["result"]["results"][i]){
        i++;
    }
    return i;
}

int* get_t1m(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t1m = new int[val + 1];    //makes the required array
    t1m[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1m"] != NULL){
            t1m[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1m"];
            pos++;
        }
    }
    return t1m;
}
float* get_t1a(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    float* t1a = new float[val + 1];    //makes the required array
    t1a[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1a"] != NULL){
            t1a[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1a"];
            pos++;
        }
    }
    return t1a;
}
int* get_t1x(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t1x = new int[val + 1];    //makes the required array
    t1x[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1x"] != NULL){
            t1x[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1x"];
            pos++;
        }
    }
    return t1x;
}
int* get_lt(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* lt = new int[val + 1];    //makes the required array
    lt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1x"] != NULL){
            lt[pos] = (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["lt"].get<long long>()/1000);
            pos++;
        }
    }
    return lt;
}
int* get_rt(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* rt = new int[val + 1];         //makes the required array
    rt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t1x"] != NULL){
            rt[pos] = (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["rt"].get<int>());
            pos++;
        }
    }
    return rt;
}
int* get_pa(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* pa = new int[val + 1];    //makes the required array
    pa[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["pa"] != NULL){
            pa[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["pa"];
            pos++;
        }
    }
    return pa;
}
int* get_cmt(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cmt = new int[val + 1];    //makes the required array
    cmt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmt"] != NULL){
            cmt[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmt"];
            pos++;
        }
    }
    return cmt;
}
int* get_t2a(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t2a = new int[val + 1];    //makes the required array
    t2a[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t2a"] != NULL){
            t2a[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t2a"];
            pos++;
        }
    }
    return t2a;
}
int* get_t2x(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t2x = new int[val + 1];    //makes the required array
    t2x[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t2x"] != NULL){
            t2x[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["t2x"];
            pos++;
        }
    }
    return t2x;
}
int* get_do(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* doDATA = new int[val + 1];    //makes the required array
    doDATA[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["do"] != NULL){
            doDATA[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["do"];
            pos++;
        }
    }
    return doDATA;
}
int* get_dos(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* dos = new int[val + 1];    //makes the required array
    dos[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["dos"] != NULL){
            dos[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["dos"];
            pos++;
        }
    }
    return dos;
}
int* get_cmp(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cmp = new int[val + 1];        //makes the required array
    cmp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmp"] != NULL){
            cmp[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmp"];
            pos++;
        }
    }
    return cmp;
}
int* get_cnp(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cnp = new int[val + 1];        //makes the required array
    cnp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cnp"] != NULL){
            cnp[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cnp"];
            pos++;
        }
    }
    return cnp;
}
int* get_ep(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* ep = new int[val + 1];        //makes the required array
    ep[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["ep"] != NULL){
            ep[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["ep"];
            pos++;
        }
    }
    return ep;
}
int* get_l1p(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* l1p = new int[val + 1];        //makes the required array
    l1p[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["l1p"] != NULL){
            l1p[pos] = j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["l1p"];
            pos++;
        }
    }
    return l1p;
}
int* get_ltPow(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* ltp = new int[val + 1];    //makes the required array
    ltp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmp"] != NULL){
            ltp[pos] = (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["lt"].get<long long>()/1000);
            pos++;
        }
    }
    return ltp;
}
int* get_rtPow(json* j, int l, int val){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* rt = new int[val];    //makes the required array
    rt[val - 1] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["cmp"] != NULL){
            rt[pos] = (j[0]["result"]["results"][0]["subDayStat"]["stats"][i]["rt"].get<int>());
            pos++;
        }
    }
    return rt;
}
json* get_data(json* j){
    int dayI = getLastDay(j);

    int l = getLastBlock(j);    //holds the last block in the log
    int powVal = floor((round((j[0]["result"]["results"][0]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][0]["subDayStat"]["stats"][1]["lt"].get<long long>())/2160000.0) - 1) / 10.0);
    int val = (l + 1 - powVal) / 2;

    int i = 0;
    int k = 0;
    int count = 1;
    float* t1a = NULL;
    int* data = NULL;

    cout << dayI << endl;

    ofstream out;
    while (!out.is_open()){
        out.open("C:/test.json", ios::out);
    }

    out << "{\n\t\"log\":{\n\t\t\"t1a\": [\n\t\t\t";

    t1a = get_t1a(j, l, val);
    out << t1a[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t1a[i];
    }
    delete[] t1a;

    out << "\n\t\t],\n\t\t\"t1m\":[\n\t\t\t";

    data = get_t1m(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"t1x\":[\n\t\t\t";

    data = get_t1x(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t";

    data = get_lt(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"pa\":[\n\t\t\t";

    data = get_pa(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"cmt\":[\n\t\t\t";

    data = get_cmt(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"t2a\":[\n\t\t\t";

    data = get_t2a(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"t2x\":[\n\t\t\t";

    data = get_t2x(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"do\":[\n\t\t\t";

    data = get_do(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"dos\":[\n\t\t\t";

    data = get_dos(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"rt\":[\n\t\t\t";

    data = get_rt(j, l, val);
    out << data[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << data[i];
        count++;
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"len\":" << count << "\n\t},\n\t\"pow\":{\n\t\t\"cmp\":[\n\t\t\t";
    count = 1;

    data = get_cmp(j, l, powVal); //\n\t\"len\":" << val
    out << data[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"cnp\":[\n\t\t\t";

    data = get_cnp(j, l, powVal);
    out << data[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"ep\":[\n\t\t\t";

    data = get_ep(j, l, powVal);
    out << data[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"l1p\":[\n\t\t\t";

    data = get_l1p(j, l, powVal);
    out << data[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t";

    data = get_ltPow(j, l, powVal);
    out << data[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << data[i];
    }
    delete[] data;

    out << "\n\t\t],\n\t\t\"rt\":[\n\t\t\t";

    for (k = 0; k <= dayI; k++){
        l = getLastBlock(j);    //holds the last block in the log
        powVal = floor((round((j[0]["result"]["results"][k]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][k]["subDayStat"]["stats"][1]["lt"].get<long long>())/2160000.0) - 1) / 10.0);
        val = (l + 1 - powVal) / 2;
        data = get_rtPow(j, l, powVal);
        out << data[0];
        for (i = 1; i < powVal; i++){
            out << ",\n\t\t\t" << data[i];
            count++;
        }
        if (k != dayI){
            out << ",\n\t\t\t";
        }
        delete[] data;
    }
    out << "\n\t\t], \n\t\t\"len\":" << count << "\n\t}\n}";
    out.close();

    /*ifstream in;
    while (!in.is_open()){
        in.open("C:/test.json", ios::in);
    }
    in >> j[0];
    in.close();*/
    return j;
}
