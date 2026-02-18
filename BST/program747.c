#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool Search(PNODE first, int no)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(no > first->data)
        {
            first = first->rchlid;
        }
        else if(no < first->data)
        {
            first = first->lchlid;
        }
        else if(no == first->data)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

int Count(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->lchlid);
        Count(first->rchlid);
    }
    return iCount;
}

int CountParentNodes(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if((first->lchlid != NULL || first->rchlid != NULL))
        {
            iCount++;
        }
        CountParentNodes(first->lchlid);
        CountParentNodes(first->rchlid);
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;
    int iRet = 0;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);
    Insert(&head,67);
    Insert(&head,40);
    Insert(&head,10);
    Insert(&head,13);
    Insert(&head,38);
    
    printf("Inorder traversal\n");
    Inorder(head);

    bRet = Search(head,47);

    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present\n");
    }

    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);

    iRet = CountParentNodes(head);
    printf("Number of parent nodes are : %d\n",iRet);

    return 0;
}


