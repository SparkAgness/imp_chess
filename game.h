#ifndef GAME
#define GAME
#include<iostream>
#include<string>
#include<vector>

#include "figures.h"
#include "player.h"
#include "field.h"

struct figures_kit {
    std::vector<Pawn> pawns_kit;
};

struct all_figures {
    figures_kit white;
    figures_kit black;
};

class Game
{
    private:
        all_figures games_kit;
        bool inning = false; // false - whites inning, true - blacks inning
    public:
        Game(const std::vector<Pawn>&, bool); //during the figures creating queue elements will be added into figures_kit and here
        void InningChange();
};

void Game::InningChange()
{
    this->inning = (false == this->inning)?true:false;
};

Game::Game(const std::vector<Pawn>& created, bool white = false) 
{
    if (white) { 
        this->games_kit.white.pawns_kit = created;
        std::cout << "White figures kit has been collected..." << std::endl;
    } else {
        this->games_kit.black.pawns_kit = created;
        std::cout << "Black figures kit has been collected..." << std::endl;
    }
};
#endif

