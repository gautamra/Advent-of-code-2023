#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>


std::vector<int> process_set(std::string set){
    std::vector<int> res = {0,0,0};

    std::stringstream set_stream(set);
    std::string draw;
    int space_index;
    int number;
    std::string color;

    while (std::getline(set_stream, draw, ',')){
        draw = draw.substr(1, -1);
        space_index = draw.find(' ');
        number = stoi(draw.substr(0, space_index));
        color = draw.substr(space_index+1, -1);

        if (color=="red"){
            res[0]=number;
        }
        else if (color=="green"){
            res[1]=number;
        }
        else if (color=="blue"){
            res[2]=number;
        }
    }

    return res;
}

std::vector<int> pick_max(std::vector<int> rgb1, std::vector<int> rgb2){
    std::vector<int> res = {0,0,0};
    res[0] = std::max(rgb1[0], rgb2[0]);
    res[1] = std::max(rgb1[1], rgb2[1]);
    res[2] = std::max(rgb1[2], rgb2[2]);
    return res;
}

int process_game(int game_number, std::string game){
    std::stringstream game_stream(game);
    std::string set;
    std::vector<int> min_rgb = {0,0,0};
    int power = 1;

    std::cout << "\n" << game << "\n";
    while (std::getline(game_stream, set, ';')){
        min_rgb = pick_max(min_rgb, process_set(set));
    }

    for (int i: min_rgb){
        std::cout << i << ", ";
    }
    for (int i: min_rgb){
        power*=i;
    }
    std::cout << "The corresponding power is "<<power<<"\n";
    return power;
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

            answer += process_game(game_number, game);
        }
    }
    std::cout << "\n" << answer;
}