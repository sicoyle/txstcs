package shippingstore;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 * Runner to run my test class 
 * @author Samantha Coyle
 * @version 11/02/2017
 */

public class MyTestRunner 
{
	/**
	 * Main function to check for failure
     * @param args this program expects no command line arguments
	 * @throws Exception
	 */
    public static void main(String[] args) throws Exception
    {
    	//Variables
        Result result = JUnitCore.runClasses(ShippingStoreTest.class);

        //Check for failure
        for(Failure failure :result.getFailures()) 
        	System.out.println(failure.toString());
        

        //Check for success
        if(result.wasSuccessful())
            System.out.println("All tests finished...");
        
    }

}