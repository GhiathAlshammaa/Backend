package src.oop.pset3.controller;

public class PlayerMotel {
    public Player getComputerPlayer() {
        return new Player2();
    }

    public Player getHumenPlayer() {
        return new Player1();
    }
}
