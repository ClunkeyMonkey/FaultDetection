#include "json.hpp"

#include "datacollect.hpp"
#include "doorswitchanalysis.hpp"
#include "dutyanalysis.hpp"
#include "poweranalysis.hpp"
#include "temperatureanalysis.hpp"

using namespace std;
using json = nlohmann::json;

int main(){
    json* raw = openJSON();
    get_data(raw);

    get_Dt(raw);

    closeJSON(raw);
    return 0;
}
