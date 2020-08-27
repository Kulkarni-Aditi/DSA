#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node* left;
    int data;
    struct node* right;
};
struct node* createnode(int data);//function to create a new node
void Inorder(struct node *root);
void mirrortree(struct node*);
int main()
{
    struct node* root=NULL;//pointer to root node
    root = createnode(1);
    root->left= createnode(2);
    root->right =createnode(3);
    root->left->left=createnode(4);
    root->left->right = createnode(5);
    printf("Printing Tree Inorder:\n");
    Inorder(root);
    printf("\nPrinting Mirror Tree Inorder:\n");
    mirrortree(root);
    Inorder(root);
    return 0;
}
struct node* createnode(int data)

{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void Inorder(struct node *temp) {
	if(temp == NULL) return;
    Inorder(temp->left);
	printf("%d ",temp->data);
	Inorder(temp->right);
}
void mirrortree(struct node *temp) {
    struct node* temp1;
	if(temp == NULL) return;
    mirrortree(temp->left);
    mirrortree(temp->right);
    temp1=temp->left;
    temp->left=temp->right;
    temp->right=temp1;
}
