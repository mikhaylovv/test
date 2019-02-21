// Example program
#include <iostream>
#include <functional>


template<class T>
class add_res { 
public:
	add_res(int val) : _val(val) {}
	
	add_res<T>& operator()(int val) {
		_val = T{}(_val, val);
		return *this; 
	} 

	operator int (){ 
		return _val; 
	} 
	
private:
	int _val = 0;
}; 

add_res<std::plus<>> add(int val) { 
	return add_res<std::plus<>>(val); 
} 

int main() { 
	int smth = add(3)(4)(5)(-2); 
	std::cout << smth << std::endl; 
	return 0; 
}




	