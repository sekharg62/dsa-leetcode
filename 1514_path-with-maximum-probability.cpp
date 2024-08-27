#include<iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the graph as an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob); // Because the graph is undirected
        }
        
        // Max-Heap to keep track of the maximum probability
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.emplace(1.0, start_node);

        while (!pq.empty()) {
            double curProb = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == end_node) {
                return curProb;
            }

            for (const auto& [v, prob] : graph[u]) {
                double newProb = curProb * prob;
                if (newProb > maxProb[v]) {
                    maxProb[v] = newProb;
                    pq.emplace(newProb, v);
                }
            }
        }
        
        return 0.0; // If there's no path from start_node to end_node
    }
};


int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<double> succProb = {0.5, 0.5, 0.5, 0.5};
    int start_node = 0;
    int end_node = 4;

    Solution solution;
    double maxProb = solution.maxProbability(n, edges, succProb, start_node, end_node);
    std::cout << "Maximum probability: " << maxProb << std::endl;

    return 0;
}