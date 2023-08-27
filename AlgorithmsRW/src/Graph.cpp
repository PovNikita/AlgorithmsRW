#include "Graph.h"

void CreateMatrix(bool*** Matrix, int column, int row)
{
    (*Matrix) = new bool* [row];
    if ((*Matrix) == NULL)
    {
        cout << "NULL was returned. Try to decrease the count of rows" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row; i++)
    {
        (*Matrix)[i] = new bool[column] {0};
        if (((*Matrix)[i]) == NULL)
        {
            cout << "NULL was returned. Try to decrease the count of columns" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void ShowMatrix(bool** Matrix, int column, int row)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << Matrix[i][j] << " ";
        cout << endl;
    }
}

void CreateLinksInMatrix(bool*** Matrix, int column, int row, int* x, int* y, int n_pairs)
{
    for (int i = 0; i < n_pairs; i++)
    {
        (*Matrix)[x[i]][y[i]] = 1;
        (*Matrix)[y[i]][x[i]] = 1;
    }
}

void CreateRandomLinksInMatrix(bool*** Matrix, int nodes)
{
    int ran = 0;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = (i + 1); j < nodes; j++)
        {
            ran = (rand() % 2);
            (*Matrix)[i][j] = ran;
            (*Matrix)[j][i] = ran;
        }
    }
}

void DFS(bool** Matrix, bool** visited, int node, int nodes)
{
    (*visited)[node] = true;
    //cout << "Node: " << node << endl;
    for (int v = 0; v < nodes; v++)
    {
        if ((Matrix[node][v] == 1) && ((*visited)[v] == false))
            DFS(Matrix, visited, v, nodes);
    }
}
void DFS(bool** Matrix, bool** visited, int node, int nodes, stack_static* stack)
{
    (*visited)[node] = true;
    (*stack).Push((float)node);
    //cout << "Node: " << node << endl;
    for (int v = 0; v < nodes; v++)
    {
        if ((Matrix[node][v] == 1) && ((*visited)[v] == false))
            DFS(Matrix, visited, v, nodes, stack);
    }
}

bool* StackDFS(bool** Matrix, int node, int nodes)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    stack_dynamic S;
    int c = 0;
    S.Push((float)node);
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        //cout << "Node: " << c << endl;
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false))
            {
                S.Push((float)v);
            }
        }
    }
    return visited;
}
bool* StackDFS(bool** Matrix, int node, int nodes, stack_static* stack)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    stack_dynamic S;
    int c = 0;
    S.Push((float)node);
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        //cout << "Node: " << c << endl;
        (*stack).Push((float)c);
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false))
            {
                S.Push((float)v);
            }
        }
    }
    return visited;
}

bool* NoDuplicatesStackDFS(bool** Matrix, int node, int nodes, stack_static* stack)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    stack_dynamic S;
    bool* instack;
    instack = new bool[nodes] {false};
    int c = 0;
    S.Push((float)node);
    instack[node] = true;
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        instack[c] = false;
        //cout << "Node: " << c << endl;
        (*stack).Push((float)c);
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false) && (instack[v] == false))
            {
                S.Push((float)v);
                instack[v] = true;
            }
        }
    }
    return visited;
}
bool* NoDuplicatesStackDFS(bool** Matrix, int node, int nodes)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    stack_dynamic S;
    bool* instack;
    instack = new bool[nodes] {false};
    int c = 0;
    S.Push((float)node);
    instack[node] = true;
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        instack[c] = false;
        //cout << "Node: " << c << endl;
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false) && (instack[v] == false))
            {
                S.Push((float)v);
                instack[v] = true;
            }
        }
    }
    return visited;
}

bool* BFS(bool** Matrix, int node, int nodes, stack_static* stack)
{
    int c = 0;
    Queue_cl Q;
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool* inqueue;
    inqueue = new bool[nodes] {false};
    Q.EnQueue((float)node);
    (*stack).Push((float)node);
    inqueue[node] = true;
    while (!Q.IsQueueEmpty())
    {
        c = (int)Q.DeQueue();
        inqueue[c] = false;
        //cout << "Node: " << c << endl;
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false) && (inqueue[v] == false))
            {
                Q.EnQueue((float)v);
                inqueue[v] = true;
                (*stack).Push((float)v);
            }
        }
        //Q.ShowQueue();
    }
    return visited;
}
bool* BFS(bool** Matrix, int node, int nodes)
{
    int c = 0;
    Queue_cl Q;
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool* inqueue;
    inqueue = new bool[nodes] {false};
    Q.EnQueue((float)node);
    inqueue[node] = true;
    while (!Q.IsQueueEmpty())
    {
        c = (int)Q.DeQueue();
        inqueue[c] = false;
        //cout << "Node: " << c << endl;
        visited[c] = true;
        for (int v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false) && (inqueue[v] == false))
            {
                Q.EnQueue((float)v);
                inqueue[v] = true;
            }
        }
        //Q.ShowQueue();
    }
    return visited;
}

bool IsGraphBipartite(bool** Matrix, int node, int nodes)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool* flag;     //It is used for painting the node.
    flag = (bool*)calloc(nodes, sizeof(bool));
    if (flag == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool* painted;     //It is used for painting the node.
    painted = (bool*)calloc(nodes, sizeof(bool));
    if (painted == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool set = false;
    bool allow = false;
    bool* instack;
    instack = new bool[nodes] {false};
    stack_dynamic S;
    int c = 0;
    S.Push((float)node);
    flag[c] = set;
    painted[c] = true;
    set = !set;
    allow = true;
    instack[node] = true;
    int v = 0;
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        instack[c] = false;
        //cout << "Node: " << c << " flag: " << flag[c] << endl;
        visited[c] = true;
        for (v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false))
            {
                S.Push((float)v);
                instack[v] = true;
                if (!painted[v])
                {
                    flag[v] = set;
                    painted[v] = true;
                }
                //cout << "Node v: " << v << " flag: " << flag[v] << endl;
                if (flag[c] == flag[v])
                    return false;
                allow = true;
            }
        }
        if (allow)
        {
            set = !set;
            allow = false;
        }

    }
    return true;
}
bool IsGraphBipartite(bool** Matrix, int node, int nodes, bool** painted)
{
    bool* visited;
    visited = (bool*)calloc(nodes, sizeof(bool));
    if (visited == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool* flag;     //It is used for painting the node.
    flag = (bool*)calloc(nodes, sizeof(bool));
    if (flag == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    (*painted) = (bool*)calloc(nodes, sizeof(bool));
    if ((*painted) == NULL)
    {
        cout << "NULL poiter was gotten. I close this function and return NULL" << endl;
        return NULL;
    }
    bool set = false;
    bool allow = false;
    bool* instack;
    instack = new bool[nodes] {false};
    stack_dynamic S;
    int c = 0;
    S.Push((float)node);
    flag[c] = set;
    (*painted)[c] = true;
    set = !set;
    allow = true;
    instack[node] = true;
    int v = 0;
    while (!S.IsStackEmpty())
    {
        c = (int)(S.Pop());
        instack[c] = false;
        //cout << "Node: " << c << " flag: " << flag[c] << endl;
        visited[c] = true;
        for (v = 0; v < nodes; v++)
        {
            if ((Matrix[c][v] == 1) && (visited[v] == false))
            {
                S.Push((float)v);
                instack[v] = true;
                if (!(*painted)[v])
                {
                    flag[v] = set;
                    (*painted)[v] = true;
                }
                //cout << "Node v: " << v << " flag: " << flag[v] << endl;
                if (flag[c] == flag[v])
                    return false;
                allow = true;
            }
        }
        if (allow)
        {
            set = !set;
            allow = false;
        }

    }
    return true;
}