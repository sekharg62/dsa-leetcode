#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<set<int>> ancestors(n);  // Use a set to keep track of ancestors
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build the adjacency list and indegree array
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                // Add ancestors of node to neighbor
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());
                ancestors[neighbor].insert(node);

                // Decrease indegree and add to queue if it becomes zero
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Convert sets to sorted vectors
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i].assign(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Example input: number of nodes and edges of a DAG
    int n = 6;
    vector<vector<int>> edges = {
        {0, 3},
        {5, 0},
        {2, 3},
        {4, 3},
        {5, 3},
        {1, 3},
        {2, 5},
        {0, 1},
        {4, 5},
        {4, 2},
        {4, 0},
        {2, 1},
        {5, 1}
    };

    vector<vector<int>> ancestors = solution.getAncestors(n, edges);

    cout << "Ancestors for each node:" << endl;
    for (int i = 0; i < ancestors.size(); ++i)
    {
        cout << "Node " << i << ":";
        for (int ancestor : ancestors[i])
        {
            cout << " " << ancestor;
        }
        cout << endl;
    }

    return 0;
}
