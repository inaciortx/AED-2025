/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool symmetricCheck ( struct TreeNode *subL, struct TreeNode *subR ) {

    if ( subL->val != subR->val ) {
        return false;
    }

    if ( subL->left == NULL && subR->right != NULL || subL->right == NULL && subR->left != NULL ||subL->left != NULL && subR->right == NULL || subL->right != NULL && subR->left == NULL  ) {
        return false;
    } 

    if ( subL->right != NULL && subR->left != NULL ) {
        if ( !symmetricCheck( subL->right, subR->left ) ) {
            return false;
        }
    }

    if ( subL->left != NULL && subR->right != NULL ) {
        if ( !symmetricCheck( subL->left, subR->right) ) {
            return false;
        }
    }

    return true;
}

bool isSymmetric(struct TreeNode* root) {
    
    if ( root == NULL || root->right == NULL && root->left == NULL ) {
        return true;
    }
    if ( root->left != NULL && root->right != NULL ) { 
        return symmetricCheck( root->right, root->left );
    }
    return false;
}