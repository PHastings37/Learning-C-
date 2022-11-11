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

    public:
        Input_validation() = default;

        Input_validation(bool limit_check, double lower_limit, std::string error_msg): 
            limits(limit_check), lower(lower_limit), error(error_msg)
        {}

        Input_validation(bool limit_check, double lower_limit, double upper_limit, std::string error_msg)
            : limits(limit_check), lower(lower_limit), upper(upper_limit), error(error_msg)
        {}


        template <class T> T type_check(){
            bool type_check{false};
            T input;
            T input_T = input;
            T input_double = input;

            std::cout<<error;
            std::cin>>input;
            
            while(!type_check){
                if (std::cin.fail()){
                    clear_input();
                    std::cout<<error;
                    std::cin>>input;
                } else if (static_cast<T>(input_T) != static_cast<double>(input_double)){
                    clear_input();
                    std::cout<<error;
                    std::cin>>input;
                } else{
                    break;
                }   
            }
            return input;
        }   

        template <class T> T limit_check(){
            bool limit_check{false};
            T input;

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

        template<class T> T get_input(){
            T input;
            return input;
        }
            
            
        };

#endif