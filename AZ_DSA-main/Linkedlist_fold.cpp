#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
    void splitMid(node* actual, node** ls1, node** ls2 ){
        node *slow = actual, *fast = actual->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        node* temp = slow->next;
        slow->next = NULL;
        *ls1 = actual;
        *ls2 = temp;
    }
    void reverse(node* cur, node** head){
        if(cur==NULL) {
            *head = NULL;
            return;
        }
        if(cur->next==NULL){
            *head = cur;
            return;
        }
        else{
            reverse(cur->next, head);
            cur->next->next=cur;
            cur->next = NULL;
        }
    }
    node* alternate(node* ls1, node* ls2){
        node* head = ls1;
        node* temp1 = ls1;
        node* temp2 = ls2;
        while(temp1!=NULL && temp2!=NULL){
            node* next1 = temp1->next;
            node* next2 = temp2->next;
            temp1->next = temp2;
            temp2->next = next1;
            temp1 = next1;
            temp2 = next2;
        }
    }
    node* fold(node* inplist){
        node *temp1, *temp2, *temp3;
        splitMid(inplist, &temp1, &temp2);
        reverse(temp2, &temp3);
        return alternate(temp1, temp3);
    }
    void splitAlternate(node* actual, node** ls1, node** ls2){
        node* temp1 = actual;
        node* temp2 = actual->next;
        *ls1 = temp1;
        *ls2 = temp2;
        while(temp1!=NULL && temp2!=NULL ){
            temp1->next = temp2->next;
            temp1 = temp1->next;
            if(temp1==NULL) break;
            temp2->next = temp1;
            temp2 = temp2->next;
        }
    }
    node* unfold(node* folded){
        node *temp1, *temp2, *temp3;
        splitAlternate(folded, &temp1, &temp2);
        reverse(temp2, &temp3);
        temp2 = temp1;
        while(temp2->next!=NULL) temp2 = temp2->next;
        temp2->next = temp3;
        return temp1;
    }
