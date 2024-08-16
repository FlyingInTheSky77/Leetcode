#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        bool l1_end = false;
        bool l2_end = false;
        int add = 0;
        while ( !(l1_end && l2_end) ) {
            int value = 0;
            if (!l1_end) {
                value += l1->val;
            }
            if (!l2_end) {
                value += l2->val;
            }
            value += add;
            add = 0;

            if ( value > 9 ) {
                value = value - 10;
                add = 1;
            }
            ListNode* temp = new ListNode(value, result);
            result = temp;

            if (l1->next == nullptr) {
               l1_end = true;
            }
            else {
                l1 = l1->next;
            }
            if (l2->next == nullptr) {
               l2_end = true;
            }
            else {
                l2 = l2->next;
            }
        }

        if ( add != 0 ) {
            ListNode* temp = new ListNode(add, result);
            result = temp;
        }
        ListNode* revers_result = reverseList(result);
        return revers_result;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

int main() {

    { // visual check block #1
     std::cout << "\n === visual check block #1 ==== \n";
    
     ListNode* first_node = new ListNode(2);
     ListNode* second_node = new ListNode(4,first_node);
     ListNode* third_node = new ListNode(3,second_node);
     ListNode* next_first = new ListNode(5);
     ListNode* next_second = new ListNode(6,next_first);
     ListNode* next_third = new ListNode(4,next_second);
     
     Solution s;
     auto list_ptr = s.addTwoNumbers(third_node, next_third);
     int i = 1;
     std::cout << "result: digit \"" << i << "\"= ";
     std::cout << list_ptr->val << std::endl;
        while (list_ptr->next) {
            list_ptr = list_ptr->next;
            i++;
            std::cout << "result: digit \"" << i << "\"= ";
            std::cout << list_ptr->val << std::endl;
        }
    }

    { // visual check block #2
        std::cout << "\n === visual check block #2 ==== \n";
        ListNode* first_node1 = new ListNode(9);
        ListNode* first_node2 = new ListNode(9,first_node1);
        ListNode* first_node3 = new ListNode(9,first_node2);
        ListNode* first_node4 = new ListNode(9,first_node3);
        ListNode* first_node5 = new ListNode(9,first_node4);
        ListNode* first_node6 = new ListNode(9,first_node5);
        ListNode* first_node7 = new ListNode(9,first_node6);

        ListNode* second_node1 = new ListNode(9);
        ListNode* second_node2 = new ListNode(9,second_node1);
        ListNode* second_node3 = new ListNode(9,second_node2);
        ListNode* second_node4 = new ListNode(9,second_node3);

        Solution s;
        auto list_ptr = s.addTwoNumbers(first_node7, second_node4);
        int i = 1;
        std::cout << "result: digit \"" << i << "\"= ";
        std::cout << list_ptr->val << std::endl;
        while (list_ptr->next) {
            list_ptr = list_ptr->next;
            i++;
            std::cout << "result: digit \"" << i << "\"= ";
            std::cout << list_ptr->val << std::endl;
        }
    }
}
