#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//  define a structure for each node in the linked list
struct node {
    int nodeData;
    struct node *nextNode;
} *head, *tail;

//  function prototypes

//  function to add an item to the end of the queue
void enqueue();

//  function to remove the item at the front of the queue
void dequeue();

//  function to display the values in the queue in order
void display();

//  main will be used to demonstrate the implemented functions
int main() {
    int mode;

    printf("Queue simulation using an array\n\r");

    //  initialise the head and tail values as null
    head = tail = NULL;
    //  loop the following while choice is not 4 (exit)
    do {
        //  output menu options
        printf("1 - Add to queue\n"
               "2 - Remove from queue\n"
               "3 - Display queue\n"
               "4 - Exit\n");
        printf("Enter option: ");
        //  read in selected option
        scanf("%d", &mode);
        //  switch case for the correct functionality based on the option
        switch (mode) {
            case 1:
                // add a value at the end of the list
                enqueue();
                break;
            case 2:
                //  remove the value from the front of the list
                dequeue();
                break;
            case 3:
                //  display the queue
                display();
                break;
            case 4:
                //  close the application
                exit(0);
            default:
                printf("Choice invalid, please try again.\n");
                break;
        }
    } while (mode != 4);
    return 0;
}

//  function to add an item to the end of the queue
void enqueue() {
    //  declare a node and allocate memory to it
    struct node *tempNode = (struct node *) malloc(sizeof(struct node));

    //  prompt for a value to push
    printf("Enter a value to enqueue: ");
    scanf("%d", &tempNode->nodeData);
    //  set the data for the current node and point it to null as there is no following node
    tempNode->nextNode = NULL;
    //  if the tail is null, this will be the first item in the queue so point both head and tail to the node
    if (tail == NULL) {
        head = tail = tempNode;
    } else {
        //  point the next node of tail to the new node
        tail->nextNode = tempNode;
        //  update tail to be the newly created node as this will now be at the end of the queue
        tail = tempNode;
    }
}

//  function to remove the item at the front of the queue
void dequeue() {
    struct node *tempNode;
    tempNode = head;

    //  check if the queue is valid (head will not be null if a value is in the queue)
    if (head == NULL) {
        //  output that the queue is empty
        printf("Queue Underflow (queue is empty)\n");
        //  set head and tail to null
        head = tail = NULL;
    } else {
        //  output the value that has been dequeued
        printf("%d has been dequeued\n", head->nodeData);
        //  update the head to point to the next node in the list
        head = head->nextNode;
        //  deallocate the memory that the head node was using
        free(tempNode);
    }
}

//  function that will display the contents of the queue
void display() {
    struct node *tempNode;
    tempNode = head;

    //  check that there is a value in the queue
    if (head == NULL) {
        //  output that the queue is empty
        printf("Queue Underflow (queue is empty)\n");
    } else {
        //  loop through the linked list being used to simulate the queue
        //  output values in sequence to illustrate the values being queued one behind another
        printf("The following values are contained within the stack:\n");
        //  loop while tempNode is true (will loop until tempNode is null)
        while (tempNode) {
            //  output the data of tempNode
            printf("%d\n", tempNode->nodeData);
            //  set tempNode to be equal to the next node in the list
            tempNode = tempNode->nextNode;
        }
    }
}