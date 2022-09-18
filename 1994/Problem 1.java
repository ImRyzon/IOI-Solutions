import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main {
    static FastReader FastReader = new FastReader();
    static BufferedWriter o = new BufferedWriter(new OutputStreamWriter(System.out));
    static PrintWriter pw;

    static void solve() throws Exception {
        int n = readInt(), dp[][] = new int[n+1][n+1], max = 0;
        dp[1][1] = readInt();
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int num = readInt();
                dp[i][j] = Math.max(dp[i-1][j-1] + num, dp[i-1][j] + num);
                if (i == n && dp[i][j] > max) max = dp[i][j];
            }
        }
        o.write(max + "\n");
    }

    public static void main(String[] args) throws Exception {
        int TEST_CASES = 1;
        for (int i = 1; i <= TEST_CASES; i++) solve();
        exit();
    }

    static class Pair {
        int first, second;
        public Pair(int first, int second) {this.first = first; this.second = second;}
    }

    private static class Edge implements Comparable <Edge> {
        int v, w;
        public Edge(int v, int w) {this.v = v; this.w = w;}
        public int compareTo(Edge e) {return w - e.w;}
    }

    static void setPrintWriter() throws Exception {
        // For Debugging Purposes
        pw = new PrintWriter(new BufferedWriter(new FileWriter("Notepad.txt", true)));
    }

    static void exit() throws Exception {
        o.close();
        System.exit(0);
    }

    static int readInt() {return FastReader.readInt();}
    static long readLong() {return FastReader.readLong();}
    static double readDouble() {return FastReader.readDouble();}
    static float readFloat() {return FastReader.readFloat();}
    static String readLine() {return FastReader.readLine();}
    static String next() {return FastReader.next();}
    static boolean readBool() {return FastReader.readBool();}

    static class FastReader extends PrintWriter {
        private final InputStream stream;
        private final byte[] buf = new byte[1 << 16];
        private int curChar, numChars;
        public FastReader() {this(System.in, System.out);}
        public FastReader(InputStream i, OutputStream o) {super(o);stream = i;}
        public FastReader(String i, String o) throws IOException {
            super(new FileWriter(o)); stream = new FileInputStream(i);
        }
        private int readByte() {
            if (numChars == -1) {throw new InputMismatchException();}
            if (curChar >= numChars) {
                curChar = 0;
                try {numChars = stream.read(buf);
                }catch(Exception e){throw new InputMismatchException();}
                if (numChars == -1) {return -1;}
            }
            return buf[curChar++];
        }
        public String next() {
            int c; do {c = readByte();} while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c > ' ');
            return res.toString();
        }
        public String readLine() {
            int c; do {c = readByte();} while (isEndLine(c));
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c >= ' ');
            return res.toString();
        }
        public int readInt() {
            int c, sgn = 1, res = 0;
            do {c = readByte();} while (c <= ' ');
            if (c == '-') {sgn = -1;c = readByte();}
            do {
                if (c < '0' || c > '9') {throw new InputMismatchException();}
                res = 10 * res + c - '0';c = readByte();
            } while (c > ' ');
            return res * sgn;
        }
        public double readDouble() {return Double.parseDouble(next());}
        public long readLong() {return Long.parseLong(next());}
        public float readFloat() {return Float.parseFloat(next());}
        public boolean readBool() {return Boolean.parseBoolean(next());}
        boolean isEndLine(int c) {return c == '\n' || c == '\r' || c == -1;}
    }
}
