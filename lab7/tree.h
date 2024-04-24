#pragma once
#include <iostream>
template<typename T>
int compara(T v1, T v2)
{
	if (v1 > v2)
		return 0;
	else return -1;
}
template<typename T>
struct node
{
	T value;
	node<T>** children;
	int numberofchildren;
};
template<typename T>
class tree
{
private:
	node<T> root;
	int maxChildrenPernode;
	tree(int number)
	{
		root = nullptr;
		maxChildrenPernode = number;
	}
	void add_node(node<T>* parent, T value)
	{
		if (root = nullptr)
		{
			root=new node<T>;
			root->value = value;
			root->numberofchildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode]

		}
		else
		{
			if (parent->numberofchildren == maxChildrenPernode)
			{
				parent = parent->children[0];
				parent->numberofchildren = 0;
			}
			parent->children[numberofchildren] = new nod<T>
		    parent->children[numberofchildren]->value = value;
			parent->children[numberofchildren]->numverofchildren = 0;
			parent->children[numberofchildren]->children = new Nod<T>*[maxChildrenPernode];
			parent->numberofchildren++;


		    

		}
	}
	node<T>* get_node(node<T>* nod)
	{
		if (nod == nullptr)
			return root;
		else return nod;

	}
	void delete_node(node<T>* nod)
	{
		if (nod != nullptr)
		{

			for (i = 0; i < nod->numberofchildren; i++)
				delete nod->children[i];
			delete nod;


		}
	}
	node<T>* find(T value,node<T>* nod)
	{
		if (nod->value == value)
			return nod;
		else
			for (i = 0; i < nod->numberofchildren; i++)
				find(value, nod->children[i]);
	}
	void sort(node<T>* nod)
	{
		if (nod != nullptr)
		{
			int ok = 0;
			do {
				ok = 1;
				for (i = 0; i < nod->numberofchildren - 1; i++)
					if (nod->children[i]->value > nod->children[i + 1]->value)
						std::swap(nod->children[i]->value, nod->children[i + 1]->value);
			}
		}
	}
	int count(node<T>* nod,int i)
	{
		if (nod == nullptr)
			nod = root;
		if (i < nod->numberofchildren)
			return 1 + count(nod, i + 1);
		else return 0;
	}
	void insert(T value,node<T>* nod,int poz)
	{
		if (nod == nullptr)
			nod = root;

		else
			if (poz < nod->numberofchildren)
			{
				for (int i = poz; i < nod->numberofchildren - 1; i++)
				{
					nod->children[i] = nod->children[i + 1];
				}
				node<T>* c;
				c = new node;
				c->value = value;
				c->numberofchildren = 0;
				c->children = new T[maxChildrenPernode];
				nod->children[poz] = c;
			}
	}
	void print(node<T>* nod)
	{
		for (int i = 0; i < nod->numberofchildren; i++)
			std::cout << nod->children[i] << " ";
	}
	


};

