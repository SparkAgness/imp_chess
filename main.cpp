#include <iostream>
#include <string>
#include <utility>
#include "field.h"
#include "figures.h"
#include "player.h"

int main()
{
    Player A("Karpov", 0);
    A.FillFiguresKit(A.FigCreating<Pawn>("a_pawn"));
    A.GetFigure<Pawn>("a_pawn");
    A.PlayerMoveFigure("a_pawn", 3);
    A.GetFigure<Pawn>("a_pawn");
}
