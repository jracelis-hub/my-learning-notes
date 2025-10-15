#include <iostream>
#include <memory> /* This is needed when dealing with smart pointers */

/* Smart Pointeres
 * There are 3 types of pointers:
 * std::unique_ptr<Type T> variable_name = std::make_unique<Type T>()
 * std::shared_ptr<Type T> variable_name = std::make_shared<Type T>()
 * std::weak_ptr<Type T> variable_name = std::make_unique<Type T>()
 *
 * */


int main()
{
	std::unique_ptr<int> my_ptr = std::make_unique<int>(10);

	/* my_ptr = 10; */

	std::cout << *my_ptr << std::endl;

	return 0;
}
