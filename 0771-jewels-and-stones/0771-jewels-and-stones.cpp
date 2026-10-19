class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
unordered_map<char,int>st;
int count=0;
unordered_map<char,int>st1;
for(int i=0;i<stones.size();i++)
{
    st1[stones[i]]++;
}
for(int i=0;i<jewels.size();i++)
{
    st[jewels[i]]++;
}
int j=0;
while(j<jewels.size())
{
    if(st1.find(jewels[j])!=st1.end() )
    {
        
            count=count+st1[jewels[j]];
        
    }
    j++;
}


return count;


    }
};