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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode* dummy = root;

        while(dummy){
            if(val < dummy->val){
                if(dummy->left){
                    dummy = dummy->left;
                } else {
                    dummy->left = new TreeNode(val);
                    break;
                }
            }       
            else{
                if(dummy->right)
                    dummy = dummy->right;
                else{
                    dummy->right = new TreeNode(val);
                    break;
                }
            }  
        }

        return root;

    }
};