#include<iostream>
#include<string>
using namespace std;

	struct Node
	{
		int id;
		Node* next;
	};

	class Queue
	{
		Node* front;
		Node* rear;
		Node* CreateNode(int id)
		{
			Node* temp = new Node();
			temp->id = id;
			temp->next = NULL;
			return temp;
		}
	public:
		Queue() :front(NULL), rear(NULL)
		{
		}
		void Enqueue(int id)
		{
			Node* item = CreateNode(id);
			if (isQueueEmpty())
			{
				front = item;
			}
			else
			{
				rear->next = item;
			}
			rear = item;
		}
		
		void Dequeue()
		{
			Node* temp;
			if (isQueueEmpty())
			{
				cout << "Nothing to delete\n";
			}
			else
			{
				temp = front;
				front = front->next;
				cout << "Dequeued element is " << temp->id << '\n';
				delete temp;
			}

		}
		
		void List()
		{
			cout << "_________Lists_________________\n\n";
			Node* trav = front;
			while (trav != NULL)
			{
				cout << trav->id << '\n';
				trav = trav->next;
			}
			cout << "__________________________\n";
		}
		bool isQueueEmpty()
		{
			return front == NULL;
		}
		char Menu()
		{
			char ch;
			cout << "Q/q-->Enqueue \n";
			cout << "D/d-->Dequeue  \n";
			cout << "L/l-->List \n";
			cout << "e-->Exit \n";
			cout << "Plz enter your choice : ";
			cin >> ch;
			return ch;
		}
		~Queue()
		{
			while (!isQueueEmpty())
				Dequeue();
		}
	};


	int main()
	{
		Queue q;

		char ch;
		int val;
		while ((ch = q.Menu()) != 'e')
		{

			switch (ch)
			{
			case 'Q':
			case 'q':
			{
				cout << "Enter id: ";
				cin >> val;
				q.Enqueue(val);
				break;
			}
			case 'D':
			case 'd':
			{
				q.Dequeue();
				break;
			}
			case 'L':
			case 'l':
			{
				q.List();
				break;
			}
			default:
				cout << "Enter a proper choice \n";
			};

		}
		return 0;
	}
