package database;

import static java.lang.System.out;
import java.util.Date;
import java.util.ArrayList;
import java.io.*;

/**
 * CompleteTransaction class deals with File I/O.
 * Implements serialization on objects.
 *
 * @author Samantha Coyle
 * @author Cassandra Coyle
 * @version 1 10/4/2017
 */
public class CompleteTransaction implements Serializable
{
	private String FileName = "Prog2.txt";
	private static ArrayList<Transaction> CTransaction;
	
	/**
	 * CompleteTransaction deals with File I/O.
	 */
	public CompleteTransaction() 
	{
		CTransaction = new ArrayList<>();
		
//		try 
//		{
//			FileInputStream fin = new FileInputStream(FileName);
//			ObjectInputStream objStream = new ObjectInputStream(fin);
//			CTransaction = (ArrayList<Transaction>) objStream.readObject();
//		}
//		catch(IOException | ClassNotFoundException ioe)
//		{
//			System.out.println("Error with file.");
//		}
//		catch(FileNotFoundException fnfe)
//		{
//			FileOutputStream fout = new FileOutputStream(FileName, false);
//		}
	}
	
	/**
	 * End transaction adds a completed transaction.
	 * @param custID the customer ID
	 * @param eID the employee ID
	 * @param tn the tracking number
	 * @param shipD the shipping date
	 * @param deliverD the deliver date
	 * @param costShip the shipping cost
	 */
	//removed , StorageList storage parameter
	public static void endTransaction(int custID, int eID, String tn, Date shipD, Date deliverD, float costShip)
	{
		CTransaction.add(new Transaction(custID, eID, tn, shipD, deliverD, costShip));
		System.out.println("Here is the complete transaction log: ");
		for(Transaction transactionsCompleted: CTransaction)
			System.out.println(transactionsCompleted);
	}	
	
	public static void printCompleteTransaction()
	{
		for(Transaction ct : CTransaction)
			System.out.println(ct.toString());
			
	}
	
}
