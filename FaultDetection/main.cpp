#include "json.hpp"

#include "datacollect.hpp"
#include "doorswitchanalysis.hpp"
#include "poweranalysis.hpp"
#include "temperatureanalysis.hpp"

using namespace std;
using json = nlohmann::json;

int main(){
    json data;

    data = openJSON();
    cout << data.dump(4) << endl;
    return 0;
}
