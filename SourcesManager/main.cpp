#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {0, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> v2 = v;

  bool isEQ = equal(v.begin(), v.end(), v2.begin(),
                    [](const int& o1, const int& o2) { return o1 == o2; });

  if (isEQ)
    cout << "\nis EQUAL\n";
  else
    cout << "\nis NOT EQUAL\n";

  cout << endl;
}
