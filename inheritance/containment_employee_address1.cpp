// Demonstrates: Class Employee contains (has-a) Address
#include <iostream>
using namespace std;

class Address 
{
     private:
     string street_addr;
     string city;
     string state;

     public:
          Address(string street_addr, string city, string state)
          {
               cout << "Address Constructor" << endl;
               this->street_addr = street_addr;
               this->city = city;
               this->state = state;
          }

          string getAddress()
          {
              string add;
              add = street_addr + ", " + city + ", " + state;
              return add;
          }

     //friend class Employee; //Sometimes useful. in general, to avoid
};

class Employee 
{
     private:
     //Each Employee has an Address, representing has-a relationship. 
     int id;
     string name;
     Address address; //creating object of Address class inside employee class

     public:
          Employee(int id, string name, string street_addr, string city, string state) : address(street_addr, city, state)
          //Employee(int id, string name, string street_addr, string city, string state) // Ques: will it compile?
          {
               // Ques: what is the order of constructor calls?
               // Ques: Can we set values in address here, instead of member initialization list?
               cout << "Employee Constructor" << endl;
               this->id = id;
               this->name = name;
          }

          void display()
          {
              cout << id <<"\t";
              cout << name <<"\t";
              cout << address.getAddress() <<"\t";

              // cout << address.state << "\t"; // just to experiment accessing private data, being a friend class
              cout << endl;
          }
};

int main(void) 
{
     int id;
     string name, homeAddress, city, state;

     cout << "Please Enter Employee Id\n";
     cin >> id;

     cin.ignore();

     cout << "Please Enter Employee Name : ";
     getline(cin,name);

     cout << "Please Enter Home Address :";
     getline(cin, homeAddress);

     cout << "Please Enter City : ";
     getline(cin, city);

     cout << "Please Enter State : ";
     getline(cin, state);

     
     Employee emp = Employee(id, name, homeAddress, city, state);
     emp.display();
     return 0;
}
