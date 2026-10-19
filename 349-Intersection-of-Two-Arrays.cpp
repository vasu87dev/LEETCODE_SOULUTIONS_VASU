class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


        vector<int>hash(1001,0);
        set<int>st;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            hash[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)

        {

         if(hash[nums2[i]]!=0)
         {
            st.insert(nums2[i]);
         }
        }
        while(!st.empty())
        {
            auto it=*st.begin();
            
          ans.push_back(it);
          st.erase(it);
        }
        return ans;
    }
};