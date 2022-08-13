#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;

    Node(int value)
    {
        this -> value = value;
        this -> Next = NULL;
    }
};
void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void insertAtHead(Node* &head,int val)
{
    //step 1:newNode creation
    Node *newNode = new Node(val);
    //step 2: update of newNode next
    newNode->Next = head;
    //step 3: update of head
    head = newNode;
}
// reverse a link list in non-recursive way
Node* reverseNonRecursive(Node* &head)
{
    Node *prev = NULL;
    Node *current = head;
    if(head == NULL)
    {
        cout<<"The linked list is empty"<<endl;
        return head;
    }
    Node *next = head->Next;

    while(true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if(current == NULL) break;
        next = next->Next;
    }
    return prev;

}
Node* reversalRecursiveWay(Node* &head)
{
    //BASE CALL
    if(head == NULL || head->Next == NULL){
        if(head == NULL) cout<<"The link list is empty"<<endl;
        return head;
    }
    //RECURSIVE CALL
    Node *newHead = reversalRecursiveWay(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;

}
void display(Node *n)
{
    while(n != NULL)
    {
        cout<<n->value;
        if(n->Next != NULL) cout<<" -> ";
        n = n->Next;
    }
}
int main()
{
    Node *head = NULL;
    int n;
    cout<<"Choice 1 : Insertion of head"<<endl<<"Choice 2 : Insertion of tail"<<endl<<"Choice 3 : Reversal of a linkList(Non-recursive)"<<endl;
    cout<<"Choice 4 : Reversal of a linkList(Recursive-way)"<<endl<<"Choice 5 : Exit"<<endl<<endl;
    int choice;
    while(choice != 0)
    {
        cout<<"Next Choice : ";
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Enter your value : ";
            cin>>n;
            insertAtHead(head,n);
        }

        else if(choice == 2)
        {
            cout<<"Enter your value : ";
            cin>>n;
            insertAtTail(head,n);
        }

        else if(choice == 3)
        {
            head = reverseNonRecursive(head);
        }
        else if(choice == 4){
           head = reversalRecursiveWay(head);
        }
    }

    cout<<endl<<"Link list : ";
    display(head);


    return 0;
}

