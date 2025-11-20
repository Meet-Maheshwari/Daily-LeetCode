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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        list<int> ans;

        for(ListNode* head : lists) {
            ListNode* p = head;

            while(p != NULL) {
                ans.push_back(p -> val);
                p = p -> next;
            }
        }

        if(ans.empty()) return NULL;

        ans.sort();

        ListNode head(0);
        ListNode* p = &head;

        for(int node : ans) {
            ListNode* newNode = new ListNode(node);
            p -> next = newNode;
            p = p -> next;
        }
        return head.next;
    }
};