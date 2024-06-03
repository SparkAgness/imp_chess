#ifndef FIGURE
#define FIGURE
#define CHESSIZE 8
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "field.h"

int HelpSubstrRet(std::string to_find);

class Figure
{
    friend class Player;
    friend class Pawn;

    protected:
        std::string name;
        int location;
        int price;
	std::string color;
        std::vector<int> beat_fields {};
        std::vector<int> move_fields {}; 

        struct fig_characs {
            std::string fig_name;
	    int fig_location;
            int fig_price;
	    std::string fig_color;
        } f_characs; 
        struct fig_characs& f_c {f_characs};

    public:
        Figure(std::string, std::string);
        ~Figure();
    private:
        int ChangeLocation(int);
        std::vector<int> GetMvFields();
        std::vector<int> GetBFields();
        void GetCharacs(fig_characs&);
        void ShowInfoMessage();
        void SetMvFields(std::vector<int>&);
        void SetBFields(std::vector<int>&);
        virtual void ChangeState() {};
        virtual void SetDurMVec() {};
        virtual void SetDurBVec() {};
	virtual int MoveFigure(int) {return 0;};
};

class Pawn: private Figure
{
    friend class Player;
    private:
        bool yet_no_motion = true;

        std::vector<int> dur_mvec {};
	std::vector<int> dur_bvec {};
        std::vector<int>& dmv {dur_mvec};
        std::vector<int>& dbv {dur_bvec};

	void SetDurMVec();
        void SetDurBVec();
	void ChangeState();
        void ConversionTo();
	int MoveFigure(int);

        Pawn(std::string s_name, std::string col) : Figure(s_name, col)
        {
            if ("black" == col) {
                std::vector<int> m_vec {7, 15, 23, 31, 39, 47, 55, 63};
                SetMvFields(m_vec);
                ChangeLocation(CHESSIZE*(char(s_name[0]) - 96) - 1);
                SetDurMVec();
                SetMvFields(dmv);
                SetDurBVec();
                SetBFields(dbv);
                
            } else {
                std::vector<int> m_vec {2, 10, 18, 26, 34, 42, 50, 58};
                SetMvFields(m_vec);
                ChangeLocation(CHESSIZE*(char(s_name[0]) - 97) + 2);
                SetDurMVec();
                SetMvFields(dmv);
                SetDurBVec();
                SetBFields(dbv);
            }
	    ShowInfoMessage();
        };
};

int Pawn::MoveFigure(int ch)
{
    this->GetCharacs(this->f_c);
    int tmp = f_characs.fig_location;
    if (!this->ChangeLocation(ch)) {
        this->ChangeState();
        this->SetDurMVec();
        this->SetDurBVec();
        this->SetMvFields(dmv);
        this->SetBFields(dbv);
        std::cout << "Figure " << this->f_characs.fig_name << " has moved from "  << tmp << " to " << ch << std::endl;
        return 0;
    }
    return 1;
};

void Figure::ShowInfoMessage()
{
    GetCharacs(this->f_c);
    std::cout << "Hello, I'm " << this->f_characs.fig_name << " My color is " << this->f_characs.fig_color  << ". My location is " << this->f_characs.fig_location << ". My cost is " << this->f_characs.fig_price << ". My enable to moving fields:";
    for (int i = 0; i < int(this->move_fields.size()); ++i) {std::cout << move_fields[i] << " ";}
    std::cout << "My beat fields:";
    for (int i = 0; i < int(this->beat_fields.size()); ++i) {std::cout << beat_fields[i] << " ";}
    std::cout << std::endl;
};

void Pawn::ChangeState()
{
    this->yet_no_motion = false;
};

void Pawn::SetDurMVec() 
{
    GetCharacs(this->f_c);
    this->dmv.clear();
    int i_limit = 1;
    if (this->yet_no_motion) i_limit = 2; 
    if ("black" == this->f_characs.fig_color) {
        for (int i = 1; i <= i_limit; ++i) this->dmv.push_back(this->f_characs.fig_location - i);
    } else {
        for (int i = 1; i <= i_limit; ++i) this->dmv.push_back(this->f_characs.fig_location + i);
    }
};

void Pawn::SetDurBVec()
{
    GetCharacs(this->f_c);
    this->dbv.clear();
    int dur_hor = this->f_characs.fig_location%CHESSIZE;
    int dur_vert = this->f_characs.fig_location/CHESSIZE;
    if ("black" == this->f_characs.fig_color) {
        if (this->f_characs.fig_location > 9 and this->f_characs.fig_location < 64) this->dbv.push_back(CHESSIZE*(dur_vert) - CHESSIZE + dur_hor - 1);    
        if (this->f_characs.fig_location > 0 and this->f_characs.fig_location < 57) this->dbv.push_back(CHESSIZE*(dur_vert + 1) + dur_hor - 1);
    } else {
        if (this->f_characs.fig_location > 9 and this->f_characs.fig_location < 64) this->dbv.push_back(CHESSIZE*(dur_vert - 1) + dur_hor + 1); 
        if (this->f_characs.fig_location > 0 and this->f_characs.fig_location < 57) this->dbv.push_back(CHESSIZE*(dur_vert + 1) + dur_hor + 1);
    }
};


void Figure::GetCharacs(fig_characs& f) 
{
    f.fig_name = this->name;
    f.fig_location = this->location;
    f.fig_price = this->price;
    f.fig_color = this->color;
};

Figure::Figure(std::string s_name, std::string col)
{
    this->name = s_name;
    this->color = col;
    this->price = HelpSubstrRet(s_name.substr(2,4));
    this->location = 0;
};

Figure::~Figure()
{
    std::cout << "The " << this->color << " " << this->name << " has been deleted!" << std::endl;
};

int Figure::ChangeLocation(int ch)
{
    if (this->move_fields.end() != std::find(this->move_fields.begin(),this->move_fields.end(), ch)) this->location = ch;
    else return 1;
    return 0; 

};

std::vector<int> Figure::GetMvFields() 
{
    return this->move_fields;
};

std::vector<int> Figure::GetBFields()
{
    return this->beat_fields;
};

void Figure::SetBFields(std::vector<int>& bf) 
{
    this->beat_fields.clear();
    for (int b : bf) this->beat_fields.push_back(b);
};

void Figure::SetMvFields(std::vector<int>& mvf)
{
    this->move_fields.clear();
    for(int m : mvf) this->move_fields.push_back(m);
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
#endif
