#include <iostream>
#include <vector>

/* a vector is a dynamically allocate array */

int main()
{
	std::vector<int> numbers(5, 100);

	numbers.push_back(55);

	std::cout << numbers[5] << std::endl;

	/* numbers.begin() returns a pointer that points to the first 
	 * index in the vector                                     */
	std::vector<int>::iterator it = numbers.begin();

	/* Gives a pointer to the index after the last element */
	/* [0, 1, 2, 3, 4, 6] 7 <--- index outside of range */
	std::vector<int>::iterator end = numbers.end();

	/* rend() = reverse end which uses a reverse_iterator 
	 * points to the value before the beginning 
	 * before -> it [0, 1, 2, 3, 4] */
	std::vector<int>::reverse_iterator it_s = numbers.rend();
	std::vector<int>::reverse_iterator its = numbers.rbegin();
	/* rbegin() = reverse begin which uses a reverse_iterator
	 * point to the last element of the value in the vector 
	 * rather than end() pointer after the end rbegin() points 
	 * exactly at the end                                  */

	/* reverse_iterator move back way when using its++ */

	std::cout << *(it) << std::endl;

	std::cout << numbers[0] << " == " << numbers.at(0) << std::endl;
	/* .back() gets the last element in the vector */
	std::cout << numbers.back() << std::endl;

	/* These are the same */
	std::cout << *(end - 1) << std::endl;
	std::cout << *(its) << std::endl;
	std::cout << "This should be the value before the end " << *(++its) << std::endl;

	for (std::vector<int>::iterator it2 = numbers.begin(); it2 != numbers.end(); it2++) {
		std::cout << *(it2) << std::endl;
	}

	std::cout << numbers.size() << std::endl;

	/* This is using the range in C++ where
	 * the data type on the right has to match the data type to the left */
	/* Thing of it like for int j in numbers do this */
	for (const int& it_3 : numbers) {
		std::cout << it_3 << std::endl;
	}

	/* To delete a specific index in a vector use
	 * numbers.erase(beginning iterator , end iterator) 
	 * numbers.erase(single value) or numbers.erase(range 0, range 4) */
	numbers.erase(numbers.begin(), numbers.end());

	std::cout << "starting " << std::endl;
	for (const int& it_3 : numbers) {
		std::cout << it_3 << std::endl;
	}

	if (numbers.empty()) {
		std::cout << "It is empty!" << std::endl;
	} else {
		std::cout << "Is not empty" << std::endl;
	}

	/* To insert a value use the .insert(iterator, quanity, value)*/
	numbers.insert(numbers.begin(), 5, 300);
	for (const int& it_3 : numbers) {
		std::cout << it_3 << std::endl;
	}

	/* Lets say you want to copy another vector into a vector using insert
	 * do the following first initialize ta vector */
	std::vector<int> numbers_2(2, 5); /* creating a {5, 5}*/
	/* To insert this value a specific location do the following */
	numbers.insert(numbers.begin() + 3, numbers_2.begin(), numbers_2.end());
	for (const int& it_3 : numbers) {
		std::cout << it_3 << std::endl;
	}

	numbers_2.push_back(3);
	/* Removes the last element from the vector */
	numbers_2.pop_back();
	for (const int& it_3 : numbers_2) {
		std::cout << it_3 << std::endl;
	}

	/* erarses everything from the vector */
	numbers_2.clear();
	for (const int& it_3 : numbers_2) {
		std::cout << it_3 << std::endl;
	}


	return 0;
}
