#include <iostream>
#include <array>

/* Array fixed size
 * To create a fix array std::array<T type, int quantity>
 * .at(index) = myArray[index] to get the element at the index
 * .size()  to get the size
 * .front() to get first element  
 * .back() to get last element 
 * .data() returns a pointer to the beginning of the array[0]
 * .empty()
 * */

int main()
{
	std::array<int, 5> myArray = {1, 3, 5, 4, 3};

	myArray[0] = 10;
	myArray[1] = 1;
	myArray[2] = 21;
	myArray[3] = 33;
	myArray[4] = 13;

	auto size = myArray.size();
	/* To get a pointer at the beginning of the array */
	int *ptr = myArray.data();
	/* The same as myArray */

	std::cout << myArray.at(0) << std::endl;
	std::cout << "Size = " << size << std::endl;
	std::cout << "First element = " << myArray.front() << std::endl;
	std::cout << "Last element = " << myArray.back() << std::endl;
	int i = 0;
	while (i != myArray.size())
	{
		std::cout << *ptr++ << std::endl;
		i++;
	}

	return 0;
}
