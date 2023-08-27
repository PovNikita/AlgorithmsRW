#include "Queue.h"

Queue* CreateQueue()
{
    Queue* temp;
    temp = (Queue*)malloc(sizeof(Queue));
    if (temp == NULL)
    {
        cout << "NULL pointer was gotten. The program will be closed" << endl;
        exit(EXIT_FAILURE);
    }
    temp->h = 0;
    temp->t = 0;
    temp->quantity = 0;
    for (int i = 0; i < Size_of_Queue; i++)
        temp->M[i] = 0;
    return temp;
}

void EnQueue(Queue* Q, float i)
{
    if (Q->quantity == Size_of_Queue)
    {
        printf("It's the full queue. Increase the 'Size_of_Queue'\n");
        return;
    }
    if ((Q->t) == Size_of_Queue)
        Q->t = 0;
    int a = Q->t;
    Q->M[Q->t] = i;
    Q->t++;
    Q->quantity++;
}

bool IsQueueEmpty(Queue* Q)
{
    if (Q->quantity == 0)
        return true;
    return false;
}

float DeQueue(Queue* Q)
{
    float data = 0.0f;
    if (IsQueueEmpty(Q))
    {
        printf("It's the empty queue\n");
        return 0.0f;
    }
    if ((Q->h) == Size_of_Queue)
        Q->h = 0;
    data = Q->M[Q->h];
    Q->M[Q->h] = 0.0f;
    Q->h++;
    Q->quantity = Q->quantity - 1;
    return data;
}

void ShowQueue(Queue* Q)
{
    if (IsQueueEmpty(Q))
    {
        printf("It's the empty queue\n");
        return;
    }
    cout << "Queue: ";
    int showed = 0;
    for (int i = Q->h; showed < Q->quantity; i++)
    {
        if (i == Size_of_Queue)
            i = 0;
        cout << (Q->M[i]) << "; ";
        showed++;
    }
    cout << endl;
}

void ShowAllQueue(Queue* Q)
{
    cout << "Queue: ";
    int showed = 0;
    for (int i = 0; i < Size_of_Queue; i++)
    {
        cout << (Q->M[i]) << "; ";
    }
    cout << endl;
}

//****************************************************QUEUE CLASS************************************************/

Queue_cl::Queue_cl()
{
    Q = (Queue*)malloc(sizeof(Queue));
    if (Q == NULL)
    {
        cout << "NULL pointer was gotten. I'm closing the program" << endl;
        exit(EXIT_FAILURE);
    }
    Q->h = 0;
    Q->t = 0;
    Q->quantity = 0;
    for (int i = 0; i < Size_of_Queue; i++)
        Q->M[i] = 0;
}

void Queue_cl::EnQueue(float i)
{
    if (Q->quantity == Size_of_Queue)
    {
        printf("It's the full queue. Increase the 'Size_of_Queue'\n");
        return;
    }
    if ((Q->t) == Size_of_Queue)
        Q->t = 0;
    int a = Q->t;
    Q->M[Q->t] = i;
    Q->t++;
    Q->quantity++;
}

bool Queue_cl::IsQueueEmpty()
{
    if (Q->quantity == 0)
        return true;
    return false;
}

float Queue_cl::DeQueue()
{
    float data = 0;
    if (IsQueueEmpty())
    {
        printf("It's the empty queue\n");
        return 0;
    }
    if ((Q->h) == Size_of_Queue)
        Q->h = 0;
    data = Q->M[Q->h];
    Q->M[Q->h] = 0;
    Q->h++;
    Q->quantity = Q->quantity - 1;
    return data;
}

void Queue_cl::ShowQueue()
{
    if (IsQueueEmpty())
    {
        printf("It's the empty queue\n");
        return;
    }
    cout << "Queue: ";
    int showed = 0;
    for (int i = Q->h; showed < Q->quantity; i++)
    {
        if (i == Size_of_Queue)
            i = 0;
        cout << (Q->M[i]) << "; ";
        showed++;
    }
    cout << endl;
}

void Queue_cl::ShowAllQueue()
{
    cout << "Queue: ";
    int showed = 0;
    for (int i = 0; i < Size_of_Queue; i++)
    {
        cout << (Q->M[i]) << "; ";
    }
    cout << endl;
}

Queue_cl::~Queue_cl()
{
    free(Q);
}