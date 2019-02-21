// Example program
#include <iostream>
#include <functional>


template<class T>
class multiplexor { 
public:
	multiplexor(int val) : _val(val) {}
	
	multiplexor<T>& operator()(int val) {
		_val = T{}(_val, val);
		return *this; 
	} 

	operator int (){ 
		return _val; 
	} 
	
private:
	int _val = 0;
}; 

multiplexor<std::plus<>> add(int val) { 
	return multiplexor<std::plus<>>(val); 
} 

int main() { 
	int smth = add(3)(4)(5)(-2); 
	std::cout << smth << std::endl; 
	return 0; 
}




	