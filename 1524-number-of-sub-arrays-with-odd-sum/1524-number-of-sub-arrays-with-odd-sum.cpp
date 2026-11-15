class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
       int n=arr.size();
       
       int evencount=1;
       int oddcount=0;
       int count=0;
       int sum=0;
       for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum%2==0){
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