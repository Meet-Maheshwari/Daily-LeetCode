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
    ListNode* splitAtMid(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        while(head1 != NULL && head2 != NULL) {
            if(head1->val <= head2 ->val) {
                p -> next = head1;
                p = p -> next;
                head1 = head1->next;
            } else {
                p -> next = head2;
                p = p -> next;
                head2 = head2->next;
            }
        }

        while(head1 != NULL) {
            p -> next = head1;
            p = p -> next;
            head1 = head1->next;
        }

        while(head2 != NULL) {
            p -> next = head2;
            p = p -> next;
            head2 = head2->next;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* mid = splitAtMid(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* p = NULL;
        ListNode* head = p;
        ListNode* q = p;

        for(ListNode* node : lists){
            if(node == NULL) continue;
            p = node;

            if(q != NULL) {
                q->next = p;
            } else {
                head = p;             
            }

            while(p->next != NULL) {
                p = p->next;
            }
            q = p;
        }
        if(head == NULL) return NULL;
        head = mergeSort(head);      
        return head;
    }
};