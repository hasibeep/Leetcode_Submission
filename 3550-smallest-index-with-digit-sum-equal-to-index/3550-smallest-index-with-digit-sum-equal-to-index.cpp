class Solution {
public:
    int digitsum(int n){
        int x=n;
        int d=0;
        while(x>0){
            d+=x%10;
            x=x/10;
        }
    return d;
    }
    int smallestIndex(vector<int>& nums) {
        bool flag=true;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
           if(digitsum(nums[i])==i){
             ind=i;
             break;
           }
        }
        return ind;
    }
};