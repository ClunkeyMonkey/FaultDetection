#include "json.hpp"

#include "datacollect.hpp"
#include "doorswitchanalysis.hpp"
#include "dutyanalysis.hpp"
#include "poweranalysis.hpp"
#include "temperatureanalysis.hpp"

using namespace std;
using json = nlohmann::json;

int main(){
    json* data = openJSON();
    get_t1a(data);
    //readJSON(data);
    closeJSON(data);
    return 0;
}
