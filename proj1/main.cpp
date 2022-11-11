#include <iostream>
#include "header.hpp"

int main() {
    int atm_num;
    int upper;
    int lower;

    Input_validation Atm_num_validation(true, 1, 118, "Please enter a valid atomic number between 1 and 118: ");
    Atm_num_validation.type_check<int>();
    Atm_num_validation.limit_check<int>();
    atm_num = Atm_num_validation.get_input<int>();
    std::cout<<"The atomic number is: "<<atm_num<<"\n";

    return 0;
}