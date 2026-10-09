class Solution {
public:
    void print(int k,int n,int i,int s,vector<vector<int>>& ans,vector<int>& ds,vector<int>& v){   
        if(s>n||ds.size()>k){
            return;
        }
        if(i==v.size()){
            if(s==n && ds.size()==k){
                ans.push_back(ds);
            }
            return ;
        }
        ds.push_back(v[i]);
        s+=v[i];
        print(k,n,i+1,s,ans,ds,v);
        ds.pop_back();
        s-=v[i];
        print(k,n,i+1,s,ans,ds,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int>v;
      for(int i=0;i<9;i++) {
        v.push_back(i+1);
      } 
      vector<vector<int>>ans;
      vector<int>ds;
      print(k,n,0,0,ans,ds,v);
      return ans;
    }
};