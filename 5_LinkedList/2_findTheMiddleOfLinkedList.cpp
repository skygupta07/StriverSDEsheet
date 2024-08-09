class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize slow and fast pointers to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list
        // Fast pointer moves two steps at a time, slow pointer moves one step at a time
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps
        }

        // When fast pointer reaches the end, slow pointer is at the middle
        return slow;
    }
};




class Solution {
public:
    ListNode* middleNode(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while (temp!=NULL){
            count++;
            temp = temp->next;
        }
        temp = head;


        for (int i=0; i<count/2; i++){
            temp = temp->next;
        }
        // 
        return temp;
        
    }
};
