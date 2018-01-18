package database;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.Scanner;
import java.util.Scanner;

/**
 * ShippingStore class calls functions while user input is not the quit option.
 *
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */

public class ShippingStore 
{	
	/**
	 * Creates Package and StorageList objects to access other classes.
	 * Tries to open file, and if not then prints the exception cause.
	 * Calls print menu to display menu. Sets Option to the user input. 
	 * While user input is not 6 it calls functions to deal with the user input request.
	 * Validates user input. If user input is 6 then write to file.
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException 
    {			
        //Create objects to access other classes
        StorageList StorageListObject = new StorageList();
        CompleteTransaction CTransaction = new CompleteTransaction();

        
        //Open file
        try{
        	StorageListObject.openFile();
        }
        catch(Exception exception) 
        {
            System.out.println(exception.getCause());   
        }      

        //Setup a scanner
        Scanner sc = new Scanner(System.in);
     
     // Display options
        String menu =         
                ("Please pick an option:\n\n" + 
                		"1.Show all existing package records in the database (sorted by tracking number).\n" +
                		"2.Add new package record to the database.\n" +
                		"3.Delete package record from a database.\n" + 
                		"4.Search for a package (given its tracking number).\n" + 
                		"5.Show a list of users in the database.\n" +
                		"6.Add new user to the database.\n" +
                		"7.Update user info (given their id).\n" +
                		"8.Complete a shipping transaction.\n" +
                		"9.Show completed shipping transactions.\n" +
                		"10.Exit program.\n"); 

        int option = -1;

        //What to do while still using program
        do
        {
            //Print menu to console for picking menu option, and read in user option
        	System.out.println(menu);

        	System.out.println("Enter your menu option:");
        	option = sc.nextInt();

        	while((option < 1) || (option > 10))
        	{
        		System.out.println("Invalid option. Enter valid option: ");
        		option = sc.nextInt();
        	}
        	
        	
        	//Show menu options for option 1
            if(option == 1)
            {
            	//StorageListObject.printPackageList();
            	StorageListObject.showPackage();
            }
            
            //Add new package to database
            if(option == 2)
            {            	
             	//Ask what package type user wants to add
            	System.out.println("What kind of package do you wish to add?");
            	System.out.println("1. Envelope\n" + "2. Box\n" + "3. Crate\n" + "4. Drum\n");
            	System.out.println("Enter your choice (whole number)\n");
            	
            	int packType = sc.nextInt();
            	      
            	//Validate user input
            	if((packType < 1) || (packType > 4))
            	{
            		System.out.println("Invalid package. Enter valid #: ");
            		packType = sc.nextInt();
            	}
            	
            	//Add packages
            	try {
					StorageListObject.addPackage(packType);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
            	
            	System.out.println("End of options 2 block");
            }
                            	
            //Get the package that the user wishes to delete
            if(option == 3)                  
            {
            	String Deletetn = null;
            	System.out.println("What is the tracking # of the package you wish to remove?: ");
            	String trash = sc.nextLine();
            	Deletetn = sc.nextLine();
            	StorageListObject.removePackage(Deletetn);
            }
                       
            //Search function given tracking number
            if(option == 4)
            {
            	System.out.println("Enter tracking # you wish to find:");
            	String trash = sc.nextLine();
            	String tn2 = sc.nextLine();
            	System.out.println("Here is trash: " + trash + "Here is tn2 " + tn2 + "in main");
            	try {
            	StorageListObject.findPackage(tn2);
            	}
            	catch(NullPointerException e) {}
            	
        	}
                        
            //Show the list of users
            if(option == 5)
            {
            	StorageListObject.listOfUsers();
            }
            
            //Add a user to database
            if(option == 6)
            {
            	StorageListObject.addUser();
        	}
            
            //Update user information
            if(option == 7)
            {
            	StorageListObject.updateUserInfo();
            }
            
            //Complete a transaction
            if(option == 8)
            {
            	int cID = -1;
            	int eID = -1;
            	String trackingNumber = null;
            	Date shipD = null;
            	Date delDate = null;
            	float cost = -1;
            	SimpleDateFormat sdf = new SimpleDateFormat("MM-dd-yyyy");
            	String line = null;
            	
            	
            	System.out.println("Enter customer ID:");
            	sc.nextLine();
            	cID = sc.nextInt();

            	User cust = StorageListObject.searchUser();
            	if(cust == null)
            	{
            		//prompt user to make cust
                	System.out.println("Enter customer ID:");
                	cID = sc.nextInt();
                	System.out.println("Enter first name:");
                	String fn = sc.next();
                	System.out.println("Enter last name:");
                	String ln = sc.next();
                	System.out.println("Enter phone number:");
                	int phoneNum = sc.nextInt();
                	System.out.println("Enter address:");
                	String address = sc.next();

            	} 
            	else 
            		cID = cust.getUserID();

            	System.out.println("Enter employee ID:");
            	sc.nextLine();
            	eID = sc.nextInt();
            	User emp = StorageListObject.searchUser();
            	if(emp == null) 
            	{
            		//prompt user to make cust
                	System.out.println("Enter employee ID:");
                	eID = sc.nextInt();
                	System.out.println("Enter first name:");
                	String fn = sc.next();
                	System.out.println("Enter last name:");
                	String ln = sc.next();
                	System.out.println("Enter social security number:");
                	int social = sc.nextInt();
                	System.out.println("Enter monthly salary:");
                	int salary = sc.nextInt();
                	System.out.println("Enter bank number: ");
                	int bankNum = sc.nextInt();
            	}
            	else 
            		eID = emp.getUserID();
            	
            	System.out.println("Enter tracking #:");
            	sc.nextLine();
            	trackingNumber = sc.nextLine();
            	
            	
            	//while(trackingNumber != packages.trackingNumber)
            	while(StorageListObject.searchIfExists(trackingNumber) == -1)
            	{
            		System.out.println("Invalid tracking #. Enter again:");
            		
            		trackingNumber = sc.nextLine();
            	}
            
            	StorageListObject.search(trackingNumber, cID, eID);
            		
            	System.out.println("Enter shipping date (MM-dd-yyyy):");
            	//sc.nextLine();
            	line = sc.nextLine();
            	
            	if(shipD == null)
            	{
            		try 
            		{
            			shipD = sdf.parse(line);
            		}
            		catch(ParseException pe)
            		{
            			System.out.println("Invalid date.");            			
            		}
             	}
            	
            	System.out.println("Enter deliver date:");
            	line = null;
            	line = sc.nextLine();
            	
            	if(delDate == null)
            	{
            		try 
            		{
            			delDate = sdf.parse(line);
            		}
            		catch(ParseException pe)
            		{
            			System.out.println("Invalid date.");
            			//continue;
            		}
            	}
            	
            	System.out.println("Enter cost: ");
            	cost = sc.nextFloat();
            	while(cost < 0)
            	{
            		System.out.println("Invalid cost. Re-enter:");
            		sc.nextLine();
            		cost = sc.nextFloat();
            	}
            	CompleteTransaction.endTransaction(cID, eID, trackingNumber, shipD, delDate, cost);
            	           	
            }
            
            //Show shipping transaction
            if(option == 9)
            {
            	CompleteTransaction.printCompleteTransaction();
            }
            
        //Close do while loop in main
        }while(option != 10);
        
        try {
			StorageListObject.WriteToFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
        
    }   
	
	/**
	 * Validate user input
	 * @param userInput the user input
	 */
	public static void validateUserInput(Scanner userInput) 
	{
		while((!userInput.hasNextInt()))
		{
			System.out.println("\n\nPlease enter in another menu options (whole number).");
			userInput.next();				
		}
	}
	
    /**
     * Constructor for objects of class ShippingStore
     */
    public ShippingStore() {}
    
  
	
}
