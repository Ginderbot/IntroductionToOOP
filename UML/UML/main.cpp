#include<iostream>

class Tank
{
	 unsigned int volume; // характеризует объект, показывает какой он, oбём бака изменяться не может
	double fuel_level;//состояние объекта, которое может меняться
public:
	const unsigned int get_volume()const
	{
		return volume;
	}
	const double get_fuel_level()
	{
		return fuel_level;
	}
	
	Tank(unsigned int volume)
	{
		this->volume = volume < 20 ? 20 : volume>100 ? 100 : volume;
		fuel_level = 0;
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
	void info()const
	{
		std::cout << "Tank volume:\t" << volume << "\t liters\t";
		std::cout << "Fuel level:\t" <<fuel_level<< "\t liters" << std::endl;
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
		std::cout << "Engine is ready:\t" << this << std::endl;
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
	std::cout << "Engine consumption:\t" << get_consumption() << "\tliters per 100 km" << std::endl;
	std::cout << "Consumption per sec:\t" << get_consumption_per_second() << "\tliters per second" << std::endl;
	std::cout << "Engine is" << (is_started ? "started" : "stopped") << ".\n";
	}
private:

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
	tank.fill(100);
	tank.info();
#endif // TANK_CHECK

	
}