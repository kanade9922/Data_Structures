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

int main()
{
    PNODE head = NULL;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);

    Inorder(head);

    return 0;
}


