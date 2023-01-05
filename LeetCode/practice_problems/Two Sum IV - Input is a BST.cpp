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

    void bfs(TreeNode* root, vector<int>& nodeList){
        if(root->left) bfs(root->left, nodeList);
        nodeList.push_back(root->val);
        if(root->right) bfs(root->right, nodeList);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> bfsList;
        bfs(root, bfsList);
        int left = 0;
        int right = bfsList.size() - 1;

        while(left < right){
            if(bfsList[left] + bfsList[right] == k)
                return 1;
            else if (bfsList[left] + bfsList[right] < k)
                left++;
            else
                right--;
        }
        return 0;
    }
};