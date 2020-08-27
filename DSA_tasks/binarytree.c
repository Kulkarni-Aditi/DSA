#include<stdio.h>
#include<stdlib.h>
// program to create a binary search tree
struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createnode(int data);//function to create a new node
struct node* insertnode(struct node*,int data);// function to insert a node
struct node* deletenode(struct node*,int data);//function to delete a node
struct node* minimum(struct node*root);
int treesize(struct node* temp);//size of tree
int sumofnodes(struct node* temp);//sum of nodes in tree

int main()
{
    struct node* root=NULL;//pointer to root node
    int choice,data,totalnodes,sum;
    while(1)
    {
        printf("\n1:Insert\n2:Delete node\n3:Compute Size\n4:Sum of Nodes:\n5:Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            printf("Enter number: ");
            scanf("%d",&data);
            root=insertnode(root,data);
            break;

        case 2:
            printf("Enter number to be deleted: ");
            scanf("%d",&data);
            root=deletenode(root,data);
            break;
        case 3:
            totalnodes=treesize(root) ;
            printf("The tree has %d nodes \n",totalnodes);

            break;
        case 4:
            sum=sumofnodes(root) ;
            printf("The sum of all nodes is %d \n",sum);

            break;
        case 5:
            exit(0);

        }
    }
    return 0;
}
struct node* createnode(int data)

{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data; // dereferencing the temp node to store the data
    newnode->left=NULL;
    newnode->right=NULL;// set the link to the address of left and right child to NULL
    return newnode;
}
struct node* insertnode(struct node* temp, int data)
{
    if (temp==NULL)
    {
       temp=createnode(data);
    }
    else if(data<=temp->data)// if data to be inserted is less than the data in parent node, insert in left subtree
     {
    temp->left=insertnode(temp->left,data);
     }
    else
    {
    temp->right=insertnode(temp->right,data);//if data to be inserted is greater than the data in parent node, insert in right subtree
    }
return temp;
}
struct node* deletenode(struct node *root, int data) {
    // search for node to be deleted recursively in left and right subtree
	if(root == NULL) return root;
	else if(data < root->data) root->left = deletenode(root->left,data);
	else if (data > root->data) root->right = deletenode(root->right,data);
	//node is found then
	else {
		// Node to be deleted is a leaf node
		if(root->left == NULL && root->right == NULL) {
			 free(root);
			root = NULL;
		}
		//Node to be deleted has one child
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			free (temp);
		}
		// Node to be deleted has 2 children
		else {
			struct node *temp = minimum(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right,temp->data);
		}
	}
	return root;
}
struct node* minimum(struct node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
};
int treesize(struct node* temp)
{
  if (temp==NULL)
    return 0;
  else
    return(treesize(temp->left) + 1 + treesize(temp->right));
}

int sumofnodes(struct node* temp)
{
    if (temp == NULL)
        return 0;
    return (temp->data + sumofnodes(temp->left) + sumofnodes(temp->right));
}

