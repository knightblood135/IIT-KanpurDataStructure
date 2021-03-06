#include <stdio.h>
#include <stdlib.h>
//Doubly Linked List
void create();
void show();

struct student
{
    int rollNo;
    struct student *prev;
    struct student *next;
};

struct student *start = NULL, *node, *temp;

int main(void)
{
    create();
    show();
    return 0;
}

void create()
{
    char choice;
    do
    {
        node = (struct student *)malloc(sizeof(struct student));
        printf("\nEnter the Roll No: ");
        scanf("%d", &node->rollNo);
        node->next = NULL;
        node->prev = NULL;
        if (start == NULL)
        {
            temp = node;
            start = node;
        }
        else
        {
            temp->next = node;
            node->prev = temp;
            temp = temp->next; // or temp = node; => So, that node and temp point the same location.
        }
        printf("\nDo You Want To Continue Y or N: ");
        fflush(stdin); //Use before scanf() => clear garbage value
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
    //Making link with first and last node and vice-versa
    node->next = start;
    start->prev = node; //start->prev = temp;
}

void show()
{
    int n;
    temp = start;
    while (temp != NULL)
    {
        printf("\nRoll No = %d\n", temp->rollNo);
        printf("\nPress 2 for Next Element.");
        printf("\nPress 1 for Previous Element.");
        printf("\nPress 0 to Exit.");
        printf("\nEnter Your Choice: ");
        scanf("%d", &n);
        if (n == 1)
        {
            temp = temp->prev;
        }
        else if (n == 2)
        {
            temp = temp->next;
        }
        else if (n == 0)
        {
            printf("Exiting The Program...\n");
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
    printf("\n\n");
}