package Controller;

import Model.Move;

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
