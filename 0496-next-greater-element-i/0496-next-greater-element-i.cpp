class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int next=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==nums1[i]){
                    for(int k=j+1;k<nums2.size();k++){
                        if(nums2[k]>nums2[j]) {
                            next=nums2[k];
                             break;
                            }      
                    }
                    break;
                }
            }
            ans.push_back(next);
        }
        return ans;
    }
};