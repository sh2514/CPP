/* ==================================================
 * Factorial
 * Shikuan Huang
 * 
 * Basic recursive implementation
 * Dynamic programming implementation
 * Tail recursive implementation
 * Iterative implementation
 * 
 * Arrays.fill can be used to fill an array of a primitive type.
 *   Arrays.fill(array, val);
 * ==================================================
 */
import java.util.*;
import java.math.BigInteger;

public class Factorial {
  public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
	System.out.println("Factorial of? ");
	long userInput = input.nextLong();
	BigInteger converted = new BigInteger(String.valueOf(userInput));
	System.out.println("Factorial(" + userInput +") = " + iFactorial(converted));
	input.close();
  }
  
  // Basic recursive implementation
  static BigInteger rFactorial(BigInteger arg) {
	if (arg.equals(BigInteger.ZERO) || arg.equals(BigInteger.ONE)) {
      return BigInteger.ONE;
	}
    return arg.multiply(rFactorial(arg.subtract(BigInteger.ONE)));
  }
  
  // Dynamic programming implementation
  static BigInteger dFactorial(BigInteger arg) {
    BigInteger[] answers = new BigInteger[arg.intValue() + 1];
    Arrays.fill(answers, new BigInteger(String.valueOf(-1)));
    return dFactorialRecursiveHelper(arg, answers);
  }
  
  static BigInteger dFactorialRecursiveHelper(BigInteger arg, BigInteger[] answers) {
	BigInteger NegOne = new BigInteger(String.valueOf(-1));
	if (!answers[arg.intValue()].equals(NegOne)) {
	  return answers[arg.intValue()];
	}

	if (arg.equals(BigInteger.ZERO) || arg.equals(BigInteger.ONE)) {
	  answers[arg.intValue()] = arg;
	  return arg;
	}
	
	answers[arg.intValue()] = 
	    arg.multiply(dFactorialRecursiveHelper(arg.subtract(BigInteger.ONE), answers));
	return answers[arg.intValue()];
  }
  
  // Tail recursive implementation
  static BigInteger tFactorial(BigInteger arg) {
	return tFactorial(arg, BigInteger.ONE);
  }
  
  static BigInteger tFactorial(BigInteger arg, BigInteger partialAns) {
	if (arg.equals(BigInteger.ZERO) || arg.equals(BigInteger.ONE)) {
	  return partialAns;
	}
	
	return tFactorial(arg.subtract(BigInteger.ONE), partialAns.multiply(arg));
  }
  
  // Iterative implementation
  static BigInteger iFactorial(BigInteger arg) {
	BigInteger argCopy = arg;
	BigInteger partialSum = new BigInteger(String.valueOf(1));
	for (int i = argCopy.intValue(); i > 1; i--) {
	  partialSum = partialSum.multiply(argCopy);
	  argCopy = argCopy.subtract(BigInteger.ONE);
	}
	return partialSum;
  }
}
