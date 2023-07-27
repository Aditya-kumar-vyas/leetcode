// typical binary search
class Solution {
    bool check(int n, vector<int>& batteries,long long time)
    {
        long long  score=0;
        long long n1= n;
        for(auto it : batteries)
        {
            if(it<=time)
            {
                score+=it;
            }
            else 
            {
                score+=time;
            }
        }
        if(score>=n1*time)
        {
            return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int n1 = batteries.size();
        long long lo =0;
        long long hi = 1e14;
        long long ans =0;
        while(lo<=hi)
        {
            long long mid = (hi+lo)/2;
            if(check(n,batteries,mid))
            {
               ans=mid;
               lo=mid+1;
            }
            else 
            {
                hi=mid-1;
            }
        }
        return ans ;

        
    }
};