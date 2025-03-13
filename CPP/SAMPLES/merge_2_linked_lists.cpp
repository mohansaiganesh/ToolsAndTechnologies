// merge two linked lists, assuming length of list1>=list2

//list1 = [1,2,3]
//list2 = [5,4]
//merged list = [1,5,2,4,3]

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_linked_list(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}


int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);

    // print_linked_list(list1);

    ListNode* list2 = new ListNode(3);
    


    ListNode* temp1 = nullptr;
    ListNode* temp2 = nullptr;

    ListNode* list1temp = list1;
    ListNode* list2temp = list2;
    while(list2temp){
        temp1 = list1temp->next;
        temp2 = list2temp->next;

        list1temp->next = list2temp;
        list2temp->next = temp1;

        list1temp = temp1;
        list2temp = temp2;
    }


    print_linked_list(list1);


        

    return 0;
}
