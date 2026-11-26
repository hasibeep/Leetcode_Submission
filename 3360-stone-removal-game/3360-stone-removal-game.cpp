class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int count=0;
        int x=10;
        while(n>=x){
            n=n-x;
            x=x-1;
            count++;
        }
        if(count%2==0) return false;
        return true;
    }
};