// NOTE: it is recommended to use this even if you don't understand the following code.

import java.util.*;
import java.io.*;
import java.lang.*;

public class quadrilateral {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Locale.setDefault(Locale.US);
        InputStream fin = System.in;
        OutputStream fout = System.out;
        // uncomment the two following lines if you want to read/write from files
        // fin = new FileInputStream("input.txt");
        // fout = new FileOutputStream("output.txt");

        Scanner scn = new Scanner(fin);
        PrintStream prnt = new PrintStream(fout);

        int N = scn.nextInt();
        
        long[] S = new long[N];
        for (int i = 0; i < N; ++i)
            S[i] = scn.nextLong();
        
        boolean ans = true;
        int[] Q = new int[4];
        
        
        // INSERT YOUR CODE HERE
        
        
        if (ans) {
            for (int i = 0; i < 4; ++i)
                prnt.format("%d ", Q[i]);
            prnt.format("\n");
        } else {
            prnt.println("-1");
        }

        fout.flush();
    }
}
