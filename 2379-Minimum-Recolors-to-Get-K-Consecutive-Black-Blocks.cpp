class Solution {
public:
    int minimumRecolors(string blocks, int k) {  
   vector<int>hash(256,0);
int mini=INT_MAX;
int s=0;
int l=0;
while(l<blocks.size())
{
hash[blocks[l]-'A']++;
if(hash['B'-'A']+hash['W'-'A']==k)
{
    mini=min(mini,hash['W'-'A']);
    hash[blocks[s]-'A']--;
    s++;
    
}
l++;
}

return mini;
    }
};