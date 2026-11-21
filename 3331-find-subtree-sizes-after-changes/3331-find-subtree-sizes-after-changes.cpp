
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> prev(n);
        vector<int> np = parent;

        stack<pair<int,int>> st;
        st.push({0, 0});

        while(!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if(state == 0) {
                prev[u] = last[c];

                if(last[c] != -1) {
                    np[u] = last[c];
                }

                last[c] = u;

                st.push({u, 1});

                for(int i = adj[u].size()-1; i >= 0; i--) {
                    st.push({adj[u][i], 0});
                }
            }
            else {
                last[c] = prev[u];
            }
        }

        vector<vector<int>> tree(n);

        for(int i = 1; i < n; i++) {
            tree[np[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> order;
        stack<int> st2;

        st2.push(0);

        while(!st2.empty()) {
            int u = st2.top();
            st2.pop();

            order.push_back(u);

            for(int v : tree[u]) {
                st2.push(v);
            }
        }

        for(int i = n-1; i >= 0; i--) {
            int u = order[i];

            for(int v : tree[u]) {
                ans[u] += ans[v];
            }
        }

        return ans;
    }
};
