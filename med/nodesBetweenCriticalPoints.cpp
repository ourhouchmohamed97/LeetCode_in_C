// Find the Minimum and Maximum Number of Nodes Between Critical Points

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first = -1;
        int last = -1;
        int minDistance = INT_MAX;
        int position = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            bool isLocalMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isLocalMin = curr->val < prev->val && curr->val < curr->next->val;

            if (isLocalMax || isLocalMin) {
                if (first == -1) {
                    first = position;
                } else {
                    minDistance = min(minDistance, position - last);
                }
                last = position;
            }

            prev = curr;
            curr = curr->next;
            ++position;
        }

        if (first == last) {
            return {-1, -1};
        }

        return {minDistance, last - first};
    }
};