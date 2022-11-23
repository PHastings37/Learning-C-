#include <iostream>
#include <cmath>

double energy_change(int atm_num, int n1, int n2){
    double E;
    E = 13.6*pow(atm_num,2)* ((1/pow(n1,2)) - (1/pow(n2,2)));
    return E;
}