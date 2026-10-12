class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x:asteroids){
            while(!st.empty() && x<0 && st.top()>0 ){
                int sum=x+st.top();
                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    x=0;
                }
                else{
                    st.pop();
                    x=0;
                }
            }
            if(x!=0){
                st.push(x);
            }
        }
        int s=st.size();
        vector<int>result(s);
       int i=s-1;
       while(!st.empty()){
        result[i]=st.top();
        st.pop();
        i--;
       }
       return result;
    }
};