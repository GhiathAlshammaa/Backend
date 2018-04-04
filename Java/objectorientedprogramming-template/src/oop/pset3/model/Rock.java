package src.oop.pset3.model;

public class Rock implements Move {
    @Override
    public String getName() {
        return "Rock";
    }

    @Override
    public boolean defeats(Move move) {
        return move.getClass() == Lizard.class || move.getClass() == Scissor.class;
    }
}
