class Solution {
public:
    int power(int a,int b){
        int res=1;
        while(b>0){
            if(b%2!=0){
                res=res*a;
            }
            else a=a*a;
            b/=2;
        }
        return res;

    }
    int countCommas(int n) {
        int x=n-999;
        if(x<=0){
            return 0;
        }
        return x;

    }
};