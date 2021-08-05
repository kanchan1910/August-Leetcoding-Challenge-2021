class Solution {
public:
    /*
    If Alex takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

The idea is that he always can play in such a way that he get all odd piles or all even piles. On the first move he needs to decide what is bigger and play this strategy.
*/
    bool stoneGame(vector<int>& piles) 
    {
        return true;
    }
};
// tc o(1)
// sc o(1)

// greedy will fail for examples:
// [1, 100, 9, 1]
// [3, 2, 10, 4]
// [1, 100, 200, 8]

// dp solution

class Solution {
public:
    int dp[505][505][2];
    bool fun(int n, vector<int>& piles, int i, int j, int alax, int lee, int flag)
    {
        if(i > j)
        {
            if(alax > lee)
            {
                return dp[i][j][flag] = true;
            }
            else
            {
                return dp[i][j][flag] = false;
            }
        }
        if(dp[i][j][flag] != -1)
        {
            return dp[i][j][flag];
        }
        if(flag == 0)
        {
            // alax turn
            return dp[i][j][flag] = fun(n, piles, i + 1, j, alax + piles[i], lee, 1) || fun(n, piles, i, j - 1, alax + piles[j], lee, 1);
        }
        else
        {
            // lee turn
            return dp[i][j][flag] = fun(n, piles, i + 1, j, alax, lee + piles[i], 0) || fun(n, piles, i, j - 1, alax, lee + piles[j], 0);
        }
    }
    bool stoneGame(vector<int>& piles) 
    {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return fun(n, piles, 0, n - 1, 0, 0, 0);
    }
};
// tc o(n * n)
// sc o(n * n * 2)
