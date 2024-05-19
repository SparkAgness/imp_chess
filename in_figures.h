#ifndef FIGURE
#define FIGURE
#define CHESSIZE 8
#define DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "field.h"
#include "player.h"

int HelpSubstrRet(std::string to_find);

Player::Figure::Figure(std::string name, std::string col)
{
    std::string basis_name = name.substr(2, 4);

    this->name = name;
    this->color = col;	    
    this->price = HelpSubstrRet(basis_name); 
    this->price = 0;
    this->location = 0;

};

void Player::Figure::ChangeLocation(int ch_loc) 
{
    if (ch_loc > 0 and ch_loc < 65) this->location = ch_loc;
}
        
void Player::Figure::ChangeCast(int cst) 
{
    this->price = cst;	
}
        //virtual void BeatEnemy() = 0;

std::vector<int> Player::Pawn::GetPawnsMoveF() 
{
    return this->move_fields;
};

std::vector<int>Player::Pawn::GetPawnsBeatF()
{
    return this->beat_fields;
};



void Player::Pawn::ShowInfoMessage()
{
    GetCharacs(this->f_c);
    std::cout << "Hello, I'm " << this->f_characs.fig_name << ". My color is " << f_characs.fig_color <<  ". My location is " << this->f_characs.fig_location << ". My cost is " << this->f_characs.fig_price << ". My enable to moving fields:";
    for (int i = 0; i < int(this->move_fields.size()); ++i) {std::cout << move_fields[i] << " ";}
    std::cout << "My beat fields:";
    for (int i = 0; i < int(this->beat_fields.size()); ++i) {std::cout << beat_fields[i] << " ";}
    std::cout << std::endl;
};

void Player::Pawn::SetPawnsMoveF() 
{
    GetCharacs(this->f_c);
    int i_limit = 1;
    if (this->yet_no_motion) i_limit = 2; 
    if ("black" == this->f_characs.fig_color) {
        for (int i = 1; i <= i_limit; ++i) this->move_fields.push_back(this->f_characs.fig_location - i);
    } else {
        for (int i = 1; i <= i_limit; ++i) this->move_fields.push_back(this->f_characs.fig_location + i);
    }
};

void Player::Pawn::SetPawnsBeatF()
{
    GetCharacs(this->f_c);
    int dur_hor = this->f_characs.fig_location%CHESSIZE;
    int dur_vert = this->f_characs.fig_location/CHESSIZE;
    if ("black" == this->f_characs.fig_color) {
        if (this->f_characs.fig_location > 9 and this->f_characs.fig_location < 64) this->beat_fields.push_back(CHESSIZE*(dur_vert) - CHESSIZE + dur_hor - 1);    
        if (this->f_characs.fig_location > 0 and this->f_characs.fig_location < 57) this->beat_fields.push_back(CHESSIZE*(dur_vert + 1) + dur_hor - 1);
    } else {
        if (this->f_characs.fig_location > 9 and this->f_characs.fig_location < 64) this->beat_fields.push_back(CHESSIZE*(dur_vert - 1) + dur_hor + 1); 
        if (this->f_characs.fig_location > 0 and this->f_characs.fig_location < 57) this->beat_fields.push_back(CHESSIZE*(dur_vert + 1) + dur_hor + 1);
    }
};

int HelpSubstrRet(std::string to_find) {
    if ("pawn" == to_find) return 1;
    if ("rook" == to_find) return 5;
    if ("hors" == to_find) return 3;
    if ("bish" == to_find) return 3;
    if ("quee" == to_find) return 8;
    if ("king" == to_find) return 9;
    return -1;
};

void Player::Figure::GetCharacs(fig_characs& f_characs)
{
    f_characs.fig_name = this->name;
    f_characs.fig_location = this->location;
    f_characs.fig_price = this->price;
    f_characs.fig_color = this->color;
};
#endif
