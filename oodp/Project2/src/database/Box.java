package database;
import java.util.Scanner;

/**
 * Template for adding a box to the database, which is a type of package object
 * @author Samantha and Cassandra Coyle
 * @version 1 10/4/2017
 */

class Box extends Package 
{
	//Private members
	private final int largeDim;
	private final int volume;
	
	/**
	 * Constructor for Box
	 * @param trackingNum for the box tracking number
	 * @param spec for the box specification
	 * @param mc for the box mailing class
	 * @param lDim for the box's largest dimension
	 * @param vol for the box's volume
	 */
	public Box(String trackingNum, String spec, String mc, int lDim, int vol)
	{
		super(trackingNum, spec, mc, "box");
		this.largeDim = lDim;
		this.volume = vol;
	}
	
	/**
	 * Gets the largest dimension of a box.
	 * @return the largest dimension of a box
	 */
	public int getLargeDim() {return this.largeDim;}	
	
	/**
	 * Gets the volume of a box.
	 * @return the volume of a box
	 */
	public int getVolume() {return this.volume;}
}	