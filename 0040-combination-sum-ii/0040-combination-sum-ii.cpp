class Solution {
public:
    void prints(vector<int>& candidates,vector<vector<int>>& v,vector<int>& w,int i,int &s,int target){
        if(s==target){
           v.push_back(w); 
           return ;
        }
        if(s>target || i==candidates.size()) return;
        w.push_back(candidates[i]);
        s+=candidates[i];
        prints(candidates,v,w,i+1,s,target);
        w.pop_back();
        s-=candidates[i];
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        prints(candidates,v,w,i+1,s,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>v;
        vector<int> w;
        int s=0;
        prints(candidates,v,w,0,s,target);
        return v;
    }
};