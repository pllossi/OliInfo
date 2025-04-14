// NOTE: it is recommended to use this even if you don't understand the following code.

import java.util.*;
import java.io.*;
import java.lang.*;

public class kmtogo {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Locale.setDefault(Locale.US);
        InputStream fin = System.in;
        OutputStream fout = System.out;
        // uncomment the two following lines if you want to read/write from files
        // fin = new FileInputStream("input.txt");
        // fout = new FileOutputStream("output.txt");

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(fout));
        reader = new BufferedReader(new InputStreamReader(fin));
        scn = new StringTokenizer(reader.readLine());

        int N = Integer.parseInt(next());

        int[] D = new int[10];


        // INSERT YOUR CODE HERE


        for (int i = 0; i < 10; ++i) {
            writer.write(String.valueOf(D[i]));
            writer.write(' ');
        }
        writer.write('\n');

        writer.flush();
    }

    static String next() throws IOException {
        while (!scn.hasMoreTokens()) scn = new StringTokenizer(reader.readLine());
        return scn.nextToken();
    }

    static BufferedReader reader;
    static StringTokenizer scn;
}
