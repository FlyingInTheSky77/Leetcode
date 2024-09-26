// 206_Reverse_Linked_List.cpp
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
      ~ListNode() {
          delete next;
      }
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current!= nullptr) {
            ListNode* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev;
    }
};

ListNode* createListNode(int size) {
    ListNode* head = nullptr;
    for (int i = 0; i < size; ++i) {
        ListNode* current = new  ListNode(i, head);
        head = current;
    }
    return head;
}

void destroedListNode(ListNode* head) {
   ListNode* current = head;
   do {
       ListNode* temp = current;
       current = current -> next;
       delete temp;
   } while (current != nullptr);
}

void printList(ListNode* head) {
    do {
        std::cout << head->val;
        head = head->next;
    } while(head != nullptr);
}

std::vector<int> doVectorFromList(ListNode* list) {
    std::vector<int> vec;
    do {
        vec.push_back(list->val);
        list = list->next;
    } while(list != nullptr);
    return vec;
}

int main() {

{ // test case #1
    const int number = 5;
    ListNode* list = createListNode(number);

    Solution s;

    std::vector< int > vec = doVectorFromList(list);
    reverse(vec.begin(), vec.end());

    assert(doVectorFromList(s.reverseList( list ) ) == vec);

    destroedListNode(list);
}

{ // test case #2
    const int number = 10;
    ListNode* list = createListNode(number);

    Solution s;

    std::vector<int> vec = doVectorFromList(list);
    reverse(vec.begin(), vec.end());

    assert(doVectorFromList(s.reverseList(list)) == vec);

    destroedListNode(list);
}

{ // test case #3
    const int number = 1;
    ListNode* list = createListNode(number);

    Solution s;

    std::vector<int> vec = doVectorFromList(list);
    reverse(vec.begin(), vec.end());

    assert(doVectorFromList(s.reverseList(list)) == vec);

    destroedListNode(list);
}

{ // test case #4
    const int number = 2;
    ListNode* list = createListNode(number);

    Solution s;

    std::vector<int> vec = doVectorFromList(list);
    reverse(vec.begin(), vec.end());

    assert(doVectorFromList(s.reverseList(list)) == vec);

    destroedListNode(list);
}

{ // test case #5
    const int number = 10;
    ListNode* list = createListNode(number);

    Solution s;

    std::vector<int> vec = doVectorFromList(list);
    reverse(vec.begin(), vec.end());

    assert(doVectorFromList(s.reverseList(list)) == vec);

    destroedListNode(list);
}

return 0;

}
