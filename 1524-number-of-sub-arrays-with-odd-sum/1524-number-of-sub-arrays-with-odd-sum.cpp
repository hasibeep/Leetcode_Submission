class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
       vector<int>pre(n,0);
       pre[0]=arr[0];
       for(int i=1;i<n;i++){
        pre[i]=arr[i]+pre[i-1];
       }
       int evencount=1;
       int oddcount=0;
       int count=0;
       for(int i=0;i<n;i++){
        if(pre[i]%2==0){
           count=(count+oddcount)%M;
           evencount++;
        }
        else{
            count=(count+evencount)%M;
            oddcount++;
        }
       }
       return count;
    }
};