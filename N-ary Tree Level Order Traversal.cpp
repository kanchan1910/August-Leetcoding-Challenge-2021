/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>>ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>tmp;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                for(Node* child: front->children)
                {
                    q.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

// tc o(n)
// sc o(n)
