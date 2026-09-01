class Solution {
public:
    int minBitFlips(int start, int goal) {
       int temp=start^goal;
       /*
       int cnt=0;
       while(temp!=0){
        temp=(temp&(temp-1));
        cnt++;
       }
      return cnt;
      */
      return __builtin_popcount(temp);
    }
};