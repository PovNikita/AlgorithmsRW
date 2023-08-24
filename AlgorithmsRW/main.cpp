#include <iostream>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <chrono>

/******************************************CREATED_LIBRARIES**********************************/
#include "Stack.h"
#include "Add_functions.h"

using namespace std;

void chapter_1();
void chapter_2();

int main()
{

    char ch_n = '0';
    while (ch_n != 'e')
    {
        cout << "Please enter the number of a chapter you need\nIf you want to exit, enter 'e'\n";
        cin >> ch_n;
        if (ch_n == '1')
        {
            chapter_1();
        }
        if (ch_n == '2')
        {
            //chapter_2();
        }
    }
    return 0;
}


void chapter_1()
{
    char ex_n = '0';
    while (ex_n != 'e')
    {
        cout << "Please enter the number of a exercise you need\nIf you want to exit, enter 'e'\n";
        cin >> ex_n;
        if (ex_n == '1')
        {
            /// Exercise 1;
            cout << "This is a first exercise of chapter 1. Here is showed an example of Stack\n";
            cout << "In the beginning you will see a static stack and some functions for working with it\n";
            float element;
            stack_static test_static;
            test_static.ShowStack();
            test_static.FullnessOfStack();
            cout << "Please enter the number you need to add\n";
            cin >> element;
            test_static.Push(element);
            cout << "Please enter the number you need to add\n";
            cin >> element;
            test_static.Push(element);
            cout << "Please enter the number you need to add\n";
            cin >> element;
            test_static.Push(element);
            test_static.FullnessOfStack();
            test_static.ShowStack();
            cout << "Top method: " << test_static.top() << endl;
            cout << "The length of a stack: " << test_static.LengthOfStack() << endl;
            cout << "Pop method: " << test_static.Pop() << endl;
            test_static.ShowStack();
            cout << "The length of a stack: " << test_static.LengthOfStack() << endl;
            test_static.ShowStack();
            test_static.FullnessOfStack();

            cout << "This is an example of dynamic stack\n";
            stack_dynamic test; /// When you create an object the constructor create a stack with 10cells of memory.
            test.ShowStack();
            test.FullnessOfStack();
            for (int i = 0; i < 11; i++)
            {
                cout << "Please enter the number you need to add\n";
                cin >> element;
                test.Push(element);
            }
            test.FullnessOfStack();
            test.ShowStack();
            cout << "Top method: " << test.top() << endl;
            cout << "The length of a stack: " << test.LengthOfStack() << endl;
            cout << "Pop method: " << test.Pop() << endl;
            test.ShowStack();
            cout << "The length of a stack: " << test.LengthOfStack() << endl;
            test.ShowStack();
            test.FullnessOfStack();
            test.FreeMemory();
        }
        ///Exercise 2; 
        else if (ex_n == '2')
        {
            cout << "This is a second exercise of chapter 1. Here the solution is showed.\n";
            cout << "This is an example without using stack.\n";
            //float quotes[7] = { 7,10,8,6,3,8,8.5 };
            //float spans[7] = { 1 };
            float quotes[700] = { 0 };
            float spans[700] = { 1 };
            bool span_end;
            int k = 0;
            int n;
            n = sizeof(spans) / sizeof(spans[0]);
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            {
                quotes[i] = (float)(1 + rand() % (10 - 1 + 1));
            }
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                k = 1;
                span_end = false;
                while ((i - k >= 0) && (!span_end))
                {
                    if (quotes[i - k] <= quotes[i])
                    {
                        k = k + 1;
                    }
                    else
                    {
                        span_end = true;
                    }
                    spans[i] = (float)k;
                }
            }
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "The execution time of an algorithm without a stack: " << duration.count() << " microseconds\n";
            for (int i = 0; i < n; i++)
            {
                //cout << spans[i] << '\n';
            }
            for (int i = 0; i < n; i++)
            {
                spans[i] = 1;
            }
            cout << "This is an example with using a stack\n";
            stack_dynamic S;
            start = chrono::high_resolution_clock::now();
            spans[1] = 1;
            S.Push(0.0f);
            for (int i = 1; i < n; i++)
            {
                while ((!(S.IsStackEmpty())) && (quotes[(int)S.top()] <= quotes[i]))
                {
                    S.Pop();
                }
                if (S.IsStackEmpty())
                {
                    spans[i] = (float)(i + 1);
                }
                else
                    spans[i] = (float)(i - (int)S.top());
                S.Push((float)i);
            }
            stop = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            cout << "The execution time of an algorithm based on a stack: " << duration.count() << " microseconds\n";
            for (int i = 0; i < n; i++)
            {
                //cout << spans[i] << '\n';
            }
        }
        ///Exercise 3;
        else if (ex_n == '3')
        {
            char str[100] = { '0' };
            float a = 0, b = 0;
            stack_dynamic Stack;
            while (!(str[0] == 'q'))
            {
                cout << "Enter an operator or an operand and press 'Enter':\n" << "If you want to finish entering and see the result, press 'e'\n";
                while (1)
                {
                    cin >> str;
                    if ((Stack.LengthOfStack() <= 1) && ((str[0] == '+') || (str[0] == '-') || (str[0] == '*') || (str[0] == '/')))
                    {
                        cout << "You have entered an operator, but in the beginning you have to enter two operands. Please enter an operand.\n";
                        cin >> str;
                        continue;
                    }
                    else if (str[0] == '+')
                    {
                        b = Stack.Pop();
                        a = Stack.Pop();
                        Stack.Push(a + b);
                        //cout << "The result of summation: " << Stack.top() << "\n";
                        //Summation
                    }
                    else if (str[0] == '-')
                    {
                        b = Stack.Pop();
                        a = Stack.Pop();
                        Stack.Push(a - b);
                        //cout << "The result of subtraction: " << Stack.top() << "\n";
                        //Subtraction
                    }
                    else if (str[0] == '*')
                    {
                        b = Stack.Pop();
                        a = Stack.Pop();
                        Stack.Push(a * b);
                        //cout << "The result of multiplication: " << Stack.top() << "\n";
                        //Multiplication
                    }
                    else if (str[0] == '/')
                    {
                        b = Stack.Pop();
                        a = Stack.Pop();
                        Stack.Push(a / b);
                        //cout << "The result of division: " << Stack.top() << "\n";
                        //Division
                    }
                    else if (str[0] == 'e')
                        break;
                    else
                        Stack.Push(input(str));
                }
                if (!Stack.IsStackEmpty())
                {
                    cout << "The result: " << Stack.top() << "\n";
                    for (int i = 0; i <= Stack.LengthOfStack(); Stack.Pop(), i++);
                }
                cout << "If you want to exit from this exercise, enter 'q'. If you want to continue press any key\n";
                cin >> str;
            }
        }
        ///Exercise 4;
        else if (ex_n == '4')
        {
            stack_dynamic Stack;
            char str[100] = { 0 };
            int n = sizeof(str) / sizeof(str[0]);
            cout << "Enter a string:";
            cin >> str;
            Stack.Push(0);
            for (int i = 0; i < n; i++)
            {
                if (((Stack.top() == (float)'(') && (str[i] == ')')) || ((Stack.top() == (float)'{') && (str[i] == '}')) ||
                    ((Stack.top() == (float)'[') && (str[i] == ']')))
                {
                    Stack.Pop();
                }
                else if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == ')' || str[i] == '}' || str[i] == ']')
                {
                    Stack.Push((float)str[i]);
                }
            }
            for (; Stack.LengthOfStack() > 1;)
            {
                cout << (char)Stack.Pop() << "\n";
            }
        }
    }
}
