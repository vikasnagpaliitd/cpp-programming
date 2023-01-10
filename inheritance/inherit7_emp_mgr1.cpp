#include <iostream>
using namespace std;

class Employee
{
    protected:
	int id;
	string name;

	public:

	Employee(int id, string name)
	{
		this->id = id;
		this->name = name;
	}

	void display()
	{
		cout << "id = " << id << endl;
		cout << "name = " << name << endl;
	}
};


class Manager : public Employee
{
	private:
	string dept;

	public:
	Manager(int id, string name, string dept): Employee(id, name)
	{
		this->dept = dept;
	}

	void display()
	{
		//cout << "id = " << id << endl;
		//cout << "name = " << name << endl;
		this->Employee::display(); // Note: Calling parent's class function with the same name
		cout << "dept = " << dept << endl;
	}
};


int main()
{
	Manager   m1(100, "Mohan", "Engg");
	m1.display();
	return 0;
}
