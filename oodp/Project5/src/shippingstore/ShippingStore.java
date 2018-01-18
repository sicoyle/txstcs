package shippingstore;

import java.io.*;
import java.util.*;

/**
 * This class represents a car dealership software, providing some basic
 * operations.
 *
 * @author Junye Wen
 */
public class ShippingStore {

    private final List<Package> packageList;
    private final List<User> users;
    private final List<Transaction> transactions;

    private int userIdCounter = 1;

    /**
     * Default constructor. Initializes the inventory, users, and transactions
     * tables.
     */
    public ShippingStore() {
        this.packageList = new ArrayList<Package>();
        this.users = new ArrayList<User>();
        this.transactions = new ArrayList<Transaction>();
    }

    /**
     * Constructor. Initializes the package list, users, and transactions to
     * given values.
     *
     * @param packageList List of packages
     * @param users List of Users
     * @param transactions List of Transactions
     */
    public ShippingStore(List<Package> packageList, List<User> users, List<Transaction> transactions) {
        this.packageList = packageList;
        this.users = users;
        this.transactions = transactions;
    }

    /**
     *
     * @param Counter
     */
    public void setUserIdCounter(int Counter) {
        this.userIdCounter = Counter;
    }

    /**
     * Auxiliary method used to find a package in the database, given its
     * tracking number.
     *
     * @param ptn
     * @return The package found, or otherwise null.
     */
    public Package findPackage(String ptn) {
        for (Package p : packageList) {
            if (p.getPtn().equals(ptn)) {
                return p;
            }
        }
        return null;
    }

    /**
     * Returns true if the package exists in the database.
     * @param ptn
     * @return
     */
    public boolean packageExists(String ptn) {
        if (findPackage(ptn) != null)
            return true;
        return false;
    }

    /**
     *
     * @param ptn
     * @param specification
     * @param mailingClass
     * @param height
     * @param width
     */
    public void addEnvelope(String ptn, String specification, String mailingClass, int height, int width) {
        Envelope env = new Envelope(ptn, specification, mailingClass, height, width);
        packageList.add(env);
    }

    /**
     *
     * @param ptn
     * @param specification
     * @param mailingClass
     * @param dimension
     * @param volume
     */
    public void addBox(String ptn, String specification, String mailingClass, int dimension, int volume) {
        Box box = new Box(ptn, specification, mailingClass, dimension, volume);
        packageList.add(box);
    }

    /**
     *
     * @param ptn
     * @param specification
     * @param mailingClass
     * @param loadWeight
     * @param content
     */
    public void addCrate(String ptn, String specification, String mailingClass, float loadWeight, String content) {
        Crate crate = new Crate(ptn, specification, mailingClass, loadWeight, content);
        packageList.add(crate);
    }

    /**
     *
     * @param ptn
     * @param specification
     * @param mailingClass
     * @param material
     * @param diameter
     */
    public void addDrum(String ptn, String specification, String mailingClass, String material, float diameter) {
        Drum drum = new Drum(ptn, specification, mailingClass, material, diameter);
        packageList.add(drum);
    }


    /**
     * This method allows the user to delete a package from the inventory
     * database given its tracking number.
     * @param ptn The package tracking number
     * @return True if the package was found and was deleted. False otherwise.
     */
    public boolean deletePackage(String ptn) {

        for (Package p : packageList) {
            if (p.getPtn().equals(ptn)) {
                packageList.remove(p);
                return true;
            }
        }
        return false;
    }


    /**
     * Auxiliary private method to return a list of packages in a formatted
     * manner.
     */
    private String getFormattedPackageList(List<Package> packages) {
        String text = "---------------------------------------------------"
                + "----------------------------------------------------------\n";
        text += String.format("| %12s | %12s | %13s | %13s | %22s |%n",
                "PACKAGE TYPE", "TRACKING #", "SPECIFICATION", "MAILING CLASS", "OTHER DETAILS");
        text +=  "---------------------------------------------------"
                + "----------------------------------------------------------\n";
        for (Package p : packages) {
            text += p.getFormattedText();
        }
        text += "---------------------------------------------------"
                + "----------------------------------------------------------\n";

        return text;
    }

    /**
     * This method return all the packages currently in the inventory, in a
     * formatted manner.
     * @return
     */
    public String getAllPackagesFormatted() {
        return getFormattedPackageList(packageList);
    }

    /**
     *
     * @param ptn
     * @return
     */
    public String getPackageFormatted(String ptn) {
        ArrayList<Package> matchingPackage = new ArrayList<Package>(1);
        matchingPackage.add(findPackage(ptn));

        return getFormattedPackageList(matchingPackage);
    }

    /**
     *
     * @param firstName
     * @param lastName
     * @param phoneNumber
     * @param address
     */
    public void addCustomer(String firstName, String lastName, String phoneNumber, String address) {
        users.add(new Customer(userIdCounter++, firstName, lastName, phoneNumber, address));
    }

    /**
     *
     * @param firstName
     * @param lastName
     * @param ssn
     * @param monthlySalary
     * @param bankAccNumber
     */
    public void addEmployee(String firstName, String lastName, int ssn, float monthlySalary, int bankAccNumber) {
        users.add(new Employee(userIdCounter++, firstName, lastName, ssn, monthlySalary, bankAccNumber));
    }



    /**
     * Auxiliary private method to return a list of users in a formatted
     * manner.
     */
    private String getFormattedUserList(List<User> users) {
        String text ="---------------------------------------------------"
                + "------------------------------------------------"
                + "---------------\n";
        text += String.format("| %10s | %9s | %12s | %12s | %35s |%n",
                "USER TYPE", "USER ID", "FIST NAME", "LAST NAME", "OTHER DETAILS");
        text += "---------------------------------------------------"
                + "-----------------------------------------------"
                + "---------------\n";
        for (User u : users) {
            text += u.getFormattedText();
        }
        text += "---------------------------------------------------"
                + "-----------------------------------------------"
                + "---------------\n";

        return text;
    }

    /**
     * Returns a string list of all users in the database in a formatted manner.
     * @return a formatted string of all the users in the database.
     */
    public String getAllUsersFormatted() {
        return getFormattedUserList(users);
    }

    /**
     *
     * @param userID
     * @return
     */
    public boolean userExists(int userID) {
        if (findUser(userID) != null)
            return true;

        return false;
    }

    /**
     *
     * @param userID
     * @return
     */
    public User findUser(int userID) {
        User user = null;

        for (User u : users) {
            if (u.getId() == userID) {
                user = u;
            }
        }

        return user;
    }

    /**
     *
     * @param userID
     * @return
     */
    public boolean isCustomer(int userID) {
        User user = findUser(userID);
        if (user instanceof Customer)
            return true;
        return false;
    }

    /**
     *
     * @param userID
     * @return
     */
    public boolean isEmployee(int userID) {
        User user = findUser(userID);
        if (user instanceof Employee)
            return true;
        return false;
    }

    /**
     *
     * @param userID
     * @param firstName
     * @param lastName
     * @param phoneNumber
     * @param address
     */
    public void updateCustomer(int userID, String firstName, String lastName,
                               String phoneNumber, String address) {
        Customer customer = (Customer) findUser(userID);
        if (customer == null) {
            MainApp.textArea.setText("\nCustomer not found!");
            return;
        }
        customer.setFirstName(firstName);
        customer.setLastName(lastName);
        customer.setPhoneNumber(phoneNumber);
        customer.setAddress(address);
    }

    /**
     *
     * @param userID
     * @param firstName
     * @param lastName
     * @param ssn
     * @param monthlySalary
     * @param bankAccNumber
     */
    public void updateEmployee(int userID, String firstName, String lastName,
                               int ssn, float monthlySalary, int bankAccNumber) {
        Employee employee = (Employee) findUser(userID);
        if (employee == null) {
            MainApp.textArea.setText("\nEmployee not found!");
            return;
        }
        employee.setFirstName(firstName);
        employee.setLastName(lastName);
        employee.setSocialSecurityNumber(ssn);
        employee.setMonthlySalary(monthlySalary);
        employee.setBankAccountNumber(bankAccNumber);
    }

    /**
     *
     * @param customerId
     * @param employeeId
     * @param ptn
     * @param shippingDate
     * @param deliveryDate
     * @param price
     */
    public void addShppingTransaction(int customerId, int employeeId, String ptn,
                                      Date shippingDate, Date deliveryDate, float price) {
        Transaction trans = new Transaction(customerId, employeeId, ptn, shippingDate, deliveryDate, price);
        transactions.add(trans);
    }


    /**
     * Return a list of all recorded transactions.
     *
     * @return transactions
     */
    public String getAllTransactionsText() {
        String transText = "";
        for (Transaction trans : transactions) {
            transText += trans.toString();
        }
        return transText;
    }


    /**
     * This method is used to read the database from a file, serializable
     * objects.
     *
     * @return A new ShippingStore object.
     */
    @SuppressWarnings("unchecked") // This will prevent Java unchecked operation warning when
    // convering from serialized Object to Arraylist<>
    public static ShippingStore readDatabase() {
        MainApp.textArea.append("\nReading database...");

        File dataFile = new File("ShippingStore.ser");

        ShippingStore ss = null;

        // Try to read existing dealership database from a file
        InputStream file = null;
        InputStream buffer = null;
        ObjectInput input = null;
        try {
            if (!dataFile.exists()) {
                MainApp.textArea.append("\nData file does not exist. Creating a new database.");
                ss = new ShippingStore();
                return ss;
            }
            file = new FileInputStream(dataFile);
            buffer = new BufferedInputStream(file);
            input = new ObjectInputStream(buffer);

            // Read serilized data
            List<Package> packageList = (ArrayList<Package>) input.readObject();
            List<User> users = (ArrayList<User>) input.readObject();
            List<Transaction> transactions = (ArrayList<Transaction>) input.readObject();
            ss = new ShippingStore(packageList, users, transactions);
            ss.userIdCounter = input.readInt();

            input.close();
        } catch (ClassNotFoundException ex) {
            MainApp.textArea.append("\n" + ex.toString());
        } catch (FileNotFoundException ex) {
            MainApp.textArea.append("\nDatabase file not found.");
        } catch (IOException ex) {
            MainApp.textArea.append("\n" + ex.toString());
        } finally {
            close(file);
        }
        MainApp.textArea.append("\nDone.");

        return ss;
    }

    /**
     * This method is used to save the Dealership database as a serializable
     * object.
     */
    public void writeDatabase() {
        MainApp.textArea.append("\nWriting database...");
        //serialize the database
        OutputStream file = null;
        OutputStream buffer = null;
        ObjectOutput output = null;
        try {
            file = new FileOutputStream("ShippingStore.ser");
            buffer = new BufferedOutputStream(file);
            output = new ObjectOutputStream(buffer);

            output.writeObject(packageList);
            output.writeObject(users);
            output.writeObject(transactions);
            output.writeInt(userIdCounter);

            output.close();
        } catch (IOException ex) {
            MainApp.textArea.append("\n" + ex.toString());
        } finally {
            close(file);
        }
        MainApp.textArea.append("\nDone.");
    }

    /**
     * Auxiliary convenience method used to close a file and handle possible
     * exceptions that may occur.
     *
     * @param c
     */
    public static void close(Closeable c) {
        if (c == null) {
            return;
        }
        try {
            c.close();
        } catch (IOException ex) {
            MainApp.textArea.append("\n" + ex.toString());
        }
    }

}