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
		//This is the address of the file that will be opened. Change what is in the quotation marks to change what file is being opened. It will currently open the file "JSONTest.json" in the root directory in C drive
        i.open("C:/JSONTest.json", ios::in);
    }
    i >> j[0];
    i.close();
    return j;
}

//This makes a console output of the JSON data
void readJSON(json* j){
    cout << j[0].dump(4) << endl;
}

//This closes the json file
void closeJSON(json* j){
    delete j;
}

//These three functions find the last items in the lists of the json file
int getLastBlock(json* j, int day){
    int i = 0;  //will result in index of the last block, once loop finished
    json::iterator it = j[0]["result"]["results"][day]["subDayStat"]["stats"].end();
    it--;
    json temp = *it;
    while(temp != j[0]["result"]["results"][day]["subDayStat"]["stats"][i]){
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
int getLastEvent(json* j, int day){
    int i = 0;  //will result in index of the last block, once loop finished
    json::iterator it = j[0]["result"]["results"][day]["subDayStat"]["events"].end();
    it--;
    json temp = *it;
    while(temp != j[0]["result"]["results"][day]["subDayStat"]["events"][i]){
        i++;
    }
    return i;
}

//Gets the data from the stat logs
float* get_t1a(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    float* t1a = new float[val + 10];    //makes the required array
    t1a[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1a"] != NULL){
            t1a[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1a"];
            pos++;
        }
    }
    return t1a;
}
int* get_t1m(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t1m = new int[val + 10];    //makes the required array
    t1m[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1m"] != NULL){
            t1m[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1m"];
            pos++;
        }
    }
    return t1m;
}
int* get_t1x(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t1x = new int[val + 10];    //makes the required array
    t1x[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1x"] != NULL){
            t1x[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1x"];
            pos++;
        }
    }
    return t1x;
}
int* get_pa(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* pa = new int[val + 10];    //makes the required array
    pa[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["pa"] != NULL){
            pa[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["pa"];
            pos++;
        }
    }
    return pa;
}
int* get_cmt(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cmt = new int[val + 10];    //makes the required array
    cmt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmt"] != NULL){
            cmt[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmt"];
            pos++;
        }
    }
    return cmt;
}
int* get_t2a(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t2a = new int[val + 10];    //makes the required array
    t2a[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t2a"] != NULL){
            t2a[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t2a"];
            pos++;
        }
    }
    return t2a;
}
int* get_t2x(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* t2x = new int[val + 10];    //makes the required array
    t2x[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t2x"] != NULL){
            t2x[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t2x"];
            pos++;
        }
    }
    return t2x;
}
int* get_do(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* doDATA = new int[val + 10];    //makes the required array
    doDATA[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["do"] != NULL){
            doDATA[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["do"];
            pos++;
        }
    }
    return doDATA;
}
int* get_dos(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* dos = new int[val + 10];    //makes the required array
    dos[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["dos"] != NULL){
            dos[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["dos"];
            pos++;
        }
    }
    return dos;
}
int* get_lt(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* lt = new int[val + 10];    //makes the required array
    lt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1x"] != NULL){
            lt[pos] = (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["lt"].get<long long>()/1000);
            pos++;
        }
    }
    return lt;
}
int* get_rt(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* rt = new int[val + 10];         //makes the required array
    rt[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["t1x"] != NULL){
            rt[pos] = (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["rt"].get<int>());
            pos++;
        }
    }
    return rt;
}

//Gets power data from the stat logs
int* get_cmp(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cmp = new int[val + 10];        //makes the required array
    cmp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmp"] != NULL){
            cmp[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmp"];
            //cout << cmp[pos] << '\t' << pos << endl;
            pos++;
        }
    }
    return cmp;
}
int* get_cnp(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* cnp = new int[val + 10];        //makes the required array
    cnp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cnp"] != NULL){
            cnp[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cnp"];
            pos++;
        }
    }
    return cnp;
}
int* get_ep(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* ep = new int[val + 10];        //makes the required array
    ep[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["ep"] != NULL){
            ep[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["ep"];
            pos++;
        }
    }
    return ep;
}
int* get_l1p(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* l1p = new int[val + 10];        //makes the required array
    l1p[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["l1p"] != NULL){
            l1p[pos] = j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["l1p"];
            pos++;
        }
    }
    return l1p;
}
int* get_ltPow(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* ltp = new int[val + 10];    //makes the required array
    ltp[val] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmp"] != NULL){
            ltp[pos] = (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["lt"].get<long long>()/1000);
            pos++;
        }
    }
    return ltp;
}
int* get_rtPow(json* j, int l, int val, int day){
    int i = 1;                          //holds currently observed index
    int pos = 0;                        //holds index to be filled
    int* rt = new int[val + 10];    //makes the required array
    rt[val - 1] = 0;

    for(i = 1; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["cmp"] != NULL){
            rt[pos] = (j[0]["result"]["results"][day]["subDayStat"]["stats"][i]["rt"].get<int>());
            pos++;
        }
    }
    return rt;
}

//Gets the event data from the event stat logs
int findEventCount(json* j, int l, int day){
    int i = 0;
    int count = 0;

    while (i < l){
        if (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["di"] == NULL){
            count++;
        }
        i++;
    }
    return count;
}
int* get_et(json* j, int l, int val, int day){
    int i = 0;
    int pos = 0;
    int* et = new int[val + 10];
    et[val - 1] = 0;

    for(i = 0; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["di"] == NULL){
            et[pos] = (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["et"].get<int>());
            pos++;
        }
    }
    return et;
}
int* get_ltEvent(json* j, int l, int val, int day){
    int i = 0;
    int pos = 0;
    int* lt = new int[val + 10];
    lt[val - 1] = 0;

    for(i = 0; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["di"] == NULL){
            lt[pos] = (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["lt"].get<long long>()/1000);
            pos++;
        }
    }
    return lt;
}
int* get_rtEvent(json* j, int l, int val, int day){
    int i = 0;
    int pos = 0;
    int* rt = new int[val + 10];
    rt[val - 1] = 0;

    for(i = 0; i <= l; i++){
        if (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["di"] == NULL){
            rt[pos] = (j[0]["result"]["results"][day]["subDayStat"]["events"][i]["rt"].get<long long>()/1000);
            pos++;
        }
    }
    return rt;
}


//This function translates the stat logs into a stream of data for each stat type (t1a, t2x, etc.)
json* get_data(json* j){
    int dayI = getLastDay(j);

    int l = 0;
    int powVal = 0;
    int val = 0;

    int i = 0;
    int k = 0;
    int n = 0;
    int count = 0;
    float* t1a = NULL;
    int* data = NULL;

    ofstream out;
    while (!out.is_open()){
		//This opens the output file. The double quoted string is the file Address. This opens a file called "test.json" in the root directory of C drive
        out.open("C:/test.json", ios::out);
    }

    out << "{\n\t\"logs\":{\n\t\t\"t1a\": [\n\t\t\t";
	//This gathers the t1a data
    for (k = 0; k <= dayI; k++){
        l = getLastBlock(j, k);

        powVal = floor((round((j[0]["result"]["results"][k]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][k]["subDayStat"]["stats"][1]["lt"].get<long long>())/2160000.0) - 1) / 10.0);
        val = (l + 1 - powVal) / 2;
        t1a = get_t1a(j, l, val, k);
        out << t1a[0];
        for (i = 1; i < val; i++){
            out << ",\n\t\t\t" << t1a[i];
        }
        if (k != dayI){
            out << ",\n\t\t\t";
        }
        delete[] t1a;
    }

	//This gathers the remaining stat log data, this makes 10 passes to gather all 10 remaining stats
    for (n = 0; n <= 9; n++){
        count = 0;
        if (n == 0){
			//n = 0 correspondes to t1m
            out << "\n\t\t],\n\t\t\"t1m\":[\n\t\t\t";
        } else if (n == 1){
			//n = 1 correspondes to t1x
            out << "\n\t\t],\n\t\t\"t1x\":[\n\t\t\t";
        } else if (n == 2){
			//n = 2 correspondes to pa
            out << "\n\t\t],\n\t\t\"pa\":[\n\t\t\t";
        } else if (n == 3){
			//n = 3 correspondes to cmt
            out << "\n\t\t],\n\t\t\"cmt\":[\n\t\t\t";
        } else if (n == 4){
			//n = 4 correspondes to t2a
            out << "\n\t\t],\n\t\t\"t2a\":[\n\t\t\t";
        } else if (n == 5){
			//n = 5 correspondes to t2x
            out << "\n\t\t],\n\t\t\"t2x\":[\n\t\t\t";
        } else if (n == 6){
			//n = 6 correspondes to do
            out << "\n\t\t],\n\t\t\"do\":[\n\t\t\t";
        } else if (n == 7){
			//n = 7 correspondes to dos
            out << "\n\t\t],\n\t\t\"dos\":[\n\t\t\t";
        } else if (n == 8){
			//n = 8 correspondes to lt
            out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t";
        } else if (n == 9){
			//n = 9 correspondes to rt
            out << "\n\t\t],\n\t\t\"rt\":[\n\t\t\t";
        }
        for (k = 0; k <=dayI; k++){
            l = getLastBlock(j, k);
            powVal = floor((round((j[0]["result"]["results"][k]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][k]["subDayStat"]["stats"][1]["lt"].get<long long>())/2160000.0) - 1) / 10.0);
            val = (l + 1 - powVal) / 2;
            if (n == 0){
                data = get_t1m(j, l, val, k);
            } else if (n == 1){
                data = get_t1x(j, l, val, k);
            } else if (n == 2){
                data = get_pa(j, l, val, k);
            } else if (n == 3){
                data = get_cmt(j, l, val, k);
            } else if (n == 4){
                data = get_t2a(j, l, val, k);
            } else if (n == 5){
                data = get_t2x(j, l, val, k);
            } else if (n == 6){
                data = get_do(j, l, val, k);
            } else if (n == 7){
                data = get_dos(j, l, val, k);
            } else if (n == 8){
                data = get_lt(j, l, val, k);
            } else if (n == 9){
                data = get_rt(j, l, val, k);
            }
            out << data[0];
            count++;
            for (i = 1; i < val; i++){
                out << ",\n\t\t\t" << data[i];
                count++;
            }
            if (k != dayI){
                out << ",\n\t\t\t";
            }
            delete[] data;
        }
    }
    out << "\n\t\t],\n\t\t\"len\":" << count << "\n\t},\n\t";
	
	//This gathers the four power stats and the corresponding time stamps
    for (n = 0; n <= 5; n++){
        count = 0;
        if (n == 0){
			//n = 0 correspondes to cmp
            out << "\"power\":{\n\t\t\"cmp\":[\n\t\t\t";
        } else if (n == 1){
			//n = 1 correspondes to cnp
            out << "\n\t\t],\n\t\t\"cnp\":[\n\t\t\t";
        } else if (n == 2){
			//n = 2 correspondes to ep
            out << "\n\t\t],\n\t\t\"ep\":[\n\t\t\t";
        } else if (n == 3){
			//n = 3 correspondes to l1p
            out << "\n\t\t],\n\t\t\"l1p\":[\n\t\t\t";
        } else if (n == 4){
			//n = 4 correspondes to lt
            out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t";
        } else if (n == 5){
			//n = 5 correspondes to rt
            out << "\n\t\t],\n\t\t\"rt\":[\n\t\t\t";
        }
        for (k = 0; k <=dayI; k++){
            l = getLastBlock(j, k);
            powVal = floor((round((j[0]["result"]["results"][k]["subDayStat"]["stats"][l]["lt"].get<long long>() - j[0]["result"]["results"][k]["subDayStat"]["stats"][1]["lt"].get<long long>())/2160000.0) - 1) / 10.0);
            val = (l + 1 - powVal) / 2;

            cout << val << '\t' << powVal << endl;

            if (n == 0){
                data = get_cmp(j, l, powVal, k);
            } else if (n == 1){
                data = get_cnp(j, l, powVal, k);
            } else if (n == 2){
                data = get_ep(j, l, powVal, k);
            } else if (n == 3){
                data = get_l1p(j, l, powVal, k);
            } else if (n == 4){
                data = get_ltPow(j, l, powVal, k);
            } else if (n == 5){
                data = get_rtPow(j, l, powVal, k);
            }
            out << data[0];
            count++;
            for (i = 1; i < powVal; i++){
                out << ",\n\t\t\t" << data[i];
                /*if (n == 0){
                    cout << data[i] << endl;
                }*/
                count++;
            }
            if (k != dayI){
                out << ",\n\t\t\t";
            }
            delete[] data;
        }
    }
    out << "\n\t\t], \n\t\t\"len\":" << count << "\n\t},\n\t";

	//This gathers a log of the events and the corresponding time stamps
    for (n = 0; n <= 2; n++){
        count = 0;
        if (n == 0){
			//n = 0 correspondes to et
            out << "\"events\":{\n\t\t\"et\":[\n\t\t\t";
        } else if (n == 1){
			//n = 1 correspondes to lt
            out << "\n\t\t],\n\t\t\"lt\":[\n\t\t\t";
        } else if (n == 2){
			//n = 2 correspondes to rt
            out << "\n\t\t],\n\t\t\"rt\":[\n\t\t\t";
        }
        for (k = 0; k <= dayI; k++){
            l = getLastEvent(j, k);
            val = findEventCount(j, l, k);
            if (n == 0){
                data = get_et(j, l, val, k);
            } else if (n == 1){
                data = get_ltEvent(j, l, val, k);
            } else if (n == 2){
                data = get_rtEvent(j, l, val, k);
            }
            out << data[0];
            count++;
            for (i = 1; i < val; i++){
                out << ",\n\t\t\t" << data[i];
                count++;
            }
            if (k != dayI){
                out << ",\n\t\t\t";
            }
            delete[] data;
        }
    }
    out << "\n\t\t], \n\t\t\"len\":" << count << "\n\t}\n}";
    out.close();
	//Here is where the newly written json file is opened so that it can be used in the program (from here to the next comment can be deleted)
    ifstream in;
    while (!in.is_open()){
        in.open("C:/test.json", ios::in);
    }
    in >> j[0];
    in.close();
	//End of new file opening and data overwriting
    return j;
}

//This function creates the csv file from the json data that is brought into the program in the openJSON function.
void get_csv(json* j){
    int dayI = getLastDay(j);

    int l = 0;
    int i = 0;
    int k = 0;

    ofstream out;
    while (!out.is_open()){
		//This opens the "test.csv" file in the root directory of the C drive. This file can be changed by changing the address of the file in the double quotations
        out.open("C:/test.csv", ios::out);
    }

    out << "rt,lt,tsp (°C),as,cmt (%),dot,pa (W),t1a (°C),";
    out << "t1x (°C),t1m (°C),t2a (°C),t2x (°C),vx (V),vm (V),do,dos\n";
    for (k = 0; k <= dayI; k++){
        l = getLastBlock(j, k);
        for (i = 0; i <= l; i++){
            if ((j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["tsp"] != NULL) && (j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["cmt"] != NULL)){
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["rt"].get<int>() << ",";
                out << to_string(j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["lt"].get<long long int>()) << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["tsp"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["as"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["cmt"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["dot"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["pa"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["t1a"].get<float>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["t1x"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["t1m"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["t2a"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["t2x"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["vx"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["vm"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["do"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i + 1]["dos"].get<int>() << "\n";
            }
        }
    }

    out << "\n\nrt,lt,cmp,ep,cnp,l1p,dp\n";
    for (k = 0; k <= dayI; k++){
        l = getLastBlock(j, k);
        for (i = 0; i <= l; i++){
            if (j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["ep"] != NULL){
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["rt"].get<int>() << ",";
                out << to_string(j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["lt"].get<long long int>()) << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["cmp"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["ep"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["cnp"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["l1p"].get<int>() << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["stats"][i]["dp"].get<int>() << "\n";
            }
        }
    }

    out << "\n\nrt,lt,Event Code\n";
    for (k = 0; k <= dayI; k++){
        l = getLastBlock(j, k);
        for (i = 0; i <= l; i++){
            if (j[0]["result"]["results"][k]["subDayStat"]["events"][i]["pv"] != NULL){
                out << j[0]["result"]["results"][k]["subDayStat"]["events"][i]["rt"].get<int>() << ",";
                out << to_string(j[0]["result"]["results"][k]["subDayStat"]["events"][i]["lt"].get<long long int>()) << ",";
                out << j[0]["result"]["results"][k]["subDayStat"]["events"][i]["et"].get<int>() << "\n";
            }
        }
    }
    out.close();
}
