
/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        deque<ListNode*> node_que;
        
        if(n<=0) return head;
        ListNode *p = head;
        while(p){
            if(node_que.size() > n) // 多保留一个，用于 [idx-1]
                node_que.pop_front();
            node_que.push_back(p);
            p = p->next;
        }
        
        size_t idx = node_que.size() - n;
        if(idx < 0) return head;
        if(idx == 0){
            return head->next;
        }
        node_que[idx-1]->next = node_que[idx]->next;
        
        return head;
    }
};
