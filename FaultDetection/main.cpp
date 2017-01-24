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
    json* data = get_data(raw);

    closeJSON(data);
    return 0;
}
