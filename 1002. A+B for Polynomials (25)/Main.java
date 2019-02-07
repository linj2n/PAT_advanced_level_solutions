import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init (InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer(" ");
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    public static void main(String[] args) {
        Main.init( System.in ); // connect Reader to an input stream

    }
}
