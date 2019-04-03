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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k<=0){
            return head;
        }
        int len=1;
        ListNode *p=head;
        while (p->next !=NULL){p=p->next;len++;}
        p->next=head;
        k=len-k %len;
        for (int i=0;i<k;i++){p=p->next;}
        head=p->next;
        p->next=NULL;
        return head;
    }
};