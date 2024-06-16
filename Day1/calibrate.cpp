#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream calibration_input; calibration_input.open("calibration_input.txt");
    std::string string_input;
    int answer = 0;

    if ( calibration_input.is_open() ){
        while ( calibration_input.good() ){
            std::getline (calibration_input, string_input);
            int i;
            std::string two_digit_string;

            for (i=0; i<string_input.size(); i++){
                if (isdigit(string_input[i])){
                    two_digit_string = string_input[i];
                    break;
                }
            }

            for (i=string_input.size()-1; i>=0; i--){
                if (isdigit(string_input[i])){
                    two_digit_string += string_input[i];
                    break;
                }
            }

            // std::cout << two_digit_string;
            // std::cout << '\n';

            answer += stoi(two_digit_string);
            // std::cout << answer << "\n";

        }

        std::cout << answer << "\n";

    }
}