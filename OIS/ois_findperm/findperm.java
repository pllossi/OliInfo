// WARNING: this is a generic template, not specific to any task

import java.util.*;
import java.io.*;
import java.lang.*;

public class findperm {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        InputStream fin = System.in;
        OutputStream fout = System.out;
        // uncomment the following lines if you want to read/write from files
        //fin = new FileInputStream("input.txt");
        //fout = new FileOutputStream("output.txt");

        Scanner scn = new Scanner(fin);
        PrintStream prnt = new PrintStream(fout);

        int N = scn.nextInt();

        // SAMPLE INTERACTION, REPLACE WITH YOUR CODE
        prnt.format("%d %d\n", 1, 2);
        fout.flush();

        int a = scn.nextInt();

        prnt.print("! ");
        for (int i = 0; i < N; ++i) {
            prnt.format("%d ", i + 1);
        }
        prnt.print("\n");
        fout.flush();
    }
}
