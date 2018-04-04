package oop.pset1;

/*
import oop.pset1.controller.MovieDatabaseSummarizer;
import oop.pset1.view.Summary;
import oop.pset1.view.SummaryDisplayer;
*/


import src.oop.pset1.view.Actor;
import src.oop.pset1.view.Movie;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Pset1Main {

    public static void main(String[] args) throws IOException {
    /*
        MovieDatabaseSummarizer summarizer = new MovieDatabaseSummarizer();
        SummaryDisplayer displayer = new SummaryDisplayer();

        Optional<Summary> summary = summarizer.summarize();
        if(summary.isPresent()){
            displayer.display(summary.get());
        } else {
            displayer.display();
        }
    */
        // shared lines of code between all the answers
        String MovieFilePath = "C:\\Users\\GHIATH\\Documents\\GitHub\\objectorientedprogramming-template\\src\\oop\\pset1\\data\\movies.csv";
        String ActorFilePath = "C:\\Users\\GHIATH\\Documents\\GitHub\\objectorientedprogramming-template\\src\\oop\\pset1\\data\\actors.csv";

        // First answer lines
        List<String> lines = Files.readAllLines(Paths.get(MovieFilePath));
        // Second answer lines
         List<String> lines2 = Files.readAllLines(Paths.get(ActorFilePath));
        // Third answer lines
        List<String> lines3 = Files.readAllLines(Paths.get(MovieFilePath));


//        // First answer
        System.out.println("1) First question :");
        List<Movie> movies = lines.stream()
            .skip(1)
            .map(s -> s.split(";"))
            .filter(strings -> strings.length == 24)
            .map(strings -> createNewMovie(strings))
            .sorted(Comparator.comparing(Movie::getRate).reversed())
            .limit(5)
            .collect(Collectors.toList());

        System.out.println("Most rated films:");
        System.out.println("## Result ##");
        movies.forEach(movie -> System.out.println(movie.getTitle() + "(" + movie.getRate() + ")" ));
        System.out.println("##################################");

        // Second answer
        System.out.println("2) Second question :");
        System.out.println("Most hired actors:");

        List<Actor> actors =
                lines2.stream().skip(1)
                      .map(s ->(s.split(";")[0]))
                      .map(object -> object.split("},"))
                      .flatMap(e -> Stream.of(e))
                      .map(s->s.split(","))
                       .filter(e -> e.length >= 5)
                       .flatMap(e -> Stream.of(e))
                      .filter(e->e.contains("'name':"))
                      .map(l->l.replaceAll("name: ", "").replaceAll("'", ""))
                      .map(l->l.replaceAll("name:", ""))
                      .map(l->l.replaceAll(" ", ""))
                      .map(s -> createNewActor(s))
                      .collect(Collectors.toList());


        System.out.println("## Result ##");
        Map<String, Long> map =
                 actors.stream()
                .map(actor -> actor.getName())
                .collect(Collectors.groupingBy(e -> e, Collectors.counting()));

        map.entrySet().stream()
                .filter(entry -> entry.getValue() > 1)
                .sorted((e1, e2) -> e2.getValue().compareTo(e1.getValue()))
                .limit(5)
                .map(entry -> entry.getKey() + "(" + entry.getValue() + ")" )
                .forEach(line -> System.out.println(line));

        System.out.println("##################################");

        // Third answer
        System.out.println("3) Third question :");
        List<Movie> movies2 = lines3.stream()
            .skip(1)
            .map(s -> s.split(";"))
            .filter(strings -> strings.length == 24)
            .flatMap(e -> Stream.of(e[3]))
            .map(s -> s.split("}, "))
            .flatMap(e -> Stream.of(e))
            .map(l->l.replaceAll("\\[", "").replaceAll("]",""))
            .map(l->l.replaceAll("\\{", "").replaceAll("}",""))
            .map(s->s.split(", "))
            .flatMap(e -> Stream.of(e))
            .filter(e->e.contains("'name': "))
            .map(l->l.replaceAll("'name':", "").replaceAll("'",""))
            .map(g -> g.trim())
//          .peek(m -> System.out.println(m))
            .map(strings -> createNewMovieForGeners(strings))
            .collect(Collectors.toList());

//         Display all the Geners
//        movies2.forEach(movie -> System.out.println(movie.getGeners()));

        System.out.println("Most appearing movie genres:");

        System.out.println("## Result ##");
        Map<Object, Long> map2 =
                 movies2.stream()
                .map(movie -> movie.getGeners())
                .collect(Collectors.groupingBy(e -> e, Collectors.counting()));

        map2.entrySet().stream()
                .filter(entry -> entry.getValue() > 1)
                .sorted((e1, e2) -> e2.getValue().compareTo(e1.getValue()))
                .map(entry -> entry.getKey() + "(" + entry.getValue()+")")
                .limit(2)
                .forEach(line -> System.out.println(line));

        System.out.println("##################################");


    }// End Main



    /* a Function related in first Task */

    public static Movie createNewMovie(String[] strings)
    {
        return new Movie(strings[20], Float.parseFloat(strings[22]),strings[3]);
    }

    /* a Function related in second Task */

    public static Actor createNewActor(String strings)
    {
        //return new Actor(strings[5]);
        return new Actor(strings);
    }

    /* a Function related in third Task */
    public static Movie createNewMovieForGeners(String string)
    {
        Movie movie = new Movie();
        movie.setGeners(string);
        return movie;
    }

}
