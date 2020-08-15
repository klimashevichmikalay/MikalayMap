#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATIONGENERATOR_H

#include <vector>

using namespace std;

class PermutationsGenerator {
 public:
  void go(int offset,
          int k,
          vector<int>& p,
          vector<int>& c,
          vector<vector<int>>& result) {
    if (k == 0) {
      result.push_back(c);
      return;
    }
    for (size_t i = offset; i <= p.size() - k; ++i) {
      c.push_back(p[i] - 1);
      go(i + 1, k - 1, p, c, result);
      c.pop_back();
    }
  }

  vector<vector<int>> getPermutations(int n, int k) {
    vector<int> p;
    vector<int> c;

    vector<vector<int>> result;
    for (int i = 0; i < n; ++i) {
      p.push_back(i + 1);
    }
    go(0, k, p, c, result);

    return result;
  }
};

#endif  // PERMUTATIONGENERATOR_H
