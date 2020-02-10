/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){

	if(NULL == head || NULL == head -> next) {
		return head;
	}

	struct ListNode *newHead = NULL, *travel = head;

	while(NULL != travel) {
		struct ListNode* InsertNode = malloc(sizeof(struct ListNode));
		InsertNode -> val = travel -> val;
		InsertNode -> next = newHead;
		newHead = InsertNode;

		travel = travel -> next;
	}

	return newHead;
}


struct ListNode* reverseBetween(struct ListNode* head, int startPos, int endPos){
    if(NULL == head || NULL == head -> next){
        return head;
    }

    /// if start and end are in same position
    if(startPos == endPos) {
        return head;
    }


    if(1 == startPos) {
        struct ListNode *chunkHead = NULL, *chunkTravel;


        /// getting the chunk
        while(endPos > 1) {
            struct ListNode* insertedNode = head;
            head = head -> next;
            insertedNode -> next = NULL;

            if(NULL == chunkHead) {
                chunkHead = insertedNode;
                chunkTravel = chunkHead;
            } else {
                while(NULL != chunkTravel -> next) {
                    chunkTravel = chunkTravel -> next;
                }

                chunkTravel -> next = insertedNode;
            }

            endPos--;
        }

        /// reversing the chunk
        chunkHead = reverseList(chunkHead);

        chunkTravel = chunkHead;

        while(NULL != chunkTravel -> next) {
            chunkTravel = chunkTravel -> next;
        }

        chunkTravel -> next = head -> next;

        head -> next = chunkHead;

        return head;
    }

    head -> next = reverseBetween(head -> next, startPos - 1, endPos - 1);

    return head;
}

