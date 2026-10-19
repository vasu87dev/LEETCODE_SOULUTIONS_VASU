class Solution {
public:
    int longestPalindrome(string s) {

if(s.size()==1)
{
    return 1;
}

vector<int>hash(256,0);
for(int i=0;i<s.size();i++)
{
    hash[s[i]]++;
}
int count=0;
int q=0;
for(int j =0;j<hash.size();j++)
{
if(hash[j]%2==0)
{
    count+=hash[j];
}
else if(hash[j]%2!=0 && hash[j]>1)
{
    int p=hash[j]/2;
    count=count+(p*2);
    q=1;
}
else if(hash[j]==1)
{
    q=1;
}
}
return count+q;




        
    }
};


