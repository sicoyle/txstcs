package database;

/**
 * Template for adding a crate to the database, which is a type of package object
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */
class Crate extends Package {
	
	//Private member fields
	private final float maxLoad;
	private final String content;
	
	/**
	 * Constructor for crate
	 * @param trackingNum for the crate tracking number
	 * @param spec for the crate specification
	 * @param mc for the crate mailing class
	 * @param mLoad for the crate maximum load weight
	 * @param cont for the crate content
	 */
	public Crate(String trackingNum, String spec, String mc, float mLoad, String cont)
	{
		super(trackingNum, spec, mc, "crate");
		this.maxLoad = mLoad;
		this.content = cont;	
	}
	
	/**
	 * Getter for the maximum load weight
	 * @return the max load weight
	 */
	public float getMaxLoad() {return this.maxLoad;}
	
	/**
	 * Getter for the content of the crate
	 * @return content of crate
	 */
	public String getContent() {return this.content;}
	
}
