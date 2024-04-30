#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int main() {
 int n;
 cout << "Enter number of cities: ";
 cin >> n;
 vector<vector<int>> cost(n, vector<int>(n, -1)); // Adjacency matrix to store costs
 vector<bool> visited(n, false); // Visited array
 // Input connections and costs
 for (int i = 0; i < n; ++i) {
 for (int j = i + 1; j < n; ++j) {
 char op;
 cout << "Do you want a connection between city " << i + 1 << " and city " << j + 1 << ": ";
 cin >> op;
 if (op == 'y' || op == 'Y') {
 cout << "Enter weight: ";
 cin >> cost[i][j];
 cost[j][i] = cost[i][j];
 }
 }
 }
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
 // Start with the first city
 visited[0] = true;
 for (int j = 0; j < n; ++j) {
 if (cost[0][j] != -1) {
 pq.push(make_pair(cost[0][j], j));
 }
 }
 int minCost = 0;
 while (!pq.empty()) {
 pair<int, int> minEdge = pq.top(); pq.pop(); // Get minimum cost edge
 int c = minEdge.first;
 int u = minEdge.second;
 if (visited[u]) continue; // Skip if already visited
 minCost += c; // Add cost
 visited[u] = true; // Mark visited
 // Push adjacent edges of u to the priority queue
 for (int v = 0; v < n; ++v) {
 if (cost[u][v] != -1 && !visited[v]) {
 pq.push(make_pair(cost[u][v], v));
 }
 }
 }
 cout << "Min. Cost: " << minCost << endl;
 return 0;
}
