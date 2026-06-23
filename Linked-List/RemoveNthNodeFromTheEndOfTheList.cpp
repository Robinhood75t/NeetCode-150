
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        if(n == 1 && head->next == NULL){
            return NULL;
        }
        ListNode* curr = head;
        int size = 0;
        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        int new_n = size - n;
        if(new_n == 0){
            return head->next;
        }

        curr = head;
        for(int i = 0; i < size - 1; i++){
            if((i + 1) == new_n){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
