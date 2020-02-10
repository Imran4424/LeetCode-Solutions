/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(NULL == head) {
        return;
    }

    struct ListNode *oddHead = NULL;
    struct ListNode *evenHead = NULL;

   struct ListNode *oddTravel, *evenTravel;
   int indicator = 1;

   while(NULL != head) {
        struct ListNode* insertNode = head;
        head = head -> next;
        insertNode -> next = NULL;
        if(indicator % 2 == 0) {
            if(NULL == evenHead) {
                evenHead = insertNode;
                evenTravel = evenHead;
            } else {
                while(NULL != evenTravel -> next) {
                    evenTravel = evenTravel -> next;
                }

                evenTravel -> next = insertNode;
            }
        } else {
            if(NULL == oddHead) {
                oddHead = insertNode;
                oddTravel = oddHead;
            } else {
                while(NULL != oddTravel -> next) {
                    oddTravel = oddTravel -> next;
                }

                oddTravel -> next = insertNode;
            }
        }

        indicator++;
    }

    while(NULL != oddTravel -> next) {
        oddTravel = oddTravel -> next;
    }

    oddTravel -> next = evenHead;

    return oddHead;
}

