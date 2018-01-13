//Problem 1 on Project Euler
//Multiples of 3 and 5
//1/13/2018

package main
import "fmt"

func main(){
	sum := 0

	for a := 1; a < 1000; a++ {
		if (a % 3 == 0) || (a % 5 == 0){
			sum += a
			}
	}

	fmt.Println(sum);
}
