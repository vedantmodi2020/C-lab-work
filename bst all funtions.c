#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node*tree=NULL;
struct node* insert(struct node*,int);
void PreorderTraversal(struct node*);
void InorderTraversal(struct node*);
void PostorderTraversal(struct node*);
struct node *findlargest(struct node *);
struct node *findsmallest(struct node *);
struct node* deleteNode(struct node*, int val);
int totalnodes(struct node *);
int Externalnodes(struct node *);
int Internalnodes(struct node *);
struct node* deletetree(struct node *);
struct node* KSmallestUsingMorris(struct node *root, int k);
int main()
{
int choice,val,k;
struct node*ptr2;
do {
printf("\n");
printf("1.Insert Element\n");
printf("2.Preorder Traversal\n");
printf("3.Inorder Traversal\n");
printf("4.Postorder Traversal\n");
printf("5.Find smallest element\n");
printf("6.Find kth smallest element\n");
printf("7.Find the largest element\n");
printf("8.Delete an element\n");
printf("9.Count the total number of nodes\n");
printf("10.count the total number of External nodes\n");
printf("11.count the total number of internal nodes\n");
printf("12.Delete the tree\n");
printf("13.Exit\n");
printf("\n Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\nEnter the value of the node\n");
scanf("%d",&val);
tree = insert(tree,val);
break;
case 2:
printf("The elements of the tree are\n");
PreorderTraversal(tree);
break;
case 3:
printf("The elements of the tree are\n");
InorderTraversal(tree);
break;
case 4:
printf("The elements of the tree are\n");
PostorderTraversal(tree);
break;
case 5:
ptr2=findsmallest(tree);
printf("\n The smallest element is %d",ptr2->data);
break;
case 6:
printf("\n Enter the value of k");
scanf("%d",&k);
printf("\n The %d smallest element is %d",k,KSmallestUsingMorris(tree,k));
break;
case 7:
ptr2=findlargest(tree);
printf("\n The largest element is %d",ptr2->data);
break;
case 8:
printf("\n Enter the element to be deleted");
scanf("%d",&val);
deleteNode(tree,val);
break;
case 9:
printf("\n The total number of nodes are %d",totalnodes(tree));
break;
case 10:
printf("\nThe total number of External nodes are %d",Externalnodes(tree));
break;
case 11:
printf("\n The total number of Internal nodes are %d",Internalnodes(tree));
break;
case 12:
deletetree(tree);
break;
case 13:
break;
}
}while (choice!=13);
return 0;
}
struct node* insert(struct node*tree,int val)
{
struct node *ptr,*temp1,*temp2;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=val;
ptr->left=NULL;
ptr->right=NULL;
if (tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
temp1=NULL;
temp2=tree;
while (temp2!=NULL)
{
temp1=temp2;
if (val<temp2->data)
temp2=temp2->left;
else
temp2 =temp2->right;
}
if (val<temp1->data)
temp1->left=ptr;
else
temp1->right=ptr;
}
return tree;
}
void PreorderTraversal(struct node*tree)
{
if (tree!=NULL)
{
printf("%d\t",tree->data);
PreorderTraversal(tree->left);
PreorderTraversal(tree->right);
}
}
void InorderTraversal(struct node*tree)
{
if (tree!=NULL)
{
InorderTraversal(tree->left);
printf("%d\t", tree->data);
InorderTraversal(tree->right);
}
}
void PostorderTraversal(struct node*tree)
{
if (tree!=NULL)
{
PostorderTraversal(tree->left);
InorderTraversal(tree->right);
printf("%d\t", tree->data);
}
}
struct node *findlargest(struct node *tree)
{
if ((tree==NULL)|| (tree->right==NULL))
return tree;
else
return findlargest(tree->right);
}
struct node *findsmallest(struct node *tree)
{
if ((tree==NULL)|| (tree->left==NULL))
return tree;
else
return findlargest(tree->left);
}
struct node* deleteNode(struct node* tree, int val)
{
if (tree == NULL)
{
return tree;
}
if (val < tree->data)
{
tree->left = deleteNode(tree->left, val);
}
else if (val > tree->data)
{
tree->right = deleteNode(tree->right, val);
}
else
{
if (tree->left == NULL)
{
struct node* temp = tree->right;
free(tree);
return temp;
}
else if (tree->right == NULL)
{
struct node* temp = tree->left;
free(tree);
return temp;
}
struct node* temp = findsmallest(tree->right);
tree->data = temp->data;
tree->right = deleteNode(tree->right, temp->data);
}
return tree;
}
int totalnodes(struct node *tree)
{
if (tree==NULL)
{
return 0;
}
else
{
return(totalnodes(tree->left)+totalnodes(tree->right)+1);
}
}
int Externalnodes(struct node *tree)
{
if (tree==NULL)
{
return 0;
}
else if ((tree->left=NULL) && (tree->right=NULL))
{
return 1;
}
else
{
return(totalnodes(tree->left)+totalnodes(tree->right));
}
}
int Internalnodes(struct node *tree)
{
if (tree==NULL||((tree->left=NULL) && (tree->right=NULL)))
{
return 0;
}
else
{
return(totalnodes(tree->left)+totalnodes(tree->right)+1);
}
}
struct node*deletetree(struct node *tree)
{
if (tree!=NULL)
{
deletetree(tree->left);
deletetree(tree->right);
free(tree);
}
}
struct node* KSmallestUsingMorris(struct node *root, int k)
{
int count = 0;
int ksmall;
struct node *curr = tree;
while (curr != NULL)
{
if (curr->left == NULL)
{
count++;
if (count==k)
ksmall = curr->data;
curr = curr->right;
}
else
{
struct node *pre = curr->left;
while (pre->right != NULL && pre->right != curr)
pre = pre->right;
if (pre->right==NULL)
{
pre->right = curr;
curr = curr->left;
}
else
{
pre->right = NULL;
count++;
if (count==k)
ksmall = curr->data;
curr = curr->right;
}
}
}
return ksmall;
}
