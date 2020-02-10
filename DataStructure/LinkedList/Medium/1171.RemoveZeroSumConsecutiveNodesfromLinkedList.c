/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeZeroSumSublists(struct ListNode* head){
    struct ListNode *travel = head, *prev = NULL;

    while(NULL != travel) {
        int sum = travel -> val;
        struct ListNode* midTravel = travel -> next;

        while(0 != sum && NULL != midTravel) {
            sum += midTravel -> val;
            midTravel = midTravel -> next;
        }

        if(0 == sum) {

            if(NULL == prev) {
                head = midTravel;

                while(NULL != head && 0 == head -> val) {
                    head = head -> next;
                }

                travel = head;
            } else {
                prev -> next = midTravel;

                while(NULL != midTravel && 0 == midTravel -> val) {
                    midTravel = midTravel -> next;
                    prev -> next = midTravel;
                }
                travel = midTravel;
            }

            continue;
        }

        prev = travel;
        travel = travel -> next;
    }

    return head;
}

