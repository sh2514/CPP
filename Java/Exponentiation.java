/* ==================================================
 * Exponentiation
 * Shikuan Huang
 * 
 * Basic recursive implementation
 * Dynamic programming implementation
 * Tail recursive implementation
 * Iterative implementation
 * ==================================================
 */

import java.util.*;
import java.math.*;

public class Exponentiation {
  public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
	System.out.print("Enter a base and a power: ");
	while (input.hasNext()) {
	  int inputBase = input.nextInt();
	  int inputPower = input.nextInt();
	  BigInteger base = new BigInteger(String.valueOf(inputBase));
	  BigInteger power = new BigInteger(String.valueOf(inputPower));
	  System.out.println(base + " raised to the power of " + power + " is " + iPow(base, power) + "\n");
	  System.out.print("Enter a base and a power: ");
	} 
	input.close();
  }
  
  // Basic recursive implementation
  static BigInteger rPow(BigInteger base, BigInteger power) {
	if (power.equals(BigInteger.ZERO)) {
	  return BigInteger.ONE; 
	}
	return base.multiply(rPow(base, power.subtract(BigInteger.ONE)));
  }
  
  // Dynamic programming implementation
  static BigInteger dPow(BigInteger base, BigInteger power) {
	BigInteger[] answers = new BigInteger[power.intValue() + 1];
	Arrays.fill(answers, new BigInteger(String.valueOf(-1)));
	return dPow(base, power, answers);
  }
  
  static BigInteger dPow(BigInteger base, BigInteger power, BigInteger[] answers) {
    BigInteger NegOne = new BigInteger(String.valueOf(-1));
	if (!answers[power.intValue()].equals(NegOne)) {
	  return answers[power.intValue()];
	}
	
	if (power.equals(BigInteger.ZERO)) {
	  answers[power.intValue()] = BigInteger.ONE;
	  return BigInteger.ONE;
	}
	
	answers[power.intValue()] = 
	    base.multiply(dPow(base, power.subtract(BigInteger.ONE), answers));
	return answers[power.intValue()];
  }
  
  // Tail recursive implementation
  static BigInteger tPow(BigInteger base, BigInteger power) {
	return tPow(base, power, BigInteger.ONE);
  }
  
  static BigInteger tPow(BigInteger base, BigInteger power, BigInteger partialProd) {
    if (power.equals(BigInteger.ZERO)) {
      return partialProd;
    }
    
    return tPow(base, power.subtract(BigInteger.ONE), partialProd.multiply(base));
  }
  
  // Iterative implementation
  static BigInteger iPow(BigInteger base, BigInteger power) {
	BigInteger partialProd = BigInteger.ONE;
	for (int i = 0; i < power.intValue(); i++) {
	  partialProd = partialProd.multiply(base);
	}
	return partialProd;
  }
}

