class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int count=0;
for(int i=0;i<k;i++)
{
    sum=sum+arr[i];
}
int s=0;
int l=k;
while(l<=arr.size())
{
    if(sum/k>=threshold)
    {
        count++;
        
    }
    
    if (l >= arr.size()) break;
        sum=sum-arr[s]+arr[l];
        s++;
        l++;
    
}
return count;

    }
};