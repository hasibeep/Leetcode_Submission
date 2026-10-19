class Solution {
public:
    vector<int> pse(vector<int>&arr){
        int n=arr.size();
        vector<int>v(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
               v[i]=st.top(); 
            } 
            st.push(i);
        }
        return v;
    }
    vector<int> nse(vector<int>&arr){
       stack<int>st;
       int n=arr.size();
       vector<int>v(n,n);
       
       for(int x=n-1;x>=0;x--){
           while(!st.empty() && arr[st.top()]>=arr[x]){
            st.pop();
           }
           if(!st.empty()){
            v[x]=st.top();
            }
           st.push(x);
       }
       return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        int MOD=1e9+7;
        int n=arr.size();
        vector<int>ans=pse(arr);
        vector<int>ans1=nse(arr);
        for(int i=0;i<n;i++){
            long long  left=i-ans[i];
            long long  right=ans1[i]-i;
            sum=(sum+ (long long)arr[i]*left%MOD*right%MOD)%MOD;
        }
        
        return sum;
    }
};