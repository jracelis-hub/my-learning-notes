#include <iostream>
#include <iostream>
#include <string>

/* Palindromes 
 * Palindromes are words or phrases that read the same backward as forward
 * Example:
   Words: civic, radar, level
   Phrases: "rats line on no evil star"
 */

/* Program Requirements
 * Ask user to enter string
 * Respond if a message is a string is a a palindrome or not
 * Ignore case Civic = civic
 * check for all characters
 */	

bool is_palindrome(std::string& s)
{
	int first = 0;
	int last = s.length() - 1;
	bool isPalindrome = true;

	while (first < last) 
	{
		if (s[first] == s[last])
		{
			first++;
			last--;
		} else if (s[first] != s[last])
		{
			std::cout << s[first] << " and " << s[last] << " are not the same!" << std::endl;
			isPalindrome = false;
			return isPalindrome;
		}
	}

	return isPalindrome;
}

int main()
{
	std::string s;	
	std::cout << "Enter a string: " << std::flush;
	std::getline(std::cin, s);

	if (is_palindrome(s)) {
		std::cout << s << " is a palindrome!" << std::endl;
	}

	return 0;
}
