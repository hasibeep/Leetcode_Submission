class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        while(left<=right){
            int mid=(right-left)/2 +left;
            if(1LL* mid*mid>x){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
           
        }
        return right;
    }
};