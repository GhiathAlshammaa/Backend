package View;

import Model.Move;
import Model.Paper;
import Model.Rock;
import Model.Scissor;

import java.util.HashMap;

public class Jury {

    private HashMap<String, String> hashMap;
    public Jury(){
        hashMap = new HashMap<>();
        hashMap.put(Rock.class.getSimpleName(), Scissor.class.getSimpleName());
        hashMap.put(Scissor.class.getSimpleName(), Paper.class.getSimpleName());
        hashMap.put(Paper.class.getSimpleName(), Rock.class.getSimpleName());
    }
    public void sayResult(Move move1, Move move2) {
        System.out.println("The Player1 move: " + move1.getName());
        System.out.println("The Computer move: " + move2.getName());

        if (move1.getName().equalsIgnoreCase(move2.getName())){
            System.out.println("Draw");
            return;
        }

        String winningMove = hashMap.get(move1.getName());
        if (winningMove.equalsIgnoreCase(move2.getName())){
            System.out.println("Player1 wins");
            return;
        }
        System.out.println("Computer wins");
    }

}
