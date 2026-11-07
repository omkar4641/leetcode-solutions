class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int a=-1;
        int b=-1;

        for(auto it:mp)
        {
            if(it.second<2 && a==-1)
            {
                a=it.first;
                continue;
            }

            if(it.second<2 && b==-1)
            {
                b=it.first;
                continue;
            }
        }
    return {a,b};
    }
};