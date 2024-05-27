#ifndef PLAYER
#define PLAYER
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "field.h"
#include "figures.h"

class Player
{
       
    private:
        std::vector<std::string> figures_names {"a_pawn", "b_pawn", "c_pawn", "d_pawn", "e_pawn", "f_pawn", "g_pawn", "h_pawn", "a_rook", "b_horse", "c_bishop", "d_queen", "e_king", "f_bishop", "g_horse", "h_rook"};
	std::vector<std::string> fig_color {"white", "black"};
        std::string player_color;
	std::string player_name;
        std::map<std::string, Figure> figures_kit;

    public:

        Figure FigCreating(std::string);

        Player(std::string name, int color)
        {
            this->player_name = name;
            this->player_color = this->fig_color[color]; //0 is white, 1 is black
            std::cout << "The player " << this->player_name << " has been created. Figures color is "  << this->player_color << std::endl;
	}

        ~Player()
        {
            std::cout << this->player_name << " has ended the game" << std::endl;
	};
};

Figure Player::FigCreating(std::string f_name)
{
    Pawn a("f_name", this->color);
    figures_kit[f_name] = a;
    return a;
};

#endif
