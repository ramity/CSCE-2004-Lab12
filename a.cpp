#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
   Student();
   Student(const Student & student);
   ~Student();

   void set(const int uaid, const string name, const double gpa);
   void get(int & uaid, string & name, double & gpa) const;
   void print() const;
   void read();

private:
   int mUaid;
   string mName;
   double mGpa;
};

Student::Student()
{
   cout << "Constructor" << endl;
   mUaid = 0;
   mName = "none";
   mGpa  = 0.0;
}

Student::Student(const Student & student)
{
   cout << "Copy constructor" << endl;
   mUaid = student.mUaid;
   mName = student.mName;
   mGpa  = student.mGpa;
}

Student::~Student()
{
   cout << "Destructor" << endl;
}

void Student::set(const int uaid, const string name, const double gpa)
{
   cout << "Set" << endl;
   mUaid = uaid;
   mName = name;

   if(gpa < 0)
      mGpa = 0.0;
   if(gpa > 4.0)
      mGpa = 4.0;
}

void Student::get(int & uaid, string & name, double & gpa) const
{
   cout << "Get" << endl;
   uaid = mUaid;
   name = mName;
   gpa  = mGpa;
}

void Student::print() const
{
   cout << "Print" << endl;
   cout << mUaid << " " << mName << " " << mGpa << endl;
}

void Student::read()
{
   cout << "Read" << endl;
   cin >> mUaid >> mName >> mGpa;

   if(mGpa < 0)
      mGpa = 0.0;
   if(mGpa > 4.0)
      mGpa = 4.0;
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.set(1234, "John", 2.5);
   student1.print();

   Student student2(student1);
   student2.print();

   student2.set(2345, "Susan", 3.9);
   student2.print();

   Student student3;
   student3.read();
   student3.print();

   return 0;
}
