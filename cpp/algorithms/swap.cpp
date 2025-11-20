#include <iostream>
#include <vector>

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}


void enter_number(int& left, int& right) {
    std::cout << "Enter first number: " << std::flush;
    std::cin >> left;

    std::cout << "Enter second number: " << std::flush;
    std::cin >> right;
}

void print_swap(int& left, int& right) {
    std::cout << "Before" << std::endl;
    std::cout << "Num1 = " << left << std::endl;
    std::cout << "Num2 = " << right << std::endl;

    swap(left, right);

    std::cout << "After" << std::endl;
    std::cout << "Num1 = " << left << std::endl;
    std::cout << "Num2 = " << right << std::endl;
}

int main() 
{
    int left;
    int right;

    enter_number(left, right);

    print_swap(left, right);

    return 0;
}