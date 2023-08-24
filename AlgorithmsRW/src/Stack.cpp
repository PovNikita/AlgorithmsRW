#include "Stack.h"

//**********************************************STACK_STATIC********************************//
int stack_static::length()
{
    return SIZE_OF_STACK_ST;
}

void stack_static::ShowStack()
{
    if (n > 0)
    {
        cout << "The static stack:\n";
        for (int i = 0; i < n; i++)
        {
            cout << Stack[i] << "; ";
        }
        cout << "\n";
    }
    else if (n == 0)
    {
        cout << "The stack is empty\n";
    }
}

void stack_static::Push(float element)
{
    Stack[n] = element;
    n = n + 1;
}

float stack_static::Pop()
{
    float element;
    if (n > 0)
    {
        element = Stack[n - 1];
        Stack[n - 1] = 0;
        n = n - 1;
        return element;
    }
    else
    {
        cout << "ERROR. The stack is empty.\n";
        return 0;
    }
}

float stack_static::top()
{
    if (n > 0)
    {
        return Stack[n - 1];
    }
    else
    {
        cout << "ERROR. The stack is empty.\n";
        return 0;
    }
}

int stack_static::LengthOfStack()
{
    return n;
}

bool stack_static::IsStackEmpty()
{
    if (n > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void stack_static::FullnessOfStack()
{
    float empty;
    float a = (float)n;
    empty = (1 - a / SIZE_OF_STACK_ST) * 100;
    cout << "Empty space: " << empty << "%\n" << "You can add " << SIZE_OF_STACK_ST - n << " element(s)\n";
}

//**********************************************STACK_DYNAMIC********************************//

stack_dynamic::stack_dynamic()
{
    Stack = (float*)calloc(10, sizeof(float));
    n = 10;
}

void stack_dynamic::ShowStack()
{
    if (lenS > 0)
    {
        cout << "The dynamic stack:\n";
        for (int i = 0; i < lenS; i++)
        {
            cout << Stack[i] << "; ";
        }
        cout << "\n";
    }
    else if (lenS == 0)
    {
        cout << "The stack is empty\n";
    }
}

void stack_dynamic::Push(float element)
{
    float* p;
    if (lenS < n)
    {
        Stack[lenS] = element;
        lenS = lenS + 1;
    }
    else
    {
        n = n + 1;
        p = (float*)realloc(Stack, (n * sizeof(float)));
        if (p == NULL)
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            Stack = p;
            Stack[lenS] = element;
            lenS = lenS + 1;
        }
    }
}

float stack_dynamic::Pop()
{
    float element;
    if (lenS > 0)
    {
        element = Stack[lenS - 1];
        Stack[lenS - 1] = 0;
        lenS = lenS - 1;
        return element;
    }
    else
    {
        cout << "ERROR. The stack is empty.\n";
        return 0;
    }
}

float stack_dynamic::top()
{
    if (lenS > 0)
    {
        return Stack[lenS - 1];
    }
    else
    {
        cout << "ERROR. The stack is empty.\n";
        return 0;
    }
}

int stack_dynamic::LengthOfStack()
{
    return lenS;
}

bool stack_dynamic::IsStackEmpty()
{
    if (lenS > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void stack_dynamic::FullnessOfStack()
{
    float empty;
    float a = (float)lenS;
    float b = (float)n;
    empty = (1 - a / b) * 100;
    cout << "Empty space: " << empty << "%\n" << "You can add " << n - lenS << " element(s)\n";
}

void stack_dynamic::FreeMemory()
{
    free(Stack);
}