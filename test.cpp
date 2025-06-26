#include <iostream>
#include <utility>
#include <vector>

//lvalue rvalue

class LogDuration
{
public:
	LogDuration(std::string id_) : id(id_), start_time(std::chrono::steady_clock::now()){}

	~LogDuration()
	{
		const auto end_time = std::chrono::steady_clock::now();
		const auto duration = end_time - start_time;
		const auto time = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
		std::cout << id << ": ";
		std::cout << time.count() << " ms" << std::endl;
	}

private:
	std::string id;
	const std::chrono::steady_clock::time_point start_time;
};

class Vector
{
public:
	Vector(size_t size, int value) : data(size, value){}
	Vector(const Vector &other)
	{
		std::cout << "Copy constructor" << std::endl;
	}
	Vector(Vector &&other)
	{
		std::cout << "Move constructor" << std::endl;
	}
	size_t size()
	{
		return data.size();
	}

private:
	std::vector<int> data;
};

int main(void)
{
	Vector v(1e8, 0);

	{
		LogDuration l("test 1");
		Vector new_vec(v);
		//std::cout << "Finished" << std::endl;
	}
	std::cout << "Vector with size = " << v.size() << std::endl;
	{
		LogDuration l("test 2");
		Vector m_vec(std::move(v));
		//std::cout << "Finished" << std::endl;
	}
	std::cout << "Vector with size = " << v.size() << std::endl;
}
