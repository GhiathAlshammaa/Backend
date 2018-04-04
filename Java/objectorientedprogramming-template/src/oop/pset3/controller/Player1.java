package src.oop.pset3.controller;

import src.oop.pset3.model.Move;

import java.util.Scanner;
import java.util.stream.Collectors;

public class Player1 implements Player{
    @Override
    public Move getMove(Moves move) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nWrite your move (");
        show(move);
        System.out.print("): ");
        String choice = scanner.nextLine();
        return toMove(choice, move);
    }

    private void show(Moves move) {
        String moves = move.getMoves().stream()
                .map(mov -> mov.getName())
                .collect(Collectors.joining(", "));
        System.out.print(moves);
    }

    private Move toMove(String choice, Moves moves) {
        return moves.getMoves().stream()
                .filter(card -> card.getName().equalsIgnoreCase(choice))
                .findFirst().get();
    }
}
