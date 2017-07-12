#include<stdio.h>
#include<conio.h>


typedef struct node_tag
{
    int data;
    int colnum;
    struct node_tag* next;
}node_type;
typedef struct at_node_tag
{
    int rownum;
    node_type* dptr;
    struct at_node_tag* next;
}at_node;



node_type* InitialiseAT(at_node** attop);
void PrintAT(at_node* attop);

node_type* InitialiseAT(at_node** attop)
{
    at_node *atptr, *atnptr;
    node_type* ptr, *nptr, *top;
    int r,c,rp,d;
    int cont=1,atstart=1;
    printf("Enter 'ROW' and 'COLOUMN' numbers");
    scanf("%d%d",&r, &c);
    printf("Enter the data for(%d,%d)",r,c);
    scanf("%d",&d);
    while(cont==1)
    {
        nptr=(node_type*)malloc(sizeof(node_type));
        nptr->data=d;
        nptr->colnum=c;
        nptr->next=NULL;
        if(atstart==1||rp!=r)
        {
            atnptr=(at_node*)malloc(sizeof(at_node));
            atnptr->dptr=nptr;
            atnptr->rownum=r;
            atnptr->next=NULL;
            if(atstart==1)
            {
                *attop=atnptr;
                top=ptr=nptr;
                atstart=0;
            }
            else
            {
                atptr->next=atnptr;
                ptr->next=nptr;
                ptr=nptr;
            }
            atptr=atnptr;
        }
        else
        {
            ptr->next=nptr;
            ptr=nptr;
        }
        printf("\nDo you wish to continue?\n0-NO\n1-YES\n");
        scanf("%d",&cont);
        if(cont==1)
        {
            rp=r;
            printf("Enter 'ROW' and 'COLOUMN' numbers");
            scanf("%d%d",&r, &c);
            printf("Enter the data for(%d,%d)",r,c);
            scanf("%d",&d);
        }
    }
    return top;
}

void PrintAT(at_node* attop)
{
    at_node* atptr=attop;
    node_type* ptr;
    int f=0;

    if(attop==NULL)
    {
        printf("\nNo AT present");
    }
    else
    {
        atptr=attop;
        ptr=atptr->dptr;
        while(atptr!=NULL)
        {

            if(atptr->next==NULL)
            {
                while(ptr!=NULL)
                {
                    printf("(%d,%d):",atptr->rownum,ptr->colnum);
                    printf(" %d,  ",ptr->data);
                    ptr=ptr->next;
                }
            }
            else
            {
                while((atptr->next)->dptr!=ptr)
                {
                    printf("(%d,%d):",atptr->rownum,ptr->colnum);
                    printf(" %d,  ",ptr->data);
                    ptr=ptr->next;

                }
            }
            printf("\n");
            atptr=atptr->next;
        }

    }
}

void PrintLL(node_type* top)
{
    node_type* ptr;
    for(ptr=top;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d,",ptr->data);
    }
}

void main()
{
    at_node* attop;
    node_type* top;
    top=InitialiseAT(&attop);
    PrintAT(attop);
    printf("\n\nPrinting LL\n\n");
    PrintLL(top);
}
