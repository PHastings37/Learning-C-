#include <iostream>
#include "header.hpp"

int main() {
    int atm_num;
    int upper;
    int lower;
    Input_validation Atm_num_validation(true, 1, 118, "Please enter a valid atomic number between 1 and 118: ");
    Atm_num_validation.type_check<int>();

    return 0;
}