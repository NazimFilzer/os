
# Prime Number Checker

This shell script allows the user to enter a number and checks whether it is a prime number or not.

## Usage

1. Open a terminal or command prompt.
2. Navigate to the directory where the script is located.
3. Run the following command to execute the script:

   ```bash
   bash prime.sh
   ```

4. Enter a number when prompted by the script.

5. The script will determine whether the entered number is prime or not and display the result.


## How It Works

1. The script prompts the user to enter a number.
2. The entered number is stored in the `number` variable.
3. The script initializes the `isPrime` variable as `true`.
4. It checks if the entered number is equal to 1. If it is, then `isPrime` is set to `false` because 1 is not a prime number.
5. The script enters a loop from 2 to half of the entered number.
   - It checks if the number is divisible by any value in that range. If it is, then `isPrime` is set to `false` and the loop breaks.
6. Finally, the script checks the value of `isPrime` and prints the appropriate message.


