package sortPackage;

import java.util.*;

/**
 * This class carries out the merge sort algorithm.
 * I have modified it to implement a multithreaded algorithm.
 * @author Samantha Coyle
 * @version 12/5/2017 
 */
public class ParallelMergeSorter 
{
    /**
     * Sorts an array, using the merge sort algorithm.
     *
     * @param a the array to sort
     * @param comp the comparator to compare array elements
     */
    public static <E> void sort(E[] a, Comparator<? super E> comp) 
    {
        mergeSort(a, 0, a.length - 1, comp);
    }

    /**
     * This sorts the arrays using the merge sort algorithm.
     * This also utilizes multiple threads.
     * @param a the array to sort
     * @param firstElem first element of the array to sort
     * @param lastElem last element of the array to sort
     * @param comp the comparator to compare the array elements
     * @param availableThreads the number of available threads
     */
    private static <E> void parallelMS(E[] a, int firstElem, int lastElem, Comparator<? super E> comp, int availableThreads) 
    {
    	//Variables
    	int threads = availableThreads - 1;
    	final int HALF = (lastElem + firstElem)/2;
    	int newHalf = HALF + 1;
    	
    	//Initial checks
    	if(availableThreads == 0)
    	{
    		//Use merge sort algorithm to sort array
    		mergeSort(a, firstElem, lastElem, comp);
    		return;
    	}
    	
    	else if(lastElem == firstElem)
    		return;
    	
    	//Create threads
    	Thread unoThread = new Thread()
    	{
    		/**
    		 * Run the first thread
    		 */
    		public void run()
    		{
    			parallelMS(a, firstElem, HALF, comp, threads);
    		}
    	};
    	    	
    	//Create a second thread
    	Thread dosThread = new Thread()
    	{
    		/**
    		 * Run the second thread
    		 */
    		public void run()
    		{
    			parallelMS(a, newHalf, lastElem, comp, threads);
    		}
    	};
  
    	//Start and join the threads
    	startThreads(unoThread, dosThread);
    	
    	//Merge the array
    	merge(a, firstElem, HALF, lastElem, comp);
	}
    
   /**
    * Start the threads
    * @param unoThread first thread
    * @param dosThread second thread
    */
    public static void startThreads(Thread unoThread, Thread dosThread)
    {
    	//Start the first thread
    	unoThread.start();
    	
    	//Start the second thread
    	dosThread.start();
    	
    	//Join togther the threads
    	joinThreads(unoThread, dosThread);
    }
    
    /**
     * Join together the threads
     * @param unoThread first thread
     * @param dosThread second thread
     */
    public static void joinThreads(Thread unoThread, Thread dosThread)
    {
    	//Join together the threads!
    	try
    	{
    		unoThread.join();
    		dosThread.join();
    	}
    	catch(InterruptedException ie)
    	{
    		//Catch and inform of exception
    		System.out.println("Exception thrown when joining threads :(\n");
    	}
    }
    
    /**
     * Sorts an array, using the merge sort algorithm with another parameter.
     * This takes in the number of threads available for usage.
     * @param numThreads number of available threads
     * @param a the array to sort
     * @param comp the comparator to compare array elements
     */
    public static <E> void sort (int numThreads, E[] a, Comparator<?super E> comp)
    {
    	//Variables
    	int firstElem = 0;
    	int lastElem = ((a.length) - 1);
    	int availableThreads = threadCount(numThreads);
    	
    	//Sort the arrays with multiple threads
    	parallelMS(a, firstElem, lastElem, comp, availableThreads);
    }
    
	/**
     * Sorts a range of an array, using the merge sort algorithm.
     *
     * @param a the array to sort
     * @param from the first index of the range to sort
     * @param to the last index of the range to sort
     * @param comp the comparator to compare array elements
     */
    private static <E> void mergeSort(E[] a, int from, int to,
            Comparator<? super E> comp) {
        if (from == to) {
            return;
        }
        int mid = (from + to) / 2;
        // Sort the first and the second half
        mergeSort(a, from, mid, comp);
        mergeSort(a, mid + 1, to, comp);
        merge(a, from, mid, to, comp);
    }

    /**
     * Merges two adjacent subranges of an array
     *
     * @param a the array with entries to be merged
     * @param from the index of the first element of the first range
     * @param mid the index of the last element of the first range
     * @param to the index of the last element of the second range
     * @param comp the comparator to compare array elements
     */
    @SuppressWarnings("unchecked")
    private static <E> void merge(E[] a,
            int from, int mid, int to, Comparator<? super E> comp) {
        int n = to - from + 1;
         // Size of the range to be merged

        // Merge both halves into a temporary array b
        Object[] b = new Object[n];

        int i1 = from;
        // Next element to consider in the first range
        int i2 = mid + 1;
        // Next element to consider in the second range
        int j = 0;
         // Next open position in b

        // As long as neither i1 nor i2 past the end, move
        // the smaller element into b
        while (i1 <= mid && i2 <= to) {
            if (comp.compare(a[i1], a[i2]) < 0) {
                b[j] = a[i1];
                i1++;
            } else {
                b[j] = a[i2];
                i2++;
            }
            j++;
        }

        // Note that only one of the two while loops
        // below is executed
        // Copy any remaining entries of the first half
        while (i1 <= mid) {
            b[j] = a[i1];
            i1++;
            j++;
        }

        // Copy any remaining entries of the second half
        while (i2 <= to) {
            b[j] = a[i2];
            i2++;
            j++;
        }

        // Copy back from the temporary array
        for (j = 0; j < n; j++) {
            a[from + j] = (E) b[j];
        }
    }
    
    /**
     * Get power of 2 for thread count
     * @param threads the number of threads passed in
     * @return number of threads available
     */
    private static int threadCount(int threads)
    {
    	//Variables
    	int serialProgram = 1;
    	int threads2 = threads - 1;
    	
    	//If thread count is power of 2 go here
    	if(((threads & (threads2)) == 0))
    		{
    			//Get the power of 2
    			for(int power = 0; power < 20; ++power)
    			{
    				//Return the power
    				if(Math.pow(2, power) == threads)
    					return power;
    			}
    		}
    	
    	//Return 1 thread
   		return serialProgram;
    }
    
}