#pragma once
#include<iostream>
using namespace std;


template<class T>
class Linklist
{
	class Node
	{
	private:
		Node* next;
		T data;

	public:


		friend class Linklist<T>;
		Node()
		{
			data = '/0';
			next = nullptr;

		}
		Node(T v)
		{
			data = v;
			next = nullptr;

		}

	};


private:
	Node* head;

public:

	friend class Queuee;
	Linklist()
	{
		head = new Node;
	}
	~Linklist()
	{
		/*Node* temp;
		while (head->next != tail)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		delete head;*/
	}

	class Queuee
	{
	private:
		Linklist<T> l;
		Node* front;
		Node* rear;

	public:
		void Enqueue(T x)
		{
			Node* p = new Node(x);
			if (l.head->next == NULL)
			{
				front = rear = p;
				l.head->next = p;
				p->next = p;
			}
			else
			{
				rear->next = p;
				p->next = front;
				rear = rear->next;
			}
		}

		T Dequeue()
		{
			if (front != nullptr)
			{
				Node* t = front;
				T x = t->data;
				front = front->next;
				rear->next = front;
				delete(t);
				return x;
			}
		}

		void print()
		{
			Node* p = front;
			do
			{
				cout << p->data << endl;
				p = p->next;
			} while (p != rear->next);
		}

		void move_next()
		{
			front = front->next;
			rear = rear->next;
		}


	};
}; 
