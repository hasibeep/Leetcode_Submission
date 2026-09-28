class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                maxp=max(maxp,cnt);
                cnt--;
            }
        }
        return maxp;
    }
};