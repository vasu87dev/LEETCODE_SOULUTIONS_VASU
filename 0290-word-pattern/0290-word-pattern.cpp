
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        vector<string> new1;

        string sp = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                new1.push_back(sp);
                sp = "";
            }
            else
            {
                sp += s[i];
            }
        }

        new1.push_back(sp);

        if(pattern.size() != new1.size())
            return false;

        for(int i = 0; i < pattern.size(); i++)
        {
            if(mp.find(pattern[i]) != mp.end() &&
               mp[pattern[i]] != new1[i])
            {
                return false;
            }

            if(mp1.find(new1[i]) != mp1.end() &&
               mp1[new1[i]] != pattern[i])
            {
                return false;
            }

            mp[pattern[i]] = new1[i];
            mp1[new1[i]] = pattern[i];
        }

        return true;
    }
};
