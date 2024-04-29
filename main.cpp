#include<iostream>
using namespace std;
template<class T>
class List
{
	struct Node
	{
		T data;
		Node* next;


		Node()
		{
			next = nullptr;
		}

		Node(T val, Node* nptr)
		{

			data = val;
			next = nptr;

		}
	};
public:
	Node* head;
	Node* tail;
	int size = 0;
public:
	class Iterator                // creating Iterator class
	{
		friend class List<T>;
		Node* curr;
		Iterator(Node* c)
		{
			curr = c;
		}
	public:
		Iterator()
		{
			curr = NULL;
		}
		T& operator*()
		{
			return curr->data;
		}
		Iterator& operator++()
		{
			curr = curr->next;
			return *this;
		}


		bool operator!=(const Iterator& it)
		{
			if (curr != it.curr)
			{
				return true;
			}
			else
				return false;
		}

		bool operator==(const Iterator& it)
		{
			if (curr == it.curr)
			{
				return true;
			}
			else
				return false;
		}

		Iterator& operator++(int)
		{
			Iterator old;
			old.curr = curr;
			curr = curr->next;
			return old;
		}




	};
	List()
	{
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->next = nullptr;
		size = 0;
	}


	List(List& obj)
	{
		// copy constructor
		if (obj.isempty() == false)
		{
			Node* temp = obj.head->next;

			while (temp != tail)
			{
				this->insert_at_end(temp->data);
				temp = temp->next;
			}

			this->size = obj.size;
		}
	}
	
	Iterator begin()  // for accessing node which is present next to dummy head
	{
		Iterator it;
		it.curr = head->next;
		return it;

	}
	Iterator end()  // for accessing tail
	{
		Iterator it(tail);
		return it;
	}

	void Insert(Iterator it, T d)  // for inserting in list
	{
		size++;
		Node* t = new Node;
		t->data = d;
		Node* temp = head;


		while (temp->next != it.curr)
		{

			temp = temp->next;
		}
		temp->next = t;
		t->next = it.curr;



	}

	Iterator Remove(Iterator it) // for removing from list
	{

		size--;
		Node* t = it.curr;

		Node* temp = head;
		while (temp->next != tail)
		{
			if (temp->next == t)
			{
				temp->next = t->next;
				break;
			}
			else
				temp = temp->next;
		}
		Iterator o(t->next);
		delete t;
		return o;
	}





	void insert_at_start(T d)
	{
		Insert(begin(), d);
	}
	void insert_at_end(T d)
	{
		Insert(end(), d);
	}
	void remove_at_start()
	{
		Remove(begin());
	}
	void remove_at_end()
	{
		Remove(end());
	}
	void print()
	{
		Node* temp = head->next;
		while (temp != tail)
		{
			cout << temp->data;
			temp = temp->next;
		}



	}
	int getsize()
	{
		return size;
	}

	bool isempty()
	{

		if (head->next = tail)
			return true;

		else
			return true;
	}

	Iterator gethead()
	{
		Iterator ite(this->head);
		return ite;
	}
	Iterator gettail()
	{
		Iterator ite(this->tail);
		return ite;
	}


};



class block {

private:
	int start_byte_ID;
	int total_bytes;

public:

	block()
	{
		start_byte_ID = 0;
		total_bytes = 0;
	}
	block(int start_byte_ID, int total_bytes)
	{
		this->start_byte_ID = start_byte_ID;
		this->total_bytes = total_bytes;
	}

	block(block& obj)  // copy constructor 
	{
		this->start_byte_ID = obj.start_byte_ID;
		this->total_bytes = obj.total_bytes;
	}
	int getstart_byte_ID()
	{
		return start_byte_ID;

	}

	int gettotal_bytes()
	{
		return total_bytes;
	}

	void setstart_id(int a)
	{
		start_byte_ID = a;

	}

	void setTotal_bytes(int a)
	{
		total_bytes = a;
	}



	friend ostream& operator<<(ostream& out, block p)
	{
		out << "Starting byte of block is " << p.getstart_byte_ID() << "  : Total bytes of  block is " << p.gettotal_bytes() << endl;
		cout << endl;


		return out;
	}
	~block()
	{

	}
};



class program {

private:

	string id;
	int Psize;
	List<block>Blocklist;

public:

	program()
	{
		id = '\0';
		Psize = 0;
	}


	//constructor
	program(string id, int size, block b)
	{
		this->id = id;
		addblock(size, b);
	}

	program(program& obj)
	{
		this->id = obj.id;
		this->Psize = obj.Psize;
		this->Blocklist = obj.Blocklist;
	}

	void addblock(int size, block& b) // adds block in List of a program 
	{
		Psize = getPsize() + size;
		Blocklist.insert_at_end(b);

	}


	block removeblock()
	{
		List<block>::Iterator obj;
		block b;
		obj = Blocklist.begin();
		b = *obj;

		Blocklist.remove_at_start();

		return b;
	}


	bool isEmpty()
	{
		if (Blocklist.begin() == Blocklist.end())
		{
			return true;
		}
		else
			return false;

	}
	string getId()
	{
		return id;
	}

	void setId(string a)
	{
		id = a;
	}
	int getPsize()
	{
		return Psize;
	}


	void setPsize(int a)
	{
		Psize = a;
	}
	friend ostream& operator<<(ostream& out, program p)
	{
		out << "Id of program is " << p.getId() << "   Total bytes of  program is " << p.getPsize() << endl;
		cout << endl;
		p.Blocklist.getsize();
		p.Blocklist.print();
		return out;
	}
	~program()
	{

	}
};

class MemoryManagementSystem
{
private:
	List<block>pool;

	List<program>progs;

	int RAM;

	bool Strategy;

public:

	MemoryManagementSystem(int size, bool  strategy)
	{
		RAM = size;
		Strategy = strategy;


		block b;
		b.setstart_id(0);
		b.setTotal_bytes(size);

		pool.insert_at_end(b);

		cout << endl;
	}



	void addinPOOL(int size)
	{
		block b;
		b.setstart_id(0);
		b.setTotal_bytes(size);

		pool.insert_at_end(b);
	}

	MemoryManagementSystem(MemoryManagementSystem const& obj)
	{
		this->pool = obj.pool;
		this->progs = obj.progs;
		this->RAM = obj.RAM;
		this->Strategy = obj.Strategy;
	}


	void setRAM(int a)
	{
		RAM = a;
		addinPOOL(RAM);
	}


	void SetStrategy(bool a)
	{
		Strategy = a;
	}
	void printProgs()
	{

		if (progs.begin() == progs.end())
		{
			cout << "No Programs currently in RAM \n" << endl;
		}
		else
			progs.print();
	}

	void printPool()
	{
		if (pool.begin() == pool.end())
		{
			cout << "Pool is empty \n" << endl;
			cout << endl;
		}
		else
		{
			pool.print();
		}
	}



	bool mergeBlocks(block b)
	{

		List<block>::Iterator obj;

		obj = pool.begin();

		block x;

		while (obj != pool.end())
		{
			x = *obj;



			if (x.getstart_byte_ID() + x.gettotal_bytes() == b.getstart_byte_ID())
			{
				x.setTotal_bytes(x.gettotal_bytes() + b.gettotal_bytes());
				*obj = x;
				return true;
				break;
			}
			else if (b.getstart_byte_ID() + b.gettotal_bytes() == x.getstart_byte_ID())
			{
				x.setTotal_bytes(x.gettotal_bytes() + b.gettotal_bytes());
				x.setstart_id(x.getstart_byte_ID() - b.gettotal_bytes());
				*obj = x;
				return true;
				break;
			}
			else
				++obj;
		}

		return false;

	}



	void mergePOOL()
	{

		List<block>::Iterator obj, obj1;

		obj = pool.begin();
		if (++pool.begin() == pool.end())
		{
			return;
		}
		else
			obj1 = ++pool.begin();
		block d;

		block p;

		;
		while (obj1 != pool.end())
		{

			d = *obj;
			p = *obj1;

			if (d.getstart_byte_ID() + d.gettotal_bytes() == p.getstart_byte_ID())
			{

				d.setTotal_bytes(d.gettotal_bytes() + p.gettotal_bytes());

				*obj = d;
				pool.Remove(obj1);




				break;

			}
			else if (p.getstart_byte_ID() + p.gettotal_bytes() == d.getstart_byte_ID())
			{

				p.setTotal_bytes(p.gettotal_bytes() + d.gettotal_bytes());
				p.setstart_id(p.getstart_byte_ID() - d.gettotal_bytes());
				*obj1 = p;
				pool.Remove(obj);


				break;
			}
			else
			{
				++obj;
				++obj1;
			}
		}
	}
	void insertSortedOrder(block b)
	{
		List<block>::Iterator obj;

		obj = pool.begin();
		block x;
	
		while (obj != pool.end())
		{
			x = *obj;
			if (b.getstart_byte_ID() < x.getstart_byte_ID())
			{
				pool.Insert(obj, b);
				return;
			}
			else
				++obj;
		}


		pool.insert_at_end(b);





	}
	
	bool deleteProgram(string id)
	{

		List<program>::Iterator obj1;



		List<block>::Iterator obj;
		block b;
		obj1 = progs.begin();
		program p;

		while (obj1 != progs.end())
		{
			p = *obj1;
			if (id == p.getId())
			{

				while (!p.isEmpty())
				{

					b = p.removeblock();


					if (mergeBlocks(b) == true)
					{


					}
					else
						insertSortedOrder(b);

				}

				progs.Remove(obj1);
				mergePOOL();
				return true;
			}
			else
				++obj1;
		}


		return false;

	}
	
	bool memory(string id, int size)
	{


		if (Strategy == 0)   // for First Fit
		{


			bool check = false;

			List<block>::Iterator Bobj;   // iterates on blocks of pool

			Bobj = pool.begin();


			if (pool.begin() == pool.end())
			{
				cout << "Your RAM has finished. Can not give any more Memory " << endl;
				return false;
			}
			block a;



			int s;

			while (Bobj != pool.end())   // for getting memory from block in pool
			{

				a = *Bobj;



				if (a.gettotal_bytes() == size)
				{
					s = a.getstart_byte_ID();

					/*cout << "start id full match " << s << endl;*/
					a.setTotal_bytes(a.gettotal_bytes() - size);
					a.setstart_id(a.getstart_byte_ID() + size);
					*Bobj = a;
					pool.Remove(Bobj);
					check = true;
					break;

				}
				else if (a.gettotal_bytes() > size)
				{
					s = a.getstart_byte_ID();

					/*cout << "start id " << s << endl;*/
					a.setTotal_bytes(a.gettotal_bytes() - size);
					a.setstart_id(a.getstart_byte_ID() + size);
					*Bobj = a;
					check = true;
					break;

				}



				++Bobj;

			}



			if (check == false)
			{
				cout << "Pool does not contain any block of this size " << endl;
				return false;
			}

			else {

				List<program>::Iterator obj1;


				obj1 = progs.begin();

				if (progs.begin() != progs.gettail())// checking if there is already any program present in list of programs
				{

					block b;
					program p;


					while (obj1 != progs.end())
					{

						block  c;
						program temp1;
						temp1 = *obj1;

						if (id == temp1.getId())// checks if program of same id aleady exists
						{

							c.setstart_id(s);
							c.setTotal_bytes(size);
							temp1.addblock(size, c); // if it exists then add the block to list of already present found program
							*obj1 = temp1;

							return true;
						}
						++obj1;
					}

					p.setId(id);  // otherwise creates a new program of the id sent and then add the block in its list of programs




					b.setstart_id(s);
					b.setTotal_bytes(size);

					p.addblock(size, b);
					progs.insert_at_end(p);
					*obj1 = p;


					++obj1;


					return true;
				}




				if (progs.begin() == progs.gettail())// checks if list of programs is empty
				{
					program temp;
					block b;

					temp = *obj1;

					temp.setId(id);



					b.setstart_id(s);
					b.setTotal_bytes(size);

					temp.addblock(size, b);
					*obj1 = temp;
					progs.insert_at_end(temp); // creates program then add block to it



					++obj1;
				}



				return true;


			}
		}



		else  if (Strategy == 1)  // best fit
		{



			List<block>::Iterator Bobj, Bobj1;

			Bobj = pool.begin();

			if (pool.begin() == pool.end())
			{
				cout << "Your RAM has finished. Can not give any more memory " << endl;
				return false;
			}
			int lsize = 1000;
			int tsize;
			block a;

			int s;

			block  c;
			int x = 0;

			bool check = false;

			int i = 0;

			int foundblock = i;

			if (Bobj != pool.end())// checks if there is block present in pool
			{

				while (Bobj != pool.end())
				{
					a = *Bobj;

					tsize = a.gettotal_bytes() - size; // saves the difference in size of first block and size sent by user

					i++;



					if (tsize == 0) // if differnce is zero then that bloxk is removed from pool
					{
						c.setstart_id(a.getstart_byte_ID());
						c.setTotal_bytes(a.gettotal_bytes());
						pool.Remove(Bobj);

						x = 1;
						check = true;
						break;


					}
					if (tsize > 0 && tsize < lsize) // if the differnce of block with size is less than the differnce we calcualtd for forst block than update the least difference variable
					{

						lsize = tsize;
						foundblock = i;

						c.setstart_id(a.getstart_byte_ID());
						c.setTotal_bytes(size);
						check = true;
						++Bobj;
					}

					else
						++Bobj;


				}
			}

			if (check == false)
			{
				cout << "Pool does not contain any block of this size " << endl;
				return false;
			}

			else {
				{
					if (x != 1) // if we did not found a block of exact size in pool and did not remove it  we go in this IF and remove block from pool of the size required

					{
						block b;
						Bobj1 = pool.begin();
						b = *Bobj1;


						int j = 1;


						while (j != foundblock)// found block is the variable which tells us at which block no in list we found the block for least difference in its size and size sent by user
						{
							++Bobj1;
							b = *Bobj1;
							j++;
						}



						s = b.getstart_byte_ID();  // updating the block which is used to get memeory for program
						b.setstart_id(b.getstart_byte_ID() + size);
						b.setTotal_bytes(b.gettotal_bytes() - size);
						*Bobj1 = b;
					}





					List<program>::Iterator obj;
					obj = progs.begin();




					if (obj == progs.end())// tells us list of progs was empty
					{
						block b;
						program temp1;
						temp1.setId(id);

						temp1.addblock(size, c);

						*obj = temp1;

						progs.insert_at_end(temp1);
						++obj;
						return true;
					}
					while (obj != progs.end())
					{
						program temp;
						block b;
						temp = *obj;

						if (id == temp.getId())// if id matches then add in the list of already present
						{

							temp.addblock(size, c);

							*obj = temp;
							++obj;
							return true;


						}
						else
							++obj;
					}

					block t;  // if we dont find program of id send we create a new program assign sent id to it and insert it in end of programs list
					program p;

					p.setId(id);

					p.addblock(size, c);
					*obj = p;
					progs.insert_at_end(p);
					++obj;

					return true;



				}
			}

		}
		return false;

	}



};


int main()
{




	cout << "Welcome to Memory Management System \n " << endl;
	cout << endl;
	int a;
	bool p;
	cout << "How much RAM would you like to give to your Management System \n " << endl;
	cin >> a;

	cout << endl;

	cout << "Which Strategy would you like to choose \n " << endl;
	cout << endl;
	cout << "Press 0  for FIRST FIT \n" << endl;
	cout << "Press 1 for BEST FIT \n" << endl;
	cin >> p;


	MemoryManagementSystem s(a, p);

	int choice;

	bool run = true;

	while (run)
	{
		do {


			cout << "Press 1 to Assign memory to a program \n" << endl;

			cout << "Press 2 if you want to delete a Program \n" << endl;

			cout << "Press 3 to print List of Programs \n" << endl;
			cout << "Press 4 to Print pool \n" << endl;



			cout << "If you want to exit press 5 \n" << endl;


			cin >> choice;
		} while (choice < 1 || choice > 5);






		if (choice == 1)
		{
			string name;
			int size;
			cout << "Enter the id of program \n" << endl;
			cin >> name;

			do {
				cout << "Enter the size you want to allocate to program \n" << endl;
				cin >> size;
			} while (size <= 0);



			if (!s.memory(name, size))
			{


				cout << "Enter size again \n" << endl;
				cin >> size;
				if (s.memory(name, size))
					cout << "Memory Successfull allocated \n" << endl;


			}
			else {

				cout << "Memory Successfull allocated \n" << endl;
			}



		}



		if (choice == 3)
		{
			s.printProgs();
			cout << "\n" << endl;

		}

		if (choice == 4)
		{
			s.printPool();
			cout << "\n" << endl;
		}

		if (choice == 2)
		{
			string a;
			cout << "Enter the id of program you want to delete \n" << endl;
			cin >> a;
			if (s.deleteProgram(a))
			{

				cout << "Program with ID " << a << " has been deleted from RAM \n" << endl;
				s.mergePOOL();
			}
			else
			{
				cout << "Program with ID " << a << " did not exist in RAM \n" << endl;
			}
		}

		if (choice == 5)
		{
			cout << "HAPPY CODING \n";
			cout << "GOOD BYE \n" << endl;
			run = false;
		}
	}




}