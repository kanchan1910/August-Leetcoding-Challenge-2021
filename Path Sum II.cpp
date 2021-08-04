
class Solution 
{
public:
    void fun(TreeNode* root, int targetSum, int curSum, vector<int>tmp, vector<vector<int>>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        // include
        curSum += root->val;
        tmp.push_back(root->val);
        
        // if leaf node
        if(root->left == NULL && root->right == NULL)
        {
            if(curSum == targetSum)
            {
                ans.push_back(tmp);
            }
        }
        
        // explore left and right
        fun(root->left, targetSum, curSum, tmp, ans);
        fun(root->right, targetSum, curSum, tmp, ans);
        
        // backtrack
        curSum -= root->val;
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ans;
        vector<int>tmp;
        fun(root, targetSum, 0, tmp, ans);
        return ans;
    }
};
