package src.oop.pset3.model;

public class Scissor implements Move {
    @Override
    public String getName() {
        return "Scissor";
    }

    @Override
    public boolean defeats(Move move) {
        return move.getClass() == Paper.class || move.getClass() == Lizard.class;
    }
}
