// WARNING: this is a generic template, not specific to any task

import java.util.*;
import java.io.*;
import java.lang.*;

public class alienabc {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        InputStream fin = System.in;
        OutputStream fout = System.out;
        // uncomment the following lines if you want to read/write from files
        //fin = new FileInputStream("input.txt");
        //fout = new FileOutputStream("output.txt");

        Scanner scn = new Scanner(fin);
        PrintStream prnt = new PrintStream(fout);

        int T = Integer.parseInt(scn.nextLine());
        for (int i = 0; i < T; i++) {
            String S = scn.nextLine();
	    String abc = "";
	    // insert your code here

	    prnt.format("%s\n", abc); // print the i-th result
	    fout.flush();
	}
	scn.close();
    }
}
