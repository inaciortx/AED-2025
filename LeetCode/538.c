/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void subSum ( struct TreeNode* node, int *sum ) {
    
    if ( node == NULL ) return;

    subSum ( node->right, sum );

    *sum += node->val;
    node->val = *sum;

    subSum( node->left, sum);

}
struct TreeNode* convertBST(struct TreeNode* root) {

    int sum = 0;
    if ( root == NULL ) return NULL;

    subSum( root, &sum );

    return root;

}
