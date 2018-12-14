#include <iostream>
#include "IOperand.hpp"
#include "Float.hpp"

int main(){
    std::cout << "Hello" << std::endl;
    Factory f = Factory(int8, 3);
    std::cout << f->ptrOperand->getType()
}
