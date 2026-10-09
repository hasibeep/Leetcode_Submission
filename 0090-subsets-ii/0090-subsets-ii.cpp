class Solution {
public:
    void prints(vector<int>& nums,set<vector<int>>& v,vector<int>& w,int i){
        if(i==nums.size()){
           v.insert(w); 
           return ;
        }
        w.push_back(nums[i]);
        prints(nums,v,w,i+1);
        w.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        prints(nums,v,w,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>v;
        vector<int> w;
        prints(nums,v,w,0);
        return vector<vector<int>>(v.begin(),v.end());
    }
};