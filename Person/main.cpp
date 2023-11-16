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
        cin.ignore();//”·Ë‚‡ÂÚ ÏÛÒÓ ‚ ·ÛÙÂÂ
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


    void Input(const char* Univer)//«¿Ã≈Ÿ≈Õ»≈(” ÔÂ‰Í‡ ·˚ÎÓ ·ÂÁ Ô‡‡ÏÂÚÓ‚ ËÌÔÛÚ)
    {
        delete[] University;
        University = new char[strlen(Univer) + 1];
        strcpy_s(University, strlen(Univer) + 1, Univer);
        Person::Input();//¬≤«Œ¬ »Õœ”“ œ–≈ƒ ¿
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

    void Print()//œ≈–≈Œœ–≈ƒ≈À≈Õ»≈
    {
        cout << "Teacher: name=" << name << ", age=" << age << ", school=" << school << ", salary=" << salary << ", subjects=[";
        for (int i = 0; i < subjectsCount; i++) {
            if (i > 0) cout << ", ";
            cout << subjects[i];
        }
        cout << ']';
    }

    void Input( string school, double salary, initializer_list<string> subs)//«¿Ã≈Ÿ≈Õ»≈(” ÔÂ‰Í‡ ·˚ÎÓ ·ÂÁ Ô‡‡ÏÂÚÓ‚ ËÌÔÛÚ)
    {
        this->school = school;
        this->salary = salary;
        fillSubjects(subs);
        Person::Input();//¬≤«Œ¬ »Õœ”“ œ–≈ƒ ¿
    }




    string GetSchool() {
        return school;
    }
    double GetSalary() {
        return salary;
     }
    string* GetSubjcts()
    {
        return subjects;
    }
    
    void SetSubjcts(initializer_list<string> subs)
    {
        fillSubjects(subs);
    }
    void SetSchool(string school)
    {
       this-> school = school;
    }
    void SetSalary(double salary)
    {
        this->salary = salary;
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









class Driver : public Person
{
    string carNumber;
    string carSeries;
    string driverLicense;
public:


    Driver() = default;
    Driver(const char* n, int a, string carNumber, string carSeries, string driverLicense) : Person(n, a)
    {
        this->carNumber = carNumber;
        this->carSeries = carSeries;
        this->driverLicense = driverLicense;
    }

    void Print()
    {
        cout << "Driver name:" << name << ",age: " << age<<" carNumber: " << carNumber <<" ,carSeries: " << carSeries <<" ,driverLicense: " << driverLicense << endl;

    }

    void Input(string carNumber, string carSeries, string driverLicense)//«¿Ã≈Ÿ≈Õ»≈(” ÔÂ‰Í‡ ·˚ÎÓ ·ÂÁ Ô‡‡ÏÂÚÓ‚ ËÌÔÛÚ)
    {

       
        this->carNumber = carNumber;
        this->carSeries = carSeries;
        this->driverLicense = driverLicense;
        Person::Input();//¬≤«Œ¬ »Õœ”“ œ–≈ƒ ¿
    }
    

    string GetcarNumber() const
    {
        return carNumber;
    }

    void SetcarNumber(string carNumber)
    {
        this->carNumber = carNumber;
    }

    string GetcarSeries() const
    {
        return carSeries;
    }

    void SetcarSeries(string carSeries)
    {
        this->carSeries = carSeries;
    }

    string GetdriverLicense() const
    {
        return driverLicense;
    }

    void SetdriverLicense(string driverLicense)
    {
        this->driverLicense = driverLicense;
    }
};



class Doct : public Person
{
    string spec;
    int yearsExp;
    bool famalyDoctor;
public:


    Doct() = default;
    Doct(const char* n, int a, string spec, int yearsExp, bool famalyDoctor) : Person(n, a)
    {
        this->spec = spec;
        this->yearsExp = yearsExp;
        this->famalyDoctor = famalyDoctor;
    }

    void Print()//œ≈–≈Œœ–≈ƒ≈À≈Õ»≈
    {
       
        cout << "Doctor name:" <<name<<",age: "<<age << ",spec: " << spec << ", yearsExp : " << yearsExp << ", famalyDoctor : " << famalyDoctor << endl;

    }

    void Input(string spec, int yearsExp, bool famalyDoctor)//«¿Ã≈Ÿ≈Õ»≈(” ÔÂ‰Í‡ ·˚ÎÓ ·ÂÁ Ô‡‡ÏÂÚÓ‚ ËÌÔÛÚ)
    {

        this->spec = spec;
        this->yearsExp = yearsExp;
        this->famalyDoctor = famalyDoctor;
        Person::Input();//¬≤«Œ¬ »Õœ”“ œ–≈ƒ ¿
    }


    string Getspec() const
    {
        return spec;
    }

    void Setspec(string spec)
    {
        this->spec = spec;
    }

    int GetyearsExp() const
    {
        return yearsExp;
    }

    void SetyearsExp(int yearsExp)
    {
        this->yearsExp = yearsExp;
    }

    bool GetfamalyDoctor() const
    {
        return famalyDoctor;
    }

    void SetdriverLicense(bool famalyDoctor)
    {
        this->famalyDoctor = famalyDoctor;
    }
};


int main()
{

    Teacher mask("Ilona Mask", 52, "Wharton School", 100500, { "Politics","Rusomania","Computer Science" });
    mask.Print();

    Driver driver("Ilona Mask",52, "1012", "AI", "10120488");
    driver.Print();

    Doct doctor("Ilona Mask", 52, "Genicology", 10, true);
    doctor.Print();

  
    Doct doc;
    doc.Input( "Genicology", 10, true);
    doc.Print();


    Driver d;
    d.Input( "1012", "AI", "10120488");
    d.Print();
}