#include <iostream>
#include <vector>
#include <cstdlib> // For EXIT_SUCCESS
#include <map>
using namespace std;
class Solution
{
public:
    int findCenter(std::vector<std::vector<int>> &edges)
    {
        map<int, int> mymap;
        for (const auto &row : edges)
        {
            for (int num : row)
            {
                mymap[num]++;
            } 
        }
       
        int maxElement = edges[0][0];
        int maxFrequency = 0;
        for (const auto &pair : mymap)
        {
            if (pair.second > maxFrequency)
            {
                maxElement = pair.first;
                maxFrequency = pair.second;
            }
        }
        return maxElement;
        // Assuming findCenter implementation here
        // The implementation will determine the center node in the star graph
    }
};

int main()
{
    Solution solution;

    // Example input: edges of a star graph
    vector<std::vector<int>> edges = {
        {1, 2},
        {5,1},
        {1,3},
        {1,4}};

    int center = solution.findCenter(edges);

    cout << "The center of the star graph is: " << center << std::endl;

    return EXIT_SUCCESS;
}
