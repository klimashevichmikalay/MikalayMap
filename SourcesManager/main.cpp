#include <ctime>
#include <iostream>

using namespace std;

int i = 0;
/*void f(const double& d) {
  i = d;
}*/

void f(double d) {
  i = d;
}

int main() {
  time_t start = clock();

  for (int i = 0; i < 24000000; i++)
    f(i);

  cout << clock() - start << endl;
  return 0;
}
