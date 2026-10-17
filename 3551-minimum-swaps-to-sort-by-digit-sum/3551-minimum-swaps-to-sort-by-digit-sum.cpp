class Solution {
public:
    int digitsum(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>v(nums);
        int n=nums.size();
        auto lambda=[&](int num1,int num2){
            int d1=digitsum(num1);
            int d2=digitsum(num2);

            if(d1!=d2){
                return d1<d2;
            }
            return num1<num2;
        };
        sort(v.begin(),v.end(),lambda);
        unordered_map<int,int>valToIdx;
        for(int i=0;i<n;i++){
            valToIdx[nums[i]]=i;
        }
        int swap=0;
        for(int i=0;i<n;i++){
            int xpected=v[i];
            int currval=nums[i];

            if(xpected==currval){
                continue;
            }
            int idx=valToIdx[xpected];
            nums[i]=xpected;
            nums[idx]=currval;

            valToIdx[xpected]=i;
            valToIdx[currval]=idx;

            swap++;
        }
        return swap;
    }
};