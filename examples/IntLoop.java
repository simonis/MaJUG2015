public class IntLoop {

  static void loop(int count) {
    for (int i = 0; i < count; i++)
      for (int j = 0; j < 1_000_000; j++);
  }

  public static void main(String[] args) {

    for (long i = 0; i < 100; i++)
      loop(2);
    System.out.println("Warmup done");

    long start  = System.currentTimeMillis();
    loop(Integer.parseInt(args[0]));
    long end = System.currentTimeMillis();

    System.out.println(end - start + "ms");
  }
}
