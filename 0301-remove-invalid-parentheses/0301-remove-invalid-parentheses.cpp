class Solution {
public:
    int n;
    unordered_set<string>st;
    void solve(int i,string& curr,string &s,int count,int& maxlen){
        if(count<0) return ;
        if(i==n){
            if(count==0){

                if(curr.length()>maxlen){
                    maxlen=curr.length();
                    st.clear();
                }

                if(curr.length()==maxlen){
                    st.insert(curr);
                }
                
            }
            return;
        }
            if(s[i]!='(' && s[i]!=')'){
                curr.push_back(s[i]);
                solve(i+1,curr,s,count,maxlen);
                curr.pop_back();
                return ;
            }
            else{
                curr.push_back(s[i]);
                solve(i+1,curr,s,count+(s[i]=='('?1:-1),maxlen);
                curr.pop_back();
                solve(i+1,curr,s,count,maxlen);
            }
        }
    
    vector<string> removeInvalidParentheses(string s) {
        n=s.length();
        st.clear();
        int count=0;
        string curr="";
        int maxlen=0;
        solve(0,curr,s,count,maxlen);
        return vector<string>(st.begin(),st.end());
    }
};