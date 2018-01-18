/*
 * Shipping Store Management Software v0.1
 * Developed for CS3354: Object Oriented Design and Programming.
 * Copyright: Junye Wen (j_w236@txstate.edu)
 */
package shippingstore;

/**
 * Custom Exception type, used to report bad input from user.
 * @author Junye Wen
 */
public class BadInputException extends Exception {

    /**
     * Constructor, allows custom message assignment for thrown exception.
     * @param message custom message assignment
     */
    public BadInputException(String message) {
        super(message);
    }
}