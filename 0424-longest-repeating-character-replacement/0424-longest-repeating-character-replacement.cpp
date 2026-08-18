class Solution {
public:
    int characterReplacement(string s, int k) {

        int l=0;
        int r=0;
        int hash[26]={0};
        int maxf=0;
        int maxl=0;
        while(r<s.length())
        {
            hash[s[r]-'A']++;
            // int length=r-l+1;
            maxf=max(maxf,hash[s[r]-'A']);
            if((r-l+1)-maxf>k)
            {
                hash[s[l]-'A']--;
                 
                //    if(hash[s[l]-'A']==0)
                // {
                //     break;
                // }
                // //  for(int i=l;i<r;i++)
                //  {
                //     maxf=max(maxf,hash[i]);
                //  }
              
                l++;
            }
            if((r-l+1)-maxf<=k)
            {
                maxl=max(maxl,r-l+1);
                
            }
            r++;
        }
return maxl;




        
    }
};