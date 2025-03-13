#include<iostream>

using namespace std;

struct ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int x): val(x), next(nullptr){}
};


ListNode* create_linked_list(int len){
    ListNode* head = nullptr;

    if(!len)
    return head;

    head = new ListNode(1);
    ListNode* curr = head;

    for(int i=2; i<=len; i++){
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    return head;
}

void print_linked_list(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}

ListNode* remove_nth_from_start(ListNode* head, int n){ //assuming 'n' is always less than the len of the linked list
    int count = 0;
    ListNode* newHead = head;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr){
        count++;
        if(count==n){
            if(curr==head){
                newHead = head->next;
                delete head;
                break;
            }
            else{
                prev->next = curr->next;
                delete curr;
                break;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    return newHead;

}



int main(){

    ListNode* head = create_linked_list(7);
    print_linked_list(head);

    ListNode* newHead = remove_nth_from_start(head, 5);
    print_linked_list(newHead);

    return 0;
}