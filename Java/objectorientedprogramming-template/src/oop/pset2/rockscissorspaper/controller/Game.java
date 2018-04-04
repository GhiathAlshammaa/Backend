package Controller;

import Model.Move;
import View.Jury;

public class Game {
    private PlayerMotel playerMotel = new PlayerMotel();

    public void play() {
        Player player1 = playerMotel.getHumenPlayer();
        Player player2 = playerMotel.getComputerPlayer();
        Moves moves = new Moves();
        Move move1 = player1.getMove(moves);
        Move move2 = player2.getMove(moves);
        Jury jury = new Jury();
        jury.sayResult(move1, move2);
    }
}
