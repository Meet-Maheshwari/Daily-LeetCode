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
        if(head == NULL) return 0;
        int count = 0;
        ListNode* p = head;

        while(p != NULL) {
            count++;
            p = p-> next;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        int s = getSize(head);
        if(k == s) return head;

        if(k > s) {
            k = k % s;
        }

        for(int i = 0; i < k; i++) {
            ListNode* p = head;
            ListNode* q = NULL;
            ListNode* tail = NULL;
            while(p -> next != NULL) {
                q = p;
                p = p -> next;
            }

            q -> next = NULL;
            p -> next = head;
            head = p;
        }

        return head;
    }
};