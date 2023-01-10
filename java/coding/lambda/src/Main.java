import java.util.function.Function;

public class Main {

    static Object f(Function<Integer, Object> ff, Integer p) {
        return "Identite:" + ff.apply(p);
    };

    public static void main(String[] args) {

        Function<Integer, Integer> id = (a) -> a;
        System.out.println("" + id.apply(10));

        Function<Integer, Object> fnull = (a) -> null;

        System.out.println(f(fnull, 42));
        Function<Integer, Object> tmp = (i) -> "titi";
        System.out.println(f(tmp, 42));

        Function<Function<Integer, Function<Integer, Integer>>, Integer> f_42 = (f) -> f.apply(40).apply(2);
        int f = f_42.apply((k) -> ((z) -> k + z));
        System.out.println(f);
        f = f_42.apply(k -> z -> k + z);
        System.out.println(f);
    }
}
