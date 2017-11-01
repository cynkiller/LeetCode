/****************************************************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*****************************************************************************/

#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1, *p2, *p3, *h3, *next = NULL;
        int carry = 0;
        p1 = l1;
        p2 = l2;
        p3 = NULL;
        h3 = NULL;
        while (p1 || p2){
            next = new ListNode(0);
            if (!p3)
                h3 = p3 = next;
            else {
                p3->next = next;
                p3 = p3->next;
            }
            next->val = (((p1 != NULL) ? p1->val : 0) + ((p2 != NULL) ? p2->val : 0) + carry) % 10;
            next->next = NULL;
            carry = (((p1 != NULL) ? p1->val : 0) + ((p2 != NULL) ? p2->val : 0) + carry) / 10;
            p1 = (p1 != NULL) ? p1->next : p1;
            p2 = (p2 != NULL) ? p2->next : p2;
        }
        if (carry) {
            next = new ListNode(0);
            p3->next = next;
            p3 = p3->next;
            next->val = 1;
            next->next = NULL;
        }
        return h3;
    }
};

int main() {
    Solution slt;
    ListNode *l1, *l2, *n1, *n2 = NULL;
    l1 = NULL;
    l2 = NULL;
    n1 = NULL;
    n2 = NULL;
#define ARR_SIZE 3
    int arr1[ARR_SIZE] = {2, 4, 3};
    int arr2[ARR_SIZE] = {5, 6, 4};
    for (int i = 0; i < ARR_SIZE; i++) {
        n1 = new ListNode(0);
        n2 = new ListNode(0);
        n1->val = arr1[i];
        n2->val = arr2[i];
        if (!l1)
            l1 = n1;
        else
            l1->next = n1;
        if (!l2)
            l2 = n2;
        else
            l2->next = n2;
    }
    ListNode* result = slt.addTwoNumbers(l1, l2);
    for(int i = 0; i < ARR_SIZE; i++) {
        std::cout << result->val << "\t";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}