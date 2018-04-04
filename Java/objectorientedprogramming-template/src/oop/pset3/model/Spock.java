package src.oop.pset3.model;

public class Spock implements Move {
    @Override
    public String getName() {
        return "Spock";
    }

    @Override
    public boolean defeats(Move move) {
        return move.getClass() == Scissor.class || move.getClass() == Rock.class;
    }
}
