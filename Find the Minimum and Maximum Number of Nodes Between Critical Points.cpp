// C++ Solution

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL) return {-1,-1};
        ListNode* temp = head;
        ListNode* prev = head;
        temp = temp->next;
        vector<int> ans;
        if(temp == NULL || temp->next == NULL) return {-1,-1};
        int len = 1;
        while(temp->next){
        if((temp->next->val > temp->val && prev->val > temp->val) || (temp->next->val < temp->val && prev->val < temp->val) ) ans.push_back(len);
        len++;
        prev = temp;
        temp=temp->next;
        }
        if(ans.size()<=1) return {-1,-1};
        int minima = INT_MAX;
        for(int i=1;i<ans.size();i++){
             minima=min(minima, ans[i]-ans[i-1]);
        }
        return {minima, ans.back() - ans[0]};
    }
};
