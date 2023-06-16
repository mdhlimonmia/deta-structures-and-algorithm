#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node
{
    int data;
    struct node *next;
};

// Initialize head newnode and temp
struct node *head = 0;
struct node *newnode;
struct node *temp;

// Insert new data at beginning
void insert_beginning()
{
    // Allocated memory for new node
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter new data at beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

// Insert new data at end
void insert_end()
{
    // Allocated memory for new node
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter new data at end: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    // start from head
    temp = head;

    // find the last node;
    while (temp->next != 0)
    {
        temp = temp->next;
    }

    // linked new node at last node
    temp->next = newnode;
}

// Find linked list length
int linked_list_length()
{
    int i = 0;
    temp = head;
    while (temp->next != 0)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

// Insert after location
void insert_after_location()
{
    int position, i = 1;
    printf("Enter position: ");
    scanf("%d", &position);

    int length;
    length = linked_list_length();
    if (position > length)
    {
        printf("Invalid position\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for given position: ");
        scanf("%d", &newnode->data);

        temp = head;

        //Find given location
        while (i < position)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Print linked list
void print_linked_list()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main()
{

    insert_beginning();
    insert_end();
    insert_beginning();
    insert_end();
    insert_beginning();
    insert_end();
    insert_after_location();

    print_linked_list();
}