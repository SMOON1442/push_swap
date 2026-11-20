# Push Swap

## Compilation & Commands

To compile the project, run:

    make

To clean up object files:

    make clean

To remove object files and the executable:

    make fclean

To recompile everything from scratch:

    make re

## Testing

To test the program, run `push_swap` and pipe its output to `checker_linux`:

    ./push_swap [--algo] [your_array_of_ints] | ./checker_linux [same_array_of_ints]

Example:

    ./push_swap --simple 4 67 3 87 23 | ./checker_linux 4 67 3 87 23

The checker should display `OK` if the sorting instructions are correct, or `KO` if they are not.

## Contributing

If you want to contribute to this project, please follow these guidelines:

1. **Makefile:** Don't forget to add any new files you create to the `Makefile`.

2. **Document your changes:** If you modify an existing file, add a comment after each modification explaining what you changed.

   Example:

       // Modified: Updated the sorting logic to handle smaller arrays.

3. **Peer review:** Before pushing your changes, make sure to review the changes with a peer.

## Final Note

Keep the code clean, document your changes, and make sure everything works before pushing!
