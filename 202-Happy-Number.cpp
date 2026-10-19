class Solution {
public:

int sum(int n)
{

    
    int sum=0;
    for(int temp=n;temp!=0;temp=temp/10)
    {
        int rem=temp%10;
        sum=sum+(rem*rem);
    }
    return sum;
}


    bool isHappy(int n) {
set<int>s;
        int sum2=sum(n);
        
int cny=0;
        while(!s.contains(sum2))
        {
            s.insert(sum2);
        if(sum2==1)
        {
            return true;
        }
       
        else
        {
            sum2=sum(sum2);
        }
        
        }
        return false;
    }
};