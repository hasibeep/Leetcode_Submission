class Solution {
public:

    unordered_map<int,int> prime(int n){
        unordered_map<int,int>v;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
               v[i]++;
            }
            while(n%i==0){
                n=n/i;
            }
        }
        if(n>1){
            v[n]++;
        }
        return v;
    }
    void add(unordered_map<int,int>& mp,int n){
        unordered_map<int,int> factors=prime(n);
        for(auto [p,cnt]:factors){
            mp[p]+=cnt;
        }
        return ;
    }
    void reduce(unordered_map<int,int>& mp,int n){
        unordered_map<int,int> factors=prime(n);
        for(auto [p,cnt]:factors){
            mp[p]--;
            if(mp[p]==0){
                mp.erase(p);
            }
        }      
        return ;
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int max_size=0;
        while(right<nums.size()){
            add(mp,nums[right]);
            while(mp.size()>k){
                reduce(mp,nums[left]);
                left++;
            }
            
            max_size=max(max_size,right-left+1);
            right++;
        }
        return max_size;
    }
};