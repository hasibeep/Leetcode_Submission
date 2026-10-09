class Solution {
public:
    void solve(vector<int>& nums,int i,vector<int>&w,vector<vector<int>>&ans,int n){
        if(i==n){
            ans.push_back(w);
            return;
        }
        w.push_back(nums[i]);
        solve(nums,i+1,w,ans,n);
        w.pop_back();
        solve(nums,i+1,w,ans,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>w;
        int n=nums.size();
        solve(nums,0,w,ans,n);
        // for(int mask=0;mask<(1<<n);mask++){
        //     vector<int>w;
        //    for(int i=0;i<n;i++){

        //     if(mask&(1<<i)){
        //         w.push_back(nums[i]);
        //     }

        //    }
        //    ans.push_back(w);
        // }
        return ans;

    }
};