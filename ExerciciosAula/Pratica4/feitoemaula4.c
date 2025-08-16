/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* sortList(struct ListNode* head) {

    if ( head == NULL || head->next == NULL ) { return head;}
    

    struct ListNode *node = head;
    struct ListNode *prox = node->next;
    int changes = 0;

    do {
        node = head;
        prox = node->next;  
        changes = 0;

        while ( node->val < prox->val && node->next != NULL){
        
            node = node->next;
            if ( prox->next != NULL ) {
                prox = prox->next;
            }

        }

        while ( node->val > prox->val && node->next != NULL ) {
            
                if ( prox->next != NULL ) {
                    node->next = prox->next;
                    changes++;
                } else {
                    node->next = NULL;
                }
                    prox->next = head;
                    head = prox;
                    if ( node->next != NULL ) {
                        prox = node->next;
                    }
        } 
    } while( changes != 0);


    return head;

}

/*

int compare( const void *a, const void *b ) {
    return (*(int*)a - *(int*)b );
}


struct ListNode* sortList(struct ListNode* head) {
    
    if ( head == NULL ) { return head;}

    int *vec = NULL;
    int vSize = 0;
    struct ListNode *node = head;
    
    while ( node != NULL ) {
        vSize++;
        vec = realloc(vec, sizeof(int) * vSize);
        vec[vSize-1] = node->val;
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
 
*/
