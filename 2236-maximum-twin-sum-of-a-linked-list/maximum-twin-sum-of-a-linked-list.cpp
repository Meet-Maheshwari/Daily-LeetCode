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
        ListNode* p = head;
        vector<int> list;

        while(p != NULL) {
            list.push_back(p -> val);
            p = p->next;
        }

        int maxTwinSum = 0, n = list.size();
        for(int i = 0; i < n/2; i++) {
            int twinSum = list[i] + list[n-i-1];
            maxTwinSum = max(maxTwinSum, twinSum);
        }

        return maxTwinSum;
    }
};