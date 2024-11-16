// WARNING: this is a generic template, not specific to any task

import java.util.*;
import java.io.*;
import java.lang.*;

public class f1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        InputStream fin = System.in;
        OutputStream fout = System.out;
        // uncomment the following lines if you want to read/write from files
        //fin = new FileInputStream("input.txt");
        //fout = new FileOutputStream("output.txt");

        Scanner scn = new Scanner(fin);
        PrintStream prnt = new PrintStream(fout);

        int N = scn.nextInt();
        int[] H = new int[N];
        for (int i = 0; i < N; i++)
            H[i] = scn.nextInt();
        int[] V = new int[N];
        for (int i = 0; i < N; i++)
            V[i] = scn.nextInt();
        // insert your code here

        prnt.format("%d\n", 42); // print the result
        fout.flush();
    }
}
