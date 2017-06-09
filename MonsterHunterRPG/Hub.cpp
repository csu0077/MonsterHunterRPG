#include <iostream>
#include <string>
//Main hub: choose your destination using the numbers and press enter.

int validateInput()
{
	int input = 0;
	while (true)
	{
		std::cout << "\nPlease enter input: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << "bad input, looping" << std::endl;
		}
		else if (!std::cin.fail())
		{
			break;
		}
	}
	return input;
}

int goToInn()
{
	std::cout << "1. Rest\n";
	std::cout << "2. Eat\n";
	std::cout << "3. Storage\n";
	std::cout << "4. Save\n";
	std::cout << "5. Leave\n";
	std::cout << "  Welcome! What would you like to do? \n";

	int input = validateInput();

	switch (input)
	{
	case 1:
		//rest();
		break;
	case 2:
		//eat();
		break;
	case 3:
		//storage();
		break;
	case 4:
		//save();
		break;
	case 5:
		return 1;
		break;
	default:
		return 0;
		break;
	}
	//TODO rest,eat,storage, save
	return 0;
}

int goToShop()
{
	return 0;
}


int mainHub()
{
	int input = 0;

	std::cout << "1. Inn & Cafe\n";
	std::cout << "2. Shop\n";
	std::cout << "3. Smithy\n";
	std::cout << "4. Guild\n";
	std::cout << "5. Dungeon\n";
	std::cout << "  Where would you like to go? Input a number: " << std::endl;
	input = validateInput();

	switch (input)
	{
	case 1:
		//std::cout << "one\n";
		goToInn();
		break;
	case 2:
		//std::cout << "two\n";
		break;
	default:
		std::cout << "broken\n";
		break;

	}
	return 0;
	//0 means error
}