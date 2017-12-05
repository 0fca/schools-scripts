package com.company;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        //List<String> list = loadFile();
        List<String> lines = loadFile();
        List<String> out = new ArrayList<>();

        for (String line : lines) {
            if (isPilandrom(line)) {
                out.add(line);
                System.out.println(line);
            }
        }

        saveToFile(out);
        System.out.println(String.valueOf(((char)(3))).toLowerCase());
    }

    static List<String> loadFile() throws IOException {
        return Files.readAllLines(Paths.get("C:\\Users\\R_Informatyka\\IdeaProjects\\Zadanie\\palindromy.txt"));
    }

    static void saveToFile(List<String> list) throws IOException {
        final BufferedWriter bw = new BufferedWriter(new FileWriter("wynik.txt"));
        list.forEach(line ->{
            try {
                bw.append(line);
                bw.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
        bw.append(String.valueOf(list.size()));
        bw.flush();
        bw.close();
    }

    static boolean isPilandrom(String line){
        boolean isOk = true;
        line = line.trim();
        line = line.toLowerCase();
        line = clearChars(line);
        //System.out.println(line);
        String[] split = line.split(" ");

        StringBuilder lineBuilder = new StringBuilder();
        for(String con : split){
            lineBuilder.append(con);
        }

        line = lineBuilder.toString();

        for(int i = 0; i < line.toCharArray().length / 2; i++){
            char c = line.toCharArray()[i];
            char c2 = line.toCharArray()[line.toCharArray().length - i - 1];
                if(c != c2) {
                    isOk = false;
                    break;
                }
        }

        return isOk;
    }

    static String clearChars(String line){
        StringBuilder out = new StringBuilder();

        for(int i = 0; i < line.toCharArray().length; i++){
            char c = line.toCharArray()[i];
            if((c >= 'a' && c <= 'z')){
                out.append(String.valueOf(c));
            }
        }
        return out.toString();
    }
}
