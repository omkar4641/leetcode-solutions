class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            bool alive=true;
            while(!st.empty() && asteroids[i]<0 && st.top()>0)
            {
                if(st.top()>abs(asteroids[i]))
                {
                    alive=false;
                    break;
                }
                else if(st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                else if(st.top()==abs(asteroids[i]))
                {
                    alive=false;;
                    st.pop();
                    break;
                }

            }

            if(alive)
            {
                st.push(asteroids[i]);
            }
            
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};