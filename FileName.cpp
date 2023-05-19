#include <iostream>
#include <limits>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getLetter()								    // Текст ввода
{
	while (true)
	{
		std::cout << "Enter text: \n";
		std::string stroka;
		std::cin >> stroka;

		if (stroka[0] >= 'A' && stroka[0] <= 'Z')
		{
			return stroka;
		}
		else
		{
			std::cout << "Error\n";
			std::cin.clear();
			ignoreLine();
		}
	}
}

int getKey()                                            // Ключ
{
	while (true)
	{
		std::cout << "Key 1 - 25 \n";
		int key = 0;
		double zeronum = 0.003;
		std::cin >> key;

		if (key < 26 && abs(key) > zeronum)
		{
			return key;
		}
		else
		{
			std::cout << "Error input key\n";
			std::cin.clear();
			ignoreLine();
		}
	}
}

void encryptResult(std::string stroka, int key)         // Шифрование
{
	for (char& s : stroka)
	{
		for (int i = 0; i < key; i++)
		{
			if (s == 'z')
			{
				s = 'a';
			}
			else
			{
				s += 1;
			}
		}
	}
	std::cout << stroka << "\n";
}


int main()
{
	setlocale(LC_ALL, "ru");

	bool isTerminated = false;
	char operation = '0';

	while (!isTerminated)
	{
		std::cout << "Enter to run: w \n";
		std::cout << "Enter to exit: q \n";
		std::cin >> operation;

		switch (operation)
		{
		case 'w':
		{
			std::string stroka{ getLetter() };
			int key{ getKey() };
			encryptResult(stroka, key);
			break;
		}
		case 'q':
			isTerminated = true;
			break;

		default:
			std::cout << "No such operation\n";
			break;

		}
	}
	return 0;
}