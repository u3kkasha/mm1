#include <string>

#include <stdlib.h>

using namespace std;

int main()

{

  int mean_inter_arrival_time = 1000;

  int mean_service_time = 1;

  while (++mean_service_time < mean_inter_arrival_time)

    system((string("./tandem ") + to_string(mean_inter_arrival_time) + ' ' +
            to_string(mean_service_time) + " >> output.csv")
               .c_str());

  return 0;
}