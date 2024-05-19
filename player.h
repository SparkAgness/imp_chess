#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <vector>
#include <string>
#include "field.h"
#include "figures.h"

class Player
{
       
    private:
        std::vector<std::string> figures_names {"a_pawn", "b_pawn", "c_pawn", "d_pawn", "e_pawn", "f_pawn", "g_pawn", "h_pawn", "a_rook", "b_horse", "c_bishop", "d_queen", "e_king", "f_bishop", "g_horse", "h_rook"};
	std::vector<std::string> fig_color {"white", "black"};
        std::string player_color;
	std::string player_name;
	std::vector<Figure> figures_kit {};
 
    public:
        void FiguresKitCreating();
        //void FigMoving(int, int);
        void KitRecap();

        Player(std::string name, int color)
        {
            this->player_name = name;
            this->player_color = this->fig_color[color]; //0 is white, 1 is black
            std::cout << "The player " << this->player_name << " was created. Figures color is "  << this->player_color << std::endl;
            FiguresKitCreating();
	}

        ~Player()
        {
            std::cout << this->player_name << " has ended the game" << std::endl;
	};

};

void Player::FiguresKitCreating()
{
    Pawn a(this->figures_names[0], this->fig_color[0]);
    this->figures_kit.push_back(a);
};

void Player::KitRecap() 
{
    for (int i = 0; i < int(this->figures_kit.size()); ++i) {
       this->figures_kit[i].GetCharacs(this->figures_kit[i].f_c);
       std::cout << "Figure's name: " <<(this->figures_kit[i].f_characs.fig_name) <<  "\t Location: " << this->figures_kit[i].f_characs.fig_location << std::endl;
    }
};
#endif
