/*this is a program that allows you to create an array(size 1-100) with your own elements, 
then allows you to choose to sort it from high to low, low to high or keep it as it is.*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	int myArray[100] = {};
	int elementsRemaining, end, length, temp;
	string answer, answer2;
	bool arraySorted = false, arraySorted2 = false, noSortingWanted = false, validValue = false;

	//asks user for amount of elements in the array, using while-loop to avoid invalid values
	while (validValue == false)
	{
		cout << "Please enter the amount of elements you want in your array (1-100):";
		cin >> length;
		if (length > 0 && length <= 100)
			validValue = true;
		else
			cout << "Please enter a valid value!" << endl;
	}
	
	//sets these integers to the same value as length
	elementsRemaining = length;
	end = length;

	//lets user enter the elements into the array
	for (int i = 0; i < length; i++)
	{
		if (elementsRemaining > 1)
		cout << "Enter " << elementsRemaining << " elements to your array: ";
		else
			cout << "Enter " << elementsRemaining << " element to your array: ";
		cin >> myArray[i]; //the only necessary part
		elementsRemaining--;
	}

	//print the complete array
	cout << "Your array consists of these elements: ";
	for (int i = 0; i < length; i++)
	{
		if (i < length-1)
			cout << myArray[i] << ", ";
		else
			cout << myArray[i] << endl;
	}

	//while-loop to prevent invalid answers
	while (arraySorted == false)
	{
		cout << "Do you want to sort them from high to low? (y/n)";
		cin >> answer;
		if (answer == "y" || answer == "yes")
		{
			for (int j = length-1; j > 0; j--)
			{
				for (int i = 0; i < end-1; i++)
				{
					if (myArray[i] < myArray[i + 1])
					{
						//sorting
						temp = myArray[i + 1];
						myArray[i + 1] = myArray[i];
						myArray[i] = temp;
					}

				}
				end--;
			}
			arraySorted = true;
		}
		else if (answer == "n" || answer == "no")
		{
			//while-loop to prevent invalid answers
			while (arraySorted2 == false)
			{
				cout << "Do you want to sort them from low to high instead? (y/n)";
				cin >> answer2;
				if (answer2 == "y" || answer2 == "yes")
				{
					for (int j = length - 1; j > 0; j--)
					{
						for (int i = 0; i < end-1; i++)
						{
							if (myArray[i] > myArray[i + 1])
							{
								//sorting
								temp = myArray[i + 1];
								myArray[i + 1] = myArray[i];
								myArray[i] = temp;
							}

						}
						end--;
					}
					arraySorted2 = true;
					arraySorted = true;
				}
				else if (answer2 == "n" || answer2 == "no")
				{
					noSortingWanted = true;
					arraySorted2 = true;
					arraySorted = true;
				}
				else
					cout << "Please enter a valid answer!(y/n)" << endl;
			}
		}
		else
			cout << "Please enter a valid answer!(y/n)" << endl;
	}

	//print the complete array if sorted
	if (noSortingWanted == false)
	{
		cout << "Your sorted array consists of these elements: ";
		for (int i = 0; i < length; i++)
		{
			if (i < length-1)
				cout << myArray[i] << ", ";
			else
				cout << myArray[i] << endl;
		}
	}

	system("pause");
	return 0;
}

