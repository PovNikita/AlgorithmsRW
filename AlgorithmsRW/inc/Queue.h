#pragma once
#include <iostream>

using namespace std;

const int Size_of_Queue = 110; // The size of a Queue

struct Queue {
    float M[Size_of_Queue] = { 0 };    //This massive holds elements of the queue
    int h = 0;          //This element saves a place of the first element of the queue
    int t = 0;          //This element saves a place after the last added element of the queue
    int quantity = 0;   //The number of added elements in the queue
};

Queue* CreateQueue();   //This function creates a Queue
void EnQueue(Queue* Q, float i);   //This function adds an element to the queue
bool IsQueueEmpty(Queue* Q);    //This function returns 1, if the queue is empty or returns if the queue has some elements
float DeQueue(Queue* Q);       //This function returns an element from the queue
void ShowQueue(Queue* Q);       //This function puts on a screen all elements of the queue
void ShowAllQueue(Queue* Q);    //This function puts on a screen all elements of the queue including removed elements

class Queue_cl
{
    Queue* Q = NULL;

public:
    Queue_cl();             //This constructor creates a Queue
    void EnQueue(float i);  //This method adds an element to the queue
    bool IsQueueEmpty();    //This method returns 1, if the queue is empty or returns if the queue has some elements
    float DeQueue();        //This method returns an element from the queue
    void ShowQueue();       //This method puts on a screen all elements of the queue
    void ShowAllQueue();    //This method puts on a screen all elements of the queue including removed elements
    ~Queue_cl();            //This destructor frees memory what was used for the queue
};