#include "List.h"

using namespace std;

Node* CreateList()
{
    Node* L;
    L = NULL;
    return L;
}

Node* CreateNode()
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    cout << "Temp: " << temp << endl;
    return temp;
}

Node* InsertListNode(Node** L, Node* p, Node& n)
{
    if (p == NULL)
    {
        cout << "List: " << (*L) << endl;
        n.next = (*L);
        (*L) = &n;
        return (*L);
    }
    else
    {
        if (p->next == NULL)
        {
            p->next = &n;
            n.next = NULL;
            return (&n);
        }
        else if ((p->next) != NULL)
        {
            n.next = p->next;
            p->next = &n;
            return (&n);
        }
        else
        {
            return (NULL);
        }
    }
}

Node* InsertInList(Node** L, Node* p, float data)
{
    Node* temp;
    if (p == NULL)
    {
        temp = CreateNode();
        temp->data = data;
        return InsertListNode(L, p, (*temp));
    }
    else
    {
        temp = CreateNode();
        temp->data = data;
        return InsertListNode(L, p, (*temp));

    }
}

float RemoveListNode(Node** L, Node* p, Node& r)
{
    float temp = 0.0f;
    if ((r.next == NULL) && ((&r) != NULL))
    {
        p->next = NULL;
        temp = r.data;
        free(&r);
        return temp;
    }
    else if ((p == (*L)) && (r.next != NULL))
    {
        p->next = r.next;
        temp = r.data;
        free(&r);
        return temp;
    }
    else
    {
        (*L) = r.next;
        cout << "L: " << (*L) << endl;
        temp = r.data;
        free(&r);
        return temp;
    }
}

float RemoveFromList(Node** L, float d)
{
    Node* temp;
    Node* temp_pr;
    temp = (*L);
    temp_pr = NULL;
    for (; temp != NULL; )
    {
        if (temp->data == d) break;
        temp_pr = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return RemoveListNode(L, temp_pr, (*temp));

    }
    else return NULL;
}

Node* GetNextListNode(Node** L, Node* p)
{
    if (p == NULL)
    {
        return (*L);
    }
    else
    {
        return p->next;
    }
}

Node* SearchInList(Node** L, float d)
{
    Node* temp;
    Node* temp_pr;
    temp = (*L);
    temp_pr = NULL;
    for (; temp != NULL; )
    {
        if (temp->data == d) break;
        temp_pr = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return temp;

    }
    else return NULL;
}

void ShowList(Node* L)
{
    Node* temp;
    temp = L;
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << "; ";
        temp = temp->next;
    }
    cout << endl;
}

//CLASS LIST

Node* List::CreateNode()
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    return temp;
}

Node* List::InsertListNode(Node* p, Node& n)
{
    if (p == NULL)
    {
        n.next = L;
        L = &n;
        return L;
    }
    else
    {
        if (p->next == NULL)
        {
            p->next = &n;
            n.next = NULL;
            return (&n);
        }
        else
        {
            n.next = p->next;
            p->next = &n;
            return (&n);
        }
    }
}

Node* List::InsertInList(Node* p, float data)
{
    Node* temp;
    if (p == NULL)
    {
        temp = CreateNode();
        temp->data = data;
        return InsertListNode(p, (*temp));
    }
    else
    {
        temp = CreateNode();
        temp->data = data;
        return InsertListNode(p, (*temp));

    }
}

float List::RemoveListNode(Node* p, Node& r)
{
    float temp = 0.0f;
    if ((r.next == NULL) && ((&r) != NULL))
    {
        p->next = NULL;
        temp = r.data;
        free(&r);
        return temp;
    }
    else if ((p == L) && (r.next != NULL))
    {
        p->next = r.next;
        temp = r.data;
        free(&r);
        return temp;
    }
    else
    {
        L = r.next;
        temp = r.data;
        free(&r);
        return temp;
    }
}

float List::RemoveFromList(float d)
{
    Node* temp;
    Node* temp_pr;
    temp = L;
    temp_pr = NULL;
    for (; temp != NULL; )
    {
        if (temp->data == d) break;
        temp_pr = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return RemoveListNode(temp_pr, (*temp));

    }
    else return NULL;
}

Node* List::GetNextListNode(Node* p)
{
    if (p == NULL)
    {
        return L;
    }
    else
    {
        return p->next;
    }
}

Node* List::SearchInList(float d)
{
    Node* temp;
    Node* temp_pr;
    temp = L;
    temp_pr = NULL;
    for (; temp != NULL; )
    {
        if (temp->data == d) break;
        temp_pr = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return temp;

    }
    else return NULL;
}

void List::ShowList(void)
{
    Node* temp;
    temp = L;
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << "; ";
        temp = temp->next;
    }
    cout << endl;
}