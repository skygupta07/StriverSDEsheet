#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(0);  // creation of actual node...
        ListNode* temp = dummy;     // Node pointer to traverse over the linked list..

        while (a!=NULL && b!=NULL){    
            if (a->val <= b->val){  // best candidate kaun hai...
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        
        // at this point either a or b linked list has been exhausted...

        if (a == NULL) temp->next = b;
        else temp->next = a;
        return dummy->next;
        
    }
};

// names theek kar liya karo...
/*

yes done dryrun of recursive approach....  -> it was good

*/


// -----  - - - - ---------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Base cases: if one list is empty, return the other list
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        // Recursive case: compare the values of the current nodes
        if (l1->val < l2->val) {
            // If l1's value is smaller, merge the rest of l1 with l2 and link it to l1
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            // If l2's value is smaller or equal, merge l1 with the rest of l2 and link it to l2
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
