#pragma once
#include <iostream>

struct Node {
    float data;    //It saves an element
    Node* next;     //It saves a pointer to the next element
};

Node* CreateList();     //This function creates a new list
Node* CreateNode();     //This function creates a new node
Node* InsertListNode(Node** L, Node* p, Node& n);   //This function inserts a node after node p
Node* InsertInList(Node** L, Node* p, float data); //This function creates a node with data and inserts it after node p
float RemoveListNode(Node** L, Node* p, Node& r);  //This function remove a node r after node p and returns the data of the node r
float RemoveFromList(Node** L, float d);    //This function remove a node with data d and return this data
Node* GetNextListNode(Node** L, Node* p);   //This function return the node after node p
Node* SearchInList(Node** L, float d);      //This function search the node with data d and return this node
void ShowList(Node* L); //This function shows whole list l;

class List
{
    Node* L = NULL;

public:

    Node* CreateNode();  //This method creates a new node
    Node* InsertListNode(Node* p, Node& n);     //This method inserts a node after node p
    Node* InsertInList(Node* p, float data);   //This method creates a node with data and inserts it after node p
    float RemoveListNode(Node* p, Node& r);    //This method remove a node r after node p and returns the data of the node r
    float RemoveFromList(float d);    //This method remove a node with data d and return this data
    Node* GetNextListNode(Node* p);     //This method return the node after node p
    Node* SearchInList(float d);       //This method search the node with data d and return this node
    void ShowList(void);    //This method shows whole list l;
};
