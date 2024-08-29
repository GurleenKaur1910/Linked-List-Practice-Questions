//LINKED LIST
//Insertion and Deletion of nodes at beginning, end, specific value and position.  
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d,node *next1)
    {
       data=d;
       next=next1;
    }
    node(int d)
    {
        data=d;
        next=nullptr;
    }
};
node* head=nullptr;
void insert_at_begin(int val)
    {
        node* newnode=new node(val);
        newnode->next=head;
        head=newnode;
    }
void insert_at_end(int val)
{
    node *newnode=new node(val);
    if(head==nullptr)
    {
        head=newnode;
        head->next=nullptr;
    }
    else{
    node* current=head;
    while(current->next)
    {
        current=current->next;
    }
    current->next=newnode;
    }
}
void insert_after_specific_val(int val,int d)
{
    node* newnode=new node(val);
    node* current=head;
    while(current->data!=d)
    {
        current=current->next;
    }
    node* temp=current->next;
    current->next=newnode;
    newnode->next=temp;
    
}
void insert_after_specific_pos(int val,int pos)
{
    node* newnode=new node(val);
    node* current=head;
    node* temp;
    int ct=0;
    while(ct!=pos)
    {
        current=current->next;
        ct++;
    }
    if(ct==pos)
    {
        temp=current->next;
        current->next=newnode;
        newnode->next=temp;
    }
    else
    {
        cout<<"Invalid pos";
    }
}
void display()
{
    node* current=head;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}
void delete_at_beg()
{
    if(head==nullptr)
    {
        cout<<"There is nothing to delete";
    }
    else
    {
        node* temp;
        temp=head;
        head=head->next;
        delete temp;
    }
}
void delete_from_end()
{
    if(head==nullptr)
    {
        cout<<"There is nothing to delete";
    }
    node* temp;
    if(head->next==nullptr)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        node* current=head;
        while(current->next->next)
        {
            current=current->next;
        }
        delete current->next;
        current->next=nullptr;
    }
}
void delete_specific_val(int val)
{
    if(head==nullptr)
    cout<<"There is nothing to delete";
    else
    {
        node* current=head;
        node* pre=head;
        while(current->data!=val && current)
        {
            pre=current;
            current=current->next;
        }
        pre->next=current->next;
        if(current)
        delete current;
        else
        cout<<"Does not exist";
    }
}
void delete_specific_pos(int pos)
{
    if(head==nullptr)
    cout<<"There is nothing to delete";
    else
    {
        int ct=0;
        node* current=head;
        node* pre=head;
        while(ct!=pos && current)
        {
            ct++;
            pre=current;
            current=current->next;
        }
        pre->next=current->next;
        if(current)
        delete current;
        else
        cout<<"Does not exist";
    }
}
int main() {
    // Write C++ code here
    insert_at_end(12);
    insert_at_begin(23);
    insert_at_end(33);
    insert_at_begin(3);
    insert_at_begin(43);
    insert_at_end(17);
    insert_at_end(10);
    insert_after_specific_val(11,43);
    insert_after_specific_pos(55,6);
    display();
    delete_at_beg();
    display();
    delete_from_end();
    display();
    delete_specific_val(23);
    display();
    delete_specific_pos(2);
    display();
    return 0;
}

//DOUBLY LINKED LIST
//Converting array to DLL
#include<bits/stdc++.h>
using namespace std;
/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */
Node*head=nullptr;
Node* constructDLL(vector<int>& arr) {
    // Write your code here
    int n=arr.size();
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++)
    {
        Node* newnode=new Node(arr[i],nullptr,temp);
        temp->next=newnode;
        temp=newnode;
    }
    return head;
}
void display(Node* current)
{
    while(current)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
}



//Insertion at the end
/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    Node* current=head;
    if(!head)
    {
        Node* newnode=new Node(k,nullptr,nullptr);
        head=newnode;
    }
    else
    {
        while (current->next) {
          current = current->next;
        }
        Node *newnode = new Node(k, current, nullptr);
        current->next = newnode;
    }
    return head;
}
void display(Node* current)
{
    while(current)
    {
        cout<<current->value;
        current=current->next;
    }
}

//Insertion at beginning
/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node* insertAtFront(Node *head, int k) {
    // Write your code here.
    Node* newnode=new Node(k,nullptr,head);
    if(!head)
    {
        head=newnode;
    } else {
         head->prev = newnode;
    } /* else {
     head->prev = newnode;
     newnode->next = head;
     head = newnode;
     return head;
 }*/
    return newnode;
}
void display(Node* current)
{
    while(current)
    {
        cout<<current->value;
        current=current->next;
    }
}

//Delete from beginning
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

Node * deleteHead(Node *head) {
    // Write your code here.
    if(!head)
    cout<<"Nothing to delete";
    if(!head->next)
    {
        delete head;
        head=nullptr;
    }
    else {
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    }
    return head;
}
void display(Node* current)
{
    if(!current)
    cout<<-1;
    else{
    while (current) {
      cout << current->data;
      current = current->next;
    }
    }
}




//Delete from end
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int d)
    {
        data=d;
        prev=nullptr;
        next=nullptr;
    }
   node(int d, node* prev1,node* next1)
   {
       data=d;
       prev=prev1;
       next=next1;
   }
};
node* head=nullptr;
void insertAtFront(int k) {
    // Write your code here.
    node* newnode=new node(k);
    if(!head)
    {
        head=newnode;
    } 
    else {
     head->prev = newnode;
     newnode->next = head;
     head = newnode;
    }
 
}
 void delete_from_end()
 {
     if(!head)
     {
         cout<<"nothing to delete";
     }
     if(!head->next)
     {
        delete head;
        head=nullptr;
     }
     else
     {
         node* current=head;
         while(current->next)
         {
             current=current->next;
         }
         current->prev->next=nullptr;
         delete current;
     }
 }
 void display()
 {
     node* current=head;
     while(current)
     {
         cout<<current->data<<" ";
         current=current->next;
     }
     cout<<"\n";
 }
int main() {
   
    insertAtFront(10);
    insertAtFront(66);
    insertAtFront(23);
    insertAtFront(56);
    display();
    delete_from_end();
    display();
    return 0;
}

//Deleting Kth node from the list

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */
Node * deleteHead(Node *head) {
    // Write your code here.
    if(!head)
    cout<<"Nothing to delete";
    if(!head->next)
    {
        delete head;
        head=nullptr;
    }
    else {
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    }
    return head;
}
Node* delete_from_end(Node* head)
 {
     if(!head)
     {
         cout<<"nothing to delete";
     }
     if(!head->next)
     {
        delete head;
        head=nullptr;
     }
     else
     {
         Node* current=head;
         while (current->next) {
           current = current->next;
         }
         current->prev->next = nullptr;
         delete current;
     }
     return head;
}
Node *deleteNode(Node *head, int k){
    // Write your code here
    int ct=0;
    Node* current=head;
    while(current)
    {
        ct++;
        if(ct==k)
        break;
        current=current->next;
    }
    Node* back=current->prev;
    Node* front=current->next;
    if(back==nullptr && front==nullptr)
    {
        delete current;
        return nullptr;
    }
    else if(back==nullptr)
    {
        return(deleteHead(head));
        delete current;
    }
    else if(front==nullptr)
    {
        return(delete_from_end(head));
        delete current;
    }
    else
    {
        back->next=front;
        front->prev=back;
    }
    
    return head;
}

//REVERSING A DLL

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/
#include<bits/stdc++.h>
//time complexity:O(2n) and space complexity:O(n)
Node* reverseDLL(Node* head)
{   
    // Write your code here  
    //using stack
    /*Node* temp=head;
    stack<int> st;
    while(temp!=nullptr) 
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }*/

//optimal method:swapping addresses

Node* last=nullptr;
Node* current=head;
if(!head || !head->next)
  return head;
while (current) {
  last = current->prev;
  current->prev = current->next;
  current->next = last;
  current = current->prev;
}
    return last->prev;

}

//ADD TWO NUMBERS IN A LL
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* temp=new Node(-1);
    Node* current=temp;
    int carry=0,sum=0;
    Node* t1=num1;
    Node* t2=num2;
    while(t1 || t2)
    {
        sum=carry;
        if (t1) {
          sum = sum + t1->data;
          t1 = t1->next;
        }
        if (t2) {
          sum = sum + t2->data;
          t2 = t2->next;
        }
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        current->next=newnode;
        current=current->next;
        /*if(t1)
        t1=t1->next;
        if(t2)
        t2=t2->next;*/
    }
    if (carry) {
        Node *newnode = new Node(carry);
        current->next = newnode;
    }
    return temp->next;
}

//REARRANGING ODD AND EVEN PLACED ELEMENTS
/****************************************************************
Following is the Linked list node structure already written

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

Node* oddEvenList(Node* head)
{
	// Write your code here.
  //BRUTE FORCE APPROACH
  if(!head || !head->next)
  {
     return head;
  }
   /* vector<int>arr;
    int i=0;
    Node* temp=head;
    //for odd placed elements
    while(temp && temp->next)
    {
      arr.push_back(temp->data);
      temp=temp->next->next;
    }
    if(temp)
    arr.push_back(temp->data);
    temp=head->next;
    //for even placed elements
    while(temp && temp->next)
    {
      arr.push_back(temp->data);
      temp=temp->next->next;
    }
    if(temp)
    arr.push_back(temp->data);
    //for transferring back array to ll
    temp=head;
    while(temp)
    {
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;*/
    //optimal approach without using an extra ll

    Node* odd=head;
    Node* even=head->next;
    Node* even1=head->next;
    while(even1 && even1->next)
    {
      odd->next=odd->next->next;
      even1->next=even1->next->next;
      odd=odd->next;
      even1=even1->next;
    }
    odd->next=even;
    return head;
}

//SORTING LL OF 0s,1s AND 2s
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    //BRUTE FORCE APPROACH
    /*int ct0=0,ct1=0,ct2=0;
    Node* temp=head;
    while(temp)
    {
        if(temp->data==0)
        ct0++;
        if(temp->data==1)
        ct1++;
        if(temp->data==2)
        ct2++;
        temp=temp->next;
    }
    temp=head;
    while(temp)
    {
        if(ct0)
        {
            temp->data=0;
            ct0--;
        }
        else if(ct1)
        {
            temp->data=1;
            ct1--;
        }
        else
        {
            temp->data=2;
            ct2--;
        }
        temp=temp->next;
    }
    return head;*/
    //OPTIMAL APPROACH
    //TAKING SEPARATE POINTERS FOR 0,1 AND 2  AND THEN LINKING THEM
    Node* temp=head;
    if(!head || !head->next)
    return head;
    Node* head0=new Node(-1);Node* zero=head0;
    Node* head1=new Node(-1);Node* one=head1;
    Node* head2=new Node(-1);Node* two=head2;
    while(temp)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(head1->next)?(head1->next):(head2->next);//if 1 does not exist,jump to 2s
    one->next=head2->next;
    two->next=nullptr;
    Node* newhead=head0->next;
    delete head0,head1,head2,zero,one,two,temp;
    return newhead;

}

//DELETING KTH NODE FROM THE END
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    //BRUTE FORCE APPROACH
    /*Node* temp=head;
    int ct=0;
    while(temp)
    {
       ct++;
       temp=temp->next;
    }
    temp=head;
    if(ct==K)
    {
        Node* newhead=head->next;
        delete head;
        return newhead;
    }
    else
    {
        int r=ct-K;
        while(temp)
        {
           r--;
           if(r==0)
           break;
           temp=temp->next;
        }
        Node* delnode=temp->next;
        temp->next=temp->next->next;
        delete delnode;
        return head;
    }*/
    Node* fast=head;
    Node* slow=head;
    for(int i=1;i<=K;i++)
    {
        fast=fast->next;
    }
    if(!fast)  //if K=5, we need to delete head;
    {
        Node* newhead=head->next;
        delete head;
        return newhead;
    }
    while(fast->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node* delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}


//REVERSING A LL ITERATIVE APPROACH
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };
        

*****************************************************************/
#include <bits/stdc++.h>
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    //BRUTE FORCE APPROACH-ITERATIVE
    /*stack<int> st;
    Node* temp=head;
    while(temp)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
   return head;*/
   //OPTIMAL APPROACH-ITERATIVE
    Node* front;
    Node* back=nullptr;
    Node* temp=head;
    while(temp)
    {
        front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }

 return back;
}


//REVERSING LL USING RECURSION
Node* reverseLinkedList(Node *head)
{
   
// RECURSIVE TECHNIQUE
  if(!head||!head->next)//for 0 or 1 node only
  return head;
  Node* newhead=reverseLinkedList(head->next);
  Node* front=head->next;
  front->next=head;
  head->next=nullptr;
  return newhead;
}


//CHECKING LL TO BE PALINDROME
/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/
#include <bits/stdc++.h>
Node* reverseLinkedList(Node *head)
    {
   
      // RECURSIVE TECHNIQUE
      if(!head||!head->next)//for 0 or 1 node only
      return head;
      Node* newhead=reverseLinkedList(head->next);
      Node* front=head->next;
      front->next=head;
      head->next=nullptr;
      return newhead;
    }
bool isPalindrome(Node *head)
{
    // write your code here
    //BRUTE FORCE APPROACH
    /*stack<int> st;
    Node* temp=head;
    while(temp)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp)
    {
        if(temp->data==st.top())
        {
            st.pop();
            temp=temp->next;
        }
        else
        {
            break;
        }
    }
    if(temp)
    return false;
    else
    return true;*/


    //RECURSIVE TECHNIQUE
    if(!head||!head->next)
    {
        return true;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=reverseLinkedList(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second)
    {
        if(first->data!=second->data)
        {
            reverseLinkedList(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLinkedList(newhead);
    return true;

}

//ADD 1 TO A NUMBER
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
int helper(Node* temp)
{
   if(temp==nullptr)
    return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10)
     return 0;
    temp->data=0;
    return 1;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
   int carry=helper(head);
   if(carry==1)
   {
     Node* newnode=new Node(1);
     newnode->next=head;
     return newnode;
   }
   return head;                                                                                                                                                                                                                                                                      
}


//FINDIND INTERSECTION POINT IN A LL
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <map>
//PART OF BETTER APPROACH
/*Node* collision(Node* t1,Node* t2,int d)
{
    while(d>0)
    {
        d--;
        t2=t2->next;
    }
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
    }
    return t1;

}*/
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    //Using hashing
    /*map<Node*,int> mpp;
    Node* temp=firstHead;
    while(temp)
    {
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=secondHead;
    while(temp)
    {
        if(mpp.find(temp)!=mpp.end())
        return temp;
        temp=temp->next;
    }
    return nullptr;*/

    //BETTER APPROACH
   /* Node* t1=firstHead; Node* t2=secondHead;
    int n1=0,n2=0;
    while(t1!=nullptr)
    {
        n1++;
        t1=t1->next;
    }
    while(t2!=nullptr)
    {
        n2++;
        t2=t2->next;
    }
    t1=firstHead;
    t2=secondHead;
    if(n1<n2)
    return collision(t1,t2,(n2-n1));
    else
    return collision(t2,t1,(n1-n2));*/

    //OPTIMAL APPROACH
    Node* t1=firstHead; Node* t2=secondHead;
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)
        return t1;
        if(!t1)
        t1=secondHead;
        if(!t2)
        t2=firstHead;
    }
    return t1;
}

//FINDING MIDDLE ELEMENT OF A LL
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    //BRUTE FORCE
    /*int n=0;
    Node* temp=head;
    while(temp)
    {
        n++;
        temp=temp->next;
    }
    int mid=(n/2+1);
    temp=head;
    while(temp)
    {
        mid--;
        if(mid==0)
        break;
        temp=temp->next;
    }
    return temp;*/
    //OPTIMAL APPROACH USING TORTOISE AND HAIR ALGORITHM
    //MOVING THE SLOW POINTER 1 STEP WHILE THE FAST POINTER MOVES TWICE
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

    
}

//CHECKING WHETHER A LOOP/CYC;E EXISTS IN A LL
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include <map>
bool detectCycle(Node *head)
{
	//	Write your code here
    //BRUTE FORCE APPROACH
    /*Node* temp=head;
    map<Node*,int> mpp;
    while(temp)
    {
        if(mpp.find(temp)!=mpp.end())
        return true;
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;*/
    //OPTIMAL APPROACH BY TORTOISE AND HAIR ALGORITHM
    //MOVE SLOW BY 1 STEP, FAST BY 2 STEPS
    //IF THEY MEET AT THE SAME NODE, THERE EXISTS A LOOP
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}


//FINDING LENGTH OF AN EXISTING LOOP/CYCLE IN A LL
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
#include <map>
int findlength(Node* slow,Node* fast)
{
    int ct=1;fast=fast->next;
    while(slow!=fast)
    {
        ct++;
        fast=fast->next;
    }
    return ct;
}
int lengthOfLoop(Node *head) {
    // Write your code here
    //BRUTE FORCE USING HASHING
    /*Node* temp=head;int timer=1,value;
    map<Node*,int> mpp;
    while(temp)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            value=mpp[temp];
           return (timer-value);
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return false;*/
    //OPTIMAL APPROACH USING TORTOISE HARE ALGORITHM
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return findlength(slow,fast);
    }
    return 0;

}

//DELETING THE MIDDLE NODE OF THE LL
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* deleteMiddle(Node* head){
    // Write your code here.
    //BRUTE FORCE SOLUTION 
    /*Node* temp=head;
    int n=0;
    if(!head||!head->next)
    return nullptr;
    while(temp)
    {
        n++;
        temp=temp->next;
    }
    temp=head;
    int mid=n/2;
    while(temp)
    {
        mid--;
        if(mid==0)
        {
           Node* middle=temp->next;
           temp->next=temp->next->next;
           delete middle;
           break;
        }
        temp=temp->next;
    }
    return head;*/
    //OPTIMAL APPROACH USING A VARIATION OF TORTOISE AND HARE ALGORITHM
    if(!head||!head->next)
    return nullptr;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;//so that slow remains before the middle node
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    delete middle;
    return head;

}


//FINDING THE STARTING POINT OF A LOOP IN A LL
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include <map>
Node *firstNode(Node *head)
{
    //    Write your code here.
    //BRUTE FORCE APPROACH USING HASHING
    /*Node* temp=head;
    map<Node*,int> mpp;
    while(temp)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return nullptr;*/
    //OPTIMAL APPROACH USING TORTOISE HARE ALGORITHM
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;//intuition: slow and fast will collide again and that point will be the starting point
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;


}

//DELETING ALL OCCURRENCES OF A KEY IN A DLL
/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    //TRAVERSING THROUGH THE COMPLETE DLL
    Node* temp=head;
    Node* nextnode=nullptr;
    Node* prevnode=nullptr;
    Node* del=nullptr;
    while(temp)
    {
        if(temp->data==k)
        {
            if(temp==head)
            {
                head=head->next;
            }
            nextnode=temp->next;
            prevnode=temp->prev;
            if(nextnode)
            nextnode->prev=prevnode;
            if(prevnode)
            prevnode->next=nextnode;
            delete temp;
            temp=nextnode;
        }
        else
        temp=temp->next;
    }
    return head;
}


//RETURNING PAIR OF ELEMENTS HAVING SUM 'K' IN A SORTED DLL
/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
#include <bits/stdc++.h>
Node* findTail(Node* head)
{
    while(head->next)
    {
        head=head->next;
    }
    return head;
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    //BRUTE FORCE APPROACH

    /*Node* temp1=head;
    Node* temp2=nullptr;
    vector<pair<int,int>> ds;
    while(temp1)
    {
        temp2=temp1->next;
        while(temp2 && temp1->data+temp2->data<=k)
        {
          if (temp1->data + temp2->data == k) {
            ds.push_back(make_pair(temp1->data, temp2->data));
          }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
 return ds;*/
 //OPTIMAL APPROACH USING TWO POINTER
   Node* left=head;
   Node* right=findTail(head);
   vector<pair<int,int>> ds;
   while(left->data<right->data)
   {
       if(left->data+right->data==k)
       {
         ds.push_back(make_pair(left->data, right->data));
         left=left->next;
         right=right->prev;
       }
       else if(left->data+right->data<k)
       {
           left=left->next;
       }
       else
       {
           right=right->prev;
       }
   }
   return ds;
  
}

//DELETING DUPLICATES FROM A SORTED DLL
/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    //OPTIMAL APPROACH
    //TIME COMPLEXITY:O(N) BECAUSE OUTER LOOP TRAVERSES NON DUPLICATE ELEMENTS 
    //AND INNER LOOP TRAVERSES DUPLICATE ONES
    Node* temp=head;
    Node* nextnode=nullptr;
    while(temp)
    {
       nextnode=temp->next;
       while(nextnode && nextnode->data==temp->data)
       {
           Node* copy=nextnode;
           nextnode=nextnode->next;
           delete(copy);
       }
       temp->next=nextnode;
       if(nextnode)
       nextnode->prev=temp;
       temp=temp->next;

    }
    return head;
}


//REVERSING NODES IN K GROUP SIZE IN A LL
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* reverseLinkedList(Node *head)
    {
   
      // RECURSIVE TECHNIQUE
      if(!head||!head->next)//for 0 or 1 node only
      return head;
      Node* newhead=reverseLinkedList(head->next);
      Node* front=head->next;
      front->next=head;
      head->next=nullptr;
      return newhead;
    }
Node* getKthnode(Node* temp,int k)
{
    k-=1;
    while(temp && k>0)
    {
       k--;
       temp=temp->next;
    }
    return temp;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
     Node* temp=head;
    Node* nextnode=nullptr;
    Node* prevnode=nullptr;
    while(temp)
    {
      Node* kthnode=getKthnode(temp,k);
      if(kthnode==nullptr)  //if no more splits possible
      {
          if(prevnode)
          prevnode->next=temp;
          break;
      }
      nextnode=kthnode->next;
      kthnode->next=nullptr;
      reverseLinkedList(temp);
      if(temp==head)
      {
          head=kthnode; //checking for the first split,therefore assigning kthnode to head after reversing
      }
      else{
          prevnode->next=kthnode;//connecting prev node with the next reversed linked list
      }
      prevnode=temp;
      temp=nextnode;
    }

return head;
}

//ROTATING LL K TIMES
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* findNthnode(Node* temp,int k)
{
     int ct=1;
     while(temp)
     {
          if(ct==k)
          return temp;
          ct++;
          temp=temp->next;
     }
     return temp;
}
Node *rotate(Node *head, int k) {
     // Write your code here.
     Node* tail=head;
     if(head==NULL || k==0)
     return head;
     int len=1;
     while(tail->next)
     {
        len++;
        tail=tail->next;
     }
      if(k%len==0)
      return head;

      k=k%len;
      //ATTACHING  TAIL TO THE HEAD
      tail->next=head;
      Node* newlastnode=findNthnode(head,len-k);
      head=newlastnode->next;
      newlastnode->next=nullptr;
   return head;
}


//MERGING TWO SORTED LISTS


/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include <bits/stdc++.h>
using namespace std;
Node<int>* convert(vector<int> arr)
{
    Node<int>* head;int i=1;
    Node<int>* temp=nullptr;
    Node<int>*newnode = new Node<int>(arr[0]);
    head=newnode;
    temp=head;
    //head->data=arr[0];
    while (i < arr.size()) {
      Node<int>* newnode = new Node<int>(arr[i]);
      temp->next=newnode;
      temp=temp->next;
      //newnode->data=arr[i];
      i++;
    }
    return head;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    //TRAVERSING BOTH THE LISTS AND STORING THE ELEMENTS IN AN ARRAY
    //CONVERTING THEM FURTHER INTO A LIST
    //BRUTE FORCE APPROACH
    /*Node<int>* temp1=first;
    Node<int>* temp2=second;
    vector<int> arr;
    while(temp1)                   //O(n1)
    {
     arr.push_back(temp1->data);
     temp1=temp1->next;
    }
    while(temp2)                   //O(n2)
    {
     arr.push_back(temp2->data);
     temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());   //O(n log n)
    Node<int>* head=convert(arr);  //O(n)
    return head;*/               //SC:O(n)+O(n)--> array+list

    //OPTIMAL APPROACH
    //USING THE DUMMY NODE AND CHANGING THE POINTERS
    Node<int>* t1=first;
    Node<int>* t2=second;
    Node<int>* dummy=new Node<int>(-1);
    Node<int>* temp=dummy;
    while(t1 && t2)         //O(n1+n2)  //SC:O(1)
    {
        if(t1->data<t2->data)
        {
          temp->next=t1;
          temp=t1;
          t1=t1->next;
        }
        else
        {
          temp->next=t2;
          temp=t2;
          t2=t2->next;
        }
    }
    if(t1)
    {
        temp->next=t1;
    }
    if(t2)
    {
        temp->next=t2;
    }
    return dummy->next; //head=dummy->next

}


//FLATTENING A LINKED LIST
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include <bits/stdc++.h>
//PART OF BRUTE FORCE APPROACH
/*Node* convert(vector<int> arr)
{
  Node* head=new Node(arr[0]);
  Node* temp=head;
  for(int i=1;i<arr.size();i++)
  {
	  Node* newnode=new Node(arr[i]);
      temp->child=newnode;
	  temp=temp->child;
  }
  return head;
}*/
Node* merge(Node* list1,Node* list2)
{
	Node* dummy=new Node(-1);
	Node* temp=dummy;
	while(list1 && list2)
	{
		if(list1->data<list2->data)
		{
           temp->child=list1;
		   temp=list1;
		   list1=list1->child;
		}
		else
		{
		   temp->child=list2;
		   temp=list2;
		   list2=list2->child;
		}
	if(list1)
	temp->child=list1;
	if(list2)
	temp->child=list2;
	/*if(dummy)
	{
		dummy->next->child=nullptr;
	}*/
	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	//BRUTE FORCE APPROACH
	/*Node* temp=head;
	Node* t2=nullptr;
    vector<int> arr;
	while(temp)   //O(n)
	{
		t2=temp;
		while(t2)   //O(m)
		{
          arr.push_back(t2->data);
		  t2=t2->child;
		}
		temp=temp->next;
	}
	sort(arr.begin(),arr.end());//O(n*mlog(n*m))
    return convert(arr);//O(n*m)                //SC:2*O(n*m)*/
	//OPTIMAL APPROACH
	//USING DUMMY NODE FOR MERGING TWO LISTS
	//USING RECURSION TO MERGE MULTIPLE LISTS ONE BY ONE
    if(!head || !head->next)
	return head;
	Node* merged=flattenLinkedList(head->next);
	return merge(head,merged);
}


//MERGE K SORTED LISTS
//PART OF BRUTE FORCE APPROACH
Node<int>* convert(vector<int> arr)
{
    Node<int>* head;int i=1;
    Node<int>* temp=nullptr;
    Node<int>*newnode = new Node<int>(arr[0]);
    head=newnode;
    temp=head;
    //head->data=arr[0];
    while (i < arr.size()) {
      Node<int>* newnode = new Node<int>(arr[i]);
      temp->next=newnode;
      temp=temp->next;
      //newnode->data=arr[i];
      i++;
    }
    return head;
}
//BRUTE FORCE APPROACH
func(vector<Node*> lists)
{
	vector<int> arr;         
	for(int i=0;i<lists.size();i++)   //o(k)
	{
		Node* temp=lists[i];
		while(temp)                   //o(n)
		{
			arr.push_back(temp->data);
			temp=temp->next;
		}
	}
	sort(arr.begin(),arr.end());      //o((n*k)log(n*k))
	return convert(arr);   //o(n*k)
}
//PART OF THE BELOW APPROACH
Node* merge(Node* list1,Node* list2)
{
	Node* dummy=new Node(-1);
	Node* temp=dummy;
	while(list1 && list2)
	{
		if(list1->data<list2->data)
		{
           temp->next=list1;
		   temp=list1;
		   list1=list1->next;
		}
		else
		{
		   temp->next=list2;
		   temp=list2;
		   list2=list2->child;
		}
	if(list1)
	temp->next=list1;
	if(list2)
	temp->next=list2;
	/*if(dummy)
	{
		dummy->next->child=nullptr;
	}*/
	return dummy->next;
}
//USING MERGE 2 SORTED LISTS APPROACH
func(vector<Node*> lists)
{
   Node* head=lists[0];
   for(int i=1;i<lists.size();i++)
   {
   	head=merge(head,lists[i]);
   }
   return head;
}
//OPTIMAL APPROACH:USING MIN-HEAP (PRIORITY QUEUE)
Node* merge(vector<Node*> lists)
{
	priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,
	greater<pair<int,Node*>>> pq;
	for(int i=0;i<lists.sizeE();i++)
	{
		if(lists[i])
		{
			pq.push({lists->data,lists[i]}); //filling priority queue
		}
	}
	Node* dummy=new Node(-1);
	Node* temp=dummy;
	while(!pq.empty())
	{
	  auto it=pq.top();
	  pq.pop();
	  if(it.second->next)
	  pq.push({it.second->next->data,it.second->next}); //if element exists in the list from wherre the minimum element is selected
	  temp->next=it.second;
	  temp=temp->next;
	}
}
return dummy->next;



//SORTING A LINKED LIST
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
Node* findMiddle(Node* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head){

    //BRUTE FORCE 
	//CONVERTING LIST TO ARRAY->SORT->CONVERT BACK TO LIST
    //RATHER THAN USING NEW LIST EDIT OLD LIST ONLY
    /*Node* temp=head;
	vector<int> arr;
	while(temp)
	{
     arr.push_back(temp->data);
	 temp=temp->next;
	}
	sort(arr.begin(),arr.end());
	temp=head;
	int i=0;
	while(temp)
	{
      temp->data=arr[i++];
	  temp=temp->next;
	}
	return head;*/
	//OPTIMAL APPROACH
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Find the middle of the list using the findMiddle function
    Node* middle = findMiddle(head);
    
    // Divide the list into two halves
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;
    
    // Recursively sort the left and right halves
    left = sortLL(left);
    right = sortLL(right);
    
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}

