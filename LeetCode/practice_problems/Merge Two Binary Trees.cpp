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
    void mergeOne(TreeNode* head1, TreeNode* head2){
        head1->val += head2->val;
        if(!head1->left && head2->left){
            head1->left = head2->left;
        } else if (head1->left && head2->left){
            mergeOne(head1->left, head2->left);
        }
        if(!head1->right && head2->right){
            head1->right = head2->right;
        } else if (head1->right && head2->right){
            mergeOne(head1->right, head2->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        mergeOne(root1, root2);
        return root1;
    }
};