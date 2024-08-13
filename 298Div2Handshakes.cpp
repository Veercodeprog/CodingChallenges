#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> HandshakePair;
const int MAX_STUDENTS = 1000001;

int main() {
  int studentCount;
  cin >> studentCount;

  set<HandshakePair> handshakesByModulo[3];
  int resultOrder[MAX_STUDENTS];

  // Reading input and categorizing based on modulo 3
  for (int i = 0; i < studentCount; i++) {
    int handshakes;
    cin >> handshakes;
    handshakesByModulo[handshakes % 3].insert(make_pair(handshakes, i));
    // Debugging: Show how handshakes are categorized
    cout << "Handshake: " << handshakes << " goes into handshakesByModulo["
         << (handshakes % 3) << "]" << endl;
  }

  int currentHandshakes = 0;

  for (int i = 0; i < studentCount; i++) {
    auto it = handshakesByModulo[currentHandshakes % 3].lower_bound(
        make_pair(currentHandshakes, -1));

    HandshakePair selectedStudent;
    if (it != handshakesByModulo[currentHandshakes % 3].end() &&
        it->first == currentHandshakes) {

      selectedStudent = *it;
      resultOrder[i] = selectedStudent.second + 1;
      cout << "Selected exact match: " << selectedStudent.first << " at index "
           << selectedStudent.second + 1 << endl;
    } else {
      if (it == handshakesByModulo[currentHandshakes % 3].begin()) {
        cout << "Impossible" << endl;
        return 0;
      } else {
        it--;
        selectedStudent = *it;
        resultOrder[i] = selectedStudent.second + 1;
        cout << "Selected lower match: " << selectedStudent.first
             << " at index " << selectedStudent.second + 1 << endl;
      }
    }
    handshakesByModulo[currentHandshakes % 3].erase(selectedStudent);
    currentHandshakes = selectedStudent.first + 1;
    cout << "Updated currentHandshakes to " << currentHandshakes << endl;
  }

  // If the loop completes, print the order
  cout << "Possible" << endl;
  for (int i = 0; i < studentCount; i++) {
    cout << resultOrder[i] << " ";
  }
  cout << endl;
}
