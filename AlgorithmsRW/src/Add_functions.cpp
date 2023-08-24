#include "Add_functions.h"
#include <cmath>

float input(char *str) //This function will read a massive of char elements and convert them into number in double type
{
	float element = 0;
	int a = 0;
	int k = 0;
	for (k = 0; !(str[k] == NULL); k++)
	{
		if (str[k] == '.')
		{
			break;
		}
	}
	for (a = k, k = 0; k < a; k++)
	{
		element = element + (float)pow(10, a - k - 1) * (str[k] - 48);
	}
	for (a = k, k = a + 1; !((str[k] == NULL) || (str[k - 1] == NULL)); k++)
	{
		element = element + (float)pow(10, a - k) * (str[k] - 48);
	}
	//std::cout << "element: " << element << "\n";
	return element;
}