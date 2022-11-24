#include <iostream>
#include "header.hpp"
#include "functions.cpp"

int main() {
    int atm_num;
    int upper;
    int lower;
    int n1;
    int n2;
    double E;

    Input_validation atm_num_validation(true, 1, 118, "Please enter a valid atomic number between 1 and 118: ");
    atm_num = atm_num_validation.type_check();
    atm_num = atm_num_validation.limit_check(atm_num);

    Input_validation n1_val(true, 1, "Please enter your first energy level: ");
    n1 = n1_val.type_check();
    n1 = n1_val.limit_check(n1);
    
    Input_validation n2_val(true, n1, "Please enter your second energy level: ");
    n2 = n2_val.type_check();
    n2 = n2_val.limit_check(n2);

    std::cout<<atm_num<<n1<<n2<<"\n";

    E = energy_change(atm_num, n1, n2);

    std::cout<<"The energy change was: "<< E << "ev\n";

    return 0;
}