package src.oop.pset3.model;

public interface Move {
    String getName();
    boolean defeats(Move move);
}
