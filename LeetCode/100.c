**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool verifyTree(struct TreeNode* p, struct TreeNode* q) {

    if ( p == NULL && q != NULL || q == NULL && p != NULL) {
        return false;
    } else if ( p == NULL && q == NULL ) {
        return true;
    }

    if ( p->val != q->val ) {
        return false;
    } 
    if ( !verifyTree( p->left, q->left ) ) {
        return false;
    }
    if ( !verifyTree( p->right, q->right ) ) {
        return false;
    }
    
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    return verifyTree( p, q );
}