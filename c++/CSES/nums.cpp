#include <iostream>
#include <string>
#include <boost/range/adaptor/reversed.hpp>
#include <vector>
 
int main() {
 
  const std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
 
  for (const int num : boost::adaptors::reverse(numbers)) {
  	std::cout << num << std::endl;
  }
 
  std::cout << " rbegin rend " << std::endl;
	for (auto it = numbers.rbegin(), end = numbers.rend(); it != end; ++it) {
		std::cout << (*it) << std::endl;
	}
}
