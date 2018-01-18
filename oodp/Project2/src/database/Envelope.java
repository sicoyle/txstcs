package database;

/**
 * Template for adding a envelope to the database, which is a type of package object
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */

class Envelope extends Package
{

	//Private member fields
	private final int height;
	private final int width;
	
	/**
	 * Constructor for envelope, which is a package
	 * @param trackingNum for envelope tracking number
	 * @param spec for envelope specification
	 * @param mc for envelope mailing class
	 * @param h for envelope height
	 * @param w for envelope width
	 */
	public Envelope(String trackingNum, String spec, String mc, int h, int w)
	{
		super(trackingNum, spec, mc, "envelope");
		this.height = h;
		this.width = w;
				
	}
	
	/**
	 * Getter for envelope width
	 * @return envelope width
	 */
	public int getWidth() {return this.width;}
	
	/**
	 * Getter for envelope height
	 * @return envelope height
	 */
	public int getHeight() {return this.height;}


	
}
