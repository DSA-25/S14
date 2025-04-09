
#include<stdio.h>
#include<malloc.h>

struct node {

    int data;
    struct node *left,*right;
};

struct node *create(struct node *root)
{
    struct node *p=NULL,*temp=NULL;
    int i,n;
    printf("\nHow many values");
    scanf("%d",&n);
    printf("\nEnter actual values");
    for ( i = 0; i < n; i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left=p->right=NULL;

        if (root==NULL)
        {
            root=p;
        }
        else
        {
            temp=root;
        }
        while (temp!=NULL)
        {
            if(p->data<temp->data)
            {
                if (temp->left==NULL)
                {
                    temp->left=p;
                    break;
                }
                else
                temp=temp->left;
            }
            else if (p->data > temp->data)
            {
                if (temp->right==NULL)
                {
                    temp->right=p;
                    break;
                }
                else
                temp=temp->right;                
            }   
        }
    }return root; 
} 

void inorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d\t",ptr->data);
        inorder(ptr->right);
    }
}

int isequaltree(struct node *root1,struct node *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    return (root1&&root2)&&(root1->data==root2->data)&&(isequaltree(root1->left,root2->left))&&(isequaltree(root1->right,root2->right));
}

void main()
{
    struct node *root1=NULL,*root2=NULL;
    struct node *create();
    void inorder();
    int isequaltree();

    int ch,q=0;

    do
    {
        printf("\n1.Create First Tree\n2.Create Second Tree\n3.Display Tree-1\n4.Display Tree-2\n5.Comparison of two BST\n6.Exit");
        printf("\nenter your choice");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:root1=create(root1);
            break;
        
        case 2:root2=create(root2);
            break;
        
        case 3:inorder(root1);
            break;
        case 4:inorder(root2);
            break;
        case 5:if (isequaltree(root1,root2))
                  printf("\nTrees are equal");
               else
                  printf("\nTrees are not equal");
            break;
        case 6:(q=1);
            break;
        }
    } while (q==0);
    
}