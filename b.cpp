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
   mUaid = 0;
   mName = "none";
   mGpa  = 0.0;
}

Student::Student(const Student & student)
{
   mUaid = student.mUaid;
   mName = student.mName;
   mGpa  = student.mGpa;
}

Student::~Student()
{
}

void Student::set(const int uaid, const string name, const double gpa)
{
   mUaid = uaid;
   mName = name;
   mGpa  = gpa;
   if (mGpa < 0.0)      mGpa = 0.0;
   else if (mGpa > 4.0) mGpa = 4.0;
}

void Student::get(int &uaid, string & name, double &gpa) const
{
   uaid = mUaid;
   name = mName;
   gpa  = mGpa;
}

void Student::print() const
{
   cout << mUaid << " " << mName << " " << mGpa << endl;
}

void Student::read()
{
   cin >> mUaid >> mName >> mGpa;
   if (mGpa < 0.0)      mGpa = 0.0;
   else if (mGpa > 4.0) mGpa = 4.0;
}

class Course
{
public:
   Course(const int count=0);
   Course(const Course & course);
   ~Course();

   void print() const;
   void read();

private:
   static const int MAX_STUDENTS = 100;
   Student mStudents[MAX_STUDENTS];
   int mNumStudents;
};

//Step 4
void Course::print() const
{
   cout << "Print" << endl;
   for (int index = 0; index < mNumStudents; index++)
   {
      mStudents[index].print();
      // Do some work
   }
}

void Course::read()
{
   cout << "Read" << endl;
   for (int index = 0; index < mNumStudents; index++)
   {
      mStudents[index].read();
      // Do some work
   }
}

Course::Course(const int count)
{
   cout << "Constructor" << endl;
   mNumStudents = count;
}

Course::Course(const Course & course)
{
   mNumStudents = course.mNumStudents;

   cout << "Copy constructor" << endl;
   for (int index = 0; index < mNumStudents; index++)
   {
      mStudents[index] = course.mStudents[index];
      // Do some work
   }
}

Course::~Course()
{
   cout << "Destructor" << endl;
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.set(1234, "John", 2.5);
   student1.print();

   //Step 3
   cout << "Testing Course class\n";
   Course course(5);
   course.print();

   course.read();
   course.print();

   return 0;
}
