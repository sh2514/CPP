/* ==================================================
 * Fibonacci
 * Shikuan Huang
 * 
 * Basic recursive implementation
 * Dynamic programming implementation
 * Tail recursive implementation
 * ==================================================
 */

import java.math.BigInteger;
import java.util.*;

public class Fibonacci {
  public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
	System.out.println("Fibonacci of? ");
	long userInput = input.nextLong();
	BigInteger converted = new BigInteger(String.valueOf(userInput));
	System.out.println("Fib(" + converted + ") = " + iFib(converted));
	input.close();
  }
  
  // Basic recursive implementation
  static BigInteger rFib(BigInteger arg) {
    if (arg.equals(BigInteger.ZERO) || arg.equals(BigInteger.ONE)) {
      return arg;
    }
    
    BigInteger TWO = new BigInteger(String.valueOf(2));
    return rFib(arg.subtract(BigInteger.ONE)).add(rFib(arg.subtract(TWO)));
  }
  
  // Dynamic programming implementation
  static BigInteger dFib(BigInteger arg) {
	BigInteger[] answers = new BigInteger[arg.intValue() + 1];
	Arrays.fill(answers, new BigInteger(String.valueOf(-1)));
    return dFib(arg, answers);
  }
  
  static BigInteger dFib(BigInteger arg, BigInteger[] answers) {
	BigInteger NegOne = new BigInteger(String.valueOf(-1));
    if (!answers[arg.intValue()].equals(NegOne)) {
      return answers[arg.intValue()];
    }
    
    if (arg.equals(BigInteger.ZERO) || arg.equals(BigInteger.ONE)) {
      answers[arg.intValue()] = arg;
      return arg;
    }
    
    BigInteger TWO = new BigInteger(String.valueOf(2));
    answers[arg.intValue()] = dFib(arg.subtract(BigInteger.ONE), answers)
        .add(dFib(arg.subtract(TWO), answers));
    return answers[arg.intValue()];
  }
  
  // Tail recursive implementation
  static BigInteger tFib(BigInteger arg) {
	if (arg.equals(BigInteger.ZERO)) {
	  return arg;
	}
	
	return tFib(arg.subtract(BigInteger.ONE), BigInteger.ZERO, BigInteger.ONE);
  }
  
  static BigInteger tFib(BigInteger arg, BigInteger first, BigInteger second) {
	if (arg.equals(BigInteger.ZERO)) {
	  return second;
	}
	
	return tFib(arg.subtract(BigInteger.ONE), second, first.add(second));
  }
  
  // Iterative implementation
  static BigInteger iFib(BigInteger arg) {
	if (arg.equals(BigInteger.ZERO)) {
	  return arg;
	}
    BigInteger first = BigInteger.ZERO;
    BigInteger second = BigInteger.ONE;
    BigInteger temp = BigInteger.ZERO;
    
    while (!arg.equals(BigInteger.ONE)) {
      temp = first.add(second);
      first = second;
      second = temp;
      arg = arg.subtract(BigInteger.ONE);
    }
    
    return temp;
  }
}
