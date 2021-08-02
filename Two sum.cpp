class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>>v;
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int l = 0, r = n - 1;
        while(l < r)
        {
            int sum = v[l].first + v[r].first;
            if(sum == target)
            {
                return {v[l].second, v[r].second};
            }
            else if(sum < target)
            {
                l++;
            }
            else if(sum > target)
            {
                r--;
            }
        }
        return {-1, -1};
    }
};

// tc o(n)
// sc o(n)
