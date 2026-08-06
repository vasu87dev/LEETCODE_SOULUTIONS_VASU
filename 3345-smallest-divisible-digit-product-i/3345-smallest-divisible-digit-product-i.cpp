class Solution {
public:
    int smallestNumber(int n, int t) {

int c=n;

        while(c>=n)
        {
            int pro=1;
            for(int temp=c;temp!=0;temp=temp/10)
            {
int digit=temp%10;
pro=pro*digit;
            }
            if(pro%t==0)
            {
                return c;
                
            }
            else
            {
            c++;
            }
        }
       return 0;
    }
};