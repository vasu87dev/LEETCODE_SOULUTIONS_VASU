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

        int sum2=sum(n);
int cny=0;
        while(cny<1000)
        {
        if(sum2==1)
        {
            return true;
        }
        else
        {
            sum2=sum(sum2);
        }
        cny++;
        }
        return false;
    }
};