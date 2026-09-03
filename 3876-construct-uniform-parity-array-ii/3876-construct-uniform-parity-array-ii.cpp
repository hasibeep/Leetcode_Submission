class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    int mini=INT_MAX;
    int cnt=0;
    for(int  i=0;i<nums1.size();i++){
        mini=min(nums1[i],mini);
        if(nums1[i]%2==0){
            cnt++;
        }
    }
    if(mini%2==0 && cnt!=nums1.size()){
        return false;
    }
    return true;   
    }
};