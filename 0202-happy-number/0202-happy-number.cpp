class Solution {
public:
    int getnext(int n){
        int sum=0;
        while(n>0){
            int x=n%10;
            sum+=x*x;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1){
            if(seen.count(n)){
                return false;
            }
            seen.insert(n);
            n=getnext(n);
        }
        return true;
    }
};