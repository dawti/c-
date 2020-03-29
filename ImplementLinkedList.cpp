#include<iostream>
#include<string>
using namespace std;

struct Student
{
		int id;
		string name;
		Student* next;
};

class LinkedList
{
		Student* head;
		Student* tail;
		Student* CreateNode(int id, string name)
		{
			Student* temp = new Student();
			temp->id = id;
			temp->name = name;
			temp->next = NULL;
			return temp;
		}
	public:
		LinkedList() :head(NULL), tail(NULL)
		{
		}
		void Append(int id, string name)
		{
			Student* stud = CreateNode(id, name);
			if (head == NULL)
			{
				head = stud;
			}
			else
			{
				tail->next = stud;
			}
			tail = stud;
		}
		void Prepend(int id, string name)
		{
			if (head == NULL)
			{
				Append(id, name);
			}
			else
			{
				Student* stud = CreateNode(id, name);
				stud->next = head;
				head = stud;
			}

		}
		void DeleteFirst()
		{
			Student* temp;
			if (head == NULL)
			{
				cout << "Nothing to delete";
			}
			else
			{
				temp = head;
				head = head->next;
				delete temp;
			}

		}
		void DeleteLast()
		{
			Student* temp = head, * trav = head;
			if (head == NULL)
			{
				cout << "No element to delete\n";
			}
			else if (head == tail)
			{
				delete head;
				head = NULL;
			}
			else
			{
				while (trav->next != NULL)
				{
					temp = trav;
					trav = trav->next;
				}
				temp->next = NULL;
				tail = temp;
				delete trav;
			}

		}
		void DeleteByPosition(int pos)
		{
			Student* trav = head;
			Student* temp = trav;
			Student* t = head;
			int count = 1;
			while ((head != NULL) && (t->next != NULL))
			{
				t = t->next;
				count++;
			}

			if ((pos == 1) && (head != NULL))
			{
				DeleteFirst();
			}
			else if ((pos > 1) && (pos < count))
			{
				for (int i = 1; i < pos; i++)
				{
					temp = trav;
					trav = trav->next;
				}
				temp->next = trav->next;
				delete trav;
			}
			else if (pos == count)
			{
				DeleteLast();
			}
			else
				cout << "Not possible....ENTER A VALID POSITION\n";
		}
		void DeleteByValue(int id)
		{
			Student* temp = head, * trav = head;
			while ((trav->id != id) && (trav->next != NULL))
			{
				temp = trav;
				trav = trav->next;
			}
			if (head->id == id)
			{
				DeleteFirst();
			}
			else if (trav->id == id)
			{
				temp->next = trav->next;
				delete trav;
			}
			else
			{
				cout << "Id not found\n";
			}
		}
		void InsertByPosition(int pos, int id, string name)
		{
			Student* stud;
			Student* temp = tail, * trav = head;//check value of temp
			int i;
			if (head == NULL)
			{
				Prepend(id, name);
				cout << "Inserted at beginning \n";
				return;
			}
			for (i = 0; i < pos - 1 && trav->next != NULL; i++)
			{
				temp = trav;//position before insert 
				trav = trav->next;//position to insert
			}
			if (pos == 1)
			{
				stud = CreateNode(id, name);
				stud->next = head;
				head = stud;
			}
			else if (i != pos - 1)
			{
				Append(id, name);
			}
			else
			{
				stud = CreateNode(id, name);
				stud->next = trav;
				temp->next = stud;
			}
		}
		void InsertAfter(int criteriaId, int id, string name)
		{
			Student* trav = head;
			while (trav->id != criteriaId && trav->next != NULL)
			{
				trav = trav->next;
			}
			if (trav->id == criteriaId)
			{
				Student* stud = CreateNode(id, name);
				stud->next = trav->next;
				trav->next = stud;
			}
			else
				cout << "Id not found\n";

		}
		void InsertBefore(int criteriaId, int id, string name)
		{
			Student* temp = head, * trav = head;
			if (trav->id == criteriaId)
			{
				Prepend(id, name);
				return;
			}
			while (trav->id != criteriaId && trav->next != NULL)
			{
				temp = trav;
				trav = trav->next;
			}
			if (trav->id == criteriaId)
			{
				Student* stud = CreateNode(id, name);
				stud->next = trav;
				temp->next = stud;
			}
			else
				cout << "Id not found\n";
		}
		void List()
		{
			cout << "_________List Of Students_________________\n\n";
			Student* trav = head;
			while (trav != NULL)
			{
				cout << trav->id << '\t' << trav->name << '\n';
				trav = trav->next;
			}
			cout << "__________________________\n";
		}
		char Menu()
		{
			char ch;
			cout << "P/p-->Prepend \n";
			cout << "A/a-->Append  \n";
			cout << "D/d-->Delete first \n";
			cout << "T/t-->Delete last \n";
			cout << "S/s-->Delete by Position \n";
			cout << "V/v-->Delete by value\n";
			cout << "I/i-->Insert by position\n";
			cout << "F/f-->Insert after\n";
			cout << "B/b-->Insert  before\n";
			cout << "L/l-->List \n";
			cout << "e-->Exit \n";
			cout << "Plz enter your choice : ";
			cin >> ch;
			return ch;
		}
		~LinkedList()
		{
		}
};


int main()
{
	        LinkedList lkd;

		char ch;
		int val;
		string name;
		int criteria;//for entering position
		while ((ch = lkd.Menu()) != 'e')
		{

			switch (ch)
			{
			case 'P':
			case 'p':
			{
				cout << "Enter id: ";
				cin >> val;
				cout << "Enter name:";
				cin >> name;
				lkd.Prepend(val, name);
				break;
			}
			case 'A':
			case 'a':
			{
				cout << "Enter id: ";
				cin >> val;
				cout << "Enter name:";
				cin >> name;
				lkd.Append(val, name);
				break;
			}
			case 'D':
			case 'd':
			{
				lkd.DeleteFirst();
				//cout << "The  element deleted " <<  << '\n';
				break;
			}
			case 'T':
			case 't':
			{
				lkd.DeleteLast();
				//cout << "The  element deleted " <<  << '\n';
				break;
			}
			case 'S':
			case 's':
			{
				cout << "Enter position to be deleted: ";
				cin >> criteria;
				lkd.DeleteByPosition(criteria);
				break;
			}
			case 'V':
			case 'v':
			{
				cout << "Enter id of object to be deleted: ";
				cin >> val;
				lkd.DeleteByValue(val);
				break;
			}
			case 'L':
			case 'l':
			{
				lkd.List();
				break;
			}
			case 'I':
			case 'i':
			{
				cout << "Enter id: ";
				cin >> val;
				cout << "Enter name:";
				cin >> name;
				cout << "Enter position:";
				cin >> criteria;
				lkd.InsertByPosition(criteria, val, name);
				break;
			}
			case 'F':
			case 'f':
			{
				cout << "Enter id: ";
				cin >> val;
				cout << "Enter name:";
				cin >> name;
				cout << "Enter criteria id:";
				cin >> criteria;
				lkd.InsertAfter(criteria, val, name);
				break;
			}
			case 'B':
			case 'b':
			{
				cout << "Enter id: ";
				cin >> val;
				cout << "Enter name:";
				cin >> name;
				cout << "Enter Criteria id:";
				cin >> criteria;
				lkd.InsertBefore(criteria, val, name);
				break;
			}
			default:
				cout << "Enter a proper choice \n";
			};

		}
		return 0;
}
