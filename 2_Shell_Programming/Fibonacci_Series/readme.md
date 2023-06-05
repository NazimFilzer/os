# Fibonacci Sequence Generator

This shell script generates the Fibonacci sequence up to a given number.

## Usage

1. Open a terminal or command prompt.
2. Navigate to the directory where the script is located.
3. Run the following command to execute the script:

   ```bash
   bash fibonacci.sh
   ```

4. Enter a number when prompted by the script.

5. The script will generate and display the Fibonacci sequence up to the entered number.


## How It Works

1. The script prompts the user to enter a number.
2. The entered number is stored in the `n` variable.
3. The script initializes variables `a` and `b` as 0 and 1, respectively.
4. It prints the initial values of `a` and `b`.
5. The script enters a loop from 2 to the entered number.
   - In each iteration, it calculates the next number in the Fibonacci sequence by adding the previous two numbers (`a` and `b`).
   - It stores the sum in the `c` variable and prints it.
   - It updates `a` with the value of `b` and `b` with the value of `c`.
6. Finally, the script completes the loop and ends.
