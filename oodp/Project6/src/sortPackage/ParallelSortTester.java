package sortPackage;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

/**
 * This class uses a sorting algorithm with multiple threads.
 * It checks sorting speed for the different thread numbers and creates different
 * sized arrays.
 * @author Samantha Coyle
 * @version 12/5/2017
 */
public class ParallelSortTester 
{
	/**
	 * Main function to call functions
	 * @param args
	 */
    public static void main(String[] args) 
    {
    	//Run the parallelized sort tester
    	runParallelST();
    }

    /**
     * Run parallel sort tester fucntion
     */
    public static void runParallelST()
    {
    	//Variables
    	Integer[] array = null;
       	final int LOOPS = 15;
    	final int AVAILABLE_PROCESSORS = Runtime.getRuntime().availableProcessors();
		int ARR_LENGTH = 1000;
		long start = 0;
		long finish = 0;
		long sortTime = 0;
		
    	//Display available processors
    	System.out.println("Available processors: " + AVAILABLE_PROCESSORS + "\n");
    	
		//Comparator for comparing the arrays
    	Comparator<Integer> comp = new Comparator<Integer>()
    	{
    		public int compare(Integer uno, Integer dos)
    		{
    			return uno.compareTo(dos);
    		}
    	};
    
    	//Loop through the processors
    	for(int index = 1; index <= AVAILABLE_PROCESSORS; index = index * 2)
    	{
    		//Show thread number
    		System.out.println(index + " thread(s):\n");
    		
    		//loop through to see run time
    		for(int index2 = 0, length = ARR_LENGTH; index2 < LOOPS; length = length * 2, ++index2)
    		{
    			//Create array with proper size
    			array = createRandomArray(length);

    			//Get how long sorting takes
    			start = System.currentTimeMillis();
    			ParallelMergeSorter.sort(index, array, comp);
    			finish = System.currentTimeMillis();
    			
    			//Get the total sort time
    			sortTime = (finish - start);
    			
    			//Give error if array is not sorted
    			if(!isSorted(array, comp))
    			{
    				throw new RuntimeException("Array not sorted :(\n");
    			}
    			
    			//Print out array size and sort time
    			System.out.printf("%12d elements  =>  %7d ms\n", length, sortTime); 	
    		}
    		//Give new line between each thread number
    		System.out.println('\n');
    	}    	
    	
    	//Let console know if sort was successful with multiple threads
    	System.out.println("Successfully sorted arrays with multiple threads!!");
    	System.out.println("Done!");
    	System.out.println("This goes out to my bb");
    }
    
    /**
     * Run the sort tester function
     */
    public static void runSortTester()
    {
        int LENGTH = 100000;   // length of array to sort
        Integer[] a = createRandomArray(LENGTH);

        Comparator<Integer> comp = new Comparator<Integer>() {
            public int compare(Integer d1, Integer d2) {
                return d1.compareTo(d2);
            }
        };

        // run the algorithm and time how long it takes to sort the elements
        long startTime = System.currentTimeMillis();
        ParallelMergeSorter.sort(a, comp);
        long endTime = System.currentTimeMillis();

        if (!isSorted(a, comp)) {
            throw new RuntimeException("not sorted afterward: " + Arrays.toString(a));
        }

        System.out.printf("%10d elements  =>  %6d ms \n", LENGTH, endTime - startTime);
    }

    /**
     * Returns true if the given array is in sorted ascending order.
     *
     * @param a the array to examine
     * @param comp the comparator to compare array elements
     * @return true if the given array is sorted, false otherwise
     */
    public static <E> boolean isSorted(E[] a, Comparator<? super E> comp) {
        for (int i = 0; i < a.length - 1; i++) {
            if (comp.compare(a[i], a[i + 1]) > 0) {
                System.out.println(a[i] + " > " + a[i + 1]);
                return false;
            }
        }
        return true;
    }

    // Randomly rearranges the elements of the given array.
    public static <E> void shuffle(E[] a) {
        for (int i = 0; i < a.length; i++) {
            // move element i to a random index in [i .. length-1]
            int randomIndex = (int) (Math.random() * a.length - i);
            swap(a, i, i + randomIndex);
        }
    }

    // Swaps the values at the two given indexes in the given array.
    public static final <E> void swap(E[] a, int i, int j) {
        if (i != j) {
            E temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Creates an array of the given length, fills it with random
    // non-negative integers, and returns it.
    public static Integer[] createRandomArray(int length) {
        Integer[] a = new Integer[length];
        Random rand = new Random(System.currentTimeMillis());
        for (int i = 0; i < a.length; i++) {
            a[i] = rand.nextInt(1000);
        }
        return a;
    }
    
}