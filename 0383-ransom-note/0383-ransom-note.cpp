class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int>s1;
                unordered_map<char,int>s2;
                int i=0,k=0;
                for(int i = 0; i < ransomNote.size(); i++)
        {
            s1[ransomNote[i]]++;
        }

        for(int k = 0; k < magazine.size(); k++)
        {
            s2[magazine[k]]++;
        }
                for(int j=0;j<ransomNote.size();j++)
                {
                    if(s1[ransomNote[j]]>s2[ransomNote[j]])
                    {
                      return false;
                    }
                }
return true;

        
    }
};