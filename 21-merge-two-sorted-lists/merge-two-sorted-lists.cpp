/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p != NULL) {
            count++;
            p = p->next;
        }

        return count;
    } 

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* head = nullptr;  // head of merged list
        ListNode* temp = nullptr;  // keeps track of last node

        ListNode* i = list1;
        ListNode* j = list2;

        // initialize head
        if(i->val <= j->val) {
            head = i;
            i = i->next;
        } else {
            head = j;
            j = j->next;
        }

        temp = head;

        while(i != NULL && j != NULL) {
            if(i -> val <= j -> val) {
                temp -> next = i;
                i = i -> next;
            } else {
                temp -> next = j; 
                j = j -> next;
            }
            temp = temp -> next;
        }

        if(i == NULL) temp -> next = j;
        if(j == NULL) temp -> next = i;

        return head;
    }
};