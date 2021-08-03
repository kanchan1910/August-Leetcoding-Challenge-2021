class Solution {
public:
    void unique_subsets(vector<int>& nums, int n, int index, set<vector<int>>& s, vector<int> tmp)
    {
        s.insert(tmp);
        if(index >= n)
        {
            return;
        }
        for(int i = index; i < n; i++)
        {
            tmp.push_back(nums[i]);
            unique_subsets(nums, n, i + 1, s, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>tmp;
        unique_subsets(nums, n, 0, s, tmp);
        for(auto x: s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

/*
Refer this:

https://www.techiedelight.com/difference-between-subarray-subsequence-subset/ 


Input:
[4,4,4,1,4]
Output:
[[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
Expected:
[[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
*/
