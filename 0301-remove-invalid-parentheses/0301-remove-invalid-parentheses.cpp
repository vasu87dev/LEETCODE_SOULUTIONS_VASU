class Solution {
public:

    bool check(string s)
    {
        int cnt = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                cnt++;
            }
            else if(c == ')')
            {
                cnt--;

                if(cnt < 0)
                {
                    return false;
                }
            }
        }

        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty())
        {
            string str = q.front();
            q.pop();

            if(check(str))
            {
                ans.push_back(str);
                found = true;
            }

            // Once we found valid strings at this level,
            // don't generate strings with more removals.
            if(found)
            {
                continue;
            }

            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] != '(' && str[i] != ')')
                {
                    continue;
                }

                string temp = str.substr(0, i) + str.substr(i + 1);

                if(vis.find(temp) == vis.end())
                {
                    vis.insert(temp);
                    q.push(temp);
                }
            }
        }

        return ans;
    }
};