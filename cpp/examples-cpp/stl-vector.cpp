#include <iostream>
#include <string>
#include <vector>

/* Standard Template Library (STL)
   vector is a container
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

	/* Anytime a vector is created it is initialized as an empty array */
	std::vector<std::pair<int, int>> numbers; /* {} */

	/* Creates a vector of size 5 */
	std::vector<int> v(5);

	/* Creates a vector of size 5
	 * initializing each index with
	 * the value of 100          */
	std::vector<int> v(5, 100);

	/* Do this to copy the container for v into v1 */
	std::vector<int> v1(v);

	numbers.push_back({1, 2});
	/* Using placeback the brakets are not needed when dealing with pairs */
	numbers.emplace_back(1, 2); 

	/* Method dynamically increases size and appends the value passing in as a argument */
	numbers.emplace_back(2);

	/* Method of vector to append a value to the end of the vector */
	names.push_back("Joe");
	/* Method of vector to get the size of vector elements */
	names.size();

	/* Method of vector to get iterator that points at the memory of the first index */
	std::vector<int>::iterator it = names.begin();
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
