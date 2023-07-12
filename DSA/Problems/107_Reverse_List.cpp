//My own solution without copying with concept from the help of youTube video
//https://www.youtube.com/watch?v=bjtMCwy_LMA
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode *prev=nullptr;
        ListNode *curr=head;
        ListNode *Next;

        while(curr != NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
};

//without stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }
};

//using stack
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    } else {
        stack<ListNode*> stk;
        while (head != nullptr) {
            stk.push(head);
            head = head->next;
        }
        ListNode* reversedList = stk.top();
        ListNode* reversedListHead = reversedList;
        stk.pop(); // Remove the first element from the stack since it will be the head of the reversed list
        while (!stk.empty()) {
            reversedList->next = stk.top();
            stk.pop();
            reversedList = reversedList->next;
        }
        reversedList->next = nullptr;
        return reversedListHead;
    }
}

};