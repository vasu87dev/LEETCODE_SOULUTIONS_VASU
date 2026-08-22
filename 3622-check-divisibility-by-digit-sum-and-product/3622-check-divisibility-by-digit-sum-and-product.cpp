class Solution {
public:
    bool checkDivisibility(int n) {
int sum=0;
int mult=1;

        for(int temp=n;temp!=0;temp=temp/10)
        {
            int rem=temp%10;
sum=sum+rem;
mult=mult*rem;
        }
        if(n%(mult+sum)==0)
        {
            return true;
        }
        else
        {
           return false;
        }


        
    }
};