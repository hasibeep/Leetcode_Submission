class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int max_element=INT_MIN;
        int min_element=INT_MAX;
        int min_i=-1;
        int max_i=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_element){
                max_element=nums[i];
                max_i=i;
            }

            if(nums[i]<min_element){
                min_element=nums[i];
                min_i=i;
            }
        }
        int left=n-min(max_i,min_i);
        int right=max(max_i,min_i)+1;
        int both=min(max_i,min_i)+1+n-max(min_i,max_i);
        return min({left,right,both});
    }
};