#ifndef FIGURE
#define FIGURE
#define CHESSIZE 8
#include <iostream>
#include <vector>
#include <string>
#include "field.h"

int HelpSubstrRet(std::string to_find);

class Figure {
    private:
        std::string name;
        int location;
        int price;
	std::string color;

    public:
        Figure(std::string s_name, std::string col)
{
        std::string basis_name = s_name.substr(2, 4);

        this->name = s_name;
        this->color = col;	    
        if ("black" == col) {
            this->location = CHESSIZE + CHESSIZE*(char(s_name[0]) - 'a');
            if (1 == HelpSubstrRet(basis_name)) {
                this->location -= 1;
            }
        } else {
            this->location = 1 + CHESSIZE*(char(s_name[0]) - 'a');
	    if (1 == HelpSubstrRet(basis_name)) {
                this->location += 1; 
            }
        }
       this->price = HelpSubstrRet(basis_name); 
};
        virtual void ChangeLocation();
        virtual void BeatEnemy();
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
