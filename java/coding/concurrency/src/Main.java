import com.doali.thread.MyRunnable1;
import com.doali.thread.MyRunnable2;

public class Main {

    private static void testThreadSimple1() {
        MyRunnable1 myRunnable1 = new MyRunnable1(0);
        Thread thread = new Thread(myRunnable1);
        thread.setName("MyRunnable1");
        thread.start();
    }


    private static void testThreadSimple2() {
        MyRunnable2 myRunnable2 = new MyRunnable2(0);
        Thread thread = new Thread(myRunnable2);
        thread.setName("MyRunnable2");
        thread.start();
    }

    public static void main(String[] args) {
        Main.testThreadSimple1();
        Main.testThreadSimple2();
    }
}
