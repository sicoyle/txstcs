package shippingstore;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.io.IOException;
import java.util.logging.*;

/**
 * Main access point
 */
public class MainApp {

    private ShippingStore ss;
    private JFrame frame;
    public static JTextArea textArea = new JTextArea(200, 100);         //Text area for output
    private final Scanner sc; // Used to read from System's standard input
    private static final Logger logger = Logger.getLogger("shippingstore.MainApp");
    private static final FileHandler fh = initFh();

    private static FileHandler initFh() {
        FileHandler fh = null;
        try {
            fh = new FileHandler("shippingstore.log");
            fh.setFormatter(new SimpleFormatter());
            logger.addHandler(fh);
        } catch (IOException ex) {
            Logger.getLogger(MainApp.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SecurityException ex) {
            Logger.getLogger(MainApp.class.getName()).log(Level.SEVERE, null, ex);
        }
        return fh;
    }

    /**
     * Constructor
     */
    public MainApp() {
        ss = ShippingStore.readDatabase();
        this.sc = new Scanner(System.in);
        frame = new JFrame("Shipping Store Interface");  //Initial frame setup
    }

    /**
     * This method servers as the main interface between the program and the user.
     * The method interacts with the user by printing out a set of options, and
     * asking the user to select one.
     */
    public void runSoftware() {

        frame.setLayout(new FlowLayout());
        JButton showPackageButton = new JButton("Show Packages");   //Buttons for user interaction
        JButton addPackageButton = new JButton("Add New Package");
        JButton deletePackageButton = new JButton("Delete Old Package");
        JButton searchPackageButton = new JButton("Search For Package");
        JButton showUserButton = new JButton("Show Users");
        JButton addUserButton = new JButton("Add User");
        JButton updateUserButton = new JButton("Update User");
        JButton deliverPackageButton = new JButton("Deliver Package");
        JButton showTransactionButton = new JButton("Show Complete Transactions");
        JButton exitButton = new JButton("Save Data and Exit Program");

        showPackageButton.addActionListener(new ActionListener() {      //Listeners for buttons
            public void actionPerformed(ActionEvent e) {
                showAllPackages();
                logger.info("showed all packages");
            }
        });

        addPackageButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    logger.info("starting to add a new package");
                    addNewPackage();
                    logger.info("package added successfully");
                } catch (BadInputException ex) {
                    logger.warning("illegal input values: new package not created");
                    textArea.append("Bad input. " + ex.getMessage());
                    textArea.append("Please try again.");
                }
            }
        });

        deletePackageButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                deletePackage();
                logger.info("deleted a package");
            }
        });

        searchPackageButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                searchPackage();
                logger.info("searched for a package");
            }
        });

        showUserButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showAllUsers();
                logger.info("showed all users");
            }
        });

        addUserButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                addNewUser();
                logger.info("added a new user");
            }
        });

        updateUserButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    logger.info("starting to update a user");
                    updateUser();
                    logger.info("updated user successfully");
                } catch (BadInputException ex) {
                    logger.warning("illegal input values: user not updated");
                    textArea.append("Bad input. " + ex.getMessage());
                    textArea.append("Please try again.");
                }
            }
        });

        deliverPackageButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    logger.info("starting to record package as delivered");
                    deliverPackage();
                    logger.info("recorded a package as delivered successfully");
                } catch (BadInputException ex) {
                    logger.warning("illegal input values: package not delivered");
                    textArea.append("Bad input. " + ex.getMessage());
                    textArea.append("Please try again.");
                }
            }
        });

        showTransactionButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showAllTransactions();
                logger.info("showed all transactions");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                ss.writeDatabase();
                frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
                logger.info("clicked save and exit");
            }
        });

        frame.add(showPackageButton);   //Adding buttons to framework
        frame.add(addPackageButton);
        frame.add(deletePackageButton);
        frame.add(searchPackageButton);
        frame.add(showUserButton);
        frame.add(addUserButton);
        frame.add(updateUserButton);
        frame.add(deliverPackageButton);
        frame.add(showTransactionButton);
        frame.add(exitButton);
        frame.add(textArea);

        frame.setSize(1200, 800);    //Setting frame values
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setUndecorated(true);
        frame.setVisible(true);
    }

    /**
     * This method allows the user to enter a new package to the list
     * database.
     * @throws shippingstore.BadInputException bad input
     */
    public void addNewPackage() throws BadInputException {
        try {
            int packageType = Integer.parseInt(JOptionPane.showInputDialog("Select package type:\n"
                    + "1. Envelope\n"
                    + "2. Box\n"
                    + "3. Crate\n"
                    + "4. Drum"));
            if (packageType < 1 || packageType > 4) {
                throw new BadInputException("Legal package type values: 1-4.");
            }

            String ptn = JOptionPane.showInputDialog("\nEnter tracking number (string): ");
            if (ptn.length() > 5) {
                throw new BadInputException("Tracking number should not be more that 5 characters long.");
            }

            if (ss.packageExists(ptn)) {
                throw new BadInputException("\nPackage with the same tracking number exists, try again");
            }

            String specification = JOptionPane.showInputDialog("\nEnter Specification: Fragile, Books, Catalogs, Do-not-bend, or N/A");
            boolean correct = false;

            correct = specification.equalsIgnoreCase("Fragile") || specification.equalsIgnoreCase("Books") || specification.equalsIgnoreCase("Catalogs");
            correct = correct || specification.equalsIgnoreCase("Do-not-bend") || specification.equalsIgnoreCase("N/A");

            if (!(correct)) {
                throw new BadInputException("Specifications can only be one of the following: Fragile, Books, Catalogs, Do-not-bend, or N/A");
            }

            String mailingClass = JOptionPane.showInputDialog("\nEnter mailing class can be First-Class, Priority, Retail, Ground, or Metro.");

            correct = mailingClass.equalsIgnoreCase("First-Class") || mailingClass.equalsIgnoreCase("Priority") || mailingClass.equalsIgnoreCase("Retail");
            correct = correct || mailingClass.equalsIgnoreCase("Ground") || mailingClass.equalsIgnoreCase("Metro");
            if (!(correct)) {
                throw new BadInputException("Specifications can only be one of the following: Fragile, Books, Catalogs, Do-not-bend, or N/A");
            }

            if (packageType == 1) {
                int height = Integer.parseInt(JOptionPane.showInputDialog("\nEnter height (inch), (int): "));
                if (height < 0) {
                    throw new BadInputException("Height of Envelope cannot be negative.");
                }

                int width = Integer.parseInt(JOptionPane.showInputDialog("\nEnter width (inch), (int): "));
                if (width < 0) {
                    throw new BadInputException("Width of Envelope cannot be negative.");
                }

                ss.addEnvelope(ptn, specification, mailingClass, height, width);

            } else if (packageType == 2) {
                int dimension = Integer.parseInt(JOptionPane.showInputDialog("\nEnter largest dimension (inch), (int): "));
                if (dimension < 0) {
                    throw new BadInputException("Largest dimension of Box cannot be negative.");
                }

                int volume = Integer.parseInt(JOptionPane.showInputDialog("\nEnter volume (inch^3), (int): "));
                if (volume < 0) {
                    throw new BadInputException("Volume of Box cannot be negative.");
                }

                ss.addBox(ptn, specification, mailingClass, dimension, volume);

            } else if (packageType == 3) {

                float weight = Float.parseFloat(JOptionPane.showInputDialog("\nEnter maximum load weight (lb), (float): "));
                if (weight < 0.0f) {
                    throw new BadInputException("Maximum load weight of Crate cannot be negative.");
                }

                String content = JOptionPane.showInputDialog("\nEnter content (string): ");

                ss.addCrate(ptn, specification, mailingClass, weight, content);

            } else if (packageType == 4) {

                String material = JOptionPane.showInputDialog("\nEnter material (Plastic / Fiber): ");
                if (!(material.equalsIgnoreCase("Plastic") || material.equalsIgnoreCase("Fiber"))) {
                    throw new BadInputException("Material of Drum can only be plastic or fiber.");
                }

                float diameter = Float.parseFloat(JOptionPane.showInputDialog("\nEnter diameter (float): "));
                if (diameter < 0.0f) {
                    throw new BadInputException("Diameter of Drum cannot be negative.");
                }

                ss.addDrum(ptn, specification, mailingClass, material, diameter);

            } else {
                textArea.append("Unknown package type entered. Please try again.");
            }
        } catch (NumberFormatException e) {
            textArea.setText("\nInput must be a number, please try again");
        }
    }

    /**
     * This method prints out all the package currently in the inventory, in a
     * formatted manner.
     */
    public void showAllPackages() {
        textArea.setText(ss.getAllPackagesFormatted());

    }

    /**
     * This method allows the user to delete a package from the inventory
     * database.
     */
    public void deletePackage() {
        String ptn = JOptionPane.showInputDialog("\nEnter tracking number of pacakge to delete (string): ");

        if (ss.deletePackage(ptn))
            textArea.append("Package deleted.");
        else
            textArea.append("Package with given tracking number not found in the database.");
    }

    /**
     * This method allows the users to search for a package given its tracking number
     * and then it prints details about the package.
     */
    public void searchPackage() {
        String ptn = JOptionPane.showInputDialog("\nEnter tracking number of package to search for (string): ");

        if (ss.packageExists(ptn))
            textArea.setText(ss.getPackageFormatted(ptn));
        else
            textArea.setText("Package with PTN " + ptn + " not found in the database");
    }

    /**
     * Prints out a list of all users in the database.
     */
    public void showAllUsers() {
        textArea.setText(ss.getAllUsersFormatted());
    }

    /**
     * This method allows a new user to be added to the database.
     *
     */
    public void addNewUser() {
        try {

            boolean success;
            // Add fields for new user
            int userType = 0;
            boolean check = false;

            userType = Integer.parseInt(JOptionPane.showInputDialog("Select user type:\n"
                    + "1. Customer\n"
                    + "2. Employee"));
            while (userType < 1 || userType > 2) {
                userType = Integer.parseInt(JOptionPane.showInputDialog("Wrong integer value: choose 1 or 2\n Select user type:\n"
                        + "1. Customer\n"
                        + "2. Employee"));
            }

            String firstName = JOptionPane.showInputDialog("\nEnter first name (string): ");

            String lastName = JOptionPane.showInputDialog("\nEnter last name (string): ");

            if (userType == 1) {
                String phoneNumber = JOptionPane.showInputDialog("\nEnter phone number (string): ");

                String address = JOptionPane.showInputDialog("\nEnter address (string): ");

                ss.addCustomer(firstName, lastName, phoneNumber, address);

            } else if (userType == 2) {

                check = false;
                float monthlySalary = 0.0f;

                    monthlySalary = Float.parseFloat(JOptionPane.showInputDialog("\nEnter monthly salary (float): "));
                    while (monthlySalary < 0.0f) {
                        monthlySalary = Float.parseFloat(JOptionPane.showInputDialog("Monthly salary cannot be less than zero" +
                                "\nEnter monthly salary (float): "));
                    }

                int ssn = 0;
                check = false;
                while (!check) {

                    ssn = Integer.parseInt(JOptionPane.showInputDialog("\nEnter SSN (9-digital int): "));
                    if (String.valueOf(ssn).length() != 9) {
                        textArea.append("\nThat is not a nine digit number");
                    } else if (ssn < 10000000 || ssn > 999999999) {
                        textArea.append("\nGive a correct 9 digit integer");
                    } else {
                        check = true;
                    }
                }// end while

                check = false;
                int bankAccNumber = 0;
                while (!check) {
                    bankAccNumber = Integer.parseInt(JOptionPane.showInputDialog("\nEnter bank account number (int): "));
                    if (bankAccNumber < 0) {
                        textArea.append("\nBank account cannot be negative");
                    } else {
                        check = true;
                    }
                }//end while

                ss.addEmployee(firstName, lastName, ssn, monthlySalary, bankAccNumber);
            } else {
                textArea.append("Unknown user type. Please try again.");
            }
        } catch (NumberFormatException e) {
            textArea.setText("\nInput must be a number, please try again");
        }
    }

    /**
     * This method can be used to update a user's information, given their user
     * ID.
     *
     * @throws shippingstore.BadInputException
     */
    public void updateUser() throws BadInputException {
        try {

            boolean check = false;
            int userID = Integer.parseInt(JOptionPane.showInputDialog("\nEnter user ID: "));

            if (!ss.userExists(userID)) {
                textArea.append("User not found.");
                return;
            }


            String firstName = JOptionPane.showInputDialog("\nEnter first name (string): ");

            String lastName = JOptionPane.showInputDialog("\nEnter last name (string): ");

            if (ss.isCustomer(userID)) {
                String phoneNumber = JOptionPane.showInputDialog("\nEnter phone number (string): ");
                String address = JOptionPane.showInputDialog("\nEnter address (string): ");

                ss.updateCustomer(userID, firstName, lastName, phoneNumber, address);

            } else { //User is an employee

                float monthlySalary = 0.0f;
                check = false;
                while (!check) {
                    monthlySalary = Float.parseFloat(JOptionPane.showInputDialog("\nEnter monthly salary (float): "));
                    if (monthlySalary < 0.0f) {
                        new BadInputException("Monthly salary cannot be negative.");
                    } else {
                        check = true;
                    }
                }

                int ssn = 0;
                check = false;
                while (!check) {
                    ssn = Integer.parseInt(JOptionPane.showInputDialog("\nEnter SSN (9-digital int): "));
                    if (String.valueOf(ssn).length() != 9) {
                        new BadInputException("\nThat is not a nine digit number");
                    } else if (ssn < 10000000 || ssn > 999999999) {
                        new BadInputException("\nGive a correct 9 digit integer");

                    } else {
                        check = true;
                    }
                }// end while

                int bankAccNumber = 0;
                check = false;
                while (!check) {
                    bankAccNumber = Integer.parseInt(JOptionPane.showInputDialog("\nEnter bank account number (int): "));
                    if (bankAccNumber < 0) {
                        new BadInputException("Bank account cannot be negative");
                    } else {
                        check = true;
                    }
                } //end while

                ss.updateEmployee(userID, firstName, lastName, ssn, monthlySalary, bankAccNumber);
            }

        } catch (NumberFormatException e) {
            textArea.setText("\nInput must be a number, please try again");
        }
    }

    /**
     * This method is used to complete a package shipping/delivery transaction.
     *
     * @throws shippingstore.BadInputException
     */
    public void deliverPackage() throws BadInputException {
        try {
            Date currentDate = new Date(System.currentTimeMillis());

            int customerId = Integer.parseInt(JOptionPane.showInputDialog("\nEnter customer ID (int): "));
            //Check that the customer exists in database
            boolean customerExists = ss.userExists(customerId);

            if (!customerExists) {
                textArea.setText("\nThe customer ID you have entered does not exist in the database.\n"
                        + "Please add the customer to the database first and then try again.");
                return;
            }

            int employeeId = Integer.parseInt(JOptionPane.showInputDialog("\nEnter employee ID (int): "));

            //Check that the employee exists in database
            boolean employeeExists = ss.userExists(employeeId);

            if (!employeeExists) {
                textArea.setText("\nThe employee ID you have entered does not exist in the database.\n"
                        + "Please add the employee to the database first and then try again.");
                return;
            }

            String ptn = JOptionPane.showInputDialog("\nEnter tracking number (string): ");

            //Check that the package exists in database
            if (!ss.packageExists(ptn)) {
                textArea.setText("\nThe package with the tracking number you are trying to deliver "
                        + "does not exist in the database. Aborting transaction.");
                return;
            }

            float price = Float.parseFloat(JOptionPane.showInputDialog("\nEnter price (float): "));
            if (price < 0.0f) {
                throw new BadInputException("Price cannot be negative.");
            }

            ss.addShppingTransaction(customerId, employeeId, ptn, currentDate, currentDate, price);
            ss.deletePackage(ptn);

            textArea.append("\nTransaction Completed!");

        } catch (NumberFormatException e) {
            textArea.setText("\nInput must be a number, please try again");
        }
    }


    /**
     * Prints out a list of all recorded transactions.
     */
    public void showAllTransactions() {
        textArea.setText(ss.getAllTransactionsText());
    }


    /**
     * The main method of the program.
     *
     * @param args the command line arguments
     */
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        MainApp app = new MainApp();
        app.runSoftware();
    }
}