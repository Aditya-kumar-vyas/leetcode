class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        string s = answerKey;
        int ans=0;
        int ans1=0;
        int i =0;
        int j =0;
        map<char,int> mp;
        while(j<n)
        {
            mp[answerKey[j]]++;
            if(mp['F']<=k)
            {
                ans=max(j-i+1,ans);
                j++;
            }
            else if(mp['F']>k)
            {
                while(mp['F']>k)
                {
                     mp[answerKey[i]]--;
                    i++;
                   
                }
                j++;
            }

        }
        i=0;
        j=0;
        map<char,int> mp1;
        while(j<n)
        {
            mp1[answerKey[j]]++;
            if(mp1['T']<=k)
            {
                ans1=max(j-i+1,ans1);
                j++;
            }
            else if(mp1['T']>k)
            {
                while(mp1['T']>k)
                {
                    mp1[answerKey[i]]--;
                    i++;
                    
                }
                j++;
            }

        }
        return max(ans,ans1);

    }
};