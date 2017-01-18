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

json* get_data(json* j){
    int l = getLastBlock(j);    //holds the last block in the log
    int powVal = ((j[0]["result"]["results"][0]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][0]["subDayStat"]["stats"][1]["lt"].get<long long>())/21600000);
    int val = (l + 1 - powVal) / 2;
    int i = 0;

    ofstream out;
    while (!out.is_open()){
        out.open("C:/test.json", ios::out);
    }

    float* t1a = get_t1a(j, l, val);
    out << "{\n\t\"log\":{\n\t\t\"t1a\": [\n\t\t\t" << t1a[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t1a[i];
    }

    int* t1m = get_t1m(j, l, val);
    out << "\n\t\t],\n\t\t\"t1m\":[\n\t\t\t" << t1m[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t1m[i];
    }

    int* t1x = get_t1x(j, l, val);
    out << "\n\t\t],\n\t\t\"t1x\":[\n\t\t\t" << t1x[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t1x[i];
    }

    int* lt = get_lt(j, l, val);
    out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t" << lt[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << lt[i];
    }

    int* pa = get_pa(j, l, val);
    out << "\n\t\t],\n\t\t\"pa\":[\n\t\t\t" << pa[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << pa[i];
    }

    int* cmt = get_cmt(j, l, val);
    out << "\n\t\t],\n\t\t\"cmt\":[\n\t\t\t" << cmt[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << cmt[i];
    }

    int* t2a = get_t2a(j, l, val);
    out << "\n\t\t],\n\t\t\"t2a\":[\n\t\t\t" << t2a[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t2a[i];
    }

    int* t2x = get_t2x(j, l, val);
    out << "\n\t\t],\n\t\t\"t2x\":[\n\t\t\t" << t2x[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << t2x[i];
    }

    int* doDATA = get_do(j, l, val);
    out << "\n\t\t],\n\t\t\"do\":[\n\t\t\t" << doDATA[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << doDATA[i];
    }

    int* dos = get_dos(j, l, val);
    out << "\n\t\t],\n\t\t\"dos\":[\n\t\t\t" << dos[0];
    for (i = 1; i < val; i++){
        out << ",\n\t\t\t" << dos[i];
    }

    int* cmp = get_cmp(j, l, powVal); //\n\t\"len\":" << val
    out << "\n\t\t],\n\t\t\"len\":" << val << "\n\t},\n\t\"pow\":{\n\t\t\"cmp\":[\n\t\t\t" << cmp[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << cmp[i];
    }

    int* cnp = get_cnp(j, l, powVal);
    out << "\n\t\t],\n\t\t\"cnp\":[\n\t\t\t" << cnp[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << cnp[i];
    }

    int* ep = get_ep(j, l, powVal);
    out << "\n\t\t],\n\t\t\"ep\":[\n\t\t\t" << ep[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << ep[i];
    }

    int* l1p = get_l1p(j, l, powVal);
    out << "\n\t\t],\n\t\t\"l1p\":[\n\t\t\t" << l1p[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << l1p[i];
    }

    int* ltPow = get_ltPow(j, l, powVal);
    out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t" << ltPow[0];
    for (i = 1; i < powVal; i++){
        out << ",\n\t\t\t" << ltPow[i];
    }

    out << "\n\t\t], \n\t\t\"len\":" << powVal << "\n\t}\n}";

    out.close();

    ifstream in;
    while (!in.is_open()){
        in.open("C:/test.json", ios::in);
    }
    in >> j[0];
    in.close();
    return j;
}
