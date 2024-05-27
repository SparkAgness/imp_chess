#ifndef FIGURE
#define FIGURE
#define CHESSIZE 8
#define DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "field.h"

int HelpSubstrRet(std::string to_find);

class Figure 
{
    friend class Player;

    private:
        std::string name;
        int location;
        int price;
	std::string color;

    public:
        struct fig_characs {
            std::string fig_name;
	    int fig_location;
            int fig_price;
	    std::string fig_color;
        } f_characs; 

        bool CheckPossibleField(std::vector<int>, int);

	fig_characs& f_c {f_characs};

        void GetCharacs(fig_characs& f_characs);

	Figure(std::string s_name, std::string col)
        {
            std::string basis_name = s_name.substr(2, 4);

            this->name = s_name;
            this->color = col;	    
            this->price = HelpSubstrRet(basis_name); 
	    this->price = 0;
	    this->location = 0;
        };

	
        void ChangeLocation(int ch_loc) 
        {
            if (ch_loc > 0 and ch_loc < 65) this->location = ch_loc;
        }
        
        void ChangeCast(int cst) 
        {
            this->price = cst;	
	}
        //virtual void BeatEnemy() = 0;
};



class Pawn : public Figure
{
    friend class Player;

    private:
	std::vector<int> beat_fields {};
        std::vector<int> move_fields {};
	bool yet_no_motion;
    public:
        void ShowInfoMessage();
        void SetPawnsMoveF();
        void SetPawnsBeatF();
        void TestForZeroes();
        std::vector<int> GetPawnsMoveF();
        std::vector<int> GetPawnsBeatF();

        Pawn(std::string s_name, std::string col) : Figure(s_name, col) 
        {
            this->yet_no_motion = true;
            GetCharacs(f_c);
            ChangeCast(1);
            if("black" == this->f_characs.fig_color) {
                ChangeLocation(CHESSIZE*(char(s_name[0]) - 96) - 1);
            } else {
                ChangeLocation( CHESSIZE*(char(s_name[0]) - 97) + 2);
            } 
	    SetPawnsMoveF();
	    SetPawnsBeatF();
            ShowInfoMessage();
	};
        ~Pawn() 
        {
        std::cout << this->f_characs.fig_name << " " << this->f_characs.fig_color << " deleted!!!" << std::endl;
        };
};

std::vector<int> Pawn::GetPawnsMoveF() 
{
    return this->move_fields;
};

std::vector<int> Pawn::GetPawnsBeatF()
{
    return this->beat_fields;
};

bool Figure::CheckPossibleField(std::vector<int> fields, int field)
{
    return (fields.end() == std::find(fields.begin(), fields.end(), field));
};

void Pawn::ShowInfoMessage()
{
    GetCharacs(this->f_c);
    std::cout << "Hello, I'm " << this->f_characs.fig_name << ". My location is " << this->f_characs.fig_location << ". My cost is " << this->f_characs.fig_price << ". My enable to moving fields:";
    for (int i = 0; i < int(this->move_fields.size()); ++i) {std::cout << move_fields[i] << " ";}
    std::cout << "My beat fields:";
    for (int i = 0; i < int(this->beat_fields.size()); ++i) {std::cout << beat_fields[i] << " ";}
    std::cout << std::endl;
};

void Pawn::SetPawnsMoveF() 
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

void Pawn::SetPawnsBeatF()
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

void Figure::GetCharacs(fig_characs& f_characs)
{
    f_characs.fig_name = this->name;
    f_characs.fig_location = this->location;
    f_characs.fig_price = this->price;
    f_characs.fig_color = this->color;
};
#endif
