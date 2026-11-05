class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int count=0;
        for(int i=0;i<n;i++){
            int a=1;
            for(int j=0;j<m;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                   a=0;
                   break;
                }
            }
            if(a) count++;
        }
        return count;
    }
};