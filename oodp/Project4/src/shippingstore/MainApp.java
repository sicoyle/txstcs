package shippingstore;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * This is the main class of the ShippingStore database manager. It provides a
 * console for a user to use the 5 main commands.
 *
 * @author Samantha Coyle
 */
public class MainApp {

    /**
     * This method will begin the user interface console. Main uses a loop to
     * continue doing commands until the user types '6'. A lot of user input
     * validation is done in the loop. At least enough to allow the interface
     * with ShippingStore to be safe.
     *
     * @param args this program expects no command line arguments
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        // Read database from file.
        ShippingStore shippingstore = new ShippingStore();
        FileReader dataReader = new FileReader(shippingstore.getDataFile());
        shippingstore.read(dataReader);

        
        // Console user intererface
        String welcomeMessage = "\nWelcome to the Shipping Store database. Choose one of the following functions:\n\n"
                + "\t1. Show all existing package orders in the database\n"
                + "\t2. Add a new package order to the database.\n"
                + "\t3. Delete a package order from a database.\n"
                + "\t4. Search for a package order (given its Tracking #).\n"
                + "\t5. Show a list of orders within a given weight range.\n"
                + "\t6. Exit program.\n";

        System.out.println(welcomeMessage);

        int selection = in.next().charAt(0);
        in.nextLine();

        while (selection != '6') {

            switch (selection) {
                case '1':
                    shippingstore.showPackageOrders();
                    break;
                case '2':
                    System.out.println("\nPlease type description of package with the following pattern:\n"
                            + "\n TRACKING #  TYPE   SPECIFICATION   CLASS   WEIGHT   VOLUME\n"
                            + "example:\nGFR23 Box Books Retail 9500.00 45\n");
                    String inTemp = in.nextLine();

                    String temp[] = inTemp.split(" ");

                    if (temp.length != 6) {
                        System.out.println("Not correct number of fields to process.");
                        break;
                    }

                    shippingstore.addOrder(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
                    break;
                case '3':
                    shippingstore.showPackageOrders();

                    System.out.println("\nPlease enter the tracking # of the package order to delete from the database.\n");
                    String orderToDelete = in.nextLine();
                    shippingstore.removeOrder(orderToDelete);
                    break;
                case '4':
                    System.out.println("\nEnter the Tracking # of the order you wish to see.\n");
                    String trackingNum = in.next();
                    in.nextLine();
                    shippingstore.searchPackageOrder(trackingNum);
                    break;
                case '5':
                    float high = 0;
                    float low = 0;
                    
                    System.out.println("\nEnter lower-bound weight.\n");
                    low = in.nextFloat();
                    System.out.println("\nEnter upper-bound weight.\n");
                    high = in.nextFloat();
                    in.nextLine();
                    
                    shippingstore.showPackageOrdersRange(low, high);
                    break;
                case 'h':
                    System.out.println(welcomeMessage);
                    break;
                default:
                    System.out.println("That is not a recognized command. Please enter another command or 'h' to list the commands.");
                    break;

            }

            System.out.println("Please enter another command or 'h' to list the commands.\n");
            selection = in.next().charAt(0);

            in.nextLine();
        }

        in.close();
        
        // Before exiting the program, save the data from the main memory to the
        // data file.
        PrintWriter pw = new PrintWriter("PackageOrderDB.txt");
        shippingstore.flush(pw);
        
        System.out.println("Done!");

    }
}
