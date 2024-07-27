#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
=
int main() {
    // Example usage
    Solution sol;
    vector <int> people = {3,2,2,1};
    int limit = 3;
    int numBoats = sol.numRescueBoats(people, limit);
    // Output the number of boats needed
  cout << "Number of boats needed: " << numBoats << endl;
    return 0;
}
