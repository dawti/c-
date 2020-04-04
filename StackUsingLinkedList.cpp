#include<iostream>
#include<string>
using namespace std;
//Stack of positive integers using Linked list

struct Node
{
	int id;
	Node* next;
};

class Stack
{
	Node* top;
	Node* CreateNode(int id)
	{
		Node* n = new Node();
		n->id = id;
		n->next = NULL;
		return n;
	}
public:
	Stack() :top(NULL){}
	void Push(int val)
	{
		Node* item;
		item = CreateNode(val);
		if (top == NULL)
		{
			top  = item;
		}
		else
		{
			item->next = top;
			top=item;
		}
	}
	int Pop()
	{
		int val=-1;
		Node* temp = top;
		if (IsEmpty())
		{
			cout<<"Stack empty\n";
		}
		else
		{
			temp = top;
			top = top->next;
			val = temp->id;
			delete temp;
		}
		return val;
	}
	int Peek()
	{
		int val=-1;
		if (IsEmpty())
		{
			cout<<"Stack is empty\n";
		}
		else
				val = top->id;
		return val;
	}
	bool IsEmpty()
	{
		return top == NULL;
	}
	void List()
	{
		Node* trav = top;
		if (IsEmpty())
		{
			cout<<"Nothing to display\n";
		}
		cout << "________________________\n";
		while(trav!=NULL)
		{
			cout << trav->id << '\n';
			trav = trav->next;
		}
		cout << "________________________\n";
	}
	char Menu()
	{
		char ch;
		cout << "P/p-->Push \n";
		cout << "O/o-->Pop  \n";
		cout << "K/k-->Peek \n";
		cout << "L/l-->List \n";
		cout << "e-->Exit \n";
		cout << "Plz enter your choice : ";
		cin >> ch;
		return ch;
	}
	~Stack()
	{
		while (!IsEmpty())
			Pop();
	}
};

int main()
{
	Stack stk;
	char ch;
	int val;
	while ((ch = stk.Menu()) != 'e')
	{
		
			switch (ch)
			{
			case 'P':
			case 'p':
			{
				cout << "Enter a positive value(id should be a whole number) : ";
				cin >> val;
				while (val < 0)
				{
					cout << "ID not possible..Enter valid id:";
					cin >> val;
				}
				stk.Push(val);
				break;
			}
			case 'O':
			case 'o':
			{
				val = stk.Pop();
				if(val!=-1)
				cout << "The poped element is " << val << '\n';
				break;
			}
			case 'K':
			case 'k':
			{
				val = stk.Peek();
				if(val!=-1)
				cout << "The  element at the top is " << val << '\n';
				break;
			}
			case 'L':
			case 'l':
			{
				stk.List();
				break;
			}
			default:
				cout << "Enter a proper choice \n";
			};
		}
		
	

	return 0;
}

