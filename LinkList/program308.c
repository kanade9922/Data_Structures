#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    NODE obj;
    PNODE ptr1 = NULL;
    PPNODE ptr2 = NULL;

    return 0;
}