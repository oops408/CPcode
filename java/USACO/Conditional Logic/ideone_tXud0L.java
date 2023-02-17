/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
 class Parent{

      public int display(String str, int... data)throws Exception{

            String s = "(String, int[])";

            System.out.println("Parent "+str + " " + s);

            return 1;

      }

}

 

class Child extends Parent{

      public int display(String str, int... data){

            String s = "(String, int[])";

            System.out.println("Overridden: "+ str+" " +s);

            return 0;

      }

 

      public static void main(String[] args) {

              try {                   

            Parent sb = new Child();

            sb.display("Welcome", 5);

            }

            catch(Exception e) {

 

            } 

      }

}

