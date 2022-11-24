#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <limits>



class Input_validation {
    private:
        bool limits{};
        double upper{std::numeric_limits<double>::max()};
        double lower{};
        std::string error{};

        void clear_input(){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }

        bool is_int(std::string str){
            for (int i=0; i<str.length(); i++){
                if (!isdigit(str[i])){
                    return false;
                }else{
                    continue;
                }
            }
            return true;
        }

    public:
        Input_validation() = default;

        Input_validation(bool limit_check, double lower_limit, std::string error_msg): 
            limits(limit_check), lower(lower_limit), error(error_msg)
        {}

        Input_validation(bool limit_check, double lower_limit, double upper_limit, std::string error_msg)
            : limits(limit_check), lower(lower_limit), upper(upper_limit), error(error_msg)
        {}


        int type_check(){
            bool type_check{false};
            int input;
            std::string input_string;

            while(!type_check){
                std::cout<<error;
                std::cin>>input_string;

                if (!is_int(input_string)){
                    clear_input();
                }
                else{
                    type_check = true;
                }    
            }
            input = stoi(input_string);
            return input;
        }   

        int limit_check(int input){
            bool limit_check{false};

            while(!limit_check){
                if (input<lower || input>upper){
                    clear_input();
                    std::cout<<error;
                    std::cin>>input;
                } else{
                    break;
                }
            }
        return input;
        }
};

#endif