/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
	int[] data;
    data = new int[]{2,4,10,6,8};
    int i, len, max_num;
    len = data.length;
    for(i = 0; i < len; i++){
      System.out.print(data[i] + ", ");
    }
    System.out.println();
    max_num = data[0];
    for(i = 1; i < len; i++){
      if(data[i] > max_num) max_num = data[i];            
    }
    System.out.println("Num" +  " : " + max_num);
	}
}