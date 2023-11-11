#include<iostream>
using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) :age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		//cout << "Person Constructor\n";
	}
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << "\t";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter Name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
	~Person()
	{
		delete[]name;
		//cout << "Person Destructor\n";
	}

    const char* GetName() const
    {
        return name;
    }

    void SetName(const char* n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    int GetAge() const
    {
        return age;
    }

    void SetAge(int a)
    {
        age = a;
    }
};



class Student : public Person
{
    char* University;
public:
    Student() = default;
    Student(const char* n, int a, const char* Univer) : Person(n, a)
    {
        University = new char[strlen(Univer) + 1];
        strcpy_s(University, strlen(Univer) + 1, Univer);
    }


    void Input(const char* Univer)//ÇÀÌÅÙÅÍÈÅ(Ó ïğåäêà áûëî áåç ïàğàìåòğîâ èíïóò)
    {
        delete[] University;
        University = new char[strlen(Univer) + 1];
        strcpy_s(University, strlen(Univer) + 1, Univer);
        Person::Input();//Â²ÇÎÂ ÈÍÏÓÒ ÏĞÅÄÊÀ
    }

    void Print()
    {
        Person::Print();
        cout << "University: " << University << endl;
    }

    ~Student()
    {
        delete[] University;
    }

    const char* GetUniversity() const
    {
        return University;
    }

    void SetUniversity(const char* Univer)
    {
        delete[] University;
        University = new char[strlen(Univer) + 1];
        strcpy_s(University, strlen(Univer) + 1, Univer);
    }

};


class Teacher : public Person
{
    
    string school;
    double salary;
    int subjectsCount = 0;
    string subjects[5];

public:
    Teacher() = default;
    Teacher(const char* name, int age, string school, double salary, initializer_list<string> subs)
        : Person(name, age), school(school), salary(salary)
    {
        fillSubjects(subs);
    }

    void Print()//ÏÅĞÅÎÏĞÅÄÅËÅÍÈÅ
    {
        cout << "Teacher: name=" << name << ", age=" << age << ", school=" << school << ", salary=" << salary << ", subjects=[";
        for (int i = 0; i < subjectsCount; i++) {
            if (i > 0) cout << ", ";
            cout << subjects[i];
        }
        cout << ']';
    }

    void Input( string school, double salary, initializer_list<string> subs)//ÇÀÌÅÙÅÍÈÅ(Ó ïğåäêà áûëî áåç ïàğàìåòğîâ èíïóò)
    {
        this->school = school;
        this->salary = salary;
        fillSubjects(subs);
        Person::Input();//Â²ÇÎÂ ÈÍÏÓÒ ÏĞÅÄÊÀ
    }

protected:
    void fillSubjects(initializer_list<string> subs) {
        int i = 0;
        for (const string* s = subs.begin(); s != subs.end(); s++) {
            subjects[i] = *s;
            i++;
        }
        subjectsCount = i;
    }

};



int main()
{

    Teacher mask("Ilona Mask", 52, "Wharton School", 100500, { "Politics","Rusomania","Computer Science" });
    mask.Print();

    //Teacher t;
    //t.Input("Wharton School", 100500, { "Politics","Rusomania","Computer Science" });
    //t.Print();

}