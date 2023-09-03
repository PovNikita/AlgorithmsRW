#pragma once
#include <vector>
#include <iostream>

using namespace std;

/**********************************************MinPriprityQueue***********************************/
template <class data_type> class MinPriorityQueue
{
	vector<data_type> PQ;
public:
	void AddLast(data_type data);	//This method add data in the end of priority queue.
	int Root();						//This method returns a root of priority queue
	data_type GetData(int node);	//This method returns data of node
	int Parent(int node);			//This method returns a parent of node
	void Exchange(int c, int p);	//This method change data between nodes c and p
	data_type ExtractLastFromPQ();	//This method returns data of the last element of priority queue
	bool HasChildren(int node);		//This method returns true if node has a child and false if it doesn't have
	int MinChild(int node);			//This method returns a child of node what has minimum data 


	void InsertInPQ(data_type data);//This method inserts data in a priority queue
	data_type ExtractMinFromPQ();	//This method extraxts a minimum node of a priority queue
	data_type FindMinInPQ();		//This method returns data of a minimum node of a priority queue
	int SizePQ();					//This method returns a size of a priority queue
	
	void Show();					//This method shows all elements of a priority queue
};

template <class data_type>
void MinPriorityQueue<data_type>::AddLast(data_type data)
{
	PQ.push_back(data);
}

template <class data_type>
int MinPriorityQueue<data_type>::Root()
{
	return 0;
}


template <class data_type>
data_type MinPriorityQueue<data_type>::GetData(int node)
{
	return PQ.at(node);
}

template <class data_type>
int MinPriorityQueue<data_type>::Parent(int node)
{
	return ((node - 1) / 2);
}

template <class data_type>
void MinPriorityQueue<data_type>::Exchange(int c, int p)
{
	data_type data;
	data = PQ.at(c);
	PQ.at(c) = PQ.at(p);
	PQ.at(p) = data;
}

template <class data_type>
data_type MinPriorityQueue<data_type>::ExtractLastFromPQ()
{
	data_type data;
	data = PQ.back();
	PQ.pop_back();
	return data;

}

template <class data_type>
bool MinPriorityQueue<data_type>::HasChildren(int node)
{
	if ((PQ.size() - 1) >= (2 * node + 1))
		return true;
	else
		return false;
}

template <class data_type>
int MinPriorityQueue<data_type>::MinChild(int node)
{
	if ((PQ.size() - 1) > (2 * node + 1))
	{
		if (PQ.at(2 * node + 1) < PQ.at(2 * node + 2))
			return (2 * node + 1);
		else
			return (2 * node + 2);
	}
	else if ((PQ.size() - 1) == (2 * node + 1))
		return (2 * node + 1);
	else
	{
		cout << "Node " << node << "doesn't have any children\n";
		return 0;
	}
}

template <class data_type>
void MinPriorityQueue<data_type>::InsertInPQ(data_type data)
{
	AddLast(data);
	int c = (int)PQ.size() - 1;
	int p = 0;
	while ((c != Root()) && (GetData(c) < GetData(Parent(c))))
	{
		p = Parent(c);
		Exchange(c, p);
		c = p;
	}
}

template <class data_type>
data_type MinPriorityQueue<data_type>::ExtractMinFromPQ()
{
	data_type c = PQ.at(Root());
	PQ.at(Root()) = ExtractLastFromPQ();
	int i = Root();
	int j = 0;
	while (HasChildren(i))
	{
		j = MinChild(i);
		if (GetData(i) < GetData(j))
			return c;
		Exchange(i, j);
		i = j;
	}
	return c;
}

template <class data_type>
void MinPriorityQueue<data_type>::Show()
{
	vector <int>::iterator Iter;
	cout << "PriorityQueue:\n";
	for (Iter = PQ.begin(); Iter != PQ.end(); Iter++)
	{
		cout << *Iter << "; ";
	}
	cout << endl;
}

template <class data_type>
data_type MinPriorityQueue<data_type>::FindMinInPQ()
{
	data_type data = PQ.at(Root());
	return data;
}

template <class data_type>
int MinPriorityQueue<data_type>::SizePQ()
{
	return PQ.size();
}


/**********************************************MaxPriprityQueue***********************************/
template <class data_type> class MaxPriorityQueue
{
	vector<data_type> PQ;
public:

	void AddLast(data_type data);	//This method add data in the end of priority queue.
	int Root();						//This method returns a root of priority queue
	data_type GetData(int node);	//This method returns data of node
	int Parent(int node);			//This method returns a parent of node
	void Exchange(int c, int p);	//This method change data between nodes c and p
	data_type ExtractLastFromPQ();	//This method returns data of the last element of priority queue
	bool HasChildren(int node);		//This method returns true if node has a child and false if it doesn't have
	int MaxChild(int node);			//This method returns a child of node what has maximum data 


	void InsertInPQ(data_type data);//This method inserts data in a priority queue
	data_type ExtractMaxFromPQ();	//This method extraxts a maximum node of a priority queue
	data_type FindMaxInPQ();		//This method returns data of a maximum node of a priority queue
	int SizePQ();					//This method returns a size of a priority queue

	void Show();					//This method shows all elements of a priority queue
};

template <class data_type>
void MaxPriorityQueue<data_type>::AddLast(data_type data)
{
	PQ.push_back(data);
}

template <class data_type>
int MaxPriorityQueue<data_type>::Root()
{
	return 0;
}


template <class data_type>
data_type MaxPriorityQueue<data_type>::GetData(int node)
{
	return PQ.at(node);
}

template <class data_type>
int MaxPriorityQueue<data_type>::Parent(int node)
{
	return ((node - 1) / 2);
}

template <class data_type>
void MaxPriorityQueue<data_type>::Exchange(int c, int p)
{
	data_type data;
	data = PQ.at(c);
	PQ.at(c) = PQ.at(p);
	PQ.at(p) = data;
}

template <class data_type>
data_type MaxPriorityQueue<data_type>::ExtractLastFromPQ()
{
	data_type data;
	data = PQ.back();
	PQ.pop_back();
	return data;

}

template <class data_type>
bool MaxPriorityQueue<data_type>::HasChildren(int node)
{
	if ((PQ.size() - 1) >= (2 * node + 1))
		return true;
	else
		return false;
}

template <class data_type>
int MaxPriorityQueue<data_type>::MaxChild(int node)
{
	if ((PQ.size() - 1) > (2 * node + 1))
	{
		if (PQ.at(2 * node + 1) > PQ.at(2 * node + 2))
			return (2 * node + 1);
		else
			return (2 * node + 2);
	}
	else if ((PQ.size() - 1) == (2 * node + 1))
		return (2 * node + 1);
	else
	{
		cout << "Node " << node << "doesn't have any children\n";
		return 0;
	}
}

template <class data_type>
void MaxPriorityQueue<data_type>::InsertInPQ(data_type data)
{
	AddLast(data);
	int c = (int)PQ.size() - 1;
	int p = 0;
	while ((c != Root()) && (GetData(c) > GetData(Parent(c))))
	{
		p = Parent(c);
		Exchange(c, p);
		c = p;
	}
}

template <class data_type>
data_type MaxPriorityQueue<data_type>::ExtractMaxFromPQ()
{
	data_type c = PQ.at(Root());
	PQ.at(Root()) = ExtractLastFromPQ();
	int i = Root();
	int j = 0;
	while (HasChildren(i))
	{
		j = MaxChild(i);
		if (GetData(i) > GetData(j))
			return c;
		Exchange(i, j);
		i = j;
	}
	return c;
}

template <class data_type>
void MaxPriorityQueue<data_type>::Show()
{
	vector <int>::iterator Iter;
	cout << "PriorityQueue:\n";
	for (Iter = PQ.begin(); Iter != PQ.end(); Iter++)
	{
		cout << *Iter << "; ";
	}
	cout << endl;
}

template <class data_type>
data_type MaxPriorityQueue<data_type>::FindMaxInPQ()
{
	data_type data = PQ.at(Root());
	return data;
}

template <class data_type>
int MaxPriorityQueue<data_type>::SizePQ()
{
	return PQ.size();
}
