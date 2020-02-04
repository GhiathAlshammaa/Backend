package src.oop.pset3.controller;

//import model.*;
import src.oop.pset3.model.*;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Moves {
    private List<Move> moves;

    public Moves() {
        moves = Stream.of(
                new Paper(),
                new Rock(),
                new Scissor(),
                new Lizard(),
                new Spock()
        ).collect(Collectors.toList());
    }

    public List<Move> getMoves() {
        return new ArrayList<>(moves);
    }
}
