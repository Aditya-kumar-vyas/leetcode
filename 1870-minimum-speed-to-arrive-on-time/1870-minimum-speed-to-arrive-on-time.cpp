class Solution {
public:

    bool check(vector<int> arr,int mid,double h)
    {
        double time = 0;

        for(int i = 0;i<arr.size();i++)
        {
            if(i==arr.size()-1)
            time = time+(double(arr[i])/mid);
            else
            time = time+ceil(double(arr[i])/mid);
        }
        
        if(time<=h)
        return true;


        return false;
    }
    int minSpeedOnTime(vector<int>& arr, double h) {
        
        int n = arr.size(),ans = INT_MAX;
        int first = 1;
        int last = 1e9+1;

        int mx = -1;
        for(auto x : arr)
        mx = max(x,mx);

        while(first<last)
        {
            int mid = (first+last)/2;

            if(check(arr,mid,h))
            {
                last = mid;
                ans = min(ans,mid);
            }
            else
            first = mid+1;
        }

        if(ans==INT_MAX)
        return -1;

        return ans;
    }
};