// Problem Link - https://leetcode.com/problems/two-sum/

// Runtime: 168 ms, faster than 16.28% of C++ online submissions for Two Sum.
// Memory Usage: 9.2 MB, less than 93.19% of C++ online submissions for Two Sum.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int diff = target - nums[i];
            for(int j=0;j<n;j++)
            {
                if(nums[j]==diff && i!=j)
                {
                    return {i, j};
                }
            }
        }
        return vector<int> ({});
    }
};




// Alternative Approach : Using hashing (unordered_map)
// Runtime: 12 ms, faster than 64.17% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 38.96% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = i;            
        }
        for(int i=0;i<n;i++)
        {
            int diff = target - nums[i];
            if(mp.find(diff)!=mp.end() && mp[diff]!=i)
            {
                return {i, mp[diff]};
            }
        }
        return vector<int> ({});
    }
};