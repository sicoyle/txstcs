package database;
import java.util.Scanner;

/**
 * Employee class extends User. It deals with all of the employee attributes.
 * It gets, sets, and validates the variables associated with employee.
 *
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */

public class Employee extends User 
{
	//Private member variables
	private int bankNum;
	private int social;
	private float salary;
	
	/**
	 * Employee constructor initializes all of the employee attributes.
	 * @param id the employee ID
	 * @param fn the employee's first name
	 * @param ln the employee's last name
	 * @param ssn the employee's social security number
	 * @param m the monthly salary
	 * @param d the bank account number associated with their direct deposit
	 */
	 Employee(int id, String fn, String ln, int ssn, float m, int d)
	 {
	        super(id, fn, ln);
	        this.social = ssn;
	        this.salary = m;
	        this.bankNum = d;
	    }
	
	 /**
	     * Retrieves employee bank number
	     * @return employee's bank number
	     */
	public int getBN() {return bankNum;}
	
	/**
     * Retrieves employee social security number
     * @return employee's social security number
     */
	public int getSSN()	{return social;}
	
	/**
     * Retrieves employee salary
     * @return employee's salary
     */
	public float getSal() {return salary;}
	
	/**
     * Assigns employee bank number
     * @return employee's bank number
     */
	public void setBN(int bankNum) {this.bankNum = bankNum;}
	
	/**
     * Assigns employee bank number
     * @return employee's bank number
     */
	public void setSSN(int social) {this.social = social;}
	
	/**
     * Assigns employee social security number
     * @return employee's social security number
     */
	public void setSal(float salary) {this.salary = salary;}

	/**
	 * Validate employee bank number
	 * @param number
	 * @return valid bank number
	 */
	public int validateBN(int number) 
	{
		while(number < 0)
		{
			System.out.println("Invalid bank number. Enter again:");
			Scanner in = new Scanner(System.in);
			number = in.nextInt();
		}
		
		//return valid bank number
		return number;
	}

	/**
	 * Validate employee social security number
	 * @param number
	 * @return valid social security number
	 */
	public int validateSSN(int number) 
	{
		while(number < 0)
		{
			System.out.println("Invalid social security number. Enter again:");
			Scanner in = new Scanner(System.in);
			number = in.nextInt();
		}
		
		//return valid bank number
		return number;
	}

/**
 * Validate employee salary
 * @param salary the employee's salary
 * @return salary the employee's salary
 */
	public float validateSal(float salary)
	{
		//While salary is not valid, ask for valid salary
		while(!(salary >= 0))
		{
			System.out.println("Invalid salary. Enter a valid salary. ");
			Scanner in = new Scanner(System.in);
			salary = in.nextFloat();
		}
		//Return valid salary
		return salary;
	}




}
