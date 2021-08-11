class Solution {
public:
    
    bool canReorderDoubled(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, int>m;
        for(int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(m[arr[i]] != 0 && m[2 * arr[i]] != 0)
            {
                m[arr[i]]--;
                m[2 * arr[i]]--;
            }
        }
        for(auto x: m)
        {
            if(x.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// tc o(n)
// sc o(n)
