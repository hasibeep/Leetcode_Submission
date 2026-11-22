class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        int count_b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
               if(flag) {
                flag=false;
                count_b++;
                break;
               }
            }
            else {
                flag=true;
            }
        }
        if(count_b==1 && !flag) return flag;
        return true;
    }
};