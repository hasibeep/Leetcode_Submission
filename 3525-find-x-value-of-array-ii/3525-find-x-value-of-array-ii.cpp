class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    vector<Node> tree;
    int K;

    Node merge(const Node& A, const Node& B) {
        Node C;
        C.prod = (A.prod * B.prod) % K;
        for (int i = 0; i < K; ++i) {
            C.cnt[i] = A.cnt[i];
        }
        for (int i = 0; i < K; ++i) {
            int nxt = (A.prod * i) % K;
            C.cnt[nxt] += B.cnt[i];
        }
        return C;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node].prod = nums[start] % K;
            tree[node].cnt[tree[node].prod] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = Node();
            tree[node].prod = val % K;
            tree[node].cnt[tree[node].prod] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        } else if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        } else {
            return merge(query(2 * node, start, mid, l, r),
                         query(2 * node + 1, mid + 1, end, l, r));
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        K = k;
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};