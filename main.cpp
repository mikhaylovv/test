// Example program
#include <iostream>
#include <functional>


template<class T>
class add_res { 
public:
	add_res(int val, T op) : _val(val), _op(op) {}
	
	add_res<T>& operator()(int val) {
		_val = _op(_val, val);
		return *this; 
	} 

	operator int (){ 
		return _val; 
	} 
	
private:
	int _val = 0; 
	T _op;
}; 

add_res<decltype(std::plus<>{})> add(int val) { 
	return add_res<decltype(std::plus<>{})>(val, std::plus<>{}); 
} 

int main() { 
	int smth = add(3)(4)(5)(-2); 
	std::cout << smth << std::endl; 
	return 0; 
}




	