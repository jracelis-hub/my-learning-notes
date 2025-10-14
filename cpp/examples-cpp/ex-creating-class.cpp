#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory {
public:
	/* Default Constructor */
	Inventory(void) {
		capacity = 10;	
		items = new std::vector<std::string>(); /* this is a constructor for the vector */
	}

	/* Overloaded Constructor */
	Inventory(int capacity) {
		this->capacity = capacity; /* this-> is a pointer to the this object that points to the capacity */
		items = new std::vector<std::string>();
	}

	/* Destructor */
	~Inventory() {
		delete items;
	}

	/* To create an operator a replacement for a function
	Inventory& operator+=(const std::string& item); */
	/*
	void addItem(const std::string& item) 
	{
		if (items->size() < capacity) { 
			items->push_back(item); 
		}
		else {
			std::cout << "Inventory is full, cannot add " << item << std::endl;
		}
	}
	*/

	/* Implementations for overload operator */
	Inventory& Inventory::operator+=(const std::string& item) 
	{
		if (items->size() < capacity) { 
			items->push_back(item); 
		}
		else {
			std::cout << "Inventory is full, cannot add " << item << std::endl;
		}
		return *this;
	}
	
	/* To create an operator a replacement for a function
	void removeItem(const std::string& item) 
	To use the following operator do the following
	myinventory -= "sword" */
	Inventory& operator-=(const std::string& item);
	{
		auto it = std::find(items->begin(), items->end(), item); /* This create an iterator that starts at the beginning to the end looking for item */
		if (it != items->end()) {
			items->erase(it);
		}
		else {
			std::cout << "Item " << item << " not found in inventory" << std::endl;
		}
	}

	/* This returns (gets) the item of the string 
	 * the const key word tells the programmer that the value
	 * should not be modified                              */
	/* Operator for this is 
	   std::string operator[](int index) const;
	   class[]                               */
	std::string getItem(int index) const {
		if (index <= 0 && index < items->size()) {
			return (*items)[index]; /* returns the string of that name */
		}
		else {
			return "Index out of bounds";
		}
	}

	int getItemCount(void) const {
		return items->size();
	}

	void displayInventory(void) const {
		std::cout << "Inventory: [ ";
		for (size_t i = 0; i < items->size(); i++) {
			std::cout << (*items)[i];
			if (i < items->size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "]";
	}

private:
	std::vector<std::string> *items; /* Pointer to a vector of items */
	int capacity; /* Maximum number of items allowed */
};

int main() 
{
	Inventory myInventory(5);

	myInventory.addItem("Health Potion");
	myInventory.addItem("Mana Potion");
	myInventory.addItem("Sword");
	myInventory.addItem("Shield");
	myInventory.addItem("Bow");
	
	myInventory.displayInventory();

	myInventory.addItem("Arror");

	myInventory.removeItem("Mana Potion");

	std::cout << "The inventory now contains: " << myInventory.getItemCount() << 
	" items." << std::endl;

	std::cout << "Item at index 2: " << myInventory.getItem(2) << std::endl;

	myInventory.displayInventory();

	return 0;
}
