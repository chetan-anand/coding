public class NumberTest {
 public static void main(String args[]) { 
 	int n=44;
 	int counter=1; 
 	int result=1; 
 	while(true) { 
 		result =n*counter; String tmp= result+""; int nine=0; 
 		for (int i =0;i<tmp.length();i++) 
 			{ if(tmp.charAt(i)== '9' || tmp.charAt(i)== '0') nine++; else break; } 
 			if(nine==tmp.length()) 
 				break; 
 			counter++; 
 		} System.out.println(result + " dds" +counter); 
 	} 
 }