/* ==================================================
 * Swap the value of two variables
 * Shikuan Huang
 * ==================================================
 */
public class Swap {
  public static void main(String[] args) {
    Wrapper<Integer> first = new Wrapper<Integer>(5);
    Wrapper<Integer> second = new Wrapper<Integer>(99);
    System.out.println("Before, first = " + first + ", second = " + second);
    swap(first, second);
    System.out.println("After, first = " + first + ", second = " + second);
  }
  
  static class Wrapper<T> {
    private T item;
    
    public Wrapper(T arg) {
      item = arg;
    }
    
    public T value() {
      return item;
    }
    
    public boolean set(T arg) {
      item = arg;
      return true;
    }
    
    public String toString() {
      return item.toString();
    }
  }
  
  static <T> void swap(Wrapper<T> first, Wrapper<T> second) {
    T temp = first.value();
    first.set(second.value());
    second.set(temp);
  }
}
