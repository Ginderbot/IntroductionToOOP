#include<iostream>
#include<conio.h>
#include<thread>
using namespace std::chrono_literals;

class Tank
{
	unsigned int volume;	//������������� ������, ���������� ����� �� (������), �������� �� �����
	double fuel_level;		//��������� �������, ������� ����� ��������.
public:
	const unsigned int get_volume() const
	{
		return volume;
	}
	const double get_fuel_level() const
	{
		return fuel_level;
	}
	Tank(unsigned int volume)
	{
		this->volume = volume < 20 ? 20 : volume>100 ? 100 : volume;
		this->fuel_level = 0;
		std::cout << "Tank ready:\t" << this << std::endl;
	}
	~Tank()
	{
		std::cout << "Tank destroyed:\t" << this << std::endl;
	}

	void fill(double fuel)
	{
		if (fuel <= 0)return;
		if (fuel_level + fuel <= volume)
		{
			this->fuel_level += fuel;
		}
		else
		{
			fuel_level = volume;
		}
	}
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}
	void info()const
	{
		std::cout << "Tank volume:\t" << volume << "\tliters.\t";
		std::cout << "Fuel level:\t" << fuel_level << "\tliters." << std::endl;
	}
};

class Engine
{
	double consumption;
	double consumption_per_second;
	bool is_started;
public:
	const double get_consumption()const
	{
		return consumption;
	}
	const double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	Engine(double consumption)
	{
		this->consumption = consumption < 3 ? 3 : consumption>20 ? 20 : consumption;
		this->consumption_per_second = this->consumption / 1000;
		is_started = false;
		std::cout << "Engine is redy:\t" << this << std::endl;
	}
	~Engine()
	{
		std::cout << "Engine is over:\t" << this << std::endl;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		std::cout << "Engine consumption:\t" << get_consumption() << "liters per 100 km" << std::endl;
		std::cout << "Consumption per sec:\t" << get_consumption_per_second() << "liters per second" << std::endl;
		std::cout << "Engine is " << (is_started ? "started" : "stopped") << ".\n";
	}
};

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
	unsigned int speed;
	unsigned int max_speed;
	struct ControlPanel
	{
		//����� (Thread) - ��� ������������������ ������ ����������. � ������ ����������� ���������� �����-�� �������.
		std::thread* main_thread;	//��� �������� �����, �� ��������� ��� �������� ������, � ���������� �������, ������� ���������� ������.
									//���� ����� �������� ������� ������������, ��������� ����� � ����� �� ������, � �������������, ���������, � ������������� ��������� ������.
		std::thread* panel_thread;	//������ ��������. �� ����� ������ ��������,� ����� �� ��� ������, ������ ����� �� ��������� ������. 
									//���� �����, ����������� �� ������ ���������. �� ����������, ������ ����� �������� ��������� ������.
									//���� ����� ����������� ���������, � ��� ����� � ����.
		std::thread* idle_thread;	//�������� ��� ���������. ���������, ����� �� ������� ������, � ���������, ����� �� ������������� ���������.
									//���� ����� ������ �� ��������� ����
		std::thread* wheeling_thread = nullptr;
	}control_panel;
public:
	Car(double tank_volume, double engine_consumption, unsigned int max_speed = 250) :
		tank(tank_volume), engine(engine_consumption),
		driver_inside(false),
		speed(0),
		max_speed(max_speed)
	{
		std::cout << "Your car is ready to go. " << std::endl;
		control_panel.main_thread = new std::thread(&Car::control, this);
	}
	~Car()
	{
		if (control_panel.main_thread->joinable())control_panel.main_thread->join();
		std::cout << "Your car is over" << std::endl;
	}

	//			Functions:
	void get_in()
	{
		driver_inside = true;
		control_panel.panel_thread = new std::thread(&Car::panel, this);
	}
	void get_out()
	{
		driver_inside = false;
		if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();
		system("CLS");
		std::cout << "You are in the street, press enter to get in your car.\n";
	}
	bool is_driver_inside()const
	{
		return driver_inside;
	}
	void fill(double fuel)
	{
		tank.fill(fuel);
	}
	void start()
	{
		if (!tank.get_fuel_level())
		{
			std::cout << "No fuel.\n";
			return;
		}
		if (driver_inside)
		{
			engine.start();
			control_panel.idle_thread = new std::thread(&Car::idle, this);
		}
	}
	void stop()
	{
		engine.stop();
		if (control_panel.idle_thread->joinable())control_panel.idle_thread->join();
	}
	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			std::cout << "Engine is " << (engine.started() ? "started" : "stopped") << ".\n";
			std::cout << "Fuel:\t" << tank.get_fuel_level() << " liters.\n";
			std::cout << (tank.get_fuel_level() < 5 ? "LOW FUEL" : "") << std::endl;
			std::cout << "Speed:\t" << speed << " km/h.\n";

			using namespace std::chrono_literals;
			std::this_thread::sleep_for(500ms);
		}
	}
	void idle()
	{
		using namespace std::chrono_literals;
		while (engine.started() && tank.give_fuel(engine.get_consumption_per_second()))
		{
			std::this_thread::sleep_for(1s);
		}
		engine.stop();
	}
	void control()
	{
		std::cout << "Press enter to get in." << std::endl;
		char key = 0;
		do
		{
			key = _getch();
			switch (key)
			{
				//case 'E':
			case 13:
				if (!is_driver_inside())get_in();
				else get_out();
				break;
			case 'F':
			case 'f':
				if (!driver_inside)
				{
					double amount;
					std::cout << "How much?"; std::cin >> amount;
					fill(amount);
				}
				else
				{
					std::cout << "Get out of car!" << std::endl;
				}
				break;
			case 'I':
			case 'i'://Ignition
				if (!engine.started())
				{
					start();
				}
				else
				{
					stop();
				}
				break;
			case 'W':
			case 'w':
				if (engine.started())
				{
					speed += 10;
					if (speed > max_speed)speed = max_speed;
				}
				break;
			case 'S':
			case 's':
				if (speed > 20)speed -= 20;
				else if (speed > 10)speed -= 10;
				else if (speed > 5)speed -= 5;
				else speed = 0;
				break;
			}
			std::this_thread::sleep_for(1s);
			if (speed > 0 && control_panel.wheeling_thread == nullptr)
				control_panel.wheeling_thread = new std::thread(&Car::free_wheeling, this);
			else if (speed == 0 && control_panel.wheeling_thread && control_panel.wheeling_thread->joinable())
			{
				control_panel.wheeling_thread->join();
				control_panel.wheeling_thread = nullptr;
			}
		} while (key != 27);
	}

	/////////////////////////////	Driving		//////////////////////////////
	void accellerate()
	{
		if (engine.started() && speed < max_speed)
		{
			speed += 10;
		}
		if (speed > max_speed)speed = max_speed;
		//std::this_thread::sleep_for(1s);
	}
	void free_wheeling()
	{
		//using namespace std::chrono_literals;
		while (speed > 0)
		{
			speed--;
			std::this_thread::sleep_for(1s);
		}
	}
};

//#define TANK_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(40);
	tank.info();
	tank.fill(20);
	tank.info();
	tank.fill(30);
	tank.info();
#endif // TANK_CHECK

	Car bmw(60, 8);


}