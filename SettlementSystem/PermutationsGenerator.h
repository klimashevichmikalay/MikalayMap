#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATIONGENERATOR_H

#include <vector>

using namespace std;

class PermutationsGenerator {
 public:
  void swap(int *a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
  }
  bool NextSet(int *a, int n, int m) {
    int j;
    do  // повторяем пока не будет найдено следующее размещение
    {
      j = n - 1;
      while (j != -1 && a[j] >= a[j + 1]) j--;
      if (j == -1) return false;  // больше размещений нет
      int k = n - 1;
      while (a[j] >= a[k]) k--;
      swap(a, j, k);
      int l = j + 1,
          r = n - 1;  // сортируем оставшуюся часть последовательности
      while (l < r) swap(a, l++, r--);
    } while (j > m - 1);
    return true;
  }
  vector<int> getPermutation(int *a, int n)  // вывод размещения
  {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      v.push_back(a[i] - 1);
    }

    return v;
  }

  bool isVectorsEquals(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < v1.size(); i++) {
      bool flag = false;
      for (int j = 0; j < v2.size(); j++) {
        if (v1[i] == v2[j]) flag = true;
      }
      if (!flag) return false;
    }
    return true;
  }

  bool isVectorHasVector(vector<vector<int>> v1, vector<int> v2) {
    for (size_t i = 0; i < v1.size(); i++) {
      if (isVectorsEquals(v1[i], v2)) return true;
    }
    return false;
  }

  vector<vector<int>> getPermutations(int n, int m) {
    vector<vector<int>> rez;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i + 1;
    rez.push_back(getPermutation(a, m));
    while (NextSet(a, n, m)) {
      vector<int> v = getPermutation(a, m);
      if (!isVectorHasVector(rez, v)) rez.push_back(v);
    };

    return rez;
  }
};

#endif  // PERMUTATIONGENERATOR_H
