class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int>hash(26,0);
                vector<int>hash1(26,0);

int maxi=max(s.size(),t.size());
if(s.size()==t.size())
{
        for(int i=0;i<maxi;i++)
        {
            hash[s[i]-'a']++;
             hash1[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
         
         if(hash[i]!=hash1[i])
         {
            return false;
         }
         
         
         
         }
}
        
            else
            {
                return false;
            }
            return true;
        
    }
};