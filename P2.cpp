/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prev = NULL;
        ListNode *n1 = l1;
        ListNode *n2 = l2;
        int carry = 0;
        int res;
        while (n1 != NULL && n2 != NULL)
        {
            res = (n2->val + n1->val) + carry;
            n2->val = res % 10;
            carry = res / 10;
            
            prev = n2;
            n2 = n2->next;
            
            n1 = n1->next;
        }
    
        while (carry != 0 || n1 != NULL)
        {
            if (n2 == NULL && n1 == NULL)
            {
                ListNode* n = new ListNode(carry);
                prev->next = n;
                carry = 0;
            }
            else if (n2 == NULL && n1 != NULL)
            {
                res = carry + n1->val;
                ListNode* n = new ListNode(res % 10);
                prev->next = n;
                carry = res / 10;
                prev = n;
                n1 = n1->next;
            }
            else if (n2 != NULL && n1 == NULL)
            {
                res = carry + n2->val;
                n2->val = res % 10;
                carry = res / 10;
                prev = n2;
                n2 = n2->next;   
            }
        }
        
        return l2;
    }