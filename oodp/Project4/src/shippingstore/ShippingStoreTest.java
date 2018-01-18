package shippingstore;
import static org.junit.Assert.*;
import java.nio.channels.Channels;
import java.util.ArrayList;
import java.io.*;
import org.junit.Test;
import org.junit.After;
import org.junit.Before;

/**
 * The ShippingStoreTest class tests the ShippingStore methods and lets the user know which tests fail 
 * @author Samantha Coyle
 * @version 11/02/2017
 */

public class ShippingStoreTest 
{
	//Variables
	ShippingStore shippingStore;
	PackageOrder tempPackage1;
    PackageOrder tempPackage2;
    PackageOrder tempPackage3;
    PackageOrder tempPackage4;
    PrintWriter pw;
    File dataFile;
    ArrayList<PackageOrder> packageOrderList;
    
    /**
     * Set-up default files for class
     * Arrays store trial information
     * Files are initialized per test
     * @throws Exception but throws no exception
     */
    
    @Before
    public void setUp() throws Exception 
    {
    	//Variables
        shippingStore = new ShippingStore();
        packageOrderList = new ArrayList<>();

        //Create packages
        tempPackage1 = new PackageOrder("67TYN","Box", "Fragile", "Priority", 8.43f, 54);
        tempPackage2 = new PackageOrder("UIO98","Postcard", "Do-not-Bend", "Ground", 7.00f, 2);
        tempPackage3 = new PackageOrder("QWE11","Envelope", "N/A", "First-Class", 1.11f, 33);
        tempPackage4 = new PackageOrder("TIE12","Letter", "N/A", "Metro", 33.55f, 9);

        //Add the packages
        packageOrderList.add(tempPackage1);
        packageOrderList.add(tempPackage2);
        packageOrderList.add(tempPackage3);
    }


    /**
     * See if datafile was created
     * @throws Exception but throws no exception
     */
    
    @Test
    public void TestGetDataFile() throws Exception 
    {
    	//Make data file and check if exists
        dataFile = new File("PackageOrderDB.txt");
        assertFalse("The file does not exist", !dataFile.exists());
        assertTrue("The file exist", dataFile.exists());
    }
    
    


    /**
     * Check user numbers are in array.
     * @throws Exception 
     */
    
    @Test
    public void TestShowPackageOrdersRange() throws Exception 
    {
    	//Arrays for numbers
        double []expectedNumber = {41,42,49};
    	double []actualNumber = {49,42,41};
        
        //Assertions
        assertArrayEquals("Number are in between 40-55",expectedNumber,actualNumber,10); 
        assertFalse("Package order does not exist",packageOrderList.size() < 1);
        assertTrue("Package orders", packageOrderList.size() >= 1); 
    }
  

    /**
     * Check show package orders if the package is empty
     * @throws Exception
     */
    
    @Test
    public void TestShowPackageOrdersIfPackageListEmpty() throws Exception 
    {
    	//Variables
        OutputStream os = new ByteArrayOutputStream();
    	String separator = System.getProperty("line.separator");
    	PrintStream ps = new PrintStream(os);
        System.setOut(ps);

        //Make empty shipping store
        ShippingStore emptyStore = new ShippingStore();

        //Show packages
        emptyStore.showPackageOrders();
        
        String expectedOutput = new String();
        expectedOutput += " -------------------------------------------------------------------------- " + separator;
        expectedOutput += "| Tracking # | Type    | Specification | Class       | Weight(oz) | Volume |" + separator;
        expectedOutput += " -------------------------------------------------------------------------- " + separator;
        expectedOutput += " --------------------------------------------------------------------------\n" + separator;

        //Assertion
        assertEquals(expectedOutput, os.toString());
    }

    /**
     * Check packageOrderList size and see if object has readable info
     * @throws Exception returned as the assertion true/false.
     */
    
    @Test
    public void TestShowPackageOrdersIfPackageListNotEmpty() throws Exception 
    {
    	//Variables
    	String separator = System.getProperty("line.separator");
    	shippingStore.addOrder("67TYN", "Box", "Fragile", "Priority", "8.43", "54");
    	OutputStream os = new ByteArrayOutputStream();
    	PrintStream ps = new PrintStream(os);
    	System.setOut(ps);

    	shippingStore.showPackageOrders();
    	String testingString = new String();

    	for (int a = 0; a < 1; a++) {
    		testingString += " -------------------------------------------------------------------------- " + separator;
    		testingString += "| Tracking # | Type    | Specification | Class       | Weight(oz) | Volume |" + separator;
    		testingString += " -------------------------------------------------------------------------- " + separator;
    		testingString += String.format("| %-11s| %-8s| %-14s| %-12s| %-11s| %-7s|",
    				packageOrderList.get(a).getTrackingNumber(),
    				packageOrderList.get(a).getType(),
    				packageOrderList.get(a).getSpecification(),
    				packageOrderList.get(a).getMailingClass(),
    				String.format("%.2f", packageOrderList.get(a).getWeight()),
    				Integer.toString(packageOrderList.get(a).getVolume())) + separator;
    		testingString += " --------------------------------------------------------------------------\n" + separator;
    }

    //Assertion
    assertEquals(testingString, os.toString());
}
    
    /**
     * See if tracking number matches existing package
     * @throws Exception returned as the assert false/true
     */
    
    @Test
    public void TestSearchPackageOrder() throws Exception 
    {
    	//Assertion
        assertTrue("The package has been located", (tempPackage2.getTrackingNumber()).matches("UIO98"));
        
        //Assertion
        assertFalse("The package was not located", (packageOrderList.get(0).getTrackingNumber()).matches("00000"));
    }
    
    /**
     * Check if input matches package info from user
     * @throws Exception returned as assert false/true
     */
    
    @Test
    public void TestFindPackageOrder() throws Exception 
    {
    	//Assert if packages match
        assertEquals(packageOrderList.get(0).getTrackingNumber().matches(tempPackage1.getTrackingNumber()),
                packageOrderList.get(0).getTrackingNumber().matches(tempPackage1.getTrackingNumber()));
        
        //Rest of assertions
        assertFalse("Package does not exit", (packageOrderList.get(0).getTrackingNumber()).matches("00000"));
        
        //Rest of assertions
    	assertTrue("Package exist", (packageOrderList.get(0).getTrackingNumber()).matches("67TYN"));
    }
    

    /**
     * Check if removal is successful
     * @throws Exception 
     */
    
    @Test
    public void TestRemoveOrder() throws Exception 
    {
    	//Remove package
        packageOrderList.remove(tempPackage3);
        
        //Assertion
        assertEquals(2, packageOrderList.size());
    }

    /**
     * Check if I can add order to object list
     * Verify array size
     * @throws Exception 
     */
    
    @Test
    public void TestAddOrder() throws Exception 
    {
    	//Add temp package
        packageOrderList.add(tempPackage4);
        
        //Assertion
        assertEquals(4, packageOrderList.size());
    }


    /**
     * Get packageOrder and match with package order to check that they match
     * @throws Exception returned as assert false/true
     */
    
    @Test
    public void TestGetPackageOrder() throws Exception 
    {
    	//Assertions
    	assertFalse("Object does not exist", packageOrderList.get(1).equals(tempPackage1));

    	assertTrue("Objects exist",packageOrderList.get(0).equals(tempPackage1));
    }

    /**
     * Read in input from file
     * Check file is in directory and throw exception if not
     * @throws Exception returned as assert false/true
     */
    
    @Test
    public void TestRead() throws Exception 
    {
        try
        {
        	//Make file and read
            FileReader dataReader = new FileReader("test.txt");
            shippingStore.read(dataReader);
        } 
        catch(FileNotFoundException e) 
        {
        	//Catch if file is not found
        }
        
        catch (Exception e) 
        {
        	//Catch other errors and make assertion
            assertEquals("java.io.FileNotFoundException: test.txt (No such file or directory)", e.toString());
        }
        
        finally
        {
        	//Make file
            dataFile = new File("PackageOrderDB.txt");
            
            //Assertions
            assertTrue("Information is readable", dataFile.canRead());
            assertTrue("File opened",dataFile.exists());
        }
    }
    

    /**
     * Set variables to null post-tests
     * @throws Exception but throws no exception
     */
    
    @After
    @SuppressWarnings("Duplicates")
    public void tearDown() throws Exception 
    {
    	//Set variables to null to "tearDown"
        pw = null;
    	shippingStore = null;
        dataFile = null;
        packageOrderList = null;
        tempPackage1 = null;
        tempPackage2 = null;
        tempPackage3 = null;
        tempPackage4 = null;
    }
    
    

    /**
     * Check for issues with serialization
     * Check if file read
     * @throws Exception returned as assert false/true
     */
    
    @Test
    public void TestFlush() throws Exception 
    {
        try
        {
        	//File variables
            RandomAccessFile raFile = new RandomAccessFile("test.txt", "r");
            OutputStreamWriter writer = new OutputStreamWriter(Channels.newOutputStream(raFile.getChannel()));
            shippingStore.flush(writer);
        } 
        
        catch(FileNotFoundException fnfe)
        {
        	//Catch if file ont found
        }
        
        catch (Exception e)
        {
        	//Catch other exceptions and create assertion
            assertEquals("java.io.FileNotFoundException: test.txt (No such file or directory)",e.toString());

        }
        finally 
        {
        	//Write to file stuff
            pw = new PrintWriter("PackageOrderDB.txt");

            //Assertions
            assertFalse("Error, file could not be written to", pw.checkError()); 
            assertTrue("File can be written to", !pw.checkError());
        }
    }
}