class Solution {
public:
    int findDay(string s,vector<int>& monthday){
        int month=stoi(s.substr(0,2));
        int day=stoi(s.substr(3));
        
        return monthday[month-1]+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>v{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>monthday(12,0);
        monthday[0]=31;
        for(int i=1;i<12;i++){
            monthday[i]=monthday[i-1]+v[i-1];
        }
        int arrivealice=findDay(arriveAlice,monthday);
        int arrivebob=findDay(arriveBob,monthday);
        int leavealice=findDay(leaveAlice,monthday);
        int leavebob=findDay(leaveBob,monthday);
        
        int ans=min(leavealice,leavebob)-max(arrivealice,arrivebob)+1;
        return ans<0?0:ans;
        
    }
};