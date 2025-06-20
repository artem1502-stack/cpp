#include <iostream>
#include <cstdlib>

class Camera
{
public:
	Camera(std::string model_): camera_model(model_)
	{
		std::cout << "Camera created" << std::endl;
	}
	void make_photo() const
	{
		std::cout << "made photo" << std::endl;
	}
	void show_param() const
	{
		std::cout << "Camera model: " << camera_model << std::endl;
	}
	std::string camera_model;
};

class Phone
{
public:
	Phone(std::string model_): phone_model(model_)
	{
		std::cout << "Phone created" << std::endl;
	}
	void make_call() const
	{
		std::cout << "made call" << std::endl;
	}
	void show_param() const
	{
		std::cout << "Phone model: " << phone_model << std::endl;
	}
	std::string phone_model;
};

class SmartPhone: public Phone, public Camera
{
public:
	SmartPhone(std::string camera_model_, 
		std::string phone_model_, std::size_t memory_) :
		Camera(camera_model_), Phone(phone_model_)
		{
			memory = memory_;
		}

	void show() const
	{
		std::cout << "C: " << camera_model << std::endl;
		std::cout << "P: " << phone_model << std::endl;
		std::cout << "M: " << memory << std::endl;
	}
	std::size_t memory;
};

int main(void)
{
	SmartPhone sp("Nokia", "Sony Erixon", 100);

	sp.Phone::show_param();
	sp.Camera::show_param();
	
}
