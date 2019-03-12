#include <iostream>

class Food
{
	int calories;
	int health;

public:
	Food (int x = 1000, int y = 0) : calories(x), health(y){}
	int getCalories() { return this->calories; }
	int getHealth() { return this->health; }
};

class Bear
{
	int calories;
	int health;

public:
	Bear() : calories(0), health(0) {};
	void info()
	{
		std::cout << "<Bear> Calories: " << this->calories << "; Health:" << this->health << std::endl;
	}

	void eat(int in_calories, int in_health)
	{
		this->calories += in_calories;
		this->health += in_health;
	}
	void eat(Food *in_food)
	{
		this->eat(in_food->getCalories(), in_food->getHealth());
		delete in_food;
	}
};

int main(int arhc, char *argv[])
{
	int reti = 0;

	Bear Pooh;
	Food honey(1000, 10);
	Food hare(2000, -10);

	Pooh.eat(honey.getCalories(), honey.getHealth());
	Pooh.info();
	//Pooh.eat(&honey);
	//Pooh.info();
	Pooh.eat(new Food(5000, -50));
	Pooh.info();

	return reti;
}

