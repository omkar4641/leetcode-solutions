class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int length=1;
        int ans=1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            if(nums[i-1]==nums[i]-1)
            {
                length++;
            }
            else
            {
                length=1;
            }

            ans=max(ans,length);
        }
    return ans;

    }
};