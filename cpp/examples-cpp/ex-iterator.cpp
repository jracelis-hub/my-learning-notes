#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> items = {"potion", "shield", "sword", "potion", "arrow"};

	/* Sort value in ascending order */
	std::sort(items.begin(), items.end());
	std::cout << "Sorting the items in order!" << std::endl;
	for (auto& item : items) {
		std::cout << item << std::endl;
	}

	/* Find given value in a loop */
	std::cout << "Finding value" << std::endl;
	auto it = std::find(items.begin(), items.end(), "bow");
	std::cout << typeid(it).name() << std::endl;
	if (it != items.end()) { std::cout << *it << std::endl; }
	else { std::cout << "Value not found" << std::endl; }

	/* Count a specific value */
	int potion_count = std::count(items.begin(), items.end(), "potion");
	std::cout << "Found " << potion_count << std::endl;

	return 0;
}
