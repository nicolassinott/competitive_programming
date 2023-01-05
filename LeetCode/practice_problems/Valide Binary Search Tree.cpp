/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* root, vector<int>& dfsList){
        if(root->left)
            dfs(root->left, dfsList);

        dfsList.push_back(root->val);

        if(root->right)
            dfs(root->right, dfsList);
    }

    bool isValidBST(TreeNode* root) {

        vector<int> dfsList;
        dfs(root, dfsList);
        int currEl = dfsList[0];

        for(int i = 1; i < dfsList.size(); i++){
            if(dfsList[i] <= currEl)
                return 0;
            currEl = dfsList[i];
        }
        return 1;
    }
};