class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        if(sum>9*num) return "";
        for(int i=1;i<=num;i++){
            if(sum>=9){
                s.push_back('9');
                sum-=9;
            }
            else{
                s.push_back('0'+sum);
                sum=0;
            }
        }
        return s;
    }
};