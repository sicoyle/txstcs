package database;
import java.util.Scanner;

/**
 * Template for adding a user to the database, which is an abstract class
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */

public abstract class User 
{
	//Private members
	private String first;
	private String last;
	private int UID;
	
	/**
	 * Constructor for user
	 * @param id for user ID number
	 * @param fName for user first name
	 * @param lName for user last name
	 */
	 public User(int id, String fName, String lName)
	 {
	        this.UID = id;
	        this.first = fName;
	        this.last = lName;
	 }
	
	 /**
	  * Validation function for name
	  * @param name for user name
	  * @return valid name
	  */
	public String validateName(String name)
	{
		Scanner in = new Scanner(System.in);
		
		//While name isn't a match in database, let user know
		while(!(name.matches("[a-z A-Z]+")))
		{
			System.out.println("Invalid name. Enter another name: ");
			name = in.next();
		}
		
		//Return valid name
		return name;
	}
	
	/**
	 * Getter function for first name of user
	 * @return user first name
	 */
	public String getFirstName() {return first;}
	
	/**
	 * Getter function for last name of user
	 * @return user last name
	 */
	public String getLastName() {return last;}
	
	/**
	 * Getter function for user ID number
	 * @return user ID number
	 */
	public int getUserID() {return UID;}

	/**
	 * Setter function for user first name
	 * @param firstName for user first name
	 */
	public void setFirstName(String firstName) {this.first = firstName;	}
	
	/**
	 * Setter function for user last name
	 * @param lastName for user last name
	 */
	public void setLastName(String lastName){this.last = lastName;}

	/**
	 * Setter function for user ID number
	 * @param userID for user ID number
	 */
	public void setUserID(int userID) {this.UID = userID;}
	
    /**
     * Override toString to print the user.
     * @return user in a string
     */
    @Override
    public String toString() {
    	return getFirstName() + " " + getLastName() + " " + getUserID() + "\n";
    }
	
}
