class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

unordered_map<int,int>hash;
int sum=0;
int cnt=0;
hash[0]=1;
for(int i=0;i<nums.size();i++)
{
sum=sum+nums[i];


int rem=sum-k;

cnt+=hash[rem];
hash[sum]+=1;




}

return cnt;        
    }
};