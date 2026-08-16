class Solution {
public:
    int lengthOfLongestSubstring(string s) {

     int l=0;
     int r=0;
     int maxl=0;
     vector<int>hash(256,-1);
    //  unordered_map<char,int>hash;
     while(r<s.length())
     {
            if(hash[s[r]]!=-1 && hash[s[r]]>=l)
            {
                
                l=hash[s[r]]+1;
                
            }

            hash[s[r]]=r;
            
            maxl=max(maxl,r-l+1);
r++;
     }
    



    return maxl;    
    }
};