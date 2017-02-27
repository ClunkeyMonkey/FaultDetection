#include "json.hpp"

#include "datacollect.hpp"
#include "doorswitchanalysis.hpp"
#include "dutyanalysis.hpp"
#include "poweranalysis.hpp"
#include "temperatureanalysis.hpp"

using namespace std;
using json = nlohmann::json;

int main(){
	//This layout opens the JSON file and translates it into the new json layout (stream of each stat type [t1a, t2x, etc])
    json* raw = openJSON();
    get_data(raw);
    closeJSON(raw);
	
	/*This layout opens the JSON file and translates it into a csv file to be opened in excel
    json* raw = openJSON();
    get_csv(raw);
    closeJSON(raw);
	*/
    return 0;
}
