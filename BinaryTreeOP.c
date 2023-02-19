#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct tree 
{
    int data;
    struct tree *left;
    struct tree *right;
} *newnode , *root=NULL, *temp;

void inOrder(struct tree *ptr)
{
    if( ptr == NULL )
            return ;
    inOrder(ptr->left);
    printf("%d",ptr->data);
    inOrder(ptr->right);
}

void preOrder(struct tree*ptr)
{
    if( ptr == NULL )
            return ;
    printf("%d",ptr->data);
    preOrder(ptr->right);
    preOrder(ptr->left);
}

void postOrder(struct tree *ptr)
{
    if( ptr == NULL )
            return ;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d",ptr->data);
}

struct tree *create()
{
    newnode = (struct tree*)malloc(sizeof(struct tree *));
    printf("Enter Data of the Node --->(0 if no data)");
    int d;
    scanf("%d",&d);
    if (d == 0)
        return NULL;
    newnode -> data = d;
    printf("Left Child of %d::  ",d);
    newnode -> left = create();
    printf("Right Child of %d::  ",d);
    newnode -> right = create();
    return newnode;
}

struct tree *search(struct tree *ptr, int d)
{
    if(ptr == NULL)
        return NULL;
    if (ptr -> data == d)
        return ptr;
    if(search(ptr->left,d) != NULL)
        return search(ptr->left,NULL);
    if(search(ptr->right,d) != NULL)
        return(search(ptr->right,NULL));
    return NULL;
}

struct tree *node(int item)
{
    newnode = (struct tree*)malloc(sizeof(struct tree*));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void insert()
{
    int op,p;
    printf("Enter Data of Parent Node: ");
    scanf("%d",&p);
    temp = search(root,p);
    if (temp == NULL)
    {
        printf("Unsuccessfull Search");
        return;
    }
    if (temp->left == NULL || temp->right == NULL)
    {
        int d;
        printf("---Enter Data to Insert----");
        scanf("%d",&d);
        printf("---Insert at Left or Right(1/2)?---");
        scanf("%d",&op);
        if (op == 1)
        {
            if (temp->left == NULL)
            {
                newnode = node(d);
                temp->left = newnode;
            }
            else
                printf("\tInvalid Insertion at Left Node\n");
        }
        else if (op == 2)
        {
            if(temp->right == NULL)
            {
                newnode = node(d);
                temp->right = newnode;
            }
            else
                printf("Invalid Insertion at Right Node\n");
        }
        else
            printf("\tInvalid Choice\n");
    }
    else
        printf("Insertion not at Leaf Node\n");
}


struct tree *parentfind(struct tree*ptr,int d)
{
    if(ptr == NULL)
        return NULL;
    if (ptr->left != NULL)
        if(ptr->left->data ==d)
            return ptr;
    if(ptr->right != NULL)
        if(ptr->right->data == d)
            return ptr;
    if(parentfind(ptr->left,d)!= NULL)
        return parentfind(ptr->left,d);
    if(parentfind(ptr->right,d)!= NULL)
        return parentfind(ptr->right,d);
    return NULL;
}




void delete()
{
    struct tree *parent;
    int d;
    printf("Enter node to delete:");
    scanf("%d",&d);
    temp = root;
    if(temp == NULL)
        printf("\tEmpty Tree\n");
    parent = parentfind(root,d);
    if(parent != NULL)
    {
        struct tree *ptr1 = parent -> left;
        struct tree *ptr2 = parent -> right;
        if (ptr1->data = d)
        {
            if (ptr1->left == NULL && ptr1->right == NULL)
            {
                free(ptr1);
                parent->left = NULL;
                printf("\tSuccessfull Deletion\n");
            }
            else
                printf("\tNode not a Leaf Node");
        }
        else if (ptr2->data = d)
        {
            if (ptr2->left == NULL && ptr2->right == NULL)
            {
                free(ptr2);
                parent->right = NULL;
                printf("\tSuccessfull Deletion\n");
            }
            else
                printf("\tNode not a Leaf Node");
        }
    }
    else
        printf("Invalid Item");
}

void main()
{
    int o;
    while(1)
    {
        printf("\n----Binary Tree Operations----");
        printf("\n1.Insert");
        printf("\n2.Create");
        printf("\n3.Delete");
        printf("\n4.Inorder");
        printf("\n5.Preorder");
        printf("\n6.Postorder");
        printf("\n7.Exit");
        printf("\n------------------------------\n");

        printf("Enter a choice");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                    if (root == NULL)
                    {
                        int data;
                        printf("\tEnter Root Data:");
                        scanf("%d",&data);
                        root = node(data);
                    }
                    else
                        insert();
                    break;
            case 2:
                    create();
                    break;
            case 3:
                    delete();
                    break;
            case 4:
                    inOrder(root);
                    break;
            case 5:
                    preOrder(root);
                    break;
            case 6:
                    postOrder(root);
                    break;
            case 7:
                    printf("\tExitng Operations....");
                    return 0;
                    break;
            default:
                    printf("\n---Invalid Option---\n");
                    break;
        }
    }
}
