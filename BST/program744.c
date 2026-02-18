#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchlid;
    struct node *rchlid;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->lchlid = NULL;
    newn->rchlid = NULL;

    if(*first == NULL)     // If tree is empty
    {
        *first = newn;
    }
    else                  // If tree contains atleast one node
    {
        temp = *first;

        while(1)
        {
            if(no > temp->data)                 // If element is greter
            {
                if(temp->rchlid == NULL)
                {
                    temp->rchlid = newn;
                    break;
                }
                temp = temp->rchlid;
            }
            else if(no < temp->data)            // If element is smaller
            {
                if(temp->lchlid == NULL)
                {
                    temp->lchlid = newn;
                    break;
                }
                temp = temp->lchlid;

            }
            else if(no == temp->data)            // If element is identical
            {
                printf("Element is already present...\n");
                free(newn);
                break;
            }
        }
    }
}

// L     D      R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchlid);
        printf("%d\n",first->data);
        Inorder(first->rchlid);
    }
}

// D   L   R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n",first->data);
        Preorder(first->lchlid);
        Preorder(first->rchlid);
    }
}

// L  R  D

void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchlid);
        Postorder(first->rchlid);
        printf("%d\n",first->data);
    }
}
int main()
{
    PNODE head = NULL;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);

    printf("Inorder traversal\n");
    Inorder(head);

    printf("Preorder traversal\n");
    Preorder(head);

    printf("Postorder traversal\n");
    Postorder(head);

    return 0;
}


