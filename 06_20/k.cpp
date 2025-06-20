#include <iostream>
#include <cstdlib>

class Person
{
public:
	Person(std::string name_, std::size_t age_)
	{
		name = name_;
		age = age_;
	}
	virtual ~Person()
	{
		std::cout << "Person deleted" << std::endl;
	}

	virtual void show() const = 0;

protected:
	std::string name;
	std::size_t age;
};

class Employee : public Person 
{
public:
	Employee(std::string name_, std::size_t age_, std::string company_): Person(name_, age_)
	{
		company = company_;
	}

	Employee &operator=(const Employee &other)
	{
		name = other.name;
		age = other.age;
		company = other.company;
		return *this;
	}

	~Employee()
	{
		std::cout << "Employee deleted" << std::endl;
	}
	void show() const
	{
		std::cout << "Name: " << name << "\t" << "Age: " << age << std::endl;
		std::cout << "Company:" << company << std::endl;
	}

private:
	std::string company;
};

class UnEmployee : public Person
{
public:
	UnEmployee(std::string name_, std::size_t age_, std::size_t ages_unemployee_): Person(name_, age_)
	{
		ages_unemployee = ages_unemployee_;
	}

	UnEmployee &operator=(const UnEmployee &other)
	{
		name = other.name;
		age = other.age;
		ages_unemployee = other.ages_unemployee;
		return *this;
	}

	void show() const
	{
		std::cout << "Name: " << name << "\t" << "Age: " << age << std::endl;
		std::cout << "Ages unemployee:" << ages_unemployee << std::endl;
	}

	~UnEmployee()
	{
		std::cout << "UnEmployee deleted" << std::endl;
	}
private:
	std::size_t ages_unemployee;

};

class University
{
public:
	Employee create_employee(std::string name_, std::size_t age_, std::string company_)
	{
		Employee e(name_, age_, company_);
		return e;
	}

	UnEmployee create_unemployee(std::string name_, std::size_t age_, std::size_t ages_unemployee_)
	{
		UnEmployee e(name_, age_, ages_unemployee_);
		return e;
	}
};

#define N 10

int main(void)
{
	University u;
	Person **p;
	
	p = new Person*[N];

	for (int i = 0; i < N / 2; i++)
	{
		p[2 * i] = new Employee("Ann", 16 + i, "Yandex");
	}

	for (int i = 0; i < N / 2; i++)
	{
		p[2 * i + 1] = new UnEmployee("Artem", 24 + i, i * 2);
	}

	for (int i = 0; i < N; i++)
	{
		p[i]->show();
		delete p[i];
	}
	delete[] p;
}
