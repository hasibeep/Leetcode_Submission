class Solution {
public:
    string get_binary(int a){
        string x;
        for(int i=7;i>=0;i--){
            if(a&(1<<i)){// checks if i th bit set or not 
                x.push_back('1');
            }
            else {
                x.push_back('0');
            }
        }
        return x;
    }
    bool isPalindromic(string s) {
        string w;
        for(int i=0;i<s.size();i++){
            int x=s[i];
            w=w+get_binary(x);
        }

        int i=0;
        int j=w.size()-1;

        while(i<j){
            if(w[i]==w[j]){
                i++;
                j--;
            }
            else {
                return false;
            }
        }
      return true;
    }
};