package database;
import java.util.Date;
import java.io.Serializable;

/**
 * Transaction class initializes and gets the user information.
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */

public class Transaction implements Serializable
{
	
	//Private member fields
	private final String trackingNum;
	private final Date deliverDate;
	private final Date shippingDate;
	private final int custID;
	private final int empID;
	private final float cost;
	
	/**
	 * Transaction constructor initializes the user attributes.
	 * @param custID the customer ID
	 * @param eID the employee ID
	 * @param tn the tracking number
	 * @param shipD the shipping date
	 * @param deliverD the deliver date
	 * @param costShip the shipping cost
	 */
	public Transaction(int custID, int eID, String tn, Date shipD, Date deliverD, float costShip)
	{
		this.custID = custID;
		this.empID = eID;
		this.trackingNum = tn;
		this.shippingDate = shipD;
		this.deliverDate = deliverD;
		this.cost = costShip;
	}
	
	/**
	 * Receives the customer ID.
	 * @return the customer's ID
	 */
	public int getCustID() {return this.custID;}

	/**
	 * Receives the tracking number.
	 * @return the tracking number
	 */
	public String getTrackingNum() {return trackingNum;}
	
	/**
	 * Receives the shipping date.
	 * @return the shipping date
	 */
	public Date getShippingDate() {return shippingDate;}
	
	/**
	 * Receives the deliver date.
	 * @return the deliver date
	 */
	public Date getDeliverDate() {return deliverDate;}
	
	/**
	 * Receives the shipping cost.
	 * @return the shipping cost
	 */
	public float getCost() {return cost;}
	
	/**
	 * Receives the employee ID.
	 * @return the employee's ID
	 */
	public int getEmpID() {return empID;}
	
	//Add a transaction to the complete transaction array list
	
}
