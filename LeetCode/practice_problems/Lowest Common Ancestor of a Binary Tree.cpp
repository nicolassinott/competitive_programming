/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        int currVal;

        while(root){
            currVal = root->val;
            if(currVal > max(pVal, qVal))
                root = root->left;
            else if (currVal < min(pVal, qVal))
                root = root->right;
            else
                return root;
        }

        return root;
        
    }
};