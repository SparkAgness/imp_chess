#include <iostream>
#include <string>
#include <utility>
#include "field.h"
#include "figures.h"
#include "player.h"

int main()
{
    struct Figures_Kit {
        std::vector<Pawn> pawns_kit;
    };
    Figures_Kit white_kit;

    Player Karpov("Karpov", 0);
    Karpov.FigCreating<Pawn>("a_pawn");

}

