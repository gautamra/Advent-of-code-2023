#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

// std::vector<std::string> split(std::string str std::string delimiter){

// }

bool process_set(std::string set){
    std::map<std::string, int> reference;
    reference["red"]=12;
    reference["green"]=13;
    reference["blue"]=14;

    std::stringstream set_stream(set);
    std::string draw;
    int space_index;
    int number;
    std::string color;
    std::cout << set << "\n";

    while (std::getline(set_stream, draw, ',')){
        draw = draw.substr(1, -1);
        std::cout<<draw<<std::endl;
        space_index = draw.find(' ');
        number = stoi(draw.substr(0, space_index));
        color = draw.substr(space_index+1, -1);
        std::cout << number << "\n";
        std::cout << color <<  "\n";
        if (number>reference[color]){
            std::cout << "failed! moving on \n\n";
            return false;
        }
    }
    return true;
}

int process_game(int game_number, std::string game){
    std::stringstream game_stream(game);
    std::string set;
    bool possible = true;

    std::cout << "\n" << game << "\n";
    while (std::getline(game_stream, set, ';')){
        possible = process_set(set);
        if (not possible){
            return 0;
        }
    }
    return game_number;
}

int main(){
    std::ifstream input; input.open("input.txt");
    std::string game;
    int colon_index = 0;
    int game_number = 0;

    int answer = 0;

    if (input.is_open()){
        while (input.good()){
            std::getline(input, game);
            colon_index = game.find(":");
            game_number = stoi(game.substr(5, colon_index-5));
            game = game.substr(colon_index+1, -1);
            // std::cout << game_number << "\n";
            // std::cout << game << "\n";

            answer += process_game(game_number, game);
        }
    }
    std::cout << "\n" << answer;
}