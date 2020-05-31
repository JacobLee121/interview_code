//
//  mergeTwoSortedList.cpp
//  LinkListTest
//
//  Created by 李鑫强 on 2020/5/31星期日.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "mergeTwoSortedList.hpp"
#include <vector>
#include <unordered_map>
class MergeList {
public:
    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        /*
         function :return merged list by order
         */
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *mHead = nullptr;
        // mHead has been created Ntimes(N =  call recursive times), the first
        // mHead return as the final answer. others return as the mid ans
        if ( l2->val > l1->val) {
            mHead = l1;
            mHead->next = mergeTwoListsRecursive(l1->next, l2);
        }
        else {
            mHead = l2;
            mHead->next = mergeTwoListsRecursive(l1, l2->next);
        }
        //mHead = ret;
        //ret->next = mHead;
        //mHead = ret;
        //mHead->next = ret;
        return mHead;
    }
    ListNode * MergeTwoSortedListLoop(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *pre = new ListNode(-1);
        ListNode *head = pre;
        //cur= head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
                
            }
            else {
                pre->next = l2;
                l2 = l2->next;
                
            }
            pre = pre->next;
        }
        pre->next = l1 == nullptr? l2: l1;
        
        return head->next;
        
    }
};
/*int main ()
{
    printf("merge to sorted list \n");
    LinkListManager llm;
    ListNode node1(1);
    ListNode node2(3);
    ListNode node4(5);
    llm.LinkLists(&node1, &node2);
    llm.LinkLists(&node2, &node4);
    llm.PrintLists(&node1);
    
    ListNode nodeb1(2);
    ListNode nodeb3(4);
    ListNode nodeb4(8);
    ListNode nodeb5(10);
    llm.LinkLists(&nodeb1, &nodeb3);
    llm.LinkLists(&nodeb3, &nodeb4);
    llm.LinkLists(&nodeb4, &nodeb5);
    llm.PrintLists(&nodeb1);
    
    MergeList s;
    //ListNode *ret = s.mergeTwoListsRecursive(&node1, &nodeb1);
    //llm.PrintLists(ret);
    
    ListNode *retLoop = s.MergeTwoSortedListLoop(&node1, &nodeb1);
    llm.PrintLists(retLoop);
}
*/
