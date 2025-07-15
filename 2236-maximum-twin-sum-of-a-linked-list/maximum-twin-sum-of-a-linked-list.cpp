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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* q = NULL;
        
        while(fast != NULL && fast->next != NULL) {
            q = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        q->next = NULL;

        ListNode* curr = slow;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        int maxTwinSum = 0;
        while(head != NULL && prev != NULL) {
            int twinSum = head->val + prev -> val;
            maxTwinSum = max(maxTwinSum, twinSum);
            head = head->next;
            prev = prev->next;
        }

        return maxTwinSum;
    }
};