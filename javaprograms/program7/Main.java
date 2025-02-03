class Buffer {
    private final int[] buf;
    private int count = 0, in = 0, out = 0;

    public Buffer(int size) { buf = new int[size]; }

    public synchronized void produce(int item) throws InterruptedException {
        while (count == buf.length) wait();
        buf[in] = item;
        in = (in + 1) % buf.length;
        count++;
        System.out.println("Produced: " + item);
        notifyAll();
    }

    public synchronized int consume() throws InterruptedException {
        while (count == 0) wait();
        int item = buf[out];
        out = (out + 1) % buf.length;
        count--;
        System.out.println("Consumed: " + item);
        notifyAll();
        return item;
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Buffer buffer = new Buffer(5);
        
        Thread producer = new Thread(() -> {
            for (int i = 1; i <= 10; i++) {
                try { buffer.produce(i); Thread.sleep(500); } 
                catch (InterruptedException e) { break; }
            }
        });
        
        Thread consumer = new Thread(() -> {
            try { while (true) { buffer.consume(); Thread.sleep(1000); } } 
            catch (InterruptedException e) {}
        });
        
        producer.start();
        consumer.start();
        producer.join();
        consumer.interrupt();
        consumer.join();
        System.out.println("Process completed");
    }
}