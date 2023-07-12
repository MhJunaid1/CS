// I created on my own with the help of youtube video
// https://youtu.be/Fj1ywT9ETQk
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using floyed's Algorithm
        //Hare and Tortoise 
        if(head==nullptr){
            return false;
        }
        ListNode *slow=head,*fast=head;
        
        while(fast!=nullptr){

            if(fast->next==nullptr){
                return false;
            }
            else{
                if(fast->next->next==nullptr){
                    return false;
                }
                else{
                    fast=fast->next->next;
                    slow=slow->next;
                }
            }
            if(fast==slow){
                return true;
            }

        }
        return false;
    }
};