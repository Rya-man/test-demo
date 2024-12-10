class Buffer {
    private int[] buffer;
    private int count = 0, in = 0, out = 0, size;

    public Buffer(int size) {
        this.size = size;
        buffer = new int[size];
        System.out.println("Buffer created with size: " + size);
    }

    public synchronized void produce(int item) throws InterruptedException {
        // If the buffer is full, wait until there's space
        while (count == size) {
            wait();
        }
        buffer[in] = item;
        in = (in + 1) % size;
        count++;
        System.out.println("Produced: " + item);
        notifyAll();
    }

    public synchronized int consume() throws InterruptedException {
        // If the buffer is empty, wait for items to be produced
        while (count == 0) {
            wait();
        }
        int item = buffer[out];
        out = (out + 1) % size;
        count--;
        System.out.println("Consumed: " + item);
        notifyAll();
        return item;
    }
}

class Producer extends Thread {
    private Buffer buffer;
    private int maxItems;

    public Producer(Buffer buffer, int maxItems) {
        this.buffer = buffer;
        this.maxItems = maxItems;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= maxItems; i++) {
                buffer.produce(i);
                Thread.sleep(500); // Simulate time to produce next item
            }
        } catch (InterruptedException e) {
            System.out.println("Producer interrupted.");
        }
    }
}

class Consumer extends Thread {
    private Buffer buffer;

    public Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            while (!isInterrupted()) {
                int item = buffer.consume();
                Thread.sleep(1000); // Simulate time to process the consumed item
            }
        } catch (InterruptedException e) {
            System.out.println("Consumer interrupted.");
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int bufferSize = 5;
        int maxItemsToProduce = 10;

        Buffer buffer = new Buffer(bufferSize);

        Producer producer = new Producer(buffer, maxItemsToProduce);
        Consumer consumer = new Consumer(buffer);

        producer.start();
        consumer.start();

        producer.join();
        consumer.interrupt();
        consumer.join();

        System.out.println("All done!");
    }
}
