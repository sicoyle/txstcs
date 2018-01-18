package database;

//All of the java importns needed
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Scanner;
import java.io.*;

/**
 * StorageList class holds ArrayList and handles file I/O.
 *
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */

public class StorageList 
{	
	//Private members and needed variables
    private static Scanner file;
    
	//Create arraylists
    private ArrayList<Package> packages = new ArrayList<>();
	ArrayList<User> userList = new ArrayList<>();
	ArrayList<Package> storage = new ArrayList<>();
	ArrayList<Transaction> transactionInfo = new ArrayList<>();    	
	
	/**
     * Constructor for objects of class StorageList
     */
    public StorageList() throws FileNotFoundException
    {       
    	//If file does not exist, create file
        File dataFile = new File("packages.txt");
        
        if(!(dataFile.exists()))
        {
            System.out.println("packages.txt does not exist. Creating it now.");
            PrintWriter pw = new PrintWriter("packages.txt");
            pw.close();  
        }  
    }

    
    
    
    
    
    
    
    
    /**
     * Searches the list to find the package with the matching tracking number.
     * @param tn the package tracking number
     * @return index the package index
     */
    public void search(String tn, int cID, int eID)
    {
    	int index = searchIfExists(tn);
    	boolean e, c = false;
    	
    		//add entry in completeTransactionCollection
    
    
    		packages.remove(index);
    		
    		
    		//function is void so no return
    		
    }
     
    /**
     * Adds a package.
     * @param packType the type of package
     * @throws IOException
     */
    public void addPackage(int packType) throws IOException
    {
    	//Add a package to the arraylist
    	Scanner in = new Scanner(System.in);
    	int userInput = packType;
    	String packageInfo;

    	packageOptions(userInput);
    
    	//Get package info
    	packageInfo = in.nextLine();
    	String info[] = packageInfo.split(" ");
    	
    	//Validation
    	if(validatePackage(info[0], info[1], info[2], info[3], info[4], userInput) == false)
    	{
    		System.out.println("Invalid package information. Package not added.");
    		return;
    	}
    	
    	//Validate package info from user
    	if((info.length > 5) || (info.length < 5))
    		return;
    	
    	//Pass in information to correct package type
    	switch(userInput)
    	{
    		//Envelope
    		case 1:
    		{
    			int height = Integer.parseInt(info[3]);
    			int width = Integer.parseInt(info[4]);
   			
    			Envelope envelopeObject = new Envelope(info[0], info[1], info[2], height, width);
    			packages.add(envelopeObject);
    			break;
    		}
    	
    		//Box
    		case 2:
    		{
    			int volume = Integer.parseInt(info[4]);
    			int largestDimension = Integer.parseInt(info[3]);
    			
    			Box boxObject = new Box(info[0], info[1], info[2], largestDimension, volume);
    			packages.add(boxObject);
    			break;
    		}
    	
    		//Crate
    		case 3:
    		{
    			float MLWeight = Float.parseFloat(info[3]);
    			Crate crateObject = new Crate(info[0], info[1], info[2],MLWeight, info[4]);
    			packages.add(crateObject);
    			break;
    		}
    		
    		//Drum
    		case 4:
    		{
    			float diameter = Float.parseFloat(info[4]);
    			Drum drumObject = new Drum(info[0], info[1], info[2], info[3], diameter);
    			packages.add(drumObject);
    			break;    			
    		}
    		
    		default:
    			break;
    	}
    	
		Collections.sort(packages);

    }

    /**
     * Validates the package.
     * @param tn the package tracking number
     * @param specif the package specification
     * @param mc the package mailing class
     * @param value the associated package value 1
     * @param value2 the associated package value 2
     * @param userInput the user input
     * @return valid if the package information is valid
     */
    private boolean validatePackage(String tn, String specif, String mc, String value, String value2, int userInput)
    {
    	//varibles needed
    	boolean valid = true;
    	String theType = null;
    	
    	if(userInput == 1)
    		theType = "envelope";
    	if(userInput == 2)
    		theType = "box";
    	if(userInput == 3)
    		theType = "crate";
    	if(userInput == 4)
    		theType = "drum";
    	
    	//Check tracking number
    	if(!(tn.matches("[A-Za-z0-9]{5}")))
    	{
    		valid = false;
    		System.out.println("Invalid tracking number.");
    	}
    	
    	//Check mailing class
    	if (!(mc.equals("first-class") || mc.equals("priority") || mc.equals("retail")
                || mc.equals("ground") || mc.equals("metro")) )
    	{
    		valid = false;
    		System.out.println("Invalid mailing class.");
    		System.out.println("Mailing class must be lower case: first-class, "
    				+ "priority, retail, ground, metro.");
    	}
    	
    	//Check specification
        if (!(specif.equals("fragile") || specif.equals("books") || specif.equals("catalogs")
            || specif.equals("do-not-bend") || specif.equals("n/a")))
        {
        	valid = false;
        	System.out.println("Invalid specification.");
        	System.out.println(" Specification must be lower case:"
        			+ " fragile, books, catalogs, do-not-bend, n/a.");
        }
        
        //Check envelope info
        if(theType.equals("envelope"))
        {
        	if(!(value.matches("[0-9]{1,2}")))
        	{
        		System.out.println("Invalid height. Must be int between 0-99.");
        		valid = false;
        	}
        	
        	if(!(value2.matches("[0-9]{1,2}")))
        	{
        		System.out.println("Invalid width. Must be int between 0-99.");
        	}
        }
        
        //Check box info
        if(theType.equals("box"))
        {
        	if(Integer.parseInt(value) < 0)
        	{
        		System.out.println("Invalid largest dimension. Must be int 0-999.");
        		valid = false;
        	}
        	if(Integer.parseInt(value2) < 0)
        	{
        		System.out.println("Invalid volume. Must be int 0-999999.");
        		valid = false;
        	}        
        }
        
        //Check crate info
        if(theType.equals("crate"))
        {
        	if((Float.parseFloat(value) < 0))
        	{
        		System.out.println("This is weight " + value);
        		System.out.println("Invalid weight. Must be positive value.");
        		valid = false;
        	}       
        }
        
        //Check drum info
        if(theType.equals("drum"))
        {
    		System.out.println("This is value: " + value);
    		System.out.println("This is value2: " + value2);

        	if(!(value.equals("fiber") || (value.equals("plastic"))))
        	{
        		System.out.println("Invalid material. Must be lower case fiber or plastic.");
        		valid = false;
        	}
        	
        	if(Float.parseFloat(value2) < 0)
        	{
        		System.out.println("Invalid diameter. Must be float value greater than 0");
        		valid = false;
        	}
        }
                
//        
//    	if(this.searchIfExists(tn) != -1)
//    	{
//    		valid = false;
//    		System.out.println("Pacakge exists already.");
//    	}	
    	return valid;
    }
    
    /**
     * Print the package to console.
     */
    public void showPackage()
    {
    	showPackages(packages);
    }
    
    /**
     * Shows the packages to the console
     * @param pack
     */
    private void showPackages(ArrayList<Package> pack)
    {
    	//Print table header
    	System.out.println(" --------------------------------------------------------------------------------------- ");
        System.out.println("|Tracking Num|   Type  | Specification |    Class    |     Other     |     Other    |");
        System.out.println(" --------------------------------------------------------------------------------------- ");

        //For every package, print the package
        for (Package p : pack){
            System.out.printf("|%11s|%10s|%16s|%13s|", p.getTrackingNumber(), p.getType(), p.getSpecification(), p.getMailingClass());

           //Print proper package information
           if(p instanceof Box)
        	   System.out.printf("Dim: %3din|vol: %6din^3|\n", ((Box)p).getLargeDim(), ((Box)p).getVolume());
                      
           if(p instanceof Envelope)
               System.out.printf(" Height: %3din | Width: %3din |\n", ((Envelope)p).getHeight(), ((Envelope)p).getWidth());
                   
           else if(p instanceof Crate)
                System.out.printf("Max wt: %5.2flb|%13s|\n", ((Crate)p).getMaxLoad(), ((Crate)p).getContent());
                      
           else if (p instanceof Drum)
                System.out.printf("Mat:%7s|Dia: %7in|\n", ((Drum)p).getMaterial(), ((Drum)p).getDiameter());
           
        }

        System.out.println(" ---------------------------------------------------------------------------------------\n");
    }

    /**
     * Displays what user can type depending on package type
     * @param userInput
     */
    public void packageOptions(int userInput)
    {
    	//Depending on input, add correct package
    	switch(userInput)
    	{
    		case 1: 
    		{
    			System.out.println("\n Tracking #	Specification	Class	Height	Width\n" + "example: \nABC12	Fragile	Ground	30	22\n");
    			break;
    		}
    		case 2:
    		{
    			System.out.println("\n Tracking #	Specification	Class	Largest Dimension	Volume\n" + "example: \nABC12	Fragile	Ground	33	51\n");
    			break;
    		}
    		case 3:
    		{
    			System.out.println("\n Tracking #	Specification	Class	Max Load Weight	Content\n" + "example: \nABC12	Fragile	Ground	76.5	Pouf\n");
    			break;
    		}
    		case 4:
    		{
    			System.out.println("\n Tracking #	Specification	Class	Material	Diameter\n" + "example: \nABC12	Fragile	Ground	Plastic	22.2\n");
    			break;
    		}
    		default:
    			break;
    	}		    	
    }
    
    /**
     * Search if the package exists.
     * @param tn the package tracking number
     * @return found if the package is found
     */
    public int searchIfExists(String tn) 
    {
    	
    	int found  = -1;
    	System.out.println("TN passed in searchIfExists function in storagelist: " + tn);
    	for(Package p : packages)/*int index = 0; index < packages.size(); index++)*/
    	{
    		System.out.println("In for loop");
    		String tempTrackingNumb = p.getTrackingNumber();
    		System.out.println("temp tn: " + tempTrackingNumb);
    		if(tn.equals(tempTrackingNumb))/*p.get(index).getTrackingNumber()))*/
    		{
    			System.out.println("In if");
    			found = packages.indexOf(p);
    			break;
    		}
    	}
    	
    	System.out.println("Here is found" + found);
    	return found;
    }
    
    /**
     * Finds the package.
     * @param tn the package tracking number
     */
    public void findPackage(String tn)
    {
    	int i = searchIfExists(tn);
		ArrayList<Package> pack = new ArrayList<>(1);
		Package tempPackage = null;
		int size = packages.size();

    		//If package found, return the package
    		if(i >= 0)
    		{
    	    	System.out.println("line 433 in if in findpackages");

    			if ((i <= size) && (i >= 0)) 								
    			{
    				System.out.println("In inner if");
    	             tempPackage = packages.get(i);
    	             System.out.println("line 436 of storagelist in if. tempPack = " + tempPackage);
    	        }
    
    			pack.add(tempPackage);
    			showPackages(pack);
    			System.out.println(" Package was successfully found.");
    		}    		
    } 
    
    /**
     * Removes a package. 
     * @param p the package
     */
    public void removePackage(String tn)
    {
    	int orderNumber = searchIfExists(tn);

    	if(tn == null)
    		System.out.println("\nPackage not removed. Invalid tracking number.");
    	else 
    	{
    		packages.remove(orderNumber);
    		System.out.println("Package removed.");
    		for(Package p : packages)
    			System.out.print("Package in remove Package function " + p);
    	}
    }
    
    /**
     * Calls ReadFile. 
     * @see ReadFile()
     * @throws IOException
     */
    public void openFile() throws IOException
    {
    	ReadFile();    	
    }
    
    /**
     * Writes the packages to the file before the program closes.
     * @throws IOException
     */
    /**
     * Writes the packages to the file before the program closes.
     * @throws IOException
     */
    public void WriteToFile() throws IOException
    {
    	ObjectOutputStream oos = null;
    
    	try {
        	oos = new ObjectOutputStream( new FileOutputStream("packages.dat"));
        	for(Package p : packages)
    	    	oos.writeObject(p);
        	} catch (IOException ioException) {
                System.err.println(ioException.getMessage());
            } catch (NoSuchElementException noSuchElementException) {
               System.err.println("Invalid input.");
            } finally {
               try {
                  if (oos != null)
                     oos.close();
               } catch (IOException ioException) {
                  System.err.println("Error closing file.");
               }
            }
    }      
    
    /**
     * Reads the file.
     * @throws IOException
     */
    public void ReadFile() throws IOException
    {
       	//Read in objects
    	try {
    		FileInputStream is = new FileInputStream ("packages.dat");
       		ObjectInputStream ois = new ObjectInputStream(is);
       		
    		Package line = null;
    		line = (Package) ois.readObject();
    		packages.add(line);
    			//Read and print object from file
    			while(line != null)
    			{
    				Package p = (Package) ois.readObject();
    				packages.add(p);
    				System.out.println("Here is package: " + p.toString());
    			}
    		
    		//Close files
    		ois.close();
    		is.close();
    	}
    		catch (ClassNotFoundException | FileNotFoundException e)
    		{	e.printStackTrace();
    		}
    	}

    /**
     * Prints the list of users.
     */
    public void listOfUsers() 
    {
    	if(userList.isEmpty())
    		System.out.println("No users.");
    	else
    	{
    		System.out.println("List of users:\n");
    		for(User users : userList)
			{
    			System.out.println("Here is UserID: " + users.getUserID());
       			System.out.println(users.toString());
			}
    	}
	}
    
    /**
     * Adds users.
     */
	public void addUser()			
	{
		System.out.println("Which user type do you wish to add? Type 1 for customer, or type 2 for employee?\n");
		System.out.println("Enter either 1 or 2: ");
		Scanner in = new Scanner(System.in);
	
		//Get and validate input
		int userType = in.nextInt();
		if(userType < 1 || userType > 2)
		{
			System.out.println("Enter 1 for customer or 2 for employee.");
			userType = in.nextInt();
		}
		
		//Add customer/employee depending on user input
	     int id;
	     String fName, lName;

	     //get random generated ID
	     id = randUserID();
	        
	     //get first name and last name from user
	     System.out.println("Enter your first name: ");
	     in.nextLine(); 
	     fName = in.nextLine();
         System.out.println("fname:" + fName);

	     System.out.println("Enter your last name: ");
	     lName = in.nextLine();
         System.out.println("lname:" + lName);

	     switch(userType)
	     {
	         case 1:
	         {
	        	 
	             System.out.println("in case 1");

	             Scanner SSN = new Scanner(System.in);
	             System.out.println("Enter social security number (8 digits): ");
	             int SSNum = SSN.nextInt();
	             System.out.println("this is the ssn" + SSNum);
	             String SSString = Integer.toString(SSNum);

	             while (SSString.length() != 8)
	             {
	                 System.out.println("Invalid SSN, enter again: ");
	                 SSN = new Scanner(System.in);
	                 SSNum = SSN.nextInt();
	                 SSString = Integer.toString(SSNum);
	             }
	             
				  Scanner sc = new Scanner(System.in);
				  System.out.println("Enter monthly salary: ");
				  float salary = sc.nextFloat();

				  System.out.println("Enter bank account number (6 digits): ");
				  int account = sc.nextInt();
				  
				  String accountString = Integer.toString(account);
				  
				  while (accountString.length() != 6)
				  {
				      System.out.println("Incorrect bank account number, enter again: ");
				      account = sc.nextInt();
				      accountString = Integer.toString(account);
				  }
				  
				  Employee employeeObject = new Employee(id, fName, lName, SSNum, salary, account);
				  userList.add(employeeObject);
				  break;
	         }
          case 2:
          {
              Scanner phoneNumber = new Scanner(System.in);

        	  System.out.println("Enter phone number (10 digits Numbers only! No spaces): ");
              String phone = phoneNumber.nextLine();
              
              while (phone.length() != 10)
              {
                  System.out.println("Invalid number, enter again: ");
                  phone = phoneNumber.nextLine();
              }

              Scanner address = new Scanner(System.in);
              System.out.println("Enter address: ");
              String location = address.nextLine();
              Customer customerObject = new Customer(id, fName, lName, phone, location);
              userList.add(customerObject);
              break;
          }
          default:
              break;
	     }
	}
	
	/**
	 * Updates user information.
	 */
	public void updateUserInfo() 
	{
		User update = searchUser();
		if (update == null)
			return;
		
		//Variables to use for name
		String line;
		Scanner in = new Scanner(System.in);

		//Get first name of user
		System.out.println("Enter your first name. It was originally: " + update.getFirstName());
		line = in.nextLine();

		//Update first name with input
		if(!(line.isEmpty()))
			update.setFirstName(update.validateName(line));
		
		//Get last name of user
		System.out.println("Enter your last name. It was originally: " + update.getLastName());
		line = in.nextLine();
		
		//Update last name with input
		if(!(line.isEmpty()))
			update.setLastName(update.validateName(line));
				
		//Update information for employee
		if(update instanceof Employee)
		{
			//Get salary and update
			System.out.println("Enter your salary. It was originally: " + ((Employee) update).getSal());
			line = in.nextLine();
			if(!(line.isEmpty()))
				((Employee) update).setSal(((Employee) update).validateSal(Float.parseFloat(line)));
			
			//Get bank account number and update
			System.out.println("Enter your bank number. It was originally: " + ((Employee) update).getBN());
			line = in.nextLine();
			if(!(line.isEmpty()))
				((Employee) update).setBN(((Employee) update).validateBN(Integer.parseInt(line)));
					
			//Get social security number and update
			System.out.println("Enter your social.  It was originally: " + ((Employee) update).getSSN());
			line = in.nextLine();
			if(!(line.isEmpty()))
				((Employee) update).setSSN(((Employee) update).validateSSN(Integer.parseInt(line)));
		}	
		
		//Update information for customer
		if(update instanceof Customer)
		{
			//Get address and update
			System.out.println("Enter your address. It was originally: " + ((Customer) update).getAddress());
			line = in.nextLine();
			if(!(line.isEmpty()))
				((Customer) update).setAddress(((Customer) update).validateAddress(line));
			
			//Get phone # and update
			System.out.println("Enter your phone # It was originally: " + ((Customer) update).getPhone());
			line = in.nextLine();
			if(!(line.isEmpty()))
				((Customer) update).setPhone(((Customer) update).validatePhone(line));
		}		
	}
    
	/**
	 * Searches for user.
	 * @return null
	 */
    public User searchUser()
    {
    	Scanner in = new Scanner(System.in);
    	int ID;
    	Boolean match = false;
    	
    	//Ask user what id to search for
    	System.out.println("What is the ID of the user you are searching? ");
    	ID = in.nextInt();

    	//Loop through every user
    	for(User users : userList)
    	{
    		//Check if IDs match
    		if((users.getUserID()) == ID)
    		{
    			match = true;
    			System.out.println("This is the match for that ID: " + users.toString());
    			return users;
    		}
    	}
    	
    	//Tell user if no ID found matching
    	if(!match)
    		System.out.println("No user match for that ID");
    		
    	return null;
    }
    
    /**
     * Formats and prints the transaction.
     */
    //Need to check this!
	public void printTransaction()
	{
		//Print out the transactions to console
		for(int i = 0; i < transactionInfo.size(); i++)
		{
			System.out.print(String.format("| %-15s| %-15s| %-15s| %-15s| %-15s| %-15s|", transactionInfo.get(i).getCustID(),
			transactionInfo.get(i).getTrackingNum(), transactionInfo.get(i).getShippingDate(), transactionInfo.get(i).getDeliverDate(),
			transactionInfo.get(i).getCost(), transactionInfo.get(i).getEmpID()));
		}
		
		System.out.println("\n\n");
	}

	/**
	 * Formats and prints the transaction.
	 */
	public void printTransactions()
	{
		System.out.println(" --------------------------------------------------------------------------------------------- ");
	    System.out.println("| Customer # | Tracking # | Shipping Date | Delivery Date  | Cost Of Shipping | Employee ID   |");
	    System.out.println(" --------------------------------------------------------------------------------------------- ");
	    for(Transaction trans : transactionInfo)
	    {
	    	System.out.println(String.format("| %-11s| %-11s| %-14s| %-15s| %-17s| %-14s|", trans.getCost(), trans.getTrackingNum(), trans.getShippingDate(),
            trans.getDeliverDate(), String.format("%.2f", trans.getCost()), trans.getEmpID()));
	    }
	    
	    System.out.println("\n\n");
	}
	
	/**
	 * Finishes the transaction.
	 */
	public void finishTransaction() 
	{
		User packageDestination = searchUser();
		User packageSource = searchUser();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter tracking #: ");
		String tn = sc.nextLine();
		Package deliver;
		
		//Tell user not valid cust
		if(!(packageDestination instanceof Customer))
		{
			System.out.println("Not a valid customer.\n");
			return;
		}
		
		//Tell user not valid emp
		if(!(packageSource instanceof Employee))
		{
			System.out.println("Not a valid employee.\n");
			return;
		}
		
		//Get price
		System.out.println("Enter price (float): ");
		sc.nextLine();
		float price = sc.nextFloat();
		
		//Validate
		while(!(sc.hasNextFloat()))
		{
			System.out.println("Enter price (float): ");
			sc.next();
			return;
		}
		
		for(Package p: storage)
		{
			if(tn.equalsIgnoreCase(p.getTrackingNumber()))
				deliver = p;
		}
	}
    
	/**
	 * Generates a random user ID.
	 * @return ID the random user ID
	 */
	public int randUserID()
	{
		int minimum = 000000000;
		int maximum = 999999999;
			
		Random random = new Random();
		int ID = random.nextInt(maximum - minimum + 1) + minimum;
		return ID;
	
	}
}

	
	

