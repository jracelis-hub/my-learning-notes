#include <iostream>
#include <vector>
#include <complex>

int main()
{
	/* Complex is a object and also as a primitive data type associcated with it */
	/* In c++ 11 std the >> brackets was thought to be bitwise shift so be aware of it */
	std::vector<std::complex<double>> points;

	/* The real and complex number defined */
	/* Used to append values to the end of the vector */
	points.push_back(std::complex<double>(3.4, 4.0));
	points.push_back(std::complex<double>(1.0, -2.0));
	points.push_back(std::complex<double>(-5.3, 6.0));

	std::cout << "The first real part: " << points.begin()->real() << std::endl;
	std::cout << "Imaginary part at index 1: " << points[1].imag() << std::endl;
	std::cout << "Next to last real: " << prev(points.end(), 2)->real() << std::endl;
	std::cout << "Last imaginary: " << (points.end() - 1)->imag() << std::endl;
	
	return 0;
}
