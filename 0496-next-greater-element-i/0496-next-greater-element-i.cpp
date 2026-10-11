class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int>ans;
      stack<int>st;
      unordered_map<int,int>mp;

      for(int x:nums2){
        while(!st.empty() && st.top()<x){
            mp[st.top()]=x;
            st.pop();
        }
        st.push(x);
      }
      while(!st.empty()){
        mp[st.top()]=-1;
        st.pop();
      }
      for(int x:nums1){
        ans.push_back(mp[x]);
      }
      return ans;
    }
};