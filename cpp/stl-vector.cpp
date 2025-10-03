#include <iostream>
#include <string>
#include <vector>

/* Standard Template Library (STL)
   vector is a dynamic array that takes a
   Type T which is any type of primitive data type
   or object
   To declare do the following
   std::vector<data_type> variable_name;
   std::vector<object>
   std::vector<std::string> myName;
   std::vector<int> myName;
*/

int main()
{
	std::vector<std::string> names = {"Hayeon", "Cliffy", "Jarron"};

	/* Method of vector to append a value to the end of the vector */
	names.push_back("Joe");
	/* Method of vector to get the size of vector elements */
	names.size();

	/* Method of vector to get iterator (position) of the first element in the vector */
	auto namesPtr = names.begin();
	/* Method of vector to get the reference of the first element in the vector */
	names.front();
	/* Method of vector to get the reference of the last vector element */
	names.back();
	/* Method of vector to get iterator (positon) of the last element */ 
	names.end();
	/* The next function takes the argument of an iterator + increment size */
	next(namesPtr, 1);

	int i;
	for (i = 0; i < names.size(); i++)
	{
		std::cout << "Name is " << names[i] << std::endl;
	}

	names[1] = "Cliffy Lee";
	for (i = 0; i < names.size(); i++)
	{
		std::cout << "Name is " << names[i] << std::endl;
	}
	
	return 0;
}
