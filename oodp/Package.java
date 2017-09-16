package Assignment1;
/**
	*This program simulates a shipping store database that allows users to maintain the packages within
	*storage room.
	*@author Samantha Coyle
	*@author Cassandra Coyle
*/
	/**
	*ShippingStore class will contain the constuctor to initialize and display menu options.
	*/
	public class Package
	{
		/**Construct the class with proper class variables*/
		private String shippingNumber;
		private String type;
		private String specification;
		private String mailingClass;
		private float weight;
		private int volume;
		String getShippingNumber(){return shippingNumber;}
		
		/**Accessors to get the values of the variables for the Package class.*/
		String getType(){return type;}
		String getSpecification(){return specification;}
		String getMailingClass(){return mailingClass;}
		float getWeight(){return weight;}
		int getVolume(){return volume;}

	
	
		/**Function to print options in menu*/
		public void menuOptions()
		{
			/**Display menu options to consolue.*/
			System.out.println("1. Show all existing package records in the database (in any order).");
			System.out.println("2. Add new package record to the database.");
			System.out.println("3. Delete package record from a database.");
			System.out.println("4. Search for a package (given its tracking number).");
			System.out.println("5. Show a list of packages within a given weight range.");
			System.out.println("6. Exit program");
		}
	



	};
	
	
