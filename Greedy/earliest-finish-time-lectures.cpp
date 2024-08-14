#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> activities[100000];

// Comparator to sort activities by their ending times
bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int maxActivities(int n, int k) {
  // Sort the activities based on their ending times
  sort(activities, activities + n, compare);

  // Initialize a vector to store end times of classrooms
  vector<int> classroomEnd(k,
                           -1); // -1 indicates that the classroom is not in use

  int roomsUsed = 0;

  for (int i = 0; i < n; i++) {
    bool assigned = false;

    // Try to assign the current activity to an existing classroom
    for (int j = 0; j < roomsUsed; j++) {
      if (classroomEnd[j] <= activities[i].first) {
        classroomEnd[j] = activities[i].second;
        assigned = true;
        break;
      }
    }

    if (!assigned) {
      // If no classroom is available, use a new classroom
      if (roomsUsed < k) {
        classroomEnd[roomsUsed] = activities[i].second;
        roomsUsed++;
      }
    }
  }

  return roomsUsed;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> activities[i].first >> activities[i].second;
  }

  cout << maxActivities(n, k) << endl;
  return 0;
}

