#include <iostream>
#include <cstdlib>

class Person
{
public:
	Person(std::string name_, std::size_t age_)
	{
		std::cout << "Person created" << std::endl;
		name = name_;
		age = age_;
	}
	Person(const Person &other)
	{
		std::cout << "Person created" << std::endl;
		name = other.name;
		age = other.age;
	}
	~Person()
	{
		std::cout << "Person deleted" << std::endl;
	}

	void show() const
	{
		std::cout << "Name: " << name << "\t" << "Age: " << age << std::endl;
	}

protected:
	std::string name;
	std::size_t age;
};

class Employee : private Person 
{
public:
	Employee(std::string name_, std::size_t age_): Person(name_, age_)
	{
		std::cout << "Employee created" << std::endl;
	}
	Employee(std::string name_, std::size_t age_, std::string company_): Person(name_, age_)
	{
		std::cout << "Employee created" << std::endl;
		company = company_;
	}
	Employee(const Employee &other): Person(other)
	{
		std::cout << "Employee created" << std::endl;
		company = other.company;
	}
	~Employee()
	{
		std::cout << "Employee deleted" << std::endl;
	}
	void new_show() const 
	{
		Person::show();
		std::cout << "Company: " << company << std::endl;
	}
	using Person::show;

private:
	std::string company;
};

int main(void)
{
	Employee p("Artem", 24, "Sber");
	p.show();
}
