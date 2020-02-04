package src.oop.pset1.view;

public class Actor {
    private String name;
    private String gender;

    public Actor(String name)
    {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Actor{" +
                "name='" + name + '\'' +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(char gernder) {
        this.gender = gender;
    }
}
