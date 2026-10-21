class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char>st;
        if(s.size()==1)
        {
            return 1;
        }
        else if(s.size()==0)
        {
            return 0;
        }
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            while(st.find(s[i])!=st.end())
            {
                                st.erase(s[i-int(st.size())]);

            }
                            st.insert(s[i]);

                                            ans=max(ans,int(st.size()));

            
            

                st.insert(s[i]);
            
        }
        return ans;
    }
};