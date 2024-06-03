In file figures.h the Figure class is redifinited. Vectors of MoveFields and BeatFields has become of mother's class members. They can be changed with SetMvFields/SetBFields methods.
In file player.h realize the struct figures_kit of vectors with figures type across the templates. Across the struct others methods of moving, beating etc maybe realized.

Because method Figure::ShowInfoMessage() changes implicity any daughter-class (Pawn e.g.) to Figure, any of methods, which use ShowInfoMessage(), conversates implicitly any class to class Figure. Solution of the problem maybe realize to change Figure::ShowInfoMessage to ...
