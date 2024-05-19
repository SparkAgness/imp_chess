#ifndef CHESSBOARD
#define CHESSBOARD
#define CHESSIZE 8
#include "field.h"
#include <iostream>
#include <vector>
class ChessBoard {
    private:
        

    public:
	ChessBoard()
        {
            std::vector<std::vector<Field>> chb;
            for (int hor = 0; hor < CHESSIZE; ++hor) {
	        std::vector<Field> vert;
		for (int ver = 1; ver <= CHESSIZE; ++ver) {
		    Field tmp_field(ver);
		    vert.push_back(tmp_field);
		}
		chb.push_back(vert);
	    
	    }
            
        }

	string NameField_Returner(int num);
        //rerturns field's name after it's number - 1 means "a1", 2 - "a2" etc...
};

#endif
