class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        // Creating an adjacency list for the given graph.
        vector<pair<ll,ll>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<ll,ll>,
                       vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<ll> dist(n, 1e15), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        
        ll mod = (ll)(1e9+7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty())
        {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                ll adjNode = it.first;
                ll edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};