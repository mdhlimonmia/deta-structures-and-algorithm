// Linked list implementation in C
#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node
{
    int data;
    struct node *next;
};

// Initialize head newnode and temp
struct node *head = 0;
struct node *newnode;
struct node *temp;

// Insert new data in a node
void insert_data()
{
    // Allocated memory for new node
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("enter a value: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    //for first node
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        //link new node with previous node
        temp->next = newnode;

        //temp to be last node 
        temp = newnode;
    }
}

//Print Linked list
void print_linked_list()
{   
    printf("value of Linked List: \n");
    //start from head so....
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);

        temp = temp->next;
    }
}

int main()
{
    int choice;
    while (choice)
    {
        insert_data();

        printf("Do you want to continue? 1 or 0: ");
        scanf("%d", &choice);
    }

    print_linked_list();

    return 0;
}