class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int x=26-(s[i]-'a');
            sum+=x*(i+1);
        }
        return sum;
    }
};