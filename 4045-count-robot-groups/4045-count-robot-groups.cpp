class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        int cnt=1;
        int w=speed[n-1];
        for(int i=n-2;i>=0;i--){
            if(position[i+1]-position[i]<=distance) continue;
            if(w>=speed[i]){
                cnt++;
                w=speed[i];
            }
        }
        return cnt;
    }
};