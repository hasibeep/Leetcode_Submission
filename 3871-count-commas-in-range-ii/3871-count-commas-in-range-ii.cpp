class Solution {
public:
    long long countCommas(long long n) {
        long long  x=1000;
        long long  comma=1;
        long long count=0;
        while(x<=n){
            long long upper=x*1000-1;
            if(upper>n) upper=n;
            count+=(upper-x+1)*comma;
            x=x*1000;
            comma=comma+1;
        }
        return count ;
    }
};