
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        // Available servers: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // Busy servers: {finish_time, weight, index}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busy;

        int m = servers.size();
        int n = tasks.size();

        // Initially, all servers are available.
        for (int i = 0; i < m; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(n);
        long long time = 0;

        for (int i = 0; i < n; i++) {

            // Current time cannot be earlier than task arrival.
            time = max(time, (long long)i);

            // Release all servers that have finished.
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [finish, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait.
            if (available.empty()) {

                time = get<0>(busy.top());

                // Release all servers finishing at this time.
                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [finish, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server.
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;

            // Mark the server as busy.
            busy.push({
                time + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};
