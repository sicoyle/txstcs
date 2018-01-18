package database;
import java.util.Scanner;

/**
 * Template for adding a customer to the database, which is type user
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */

public class Customer extends User 
{
	//Private member fields
	private String phoneNum;
	private String address;

	/**
	 * Constructor for the customer, which is part of the abstract user class
	 * @param id for customer ID number
	 * @param fn for customer first name
	 * @param ln for customer last name
	 * @param p for customer phone number
	 * @param a for customer address
	 */
    Customer(int id, String fn, String ln, String p, String a)
    {
        super(id, fn, ln);
        this.phoneNum = p;
        this.address = a;
    }
	
    /**
     * Validation function for phone number
     * @param phone for phone number
     * @return valid phone number
     */
	public String validatePhone(String phone)
	{
		Scanner in = new Scanner(System.in);
		
		//While phone number is invalid, inform user
		//and get valid number
		while((phone.length() != 8) || !phone.matches("[0-9]+"))
		{
			System.out.println("Invalid phone #. Enter a valid #");
			phone = in.next();
		}
		
		//return valid phone number
		return phone;
	}
	
	/**
	 * Validation function for address
	 * @param address for address
	 * @return valid address
	 */
	public String validateAddress(String address)
	{
		Scanner in = new Scanner(System.in);
		
		//While address is invalid, inform user and get valid address
		while(!(address.matches("[a-zA-Z0-9 ]+"))) //verify if spaces work between chars
		{
			System.out.println("Invalid address. Enter a valid address.");
			address = in.nextLine();
		}
		
		//return valid address
		return address;
	}
	
	/**
	 * Getter for customer phone number
	 * @return phone number of customer
	 */
	public String getPhone() {return phoneNum;}
	
	/**
	 * Getter for customer address
	 * @return customer address
	 */
	public String getAddress(){return address;}
	
	/**
	 * Setter function for phone number
	 * @param phoneNum for customer phone number
	 */
	public void setPhone(String phoneNum) {this.phoneNum = phoneNum;}
	
	/**
	 * Setter function for customer address
	 * @param address for customer address
	 */
	public void setAddress(String address) {this.address = address;}
}
