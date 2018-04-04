package src.oop.pset3.controller;

import src.oop.pset3.model.Move;

import java.util.Collections;
import java.util.List;

public class Player2 implements Player {
    @Override
    public Move getMove(Moves moves) {
        return computerMove(moves);
    }

    private Move computerMove(Moves moves) {
        List<Move> move = moves.getMoves();
        Collections.shuffle(move);
        return move.get(0);
    }

}
