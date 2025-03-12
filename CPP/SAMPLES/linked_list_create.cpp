#include<iostream>

using namespace std;

struct ListNode
{
    public:
        int val;
        ListNode* next;

        ListNode(int x):val(x), next(nullptr){}
};


ListNode* create_linked_list(int length){
    //create a linked list of length 'length'

    ListNode* head = nullptr;
    if(!length)
    return head;

    head = new ListNode(length);
    ListNode* curr = head;

    for(int i=length-1; i>=1; i--){
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    return head;
}

ListNode* copy_linked_list_and_add_k(ListNode* list, int k){
    ListNode* head = nullptr;
    if(!list)
    return head;

    head = new ListNode(list->val + k);
    ListNode *curr = head;

    while(list->next){
        curr->next = new ListNode(list->next->val + k);
        curr = curr->next;
        list = list->next;
    }


    return head;
}

void print_linked_list(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<"\n";
}

int main(){
    ListNode* head = create_linked_list(5);

    ListNode* copiedListHead = copy_linked_list_and_add_k(head, 1);

    print_linked_list(head);
    print_linked_list(copiedListHead);


    return 0;
}