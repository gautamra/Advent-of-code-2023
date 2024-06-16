#include <iostream>
#include <fstream>
#include <string>
#include <list>

std::string look_for_spelled_number(std::string str){
    std::string reference[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // std::cout << str << "\n";

    int i=0;
    int j=0;
    for (i=0; i<=str.size()-3; i++){
        for (j=0; j<9; j++){
            if (str.size()-i>=reference[j].size()){
                // std::cout << "compare " << str.substr(i, reference[j].size()) << " with " << reference[j] << ". ";
                if (str.substr(i, reference[j].size())==reference[j]){
                    // std::cout << "Found it!\n";
                    return std::to_string(j+1);
                }
                // std::cout << "No match :(\n";

            }
        }
        // std::cout << "\n";
    }
    return "0";
}

std::string look_for_spelled_number_backwards(std::string str){
    std::string reference[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // std::cout << str << "\n";

    int i=0;
    int j=0;
    for (i=str.size()-3; i>=0; i--){
        for (j=0; j<9; j++){
            if (str.size()-i>=reference[j].size()){
                std::cout << "compare " << str.substr(i, reference[j].size()) << " with " << reference[j] << ". ";
                if (str.substr(i, reference[j].size())==reference[j]){
                    std::cout << "Found it!\n";
                    return std::to_string(j+1);
                }
                std::cout << "No match :(\n";

            }
        }
        std::cout << "\n";
    }
    return "0";
}

int main()
{
    std::ifstream calibration_input; calibration_input.open("calibration_input.txt");
    std::ofstream troubleshoot_parse; troubleshoot_parse.open("troubleshoot_parse.txt");
    std::string string_input;
    int answer = 0;

    if ( calibration_input.is_open() ){
        while ( calibration_input.good() ){
            std::getline (calibration_input, string_input);
            int i;
            std::string two_digit_string;

            int idx=0;
            for (i=0; i<string_input.size(); i++){
                if (isdigit(string_input[i])){
                    two_digit_string = string_input[i];
                    idx=i;
                    break;
                }
            }
            std::string sub_string = string_input.substr(0, idx);
            std::cout << string_input << "\n";
            // std::cout << sub_string << "\n\n";

            std::string spelled_num="0";
            if (sub_string.size()>=3){
                spelled_num = look_for_spelled_number(sub_string);
            }
            if (spelled_num != "0"){
                two_digit_string = spelled_num;
            }
            // std::cout << two_digit_string +  "\n\n\n";

            idx=0;
            for (i=string_input.size()-1; i>=0; i--){
                if (isdigit(string_input[i])){
                    two_digit_string += string_input[i];
                    idx=i;
                    break;
                }
            }
            sub_string = string_input.substr(idx+1, string_input.size()-idx);
            std::cout << string_input << "\n";
            std::cout << sub_string << "\n\n";

            spelled_num="0";
            if (sub_string.size()>=3){
                spelled_num = look_for_spelled_number_backwards(sub_string);
            }
            if (spelled_num != "0"){
                two_digit_string = two_digit_string.substr(0, 1) + spelled_num;
            }
            std::cout << two_digit_string +  "\n\n";

            answer += stoi(two_digit_string);

            troubleshoot_parse << two_digit_string + "       "  + string_input+ "\n";

        }
        troubleshoot_parse.close();
        std::cout << answer << "\n";

    }
}