import java.util.*;

public class Main {

  public static void main(String[] args) {
  	try {
	    Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();
	    while (T-- > 0) {
	      if (sc.hasNextInt()) {
	        int S = sc.nextInt();
	      }
	      if (sc.hasNextInt()) {
	        int C = sc.nextInt();
	        int[] X = new int[S];
	        for (int i = 0; i < S; i++) {
	          if (sc.hasNextInt()) {
	            X[i] = sc.nextInt();
	          }
	        }
	        int d = (X[S - 1] - X[S - 2]) / (S - 1);
	        for (int i = S; i < S + C; i++) {
	          System.out.print(X[S - 1] + d * (i - S + 1) + " ");
	        }
	        System.out.println();
	      }
	    }
	    sc.close();
  	}
  	catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Out of Bounds.");
    } 
    catch (Exception e) {
      System.out.println("An error occurred: " + e.getMessage());
    }
  }
}