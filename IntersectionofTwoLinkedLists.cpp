/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 暴力解法
    // 时间复杂度: O(n*m)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(!headA || !headB)
    //         return NULL;
            
    //     ListNode *p = headA;
    //     while(p){
    //         ListNode *q = headB;
    //         while(q){
    //             if(p == q)
    //                 return p;
    //             q = q->next;
    //         }
    //         p = p->next;
    //     }
    //     return NULL;
    // }
    
    
    ////////////////////////////////////////////////////
    // 去掉较长链表的多余元素
    // 
    // size_t getSize(ListNode *head){
    //     size_t size = 0;
    //     while(head){
    //         size++;
    //         head = head->next;
    //     }
    //     return size;
    // }
    
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(!headA || !headB)
    //         return NULL;
            
    //     size_t size_a = getSize(headA);
    //     size_t size_b = getSize(headB);
    //     ListNode **p = NULL;
    //     int delta = 0;
    //     if(size_a > size_b){
    //         p = &headA;
    //         delta = size_a - size_b;
    //     }else if(size_b > size_a){
    //         p = &headB;
    //         delta = size_b - size_a;
    //     }
        
    //     while(delta-- && *p){
    //          *p = (*p)->next;
    //     }
    //     if(!headA || !headB)
    //         return NULL;
        
    //     while(1){
    //         if(headA == headB)
    //             return headA;
    //         headA = headA->next;
    //         headB = headB->next;
    //     }
        
    //     return NULL;
    // }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(!headA || !headB)
        //     return NULL;
    
        bool list_a_over = false, list_b_over = false;
        ListNode *p = headA, *q = headB;
        while(1){
            if(p == q) return p;
            
            if(!p){
                if(list_a_over) return NULL;
                p = headB;
                list_a_over = true;
            }else{
                p = p->next;
            }
            
            if(!q){
                if(list_b_over) return NULL;
                q = headA;
                list_b_over = true;                
            }else{
                q = q->next;
            }
        }
    }
};
