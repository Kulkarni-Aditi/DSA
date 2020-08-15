#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* link;
};


class linkedlist
{
     public:
     node* head_node=NULL;
     void insertnode();// function to insert a node
     void deletenode();// function to delete a node
     void searchnode();// function  to search a node
     void length ();// function to calculate length of linked list
};
void linkedlist::insertnode()
{
    int num;
    node* temp= new(node);// creating a new node
    cout<<"Enter number:";
    cin>>num;
    temp->data=num; // dereferencing the temp node to store the data and set the link to the address of next node to NULL
    temp->link=NULL;
    if (head_node ==NULL) // if this is the first node storing the address of temp in head node
    {
       head_node=temp;
    }
    else // else traversing the list till the end and establishing the new link
     {
       node* temp1=head_node;
       while(temp1->link !=NULL)
       {
         temp1=temp1->link;
       }
       temp1->link=temp;
    }

}
void linkedlist:: searchnode()
{
    int num,index=0;
    node* temp=head_node;
    cout<<"Enter the number to be searched";
    cin>>num;
    while(temp!=NULL)// traverses the linked list till the number to be searched is found
       {
        index++;
        if(temp->data==num)
            break;
        temp=temp->link;
        }

        if (temp==NULL)// if temp==NULL implies the element is not found
      {
         cout<<"Element not found \n";

      }
    else
        {
        cout<<"Element position is \n "<<index;//Printing the position of the element(one index)
        }
}
void linkedlist::deletenode()
{
    int num;
    node* temp=head_node;
    cout<<"Enter the number to be deleted:";
    cin>>num;
    while(temp!=NULL)// traverses the linked list till the number to be deleted is found
        {
        if(temp->data==num)
            break;
        temp=temp->link;
        }

        if (temp==NULL)// if temp==NULL the element is not found
      {
         cout<<"Element not found \n";
      }
       else
        {
        if(temp==head_node)// to delete the first element
        {
          head_node=temp->link;
          delete temp;
        }
        else// to delete element at any other position
        {
         node *temp1 = head_node;
         while (temp1->link != temp) {
            temp1 = temp1->link;
         }
         temp1->link = temp->link;
         delete temp;
      }
        }

}
void linkedlist::length()
{
    int n=0;
    node* temp1=head_node;
    while(temp1!=NULL)//loop to print elements, counter incremented in every iteration to calculate length
    {
      n++;
      cout<<"\n"<<temp1->data<<"\n|";
      temp1=temp1->link;
    }
    cout<<"\n The length of the linked list is\n :"<<n;
}

int main()
{
    linkedlist list1;
    int choice;
    while(1)
    {
        cout<<"\n1:Insert\n2:Delete\n3:Search\n4:Length\n5:Exit\n";
        cout<<"Enter Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            list1.insertnode();
            break;
        case 2:
            list1.deletenode();
            break;
        case 3:
            list1.searchnode();
            break;
        case 4:
            list1.length();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
