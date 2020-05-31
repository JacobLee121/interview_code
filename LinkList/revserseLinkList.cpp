//
//  revserseLinkList.cpp
//  reverseLinkList
//
//  Created by 李鑫强 on 2020/5/30星期六.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "revserseLinkList.hpp"
#include <iostream>
using namespace std;
class ReverseList
{
public:
    ListNode* ReverseLisetRecursive(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reveseHead = ReverseLisetRecursive(head->next);
        ListNode* tmp = head->next;
        tmp->next = head;
        head->next = nullptr;
        return reveseHead;
    }
    ListNode* ReverseListCircle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //ListNode *revsedHead = nullptr;
        ListNode *cur = nullptr;
        ListNode *sec = head;
        while(sec != nullptr) {
            ListNode *tmp = sec->next;
            sec->next = cur;
            cur = sec;
            sec= tmp;
        }
        return cur;
    }
};

/*int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    LinkListManager llm;
    ListNode node1(1);
    ListNode node3(3);
    ListNode node5(5);
    llm.LinkLists(&node1, &node3);
    llm.LinkLists(&node3, &node5);
    llm.PrintLists(&node1);
    ReverseList rl;
    printf("revert by recursive..");
    ListNode *reHead1 = rl.ReverseLisetRecursive(&node1);
    llm.PrintLists(reHead1);
    printf("reverte by circle ...");
    ListNode *reHead2 = rl.ReverseListCircle(reHead1);
    llm.PrintLists(reHead2);
    
    return 0;
}*/
