#include  <iostream>

class Engine
{
	int volume;
	int power;
public:
	Engine(int in_volume = 2000, int in_power = 100) : volume(in_volume), power(in_power) {}
	~Engine()
	{
		std::cout << "Engine destroyed." << std::endl;
	}

	void info()
	{
		std::cout << "<Engine> Volume: " << this->volume << "; Power: " << this->power << std::endl;
	}
};


class Car
{
	Engine *e;
public:
	Car(int in_volume = 1500, int in_power = 75)
	{
		this->e = new Engine(in_volume, in_power);
	}
	Car(Engine *e)
	{
		this->e = e;
	}

	~Car()
	{
		delete this->e;
	}


	void info()
	{
		std::cout << "<Car>";
		this->e->info();
	}
};

int main(int argc, char *argv[])
{
	int reti = 0;
	Car skoda;
	Car audi(3000, 200);
	Car bmw(new Engine(2500, 300));

	skoda.info();
	audi.info();
	bmw.info();


	return reti;
}