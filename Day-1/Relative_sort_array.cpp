// Problem Link - https://leetcode.com/problems/relative-sort-array/submissions/
// Beat 100% of solutions in terms of space and 43% in terms of time complexity
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(int i=0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }
        vector<int> res(arr1.size());
        int j = 0;
        for(int i=0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])!=mp.end())
            {
                while(mp[arr2[i]]!=0)
                {
                    mp[arr2[i]]--;
                    res[j] = arr2[i];
                    j++;
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            while(it->second!=0)
            {
                res[j] = it->first;
                j++;
                mp[it->first]--;
            }
        }
        
        return res;
    }
};