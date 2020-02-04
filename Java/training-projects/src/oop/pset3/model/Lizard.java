package src.oop.pset3.model;

public class Lizard implements Move {
    @Override
    public String getName() {
        return "Lizard";
    }

    @Override
    public boolean defeats(Move move) {
        return move.getClass() == Spock.class || move.getClass() == Paper.class;
    }
}
