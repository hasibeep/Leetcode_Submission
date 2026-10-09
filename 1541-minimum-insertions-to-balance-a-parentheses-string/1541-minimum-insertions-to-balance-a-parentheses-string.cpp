class Solution {
public:
    int minInsertions(string s) {
     int ans=0;
     int cnt=0;
     int n=s.length();
     int i=0;
     while(i<n){
        if(s[i]=='(') {
            cnt++;
            i++;
            }

        else{
            if(cnt>0){
                cnt--;
            }
            else ans++;

            if(s[i+1]==')') i=i+2;
            else {
                ans++;
                i++;
            }
        }
     }
     return ans+2*cnt;   
    }
};