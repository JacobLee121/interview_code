//
//  getjointnode.cpp
//  LinkListTest
//
//  Created by 李鑫强 on 2020/5/31星期日.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "getjointnode.hpp"
#include "linkListManager.hpp"
#include <unordered_set>

using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode_hashset(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> b;
        
        while (headB) {
            b.insert(headB);
            headB = headB->next;
        }
        while (headA) {
            if (b.count(headA))
            {
                return headA;
            }
            //a.insert(headA);
            headA = headA->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode_loop(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b) {
            a = ((a == nullptr) ? headB:a->next);
            b = ((b == nullptr) ? headA:b->next);
        }
        return b;
    }
};
int main()
{
    return 0;
}
