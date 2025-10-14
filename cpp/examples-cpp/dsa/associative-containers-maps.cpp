#include <iostream>
#include <map>
#include <string>

/* Map is a non-linear data structure that stores
   data through a key and a value that is associated with that
   key

   std::map<pair<T, T>> myMap;

   O(1) look up by using the key to find the value
   people["Key"]
   map.at(key)

   can change index values like arrays and vectors
   but instead using the key 
   people["Key"] = 10;

 */

int main()
{
	std::map<std::string, int> people = { {"Hayeon", 24}, {"Jarron", 27} };

	auto size = people.size();

	std::cout << "Size of map is = " << size << std::endl;

	std::cout << "The key for people[\"Hayeon\"] is " << people["Hayeon"] << std::endl;

	std::cout << "The key for people[\"Jarron\"] is " << people.at("Jarron") << std::endl;

	std::cout << people[0].first << std::endl;
	
	return 0;
}
