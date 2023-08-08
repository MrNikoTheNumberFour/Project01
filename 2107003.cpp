#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
private:
    string name;
    int age;
    int rollNo;

public:
    Student(string n, int a, int r) : name(n),age(a), rollNo(r) {}
    string getName() { return name; }
    int getAge() { return age; }
    int getRollNo() { return rollNo; }
};
class Teacher
{
private:
    string name;
    int age;
    string subject;

public:
    Teacher(string n, int a, string s) : name(n),age(a), subject(s) {}
    string getName() { return name; }
    int getAge() { return age; }
    string getSubject() { return subject; }
};
class ClassTest
{
private:
    string testName;
    vector<int> marks;

public:
    ClassTest(string tn) : testName(tn) {}
    void addMarks(int m)
    {
        marks.push_back(m);
    }
    string getTestName() { return testName; }
    vector<int> getMarks() { return marks; }
};
class Class
{
private:
    string className;
    vector<Student> students;
    Teacher teacher; //teacher object
    vector<ClassTest> tests;

public:
    Class(string cn, Teacher t) : className(cn), teacher(t) {} //Class constructor er vitore Teacher constructor call krtesi
    void addStudent(Student s)
    {
        students.push_back(s); //pushback to vector's last element
    }
    void addClassTest(ClassTest t)
    {
        tests.push_back(t);
    }
    void displayStudents()
    {
        cout << "Students in Class " << className << ":" << endl;
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Name: " << students[i].getName() << endl;
            cout << "Age: " << students[i].getAge() << endl;
            cout << "Roll No: " << students[i].getRollNo() << endl;
        }
    }
    void displayTeacher()
    {
        cout << "Teacher in Class " << className << ":" << endl;
        cout << "Name: " << teacher.getName() << endl;
        cout << "Age: " << teacher.getAge() << endl;
        cout << "Subject: " << teacher.getSubject() << endl;
    }
    void displayTests()
    {
        cout << "Tests in Class " << className << ":" << endl;
        for (int i = 0; i < tests.size(); i++)
        {
            cout << "Test Name: " << tests[i].getTestName() << endl;
            cout << "Marks: ";
            vector<int> marks = tests[i].getMarks();
            for (int j = 0; j < marks.size(); j++)
            {
                cout << marks[j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    // Input class schedule
    string className, teacherName, teacherSubject, studentName;
    int teacherAge, studentAge, rollNo, numTests;
    cout << "Enter class name: ";
    getline(cin, className); //input stream, string name
    cout << "Enter teacher name: ";
    getline(cin, teacherName);
    cout << "Enter teacher age: ";
    cin >> teacherAge;
    cout << "Enter teacher subject: ";
    cin.ignore(); //ignore the unwanted buffer
    getline(cin, teacherSubject);
    Teacher teacher(teacherName, teacherAge, teacherSubject);
    Class myClass(className, teacher);
    cout << "Enter number of students: ";
    int numStudents;
    cin >> numStudents;
    for (int i = 1; i <= numStudents; i++)
    {
        cout << "Enter name of student #" << i << ": ";
        cin.ignore();
        getline(cin, studentName);

        cout << "Enter age of student #" << i << ": ";
        cin >> studentAge;

        cout << "Enter roll no of student #" << i << ": ";
        cin >> rollNo;

        Student student(studentName, studentAge, rollNo);

        myClass.addStudent(student);  //
    }
    // Input class test marks
    cout << "Enter number of tests: ";
    cin >> numTests;
    for (int i = 1; i <= numTests; i++)
    {
        cout << "Enter name of test #" << i << ": ";
        string testName;
        cin.ignore();
        getline(cin, testName);
        ClassTest test(testName);
        for (int j = 0; j < numStudents; j++)
        {
            int marks;
            cout << "Enter marks for student #" << j + 1 << " in test #" << i << ": ";
            cin >> marks;
            test.addMarks(marks);
        }
        myClass.addClassTest(test);
    }
    // Provide information based on user requirements
    while (true)
    {
        int choice;
        cout << "\n\n";
        cout << "--------------------------------------------------------\n";
        cout << "|\t\t\tMENU\t\t\t |\n";
        cout << "--------------------------------------------------------\n";
        cout << "What information do you want to see?" << endl;
        cout << "1. Students in class" << endl;
        cout << "2. Teacher in class" << endl;
        cout << "3. Tests in class" << endl;
        cout << "4. Exit" << endl;
        cout << "--------------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            myClass.displayStudents();
            break;
        case 2:
            myClass.displayTeacher();
            break;
        case 3:
            myClass.displayTests();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
