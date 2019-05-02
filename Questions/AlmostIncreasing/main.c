#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int Number;
    struct node *next;
    int length;
} node;

int ChartoString(const char *test[], int index)
{
    int testValue = 0;
    int addingValues = 0;
    int lenOfString = 0;
    int multiplyer = 1;
    int j = 0;
    char *str;
    str = (char *)malloc(index * sizeof(char));

    for (; test[index][j] != '\0'; j++)
    {
        str[j] = test[index][j];
        testValue = str[j] - '0';
    }
    j--;
    for (; j >= 0; j--)
    {
        int newtestValue = str[j] - '0';
        int NewValue = newtestValue * multiplyer;
        addingValues += NewValue;
        multiplyer = multiplyer * 10;
    }
    return addingValues;
}

node *createLinkeList(int NodesToBeCreated, const char *test[])
{
    int i = 0;
    node *NodeLinkedList = NULL;
    node *Buffer = NULL;
    node *FindNextNull = NULL;
    int index = 1;
    if (NodesToBeCreated >= 1)
    {
        for (int i = 0; i < NodesToBeCreated; i++)
        {
            for (; index < NodesToBeCreated; index++)
            {
                Buffer = (node *)malloc(sizeof(node));
                int value = ChartoString(test, index);
                Buffer->Number = value;
                Buffer->next = NULL;

                if (NodeLinkedList == NULL)
                {
                    NodeLinkedList = Buffer;
                }
                else
                {
                    FindNextNull = NodeLinkedList;
                    while (FindNextNull->next != NULL)
                    {
                        FindNextNull = FindNextNull->next;
                    }
                    FindNextNull->next = Buffer;
                }
            }
        }
    }
    else
    {
        printf("No Args been Passed");
    }
    NodeLinkedList->length = NodesToBeCreated;
    
    return NodeLinkedList;
}

bool IterateThroughLinkedList(node IterList)
{
    bool res = true;
    int Value1, Value2;

    for (; IterList.next != NULL; IterList = *IterList.next)
    {
        if (IterList.next != NULL)
        {
            Value1 = IterList.Number;
            Value2 = IterList.next->Number;
            printf("What is value 1 = %d \n", Value1);
            printf("What is value 2 = %d \n", Value2);

            if (Value1 <= Value2)
            {
                printf("Correct\n");
            }
            else
            {
                printf("FALSE\n");
                printf("No ascending order\n");
                res = false;
                break;
            }
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    node *LinkedList1 = NULL;

    if (argc > 1)
    {
        LinkedList1 = createLinkeList(argc, argv);
        IterateThroughLinkedList(*LinkedList1);
    }
    else
    {
        printf("No arg has been added in");
    }
}
