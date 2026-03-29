#include<iostream>
using namespace std;
class Node {
    public:
   int data;
   Node *next;
   Node(int x){
    data = x;
    next = NULL;
   }
};
Node *head = NULL;
Node* insert(Node *head, int data){
    Node *n = new Node(data);
    if(head==NULL) return n;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
    }
    temp = n;
    return head;
}
Node* deleteend(Node *head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next!=NULL) temp = temp->next;
    temp = NULL;
    return head;
}
void printer(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    insert(head, 4);
    insert(head, 7);
    insert(head, 8);
    deleteend(head);
    printer(head);

}
    