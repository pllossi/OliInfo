// NOTE: it is recommended to use this even if you don't understand the following code.

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace mana {

    class Program {
        static void Main(String[] args) {
            StreamReader streamReader = new StreamReader(Console.OpenStandardInput());
            StreamWriter streamWriter = new StreamWriter(Console.OpenStandardOutput());
            // uncomment the two following lines if you want to read/write from files
            // streamReader = new StreamReader("input.txt");
            // streamWriter = new StreamWriter("output.txt");

            IEnumerator<String> it = GetEnumerator(streamReader);

            int N = Convert.ToInt32(Next(it));
            int K = Convert.ToInt32(Next(it));

            int[] C = new int[N];
            for (int i = 0; i < N; ++i)
                C[i] = Convert.ToInt32(Next(it));

            long M = 0;


            // INSERT YOUR CODE HERE


            streamWriter.WriteLine($"{M}");

            streamReader.Close();
            streamWriter.Close();
        }

        static IEnumerator<String> GetEnumerator(StreamReader sr) {
            String line;
            while ((line = sr.ReadLine()) != null) {
                String[] tokens = line.Split(' ').Where(t => t.Length > 0).ToArray();
                foreach (String t in tokens) {
                    yield return t;
                }
            }
        }

        static String Next(IEnumerator<String> iterator) {
            return iterator.MoveNext() ? iterator.Current : null;
        }
    }
}
