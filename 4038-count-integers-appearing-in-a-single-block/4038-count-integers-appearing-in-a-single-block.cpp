class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp,last,first;

        for(int i=0;i<nums.size();i++){
            if(first.find(nums[i])==first.end()){
                first[nums[i]]=i;
            }
            mp[nums[i]]++;
            last[nums[i]]=i;
        }
        int cnt=0;
        for(auto const& x:mp){
            int value=x.first;
            int f=x.second;

            if(last[value]-first[value]+1==f){
                cnt++;
            }
        }
        return cnt;
    }
};