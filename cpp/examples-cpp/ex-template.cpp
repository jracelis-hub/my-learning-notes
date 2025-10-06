#include <iostream>
#include <string>

template <typename T>
int size_in_bits(T a) {
	return sizeof(a) * 8;
}

int main() 
{
	std::cout << "Size in bits " << size_in_bits(8) << std::endl;		
	std::cout << "Size in bits " << size_in_bits('a') << std::endl;		
	std::cout << "Size in bits "  << size_in_bits(3.14f) << std::endl;		
	std::cout << "Size in bits " << size_in_bits(3.14) << std::endl;		

	std::cout << "============" << std::endl;
	std::cout << "Short size in bits " << size_in_bits((short)42) << std::endl;
	std::cout << "Long size in bits " << size_in_bits(42L) << std::endl;
	std::cout << "Bool size in bits " << size_in_bits(true) << std::endl;
	std::cout << "String size in bits " << size_in_bits((std::string)"Short") << std::endl;

	return 0;
}
