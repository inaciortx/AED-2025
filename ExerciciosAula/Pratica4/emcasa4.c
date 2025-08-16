/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 100000

int compare( const void *a, const void *b ) {
    return (*(int*)a - *(int*)b );
}

struct ListNode* sortList(struct ListNode* head) {
    
    if ( head == NULL ) { return head;}

    int vec[MAX];
    int vSize = 0;
    struct ListNode *node = head;
    
    while ( node != NULL ) {
        vec[vSize] = node->val;
        vSize++;
        node = node->next;
    }

    qsort( vec, vSize, sizeof(int), compare );

    node = head;
    int i = 0;

    while( node != NULL ) {

        node->val = vec[i];
        node = node->next;
        i++;
    }
    
    return head;    

}
 