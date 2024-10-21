struct node
{
  int info;
  struct node *right;
  struct node *left;
};

struct node *create(struct node *head)
{
    struct node* temp=NULL, *p=NULL;
    int i,n;

    temp=head;

    printf("Enter the No of Values");
    scanf("%d",&n);

    printf("Enter Actual Values:");

    for(i=0;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->info);
        p->left=p->right=NULL;

        temp->right=p;
        p->left=temp;
        temp=p;
    }
  return head;
}

void display(struct node *head)
{
    struct node *temp1=NULL,*temp2=NULL;
    temp1=head->right;

    do
    {
        printf("%d\t",temp1->info);
        temp2=temp1;
        temp1=temp1->right;
    } while (temp1!=NULL);
    do
    {
        printf("%d\t",temp2->info);
        temp2=temp2->left;
    } while (temp2!=head);
}

struct node *deletee(struct node *head)
{
    struct node *temp=NULL,*temp1=NULL,*p=NULL;
    int pos,i;

    printf("Enter Position");
    scanf("%d",&pos);

    for (temp=head,i=1;i<pos&&temp->right!=NULL;i++)
    {
        temp=temp->right;
    }
    if (temp->right!=NULL)
    {
        p=temp->right;
        printf("\n The deleted element is:%d",p->info);

        if(p->right!=NULL)
        {
            temp1=p->right;
            temp->right=temp1;
            temp->left=temp;
        }
        else
        {
            temp->right=NULL;
        }
        free(p);
    }
    else
    {
        printf("\n Position Out of Order");
    }
    return(head);
}


int count(struct node *head)
{
    struct node*temp;
    int c=0,p;
    temp=head->right;

    do
    {
        c++;
        temp=temp->right;
    } while (temp!=NULL);   
    return c;
}