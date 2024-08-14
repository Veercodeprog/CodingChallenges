#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;
int numOfIslands, currentIndex;

// Array to store the x-axis coverage range of each island by radar
pair<double, double> coverageRange[1005];
int calculateRadarCount() {
  double range = -1e9;
  int radarCount = 0;
  sort(coverageRange, coverageRange + numOfIslands);
  currentIndex = 0;
  while (currentIndex < numOfIslands) {

    while (currentIndex < numOfIslands &&
           coverageRange[currentIndex].first <= range) {
      range = min(range, coverageRange[currentIndex].second);
      ++currentIndex;
    }
    ++radarCount;
    range = coverageRange[currentIndex].second;
    currentIndex++;
  }
  cout << "coverage range pair: " << coverageRange << endl;
  return radarCount - 1;
}

int main() {

  double x, y, d;
  int invalidCase, caseNum = 0;

  while ((cin >> numOfIslands >> d) && numOfIslands) {
    invalidCase = 0;
    for (int i = 0; i < numOfIslands; ++i) {
      cin >> x >> y;
      if (y > d) {
        invalidCase = 1;
      } else {
        coverageRange[i].first = x - sqrt(d * d - y * y);
        coverageRange[i].second = x + sqrt(d * d - y * y);
      }
    }
    cout << "Case " << ++caseNum << ": "
         << (invalidCase ? -1 : calculateRadarCount()) << endl;
  }
  return 0;
}
