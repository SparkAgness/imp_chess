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
    public:
        struct player_kit {
            std::vector<Pawn> pawn_kit; //During new figure's type creating, the struct will be supplemented the types
        } figures_kit;
	
        template<typename Type>
	Type FigCreating(std::string);
        
        template<typename Type>
        Type GetFigure(std::string);

        void PlayerMoveFigure(std::string, int);
        void FillFiguresKit(Pawn); //Like the struct player_kit, overloading methods will be supplemented as FillFiguresKit void-func

	template<typenam Type>
        Type GetFigure

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

void Player::PlayerMoveFigure(std::string fig_name, int destination)
{
    int index = char(fig_name[0]) - 'a';
    if ("pawn" == fig_name.substr(2)) {
        Pawn& a = this->figures_kit.pawn_kit[index];
	a.MoveFigure(destination);
    }
};

template<typename Type>
Type Player::FigCreating(std::string f_name)
{
    Type a(f_name, this->player_color);
    return a;
};

void Player::FillFiguresKit(Pawn a)
{
    this->figures_kit.pawn_kit.push_back(a);
};

template<typename Type>
Type Player::GetFigure(std::string fig_name)
{
    if ("pawn" == fig_name.substr(2, 4)) {
        int index = char(fig_name[0]) - 'a';
        this->figures_kit.pawn_kit[index].ShowInfoMessage();
        return this->figures_kit.pawn_kit[0];
    }

};
#endif
