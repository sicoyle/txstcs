package database;

/**
 * Template for adding a drum to the database, which is a type of package object
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */
class Drum extends Package 
{
	//Private member fields
	private final String material;
	private final float diameter;
	
	/**
	 * Constructor for drum packages
	 * @param trackingNum for drum tracking number
	 * @param spec for drum specification
	 * @param mc for drum mailing class
	 * @param mat for drum material
	 * @param diam for drum diameter
	 */
	public Drum(String trackingNum, String spec, String mc, String mat, float diam)
	{
		super(trackingNum, spec, mc, "drum");
		this.material = mat;
		this.diameter = diam;
	}
	
	/**
	 * Function to get material of drum
	 * @return drum material
	 */
	public String getMaterial() {return this.material;}
	
	/**
	 * Getter function to get drum diameter
	 * @return diameter of drum
	 */
	public float getDiameter() {return this.diameter;}
	
}
