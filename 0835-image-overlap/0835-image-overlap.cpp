class Solution {
public:
    int countoverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int i,int j){
        int count=0;
        int n=img1.size();

        for(int c=0;c<n;c++){
            for(int d=0;d<n;d++){
                int B_i=c+i;
                int B_j=d+j;

                if(B_i<0 || B_i>=n || B_j<0 || B_j>=n){
                    continue;
                }
                if(img1[c][d]==1 && img2[B_i][B_j]==1){
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int max_count=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int count=countoverlaps(img1,img2,i,j);
                max_count=max(count,max_count);
            }
        }
        return max_count;
    }
};