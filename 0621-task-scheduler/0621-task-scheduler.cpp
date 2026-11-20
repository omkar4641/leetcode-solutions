class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }

        int maxFreq=0;
        for(auto it:mp)
        {
            maxFreq=max(maxFreq,it.second);
        }

        int count=0;
        for(auto it:mp)
        {
            if(maxFreq==it.second)
            {
                count++;
            }
        }

        return max((int)tasks.size(),(maxFreq - 1)*(n + 1)+count);

    }
};