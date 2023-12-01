#include <iostream>
#include <stack>

int isValidOperator(std::stack<int> &storage, char charactar)
{
	int operant1;
	int operant2;

	if (storage.size() < 2)
		throw std::range_error("Error");
	operant2 = storage.top(); 
	storage.pop();
	operant1 = storage.top();
	storage.pop();
	switch (charactar)
	{
		case '+':
			return operant1 + operant2;
		case '-':
			return operant1 - operant2;
		case '*':
			return operant1 * operant2;
		case '/':
		{
			if (operant2 == 0)
				throw std::invalid_argument("Error");
			return operant1 / operant2;
		}
		default:
			throw std::logic_error("Error");
	}
}

bool isIntorOperator(char character)
{
	return ((character <= '9' && character >= '0') ? true : false);
}

int rpn(char *str)
{
	std::stack<int> storage;

	for (size_t i=0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
			continue;
		if (isIntorOperator(str[i]))
			storage.push(str[i] - '0');
		else
			storage.push(isValidOperator(storage, str[i]));
	}

	if (storage.size() == 0)
		throw std::invalid_argument("Error");
	return storage.top();
}