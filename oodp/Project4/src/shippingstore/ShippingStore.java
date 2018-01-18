package shippingstore;

import java.io.IOException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.File;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This class is used to represent a database interface for a list of
 * <CODE>Package Order</CODE>'s. It using a plain-text file "PackageOrderDB.txt"
 * to store and write package order objects in readable text form. It contains
 * an <CODE>ArrayList</CODE> called <CODE>packageOrerList</CODE> to store the
 * database in a runtime friendly data structure. The <CODE>packageOrerList</CODE>
 * is written to "PackageOrderDB.txt" at the end of the <CODE>ShippingStore</CODE> object's
 * life by calling <CODE>flush()</CODE>. This class also provides methods for
 * adding, remove, and searching for shipping orders from the list.
 *
 * @author Samantha Coyle
 */
public class ShippingStore {

    private final File dataFile;
    private ArrayList<PackageOrder> packageOrderList;

    /**
     * This constructor is hard-coded to open "<CODE>PackageOrderDB.txt</CODE>" and
     * initialize the <CODE>packageOrerList</CODE> with its contents. If no such file
     * exists, then one is created. The contents of the file are "loaded" into
     * the packageOrerList ArrayList in no particular order. The file is then closed
     * during the duration of the program until <CODE>flush()</CODE> is called.
     * @throws IOException
     */
    public ShippingStore() throws IOException {
        
        dataFile = new File("PackageOrderDB.txt");
        packageOrderList = new ArrayList<>();
        

        // If data file does not exist, create it.
        if (!dataFile.exists()) {
            System.out.println("Data file does not exist, creating one now . . .");
            //if the file doesn't exists, create it
            PrintWriter pw = new PrintWriter(dataFile);
            //close newly created file so we can reopen it
            pw.close();
        }
    }
    
    /**
     * Method that returns a reference to the data file.
     * @return dataFile
     */
    public File getDataFile() {
        return dataFile;
    }

    /**
     * Method showPackageOrer displays the current list of package orders in the Arraylist in no
     * particular order.
     *
     */
    public void showPackageOrders() {
        showPackageOrders(packageOrderList);
    }

    /**
     * Private method used as an auxiliary method to display a given ArrayList
     * of package orders in a formatted manner.
     *
     * @param orders the package order list to be displayed.
     */
    private void showPackageOrders(ArrayList<PackageOrder> orders) {

        System.out.println(" -------------------------------------------------------------------------- ");
        System.out.println("| Tracking # | Type    | Specification | Class       | Weight(oz) | Volume |");
        System.out.println(" -------------------------------------------------------------------------- ");

        for (int i = 0; i < orders.size(); i++) {
            System.out.println(String.format("| %-11s| %-8s| %-14s| %-12s| %-11s| %-7s|",
                    orders.get(i).getTrackingNumber(),
                    orders.get(i).getType(),
                    orders.get(i).getSpecification(),
                    orders.get(i).getMailingClass(),
                    String.format("%.2f", orders.get(i).getWeight()),
                    Integer.toString(orders.get(i).getVolume())
                ));
        }
        System.out.println(" --------------------------------------------------------------------------\n");

    }

    /**
     * This method displays package orders that have a weight within the range of
     * <CODE>low</CODE> to <CODE>high</CODE>.
     *
     * @param low a float that is the lower bound weight.
     * @param high a float that is the upper bound weight.
     */
    public void showPackageOrdersRange(float low, float high) {
        ArrayList<PackageOrder> orders = new ArrayList<>();
        for (PackageOrder order : packageOrderList) {
            if ((low <= order.getWeight()) && (order.getWeight() <= high)) {
                orders.add(order);
            }
        }
        
        if (orders.isEmpty())
            System.out.println("No packages found with weight within the given range.\n");
        else
            showPackageOrders(orders);
    }

    /**
     * This method can be used to find a package order in the Arraylist of orders.
     *
     * @param trackingNumber a <CODE>String</CODE> that represents the tracking number 
     * of the order that to be searched for.
     * @return the <CODE>int</CODE> index of the package orders in the Arraylist of orders,
     * or -1 if the search failed.
     */
    public int findPackageOrder(String trackingNumber) {

        int index = -1;

        for (int i = 0; i < packageOrderList.size(); i++) {
            String temp = packageOrderList.get(i).getTrackingNumber();

            if (trackingNumber.equalsIgnoreCase(temp)) {
                index = i;
                break;
            }

        }

        return index;
    }
    
    /**
     * This method can be used to search for a package order in the Arraylist of orders.
     *
     * @param trackingNumber a <CODE>String</CODE> that represents the tracking number
     * of the order that to be searched for.
     */
    public void searchPackageOrder(String trackingNumber) {

        int index = findPackageOrder(trackingNumber);

        if (index != -1) {
            ArrayList<PackageOrder> order = new ArrayList<>(1);
            order.add(getPackageOrder(index));
            System.out.println("\nHere is the order that matched:\n");
            showPackageOrders(order);
        } else {
            System.out.println("\nSearch did not find a match.\n");
        }
    }
    

    /**
     * This method is used to add a package order to the orderList ArrayList. In order for a
     * package order to be added to the ArrayList it must comply with the following:
     * <p>
     * 1. The order is not already in the ArrayList according to the tracking number
     * as the unique key.
     * <p>
     * 2. The TrackningNumber string matches the following regular expression:
     * <CODE>"[A-Za-z0-9]{5}"</CODE> or in other words: it
     * is 5 alphanumeric characters.
     * <p>
     * 3. The Type of the order can be only one of the following:
     *    Postcard, Letter, Envelope, Packet, Box, Crate, Drum, Roll, Tube.
     * <p>
     * 4. The Specification of the order can be only one of the following:
     *    Fragile, Books, Catalogs, Do-not-Bend, N/A.
     * <p>
     * 5. The Mailing Class of the order can be only one of the following:
     *    First-Class, Priority, Retail, Ground, Metro.
     * <p>
     * 6. The Weight must be non-negative.
     * <p>
     * 7. The Volume must be non-negative.
     * @param toAdd the <CODE>PackageOrder</CODE> object to add to the
     * <CODE>packageOrerList</CODE>
     */
    public void addOrder(String trackingnumber, String type, String specification, String mailingclass, String weight, String volume) {

        if (this.findPackageOrder(trackingnumber) != -1) {
            System.out.println("Package Order already exists in database. \n");
            return;
        }

        if (!trackingnumber.matches("[A-Za-z0-9]{5}")) {
            System.out.println("Invalid Tracking Number: not proper format."
                + "Tracking Number must be at least 5 alphanumeric characters.");
            return;
        }

        if (!(type.equals("Postcard") || type.equals("Letter") || type.equals("Envelope")
            || type.equals("Packet") || type.equals("Box")|| type.equals("Crate")
            || type.equals("Drum")|| type.equals("Roll")|| type.equals("Tube"))) {
            System.out.println("Invalid type:\n"
                + "Type must be one of following: "
                + "Postcard, Letter, Envelope, Packet, Box, Crate, Drum, Roll, Tube.");
            return;
        }

        if (!(specification.equals("Fragile") || specification.equals("Books") || specification.equals("Catalogs")
            || specification.equals("Do-not-Bend") || specification.toUpperCase().equals("N/A"))) {
            System.out.println("Invalid specification:\n"
                + "Specification must be one of following: "
                + "Fragile, Books, Catalogs, Do-not-Bend, N/A.");
            return;
        }

        if (!(mailingclass.equals("First-Class") || mailingclass.equals("Priority") || mailingclass.equals("Retail")
            || mailingclass.equals("Ground") || mailingclass.equals("Metro")) ) {
            System.out.println("Invalid Mailing Class:\n"
                + "Mailing Class must be one of following: "
                + "First-Class, Priority, Retail, Ground, Metro.");
            return;
        }

        if (Float.parseFloat(weight) < 0) {
            System.out.println("The weight of package cannot be negative.");
            return;
        }

        if (!volume.matches("[0-9]{1,6}")) {
            System.out.println("Invalid volume:\n"
                + "The package's volume has to be an integer number between 0 and 999999. ");
            return;
        }

        //If passed all the checks, add the order to the list
        packageOrderList.add(new PackageOrder(trackingnumber, type, specification, mailingclass,
                Float.parseFloat(weight), Integer.parseInt(volume)));
        System.out.println("Package Order has been added.\n");
    }

    /**
     * This method will remove an order from the <CODE>packageOrerList</CODE> ArrayList. It
     * will remove the instance of an order that matches tracking number that was
     * passed to this method. If no such order exists, it will produce an error message.
     *
     * @param toDelete the <CODE>PackageOrder</CODE> object to be removed.
     */
    public void removeOrder(String trackingNum) {
        int orderID = findPackageOrder(trackingNum);
        if (orderID == -1) {
            System.out.println("\nAction failed. No package order with the given tracking # exist in database.\n");
        }
        else {
            packageOrderList.remove(orderID);
            System.out.println("\nAction successful. Package order has been removed from the database.\n");
        }
    }

    /**
     * This method is used to retrieve the PackageOrder object from the
     * <CODE>PackageOrderList</CODE> at a given index.
     *
     * @param i the index of the desired <CODE>PackageOrder</CODE> object.
     * @return the <CODE>PackageOrder</CODE> object at the index or null if the index is
     * invalid.
     */
    public PackageOrder getPackageOrder(int i) {
        if (i < packageOrderList.size() && i >= 0) {
            return packageOrderList.get(i);
        } else {
            System.out.println("Invalid Index. Please enter another command or 'h' to list the commands.");
            return null;
        }
    }
    
    /**
     * This method reads data from the FileReader provided as input and puts them
     * in the packageOrderList.
     * @param dataReader The input FileReader to read from.
     * @throws IOException If any problem occurs with the data input.
     */
    public void read(Reader dataReader) throws IOException {
        
        Scanner orderScanner = new Scanner(dataReader);

        //Initialize the Array List with package orders from PackageOrderDB.txt
        while (orderScanner.hasNextLine()) {

            // split values using the space character as separator
            String[] temp = orderScanner.nextLine().split(" ");

            packageOrderList.add(new PackageOrder(temp[0], temp[1], temp[2], temp[3],
                    Float.parseFloat(temp[4]), Integer.parseInt(temp[5])));
        }

        //Package order list is now in the ArrayList completely so we can close the file
        orderScanner.close();
    }

    /**
     * This method accepts a <CODE>Writer</CODE> to a file and overwrites it with a text representation of
     * all the package orders in the <CODE>PackageOrderList</CODE>.
     * This should be the last method to be called before exiting the program.
     * @param dataWriter The data to write in the file.
     * @throws IOException
     */
    public void flush(Writer dataWriter) throws IOException {
        
        for (PackageOrder c : packageOrderList) {
            dataWriter.write(c.toString());
        }

        dataWriter.close();
    }

}
