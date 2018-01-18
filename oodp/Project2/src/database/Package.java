package database;
import java.io.Serializable;
import java.util.Scanner;

/**
 * Package class displays the menu options and deals with getting and setting package values.
 * Implements serialization on objects.
 *
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */
public abstract class Package implements Serializable, Comparable<Package>
{
	//Private members
    private String trackingNumber;
    private String type;
    private String specification;
    private String mailingClass;

    
   /**
     * Default constructor of class package.
     */
    public Package()
    {}
    
 
    /**
     * Package constructor to initialize the package attributes. 
     * @param trackingNumber the package tracking number
     * @param specification the package specification
     * @param mailingClass the package mailing class
     * @param type the type of package
     */
    public Package(String trackingNumber, String specification, String mailingClass, String type)
    {
        this.trackingNumber = trackingNumber;
        this.specification = specification;
        this.mailingClass = mailingClass;
        this.type = type;
    } 
        
 
//    /**
//     * Sets menuOptions.
//     * @param Option the user input
//     */
//    public void setMenuOption(int Option)
//    {
//        menuOption = Option; 
//        System.out.println("Option within Menu Class: " + menuOption);
//    }
    
//    /**
//     * Get the menuOption.
//     * @return menuOption the user's selected menu option
//     */
//    public int getMenuOption(){return menuOption;}
//    
    /**
     * Get package trackingNumber.
     * @return trackingNumber the package's tracking number
     */
    public String getTrackingNumber(){return trackingNumber;}
    
    /**
     * Get package type.
     * @return type the package's type
     */
    public String getType() {return type;}
    
    /**
     * Get package specification.
     * @return specification the package's specification
     */
    public String getSpecification() {return specification;}
    
    /**
     * Get package mailingClass.
     * @return mailingClass the package's mailing class
     */
    public String getMailingClass() {return mailingClass;}
    
    /**
     * Get package weight.    
     * @return weight the package's weight
     */
//    public int getWeight() {return weight;}
    
    /**
     * Get package volume.
     * @return volume the package's volume
     */
//    public int getVolume() {return volume;}
    
    /**
     * Set package tracking number.
     * @param trackingNumber the package's tracking number
     */
	public void setTrackingNumber(String trackingNumber) {this.trackingNumber = trackingNumber;}
	
	/**
	 * Set package type.
	 * @param type the package's type
	 */
	public void setType(String type) {this.type = type;}
	
	/**
	 * Set package specification.
	 * @param specification the package's specification
	 */
	public void setSpecification(String specification) {this.specification = specification;}
	
	/**
	 * Set package mailing class.
	 * @param mailingClass the package's mailing class
	 */
	public void setMailingClass(String mailingClass) {this.mailingClass = mailingClass;}
	
	/**
	 * Set package weight.
	 * @param weight the package's weight
	 */
//	public void setWeight(String weight) {this.weight = weight;}
	
	/**
	 * Set package volume.
	 * @param volume the package's volume
	 */
//	public void setVolume(int volume) {this.volume = volume;}
	

	///I had print packages here, but moved to storage list
	
    
    /**
     * Validates the specification input
     * @param specif the package specification
     * @return specif the package specification
     */
    public String validSpecification(String specif)
    {
    	boolean isValid = false;
    	Scanner in = new Scanner(System.in);
    	
    	while(!isValid)
    	{
    		System.out.println("Invalid input. Enter specification:");
    		specif = in.next();
    		isValid = true;
    	}
    	
    	//return valid specification
    	return specif;
    }
  
    /**
     * Validates mailing class
     * @param mailingClass is the mailing class
     * @return mailingClass is the valid mailing class
     */
    public String validMailingClass(String mailingClass)
    {
    	boolean isValid = false;
    	Scanner in = new Scanner(System.in);
    	
    	while(!isValid)
    	{
    		System.out.println("Invalid input. Enter mailing class:");
    		mailingClass = in.next();
    		isValid = true;
    	}
    	
    	//return valid mailing class
    	return mailingClass;
    }
    
    /**
     * Validates the tracking number
     * @param trackNum the tracking number
     * @return trackNum the valid tracking number
     */
    public String validTrackingNum(String trackNum)
    {
    	Scanner in = new Scanner(System.in);
    	
    	//While invalid, get valid trackingNum
    	while((trackNum.length() != 5) || (!(trackNum.matches("[A-Z a-z 0-9]"))))
    	{
    		System.out.println("Invalid input. Enter tracking number: ");
    		trackNum = in.next();
    	}
    	
    	//Return valid tracking number
    	return trackNum;
    }
    
    /**
     * Override toString to print the package.
     * @return package in a string
     */
    @Override
    public String toString() {
    	return getTrackingNumber() + " " + /*getType() + " " +*/ getSpecification() + " " + getMailingClass() + " " + /*getWeight()*/ /*+ " " + getVolume() +*/ "\n";
    }

	/**
	 * Over writes compare to method. Sorts by tracking number
	 */
    @Override
    public int compareTo(Package p)
    {
    	String rightName = ((Package)p).getTrackingNumber();
    	return trackingNumber.compareTo(rightName);
    }
   
}
