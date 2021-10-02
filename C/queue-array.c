#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//  this is a basic implementation of a queue using arrays in C
//  this implementation does not handle queue limits or removal of data very well
//  and should only be used as a guide for learning the data structure
//  in real world implementations, a linked list would likely be better due to
//  potentially less memory usage and for allowing a wider range of queue sizes dynamically
//  as a non-circular array is used here, once 50 values have been used, even once dequeued, the queue is unusable

//  define a limit for the queue size
#define QUEUE_LIMIT 50

//  declare an array of size LIMIT
//  for demo purposes, the queue and related variables have been declared as global
int queue[QUEUE_LIMIT];
int head, tail;


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

    //  initialise the head and tail values as -1
    head = tail = -1;
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
    int element;
    //  check that the queue is not full
    if (tail == QUEUE_LIMIT - 1)
        printf("Queue Overflow (queue is full)\n");
    else {
        //  set head position to 0 as an item is now in the queue
        if (head == -1) {
            head = 0;
        }
        //  prompt for a value to enqueue
        printf("Enter a value to add to the queue: ");
        scanf("%d", &element);
        //  increment the index of tail
        tail++;
        //  insert the item at the index of tail (this will always be the end of the queue)
        queue[tail] = element;
    }
}

//  function to remove the item at the front of the queue
void dequeue() {
    //  check if the queue is valid (head will not be -1 and head will be less than or equal to tail)
    if (head == -1 || head > tail) {
        //  output that the queue is empty
        printf("Queue Underflow (queue is empty)\n");
    } else {
        //  output the value that has been dequeued
        printf("%d has been dequeued\n", queue[head]);
        //  increment the head index to be the next item in the queue
        head++;
    }
}

//  function that will display the contents of the queue
void display() {
    int i;

    //  check that there is a value in the queue
    if (head == -1) {
        //  output that the queue is empty
        printf("Queue Underflow (queue is empty)\n");
    } else {
        //  loop through the array being used to simulate the queue, starting at head
        //  output values in sequence to illustrate the values being queued one behind another
        printf("The elements of the queue are:\n");
        //  loop to traverse the array from head to tail (for the length that holds queued values)
        for (i = head; i <= tail; i++)
            printf("%d\n", queue[i]);
    }
}