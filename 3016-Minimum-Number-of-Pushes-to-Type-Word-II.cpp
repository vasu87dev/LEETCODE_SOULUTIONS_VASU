class Solution {
public:
    int minimumPushes(string word) {


        vector<int> st(26,0);
        int ans=0;
        int n=word.size();     
        for(int i=0;i<n;i++)
        {
            st[word[i]-'a']++;

        }   
            sort(st.begin(),st.end(),greater<int>());

            for(int j=0;j<st.size();j++)
            {
                ans+=(j/8+1)*st[j];
            }
      
return ans;


    }
};