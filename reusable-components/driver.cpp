#include <string>

#include <stdlib.h>

using namespace std;

int main()

{

  auto seeds={4784, 946783, 536743, 6882, 29383, 39872, 29577894, 97567490, 6503461, 55};
  for(auto seed : seeds)

    system((string("./system ") + to_string(seed) + " >> output.csv")
               .c_str());

  return 0;
}