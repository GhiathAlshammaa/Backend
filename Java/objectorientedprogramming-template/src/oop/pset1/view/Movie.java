package src.oop.pset1.view;

import java.util.List;

public class Movie {

//    private List<String> genres;
    private String title;
    private float rate;
    private String geners;
    //public float getTitle;

//    public Movie (List<String> genres) {
//        this.genres = genres;
//    }
//

    public Movie() {

    }

    public Movie (String title, float rate, String genres) {
        this.title = title;
        this.rate = rate;
        this.geners = genres;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public float getRate() {
        return rate;
    }

    public void setRate(float rate) {
        this.rate = rate;
    }

//    public List<String> getGenres() {

    public String getGeners() {
        return geners;
    }

    public void setGeners(String geners) {
        this.geners = geners;
    }
//        return geners;
//    }
//
//    public void setGenres(List<String> genres) {
//        this.geners = genres;
//    }

    @Override
    public String toString() {
        return "Movie{" +
                "genres=" + geners +
                ", title='" + title + '\'' +
                ", rate=" + rate +
                '}';
    }
}
