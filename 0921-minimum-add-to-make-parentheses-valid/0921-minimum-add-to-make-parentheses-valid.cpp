class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char>ch;
        int a=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ch.push('(');
            }
            else{
                if(!ch.empty()){
                    ch.pop();
                }
                else a++;
            }
        }
        return ch.size()+a;
    }
};