package database;
import java.util.Date;

/**
 * 
 * Delivered class deals with the information of a delivered transaction.
 * It has the delivered constructor and the getters and setters.
 * 
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 *
 */

public class Delivered 
{
	//Private members
	private int employeeID;
	private int userID;
	private Date shipDate;
	private Date receivedDate;
	private float shippingCost;
	private String trackingNumber;
	
	/**
	 * Default constructor
	 */
	public Delivered() {}

	/**
	 * Delivered constructor initializes all the values associated with a delivered package.
	 * @param employeeID the employee's ID
	 * @param userID the user's ID
	 * @param trackingNumber the package tracking number
	 * @param shipDate the shipping date
	 * @param receivedDate the received date
	 * @param shippingCost the shipping cost
	 */
	public Delivered(int employeeID, int userID, String trackingNumber, Date shipDate, Date receivedDate, float shippingCost)
	{
		this.employeeID = employeeID;
		this.userID = userID;
		this.trackingNumber = trackingNumber;
		this.shipDate = shipDate;
		this.receivedDate = receivedDate;
		this.shippingCost = shippingCost;
		
	}

    /**
     * Retrieves Transaction's User ID
     * @return Transaction's User ID
     */
    public int getUserID(){return userID;}

    /**
     * Retrieves Transaction's Tracking Number
     * @return Transaction's Tracking Number
     */
    public String getTrackNum() {return trackingNumber;}

    /**
     * Retrieves Transaction's Ship Date
     * @return Transaction's Ship Date
     */
    public Date getShipDate() {return shipDate;}

    /**
     * Retrieves Transaction's Received Date
     * @return Transaction's Received Date
     */
    public Date getReceivedDate() {return receivedDate;}

    /**
     * Retrieves Transaction's Shipping Cost
     * @return Transaction's Shipping Cost
     */
    public float getShippingCost() {return shippingCost;}

    /**
     * Retrieves Transaction's Employee ID
     * @return Transaction's Employee ID
     */
    public int getEmployeeID() {return employeeID;}

    /**
     * Sets Transaction's User ID
     * @param userID Transaction's User ID
     */
    public void setUserID(int userID) {this.userID = userID;}

    /**
     * Sets Transaction's Tracking Number
     * @param trackNum Transaction's Tracking Number
     */
    public void setTrackNum(String trackNum) {this.trackingNumber = trackNum;}

    /**
     * Sets Transaction's Ship Date
     * @param shipDate Transaction's Ship Date
     */
    public void setShipDate(Date shipDate) {this.shipDate = shipDate;}

    /**
     * Sets Transaction's Received Date
     * @param receivedDate Transaction's Received Date
     */
    public void setReceivedDate(Date receivedDate) {this.receivedDate = receivedDate;}

    /**
     * Sets Transaction's Shipping Cost
     * @param shippingCost Transaction's Shipping Cost
     */
    public void setShippingCost(float shippingCost) {this.shippingCost = shippingCost;}

    /**
     * Sets Transaction's Employee ID
     * @param employeeID Transaction's Employee ID
     */
    public void setEmployeeID(int employeeID) {this.employeeID = employeeID;}
	
	
}
