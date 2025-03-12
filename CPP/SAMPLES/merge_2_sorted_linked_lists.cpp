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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
            /*
                GIVEN
                    head of list1
                    head of list2
                    both are already sorted in non decreasing order
    
                CONSTRAINTS
                    number of nodes -- [0, 50]
                    node val -- [-100, 100]
    
                EXPECTED
                    return head of merged linked list(non decreasing order)
    
                REMOVE UNNECESSARY INFO
                    nothing found
    
                EXTRACT/DERIVE USEFUL INFO
                    The 2 lists are already sorted. We have 2 pointers, we need to compare values of the 2 pointers, and push them accordingly to the new list.
                    Assuming there are no cycles.
    
                TEST CASES (BASE, EDGE, GENERAL)
                    1. list1 = [] and list2 =[]
                    2. list1=[]  and list2 = [1,2,4,5,6] OR list2=[]  and list1 = [1,2,4,5,6] {One empty list and one non empty list}
                    3. list1 = [] and list2 =[1] OR list2 = [] and list1 =[1] {one empty list and other list with only one element.}
                    4. list1 = [1,2,23,4] and list2 = [5,6,7,8,9]
    
    
                ALGORITHM
                    1. if both list are empty, return nullptr.
                    2. if any of the list is empty, return pointer of other list.
                    3. if both the lists are not empty, then initilize head ptr, and create nodes accordingly.
                        compare two ptrs, and create a node containing the smaller value and go to the next ptr of current list.
                        finally return the headptr.
    
                DATA STRUCTURE
                    linked list
    
                TRY TO OPTIMIZE
    
            */
    
                
    
                if(!list1 && !list2)
                return nullptr;
    
                if(!list1)
                return list2;
    
                if(!list2)
                return list1;
    
                ListNode* head = nullptr;
                ListNode* curr = nullptr;
    
                while(list1 && list2){
                    if(list1->val <= list2->val){
                        if(!curr){
                            curr = new ListNode(list1->val);
                            head=curr;
                        }
                        else{
                            curr->next = new ListNode(list1->val);
                            curr = curr->next;
                        }
                        list1=list1->next;
                    }
                    else{
                        if(!curr){
                            curr = new ListNode(list2->val);
                            head=curr;
                        }
                        else{
                            curr->next = new ListNode(list2->val);
                            curr = curr->next;
                        }
                        list2=list2->next;
                    }
                }
    
                if(list1)
                curr->next = list1;
    
                if(list2)
                curr->next = list2;
    
                return head;
    
            
        }
    };





class Solution2 {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
                if(!list1 && !list2)
                return nullptr;
    
                if(!list1)
                return list2;
    
                if(!list2)
                return list1;
    
    
                ListNode* head = nullptr;
                ListNode* curr = nullptr;
                
                if(list1->val <= list2->val){
                    head = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else{
                    head = new ListNode(list2->val);
                    list2 = list2->next;
                }
                curr = head;
    
    
                while(list1 && list2){
                    if(list1->val <= list2->val){
                        curr->next = new ListNode(list1->val);
                        list1 = list1->next;
                    }
                    else{
                        curr->next = new ListNode(list2->val);
                        list2 = list2->next;
                    }
                    curr = curr->next;
                }
    
                if(list1)
                curr->next = list1;
    
                if(list2)
                curr->next = list2;
    
                return head;
    
            
        }
    };