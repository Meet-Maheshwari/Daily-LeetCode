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
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* dummy = NULL;

        while(fast != NULL && fast -> next != NULL) {
            dummy = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }    

       dummy -> next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        while(prev != NULL && head != NULL) {
            if(prev -> val != head -> val) {
                return false;
            }
            prev = prev -> next;
            head = head -> next;
        }

        return true;
    }
};

