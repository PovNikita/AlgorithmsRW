#include <iostream>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <random>

/******************************************CREATED_LIBRARIES**********************************/
#include "Add_functions.h"
#include "List.h"
#include "Graph.h" //Here "Stack.h" and "Queue.h" are included

using namespace std;
using namespace sf;

//These variables and functions are for the fourth exercise of the second chapter
//********************************************************************
const int windowWidth = 640;
const int windowHeight = 640;

const int x_length = 15;
const int y_length = x_length * windowHeight / windowWidth;

const float WidthOfQuad = windowWidth / x_length;
const float HeightOfQuad = windowHeight / y_length;

class GraphNode {
public:
    float x = 0.0;  //x coordinate of a up left point of node
    float y = 0.0;  //y coordinate of a up left point of node
    bool map = false;
    int dir = 6;    // It shows the direction of next move. dir = 0 - to the left
    //                                      dir = 1 - to the up
    //                                      dir = 2 - to the right
    //                                      dir = 3 - to the down
    //                                      dir = 4 - the first node
    //                                      dir = 5 - the last node

    RenderWindow* wind;
    VertexArray vertex;

    GraphNode()
    {
        vertex.setPrimitiveType(Quads);
        vertex.resize(4);
        vertex[0].color = Color::Black;
        vertex[1].color = Color::Black;
        vertex[2].color = Color::Black;
        vertex[3].color = Color::Black;
    }

    void calculateXY()
    {                                                                       //      0_______1
        vertex[0].position = Vector2f(x, y);                                //      |       |
        vertex[1].position = Vector2f(x + WidthOfQuad, y);                  //      |       |
        vertex[2].position = Vector2f(x + WidthOfQuad, y + HeightOfQuad);   //      |_______|
        vertex[3].position = Vector2f(x, y + HeightOfQuad);                 //      3       2
    }

    void set_col()
    {
        if (dir == 0)
        {
            //Set red colour for 0, 3 points
            vertex[0].color = Color::Red;
            vertex[3].color = Color::Red;
            vertex[1].color = Color::White;
            vertex[2].color = Color::White;
        }
        else if (dir == 1)
        {
            //Set red colour for 0, 1 points
            vertex[0].color = Color::Red;
            vertex[1].color = Color::Red;
            vertex[2].color = Color::White;
            vertex[3].color = Color::White;
        }
        else if (dir == 2)
        {
            //Set red colour for 1, 2 points
            vertex[1].color = Color::Red;
            vertex[2].color = Color::Red;
            vertex[0].color = Color::White;
            vertex[3].color = Color::White;
        }
        else if (dir == 3)
        {
            //Set red colour for 2, 3 points
            vertex[2].color = Color::Red;
            vertex[3].color = Color::Red;
            vertex[0].color = Color::White;
            vertex[1].color = Color::White;
        }
        else if (dir == 4)
        {
            //Set green colour
            vertex[2].color = Color::Green;
            vertex[3].color = Color::Green;
            vertex[0].color = Color::Green;
            vertex[1].color = Color::Green;
        }
        else if (dir == 5)
        {
            //Set red colour
            vertex[2].color = Color::Red;
            vertex[3].color = Color::Red;
            vertex[0].color = Color::Red;
            vertex[1].color = Color::Red;
        }
    }

    void draw()
    {
        wind->draw(vertex);
    }
};

GraphNode** CreateMap()
{
    GraphNode** p = NULL;
    p = new GraphNode * [y_length];
    for (int i = 0; i < y_length; i++)
    {
        p[i] = new GraphNode[x_length];
    }
    return p;
}

void ShowMap(GraphNode** p)
{

    for (int i = 0; i < y_length; i++)
    {
        for (int j = 0; j < x_length; j++)
            cout << p[i][j].map << " ";
        cout << endl;
    }
    cout << endl << endl;

}

void FillMap(GraphNode** p)
{
    random_device rd;
    int x = 0;
    int y = 0;
    bool end = false;
    uint8_t ran = 0;
    x = rd() % x_length;
    y = rd() % y_length;
    p[y][x].map = true;
    p[y][x].dir = 4;
    ran = rd() % 4;
    while (!end)
    {
        if ((ran == 0) && (x != 0) && (p[y][x - 1].map == false))
        {
            //To the left
            if (p[y][x].dir != 4)
                p[y][x].dir = 0;
            x = x - 1;
            p[y][x].map = true;
        }
        else if ((ran == 1) && (y != 0) && (p[y - 1][x].map == false))
        {
            //To the high
            if (p[y][x].dir != 4)
                p[y][x].dir = 1;
            y = y - 1;
            p[y][x].map = true;
        }
        else if ((ran == 2) && (x + 1 != x_length) && (p[y][x + 1].map == false))
        {
            //To the right
            if (p[y][x].dir != 4)
                p[y][x].dir = 2;
            x = x + 1;
            p[y][x].map = true;
        }
        else if ((ran == 3) && (y + 1 != y_length) && (p[y + 1][x].map == false))
        {
            //To the down
            if (p[y][x].dir != 4)
                p[y][x].dir = 3;
            y = y + 1;
            p[y][x].map = true;
        }
        if (((ran == 0) && (x == 0)) || ((ran == 1) && (y == 0)) || ((ran == 2) && (x + 1 == x_length)) || ((ran == 3) && (y + 1 == y_length)))
        {
            end = true;
            p[y][x].dir = 5;
        }
        else if ((p[y][x - 1].map == true) && (p[y - 1][x].map == true) && (p[y][x + 1].map == true) && (p[y + 1][x].map == true))
        {
            end = true;
            p[y][x].dir = 5;
        }
        ran = rd() % 4;
    }
}

void calculatePosition(GraphNode** p)
{
    for (int y = 0; y < y_length; y++)
    {
        for (int x = 0; x < x_length; x++)
        {
            p[y][x].x = x * WidthOfQuad;
            p[y][x].y = y * HeightOfQuad;
            p[y][x].calculateXY();
            p[y][x].set_col();
        }
    }
}
//********************************************************************

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
        else if (ch_n == '2')
        {
            chapter_2();
        }
        else if (ch_n == '3')
        {

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
        /// Exercise 1;
        if (ex_n == '1')
        {
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

void chapter_2()
{
    char ex_n = '0';
    while (ex_n != 'e')
    {
        cout << "Please enter the number of a exercise you need\nIf you want to exit, enter 'e'\n";
        cin >> ex_n;
        ///Exercise 1
        if (ex_n == '1')
        {
            cout << "This is a first exercise of the chapter 2. Here is showed an example of List\n";
            List list;
            Node* p1;
            Node* p2;
            Node* p3;
            p1 = list.InsertInList(NULL, 3.0f);
            p2 = list.InsertInList(NULL, 1.0f);
            p3 = list.InsertInList(NULL, 0.0f);
            cout << "p3: " << p3 << endl;
            cout << "p2: " << p2 << endl;
            cout << "p1: " << p1 << endl;
            list.ShowList();
            cout << "Remove: " << list.RemoveListNode(p2, (*p1)) << endl;
            cout << "Remove: " << list.RemoveFromList(0.0) << endl;
            cout << "GetNextListNode: " << list.GetNextListNode(NULL) << endl;
            cout << "SearchInList: " << list.SearchInList(1.0f) << endl;
            list.ShowList();

            List list2;
            list2.InsertInList(list2.InsertInList(list2.InsertInList(NULL, 3.0f), 1.0f), 0.0f);
            list2.ShowList();
        }
        ///Exercise 2
        else if (ex_n == '2')
        {
            cout << "This is a second exercise of the chapter 2. Here is showed an example of some functions of Queue library\n";
            cout << "Queue structure" << endl;
            Queue* Q = NULL;
            Q = CreateQueue();
            for (int i = 0; i < 10; i++)
            {
                EnQueue(Q, 5.0);
                ShowAllQueue(Q);
                EnQueue(Q, 6);
                ShowAllQueue(Q);
                EnQueue(Q, 2);
                ShowAllQueue(Q);
                EnQueue(Q, 9);
                ShowAllQueue(Q);
                DeQueue(Q);
                ShowAllQueue(Q);
                DeQueue(Q);
                ShowAllQueue(Q);
            }
            cout << "Queue class" << endl;
            Queue_cl Que;
            for (int i = 0; i < 10; i++)
            {
                Que.EnQueue(5.0);
                Que.ShowAllQueue();
                Que.EnQueue(6);
                Que.ShowAllQueue();
                Que.EnQueue(2);
                Que.ShowAllQueue();
                Que.EnQueue(9);
                Que.ShowAllQueue();
                Que.DeQueue();
                Que.ShowAllQueue();
                Que.DeQueue();
                Que.ShowAllQueue();
            }
        }
        ///Exercise 3
        else if (ex_n == '3')
        {
            cout << "This is a third exercise of the chapter 2. Here is showed examples of some functions of Graph library\n";
            stack_static stack;
            bool** Matrix;
            int* px;
            int* py;
            bool* visited;
            int row = 5, column = 4;
            int nodes = 0;
            int n_pairs = 0;
            //cout << "Enter the count of nodes" << endl;
            //cin >> nodes;
            nodes = 8;
            row = nodes;
            column = row;
            visited = new bool[row] {false};
            //cout << "What nodes would you like to connect? First of all please enter the count of links" << endl;
            //cin >> n_pairs;
            n_pairs = 8;
            px = new int[n_pairs] {0};
            py = new int[n_pairs] {0};
            //cout << "Now enter pairs:" << endl;
            px[0] = 0; px[1] = 0; px[2] = 0; px[3] = 1; px[4] = 4; px[5] = 5; px[6] = 5; px[7] = 5;
            py[0] = 1; py[1] = 2; py[2] = 3; py[3] = 4; py[4] = 5; py[5] = 3; py[6] = 6; py[7] = 7;
            /*for (int i = 0; i < n_pairs; i++)
                cin >> px[i] >> py[i];*/
            CreateMatrix(&Matrix, column, row);
            CreateLinksInMatrix(&Matrix, column, row, px, py, n_pairs);
            cout << "Created adjacency matrix:\n";
            ShowMatrix(Matrix, column, row);
            cout << "\n********************DFS*************************\n";
            DFS(Matrix, &visited, 0, nodes, &stack);
            cout << "\nVisited nodes:\n";
            for (int i = 0; i < nodes; i++)
            {
                cout << i << "; ";
            }
            cout << endl;
            for (int i = 0; i < nodes; i++)
            {
                cout << visited[i] << "; ";
            }
            cout << "\nThis is a stack showing the order of visiting nodes\n";
            stack.ShowStack();
            while (!stack.IsStackEmpty())
                stack.Pop();

            cout << "\n********************StackDFS*************************\n";
            bool* a;
            a = StackDFS(Matrix, 0, nodes, &stack);
            cout << "\nVisited nodes:\n";
            for (int i = 0; i < nodes; i++)
            {
                cout << i << ": ";
            }
            cout << endl;
            for (int i = 0; i < nodes; i++)
            {
                cout << a[i] << "; ";
            }
            free(a);
            cout << "\nThis is a stack showing the order of visiting nodes\n";
            stack.ShowStack();
            while (!stack.IsStackEmpty())
                stack.Pop();

            cout << "\n********************NoDuplicatesStackDFS*************************\n";
            a = NoDuplicatesStackDFS(Matrix, 0, nodes, &stack);
            cout << "\nVisited nodes:\n";
            for (int i = 0; i < nodes; i++)
            {
                cout << i << ": ";
            }
            cout << endl;
            for (int i = 0; i < nodes; i++)
            {
                cout << a[i] << "; ";
            }
            free(a);
            cout << "\nThis is a stack showing the order of visiting nodes\n";
            stack.ShowStack();
            while (!stack.IsStackEmpty())
                stack.Pop();

            cout << "\n********************BFS*************************\n";
            a = BFS(Matrix, 0, nodes, &stack);
            cout << "\nVisited nodes:\n";
            for (int i = 0; i < nodes; i++)
            {
                cout << i << ": ";
            }
            cout << endl;
            for (int i = 0; i < nodes; i++)
            {
                cout << a[i] << "; ";
            }
            free(a);
            cout << "\nThis is a stack showing the order of visiting nodes\n";
            stack.ShowStack();
            while (!stack.IsStackEmpty())
                stack.Pop();


            for (int i = 0; i < row; i++)
                free(Matrix[i]);
            delete[] Matrix;
            delete[] px;
            delete[] py;
            delete[] visited;
        }
        ///Exercise 4
        else if (ex_n == '4')
        {
            cout << "This is a fourth exercise of the chapter 2.\n";
            GraphNode** p = NULL;
            p = CreateMap();
            ShowMap(p);
            FillMap(p);
            ShowMap(p);
            calculatePosition(p);

            RenderWindow wind(VideoMode(windowWidth, windowHeight), "The fourth exercise of the second chapter");

            for (int y = 0; y < y_length; y++)
                for (int x = 0; x < x_length; x++)
                    p[y][x].wind = &wind;

            while (wind.isOpen())
            {
                Event event;
                while (wind.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        wind.close();
                }
                wind.clear();
                for (int y = 0; y < y_length; y++)
                    for (int x = 0; x < x_length; x++)
                        p[y][x].draw();
                wind.display();
            }
        }
        ///Exercise 5
        else if (ex_n == '5')
        {
            cout << "This is a fourth exercise of the chapter 2. Here is showed examples of some functions of Graph library\n";
            bool** Matrix;
            int* px, * py;
            int nodes = 9;
            int links = 11;
            bool flag = false;

            //Not bipartite Graph
            /*nodes = 8;
            links = 8;
            px = new int[links] {0};
            py = new int[links] {0};
            px[0] = 0; px[1] = 0; px[2] = 0; px[3] = 1; px[4] = 4; px[5] = 5; px[6] = 5; px[7] = 5;
            py[0] = 1; py[1] = 2; py[2] = 3; py[3] = 4; py[4] = 5; py[5] = 3; py[6] = 6; py[7] = 7;*/
            
            //Bipartite Graph
            px = new int[links] {0};
            py = new int[links] {0};
            px[0] = 0; px[1] = 0; px[2] = 0; px[3] = 1; px[4] = 2; px[5] = 2; px[6] = 2; px[7] = 4; px[8] = 5; px[9] = 5; px[10] = 6;
            py[0] = 1; py[1] = 4; py[2] = 8; py[3] = 7; py[4] = 3; py[5] = 4; py[6] = 8; py[7] = 7; py[8] = 6; py[9] = 8; py[10] = 7;
            CreateMatrix(&Matrix, nodes, nodes);
            CreateLinksInMatrix(&Matrix, nodes, nodes, px, py, links);
            cout << "Created adjacency matrix:\n";
            ShowMatrix(Matrix, nodes, nodes);
            flag = IsGraphBipartite(Matrix, 0, nodes);
            if (flag == true)
                cout << "Graph is bipartite\n";
            else if (flag == false)
                cout << "Graph isn't bipartite\n";
            for (int i = 0; i < nodes; i++)
                free(Matrix[i]);
            delete[] Matrix;
            delete[] px;
            delete[] py;
        }
    }

}