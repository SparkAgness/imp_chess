#ifndef FIELD
#define FIELD
#define CHESSIZE 8
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Field {
    char color;
    bool busy;
    int number;
    struct field_define {
        char vert;
	int horiz;
    } f_define;

    public:
        Field(int num) 
        {
            if (num > 64 || num < 1) {
	        std::cout << "It's impossible to create the field with number " << num << std::endl;
	    } else {
	        this->number = num;
                this->busy = false;
	        if (this->number%2) {
                    this->color = 'w';
	        } else this->color = 'b';

               int div = num/CHESSIZE;
	       int mod = num%CHESSIZE;

	       switch (div){
	           case 0: f_define.vert = 'a';
                       break;
                   case 1: if (!mod) f_define.vert = 'a';
                       else f_define.vert= 'b';
	               break;
                   case 2: if (!mod) f_define.vert = 'b';
		       else f_define.vert = 'c';
		       break;
                   case 3: if (!mod) f_define.vert = 'c';
                       else f_define.vert = 'd';
                       break;
                   case 4: if (!mod) f_define.vert = 'd';
                       else f_define.vert = 'e';
		       break;
                   case 5: if (!mod) f_define.vert = 'e';
                       else f_define.vert = 'f';
                       break;
                   case 6: if (!mod) f_define.vert = 'f';
                       else f_define.vert = 'g';
                       break;
                   case 7: if (!mod) f_define.vert = 'g';
                       else f_define.vert = 'h';
	       }
               switch (mod) {
                   case 0: f_define.horiz = 8;
                       break;
                   case 1: f_define.horiz = 1;
                       break;
                   case 2: f_define.horiz = 2;
                       break;
                   case 3: f_define.horiz = 3;
                       break;
                   case 4: f_define.horiz = 4;
                       break;
                   case 5: f_define.horiz = 5;
                       break;
                   case 6: f_define.horiz = 6;
                       break;
                   case 7: f_define.horiz = 7;
	       }
	    }
	    std::cout << f_define.vert << f_define.horiz << std::endl;
	}
        
    field_define GetName();
    void SetBusy();
    bool GetBusy();

};

struct Field::field_define Field::GetName()
{
    return this->f_define;
};

void Field::SetBusy() {
    this->busy = true;
};

bool Field::GetBusy() 
{
    return this->busy;
};
#endif
