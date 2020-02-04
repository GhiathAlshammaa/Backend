import Controller.Game;

import java.util.Scanner;

public class Pset2Main {
    public static void main(String[] args) {
        String choice;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Host - Welcome to the Rock, Scissors, Paper tournament!");
        do {
            new Game().play();
            System.out.print("Do you want to play again? (y/n): ");
            choice = scanner.next();
        } while (choice.toLowerCase().startsWith("y"));

        System.out.print("Host - Goodbye!");
        System.exit(0);

    }
}
