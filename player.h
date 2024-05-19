#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
#include "field.h"
#include "in_figures.h"

class Player
{
       
    public:
        class Figure
        {
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

	        fig_characs& f_c {f_characs};

                void GetCharacs(fig_characs& f_characs);

	        Figure(std::string s_name, std::string col);

                void ChangeLocation(int);
		void ChangeCast(int);
        };
	
	class Pawn : public Figure 
        {
            private:
                std::vector<int> move_fields {};
	        std::vector<int> beat_fields {};
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
		this->ShowInfoMessage();
                };

		        ~Pawn()
                {                    
                    std::cout << this->f_characs.fig_name << " " << this->f_characs.fig_color << " deleted!!!" << std::endl;    
                };
 
        };

	std::string GetFigColor(int);

    private:
        std::vector<std::string> figures_names {"a_pawn", "b_pawn", "c_pawn", "d_pawn", "e_pawn", "f_pawn", "g_pawn", "h_pawn", "a_rook", "b_horse", "c_bishop", "d_queen", "e_king", "f_bishop", "g_horse", "h_rook"};
	std::vector<std::string> fig_color {"white", "black"};
        std::string player_color;
	std::string player_name;
	std::vector<Figure> figures_kit {};
 
    public:
        void FiguresKitCreating();
        void FigMoving(int, int);
        void KitRecap();

        Player(std::string name, int color)
        {
            this->player_name = name;
            this->player_color = this->fig_color[color]; //0 is white, 1 is black
            std::cout << "The player " << this->player_name << " was created. Figures color is "  << this->player_color << std::endl;
            FiguresKitCreating();
	}


};

void Player::KitRecap()
{
    for (int i = 0; i < CHESSIZE; ++i) {
        figures_kit[i].GetCharacs(figures_kit[i].f_c);
        std::cout << this->figures_kit[i].f_characs.fig_name << std::endl;
    }
};
void Player::FigMoving(int kit_index, int dest)
{
    this->figures_kit[kit_index].ChangeLocation(dest);
};

void Player::FiguresKitCreating()
{
    int fc = 1;
    if ("white" == this->player_color) fc = 0;
    for (int i = 0; i < CHESSIZE; ++i) {
        Player::Pawn apawn(this->figures_names[i], this->fig_color[fc]);
	this->figures_kit.push_back(apawn);
    }
};

std::string Player::GetFigColor(int co)
{
    return this->fig_color[co];
};
#endif
