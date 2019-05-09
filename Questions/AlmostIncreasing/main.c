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
    NodeLinkedList->length = NodesToBeCreated  - 1;
    
    return NodeLinkedList;
}


bool checkingNodes(node Nodetoskip)
{
    return true;
}


bool IterateThroughLinkedList(node IterList)
{
    bool res = true;
    int LengthOfNodelist = IterList.length;
    node tempIterList = IterList;
    for (int countz = 0; countz < LengthOfNodelist ; countz++)
    {        
            if (IterList.next != NULL)
            {
                node value1IterList = IterList;
                for(int i = 0; i < LengthOfNodelist; i++)
                {
                    if(i == countz)
                    {
                        value1IterList = * value1IterList.next;
                    }
                    if(value1IterList.next != NULL)
                    {
                        int value1 = value1IterList.Number;
                        printf("What is value1 %d\n",value1);
                        value1IterList = * value1IterList.next; // this is the problem it is our whole way of moving through linked list
                    }
                    else
                    {
                        printf("---------FINISHED---------");
                        break;
                    }
                }
                tempIterList = * tempIterList.next;
            }
            else
            {
                printf("We are at the end\n");
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
