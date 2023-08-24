#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define SIZE_OF_STACK_ST    20 //The size of a static stack

class stack_static
{
    double Stack[SIZE_OF_STACK_ST] = { 0 };
    int n = 0;      //The current number of elements
    int length();   //It returns the number of available cells of the stack
public:
    int number;
    void ShowallStack();        //It puts on a screen all elements of the stack 
    void Push(double element);  //This method adds an inputted element to the stack
    double Pop();               //This method returns an element from the stack
    double top();               //This method returns an element from the stack without removing the element
    int LengthOfStack();        //This method returns a current number of elements
    bool IsStackEmpty();        //This method returns 1, if the stack is empty or returns if the stack has some elements
    void FullnessOfStack();     //This method shows information about the stack: Empty space, the number of available cells
};

class stack_dynamic
{
    float* Stack = NULL;
    int n = 0;      //The volume of the stack
    int lenS = 0;   //The number of elements which there are in the stack
public:
    int number = 0;
    stack_dynamic();            //This constructor allocates memory for the stack with 10 cells of the stack
                                //Please free the memory after using the stack, by calling 'nameofstack.FreeMemory'
    void ShowallStack();        //It puts on a screen all elements of the stack
    void Push(float element);  //This method adds an inputted element to the stack
    float Pop();               //This method returns an element from the stack
    float top();               //This method returns an element from the stack without removing the element
    int LengthOfStack();        //This method returns a current number of elements
    bool IsStackEmpty();        //This method returns 1, if the stack is empty or returns if the stack has some elements
    void FullnessOfStack();     //This method shows information about the stack: Empty space, the number of available cells
    void FreeMemory();          //This method free memory which is taken for a stack
};
