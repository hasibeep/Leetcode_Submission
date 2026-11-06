class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        auto lambda=[](vector<int>&vec1,vector<int>&vec2){
            return vec1[1]<vec2[1];
         };

        sort(logs.begin(),logs.end(),lambda);

        
        int w=queries.size();
        vector<int>ans(w);

        vector<pair<int,int>>q(w);
        for(int i=0;i<w;i++){
           q[i]={queries[i],i};
        }

        sort(q.begin(),q.end());

        unordered_map<int,int>mp;
        
        int i=0;
        int j=0;
        for(auto [time,idx]:q){
            int start=time-x;
            int end=time;

            while(j<logs.size() && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<logs.size() && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0) mp.erase(logs[i][0]);
                i++;
            }
            ans[idx]=n-mp.size();
        }
        return ans; 
    } 
};