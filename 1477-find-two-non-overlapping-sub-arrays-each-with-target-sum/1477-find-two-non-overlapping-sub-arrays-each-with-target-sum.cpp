class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;

        int currsum=0;
        vector<int>v(n,INT_MAX);

        int minlength=INT_MAX;
        int result=INT_MAX;
        while(j<n){
            currsum+=arr[j];
            while(currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && v[i-1]!=INT_MAX){
                    result=min(result,len+v[i-1]);
                }
                minlength=min(minlength,len);
            }
            v[j]=minlength;
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};