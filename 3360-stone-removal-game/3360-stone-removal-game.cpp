class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        bool flag=false;
        int x=10;
        while(n>=x){
            n=n-x;
            x=x-1;
            flag=!flag;
        }
        return flag;
    }
};