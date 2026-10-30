class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
      long long ans=0;
      int count=0;
      if(k%2==0)
      {
        return -1;
      }

      while(true)
      {
        ans=(ans*10+1)%k;
        count++;
        if(ans==0)
        {
            break;
        }
        if(count>k)
        {
            return -1;
        }
      }
    return count;
    }
};