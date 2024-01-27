# get_next_line
get_next_line function helps to read a file using the file descriptor (fd) in the buff, at the maximium size of buffer_size line by line. Putting consideration for the end of a line ('\0) where a value of 0 is return and for the case of a new line , with a helper function in the program the lines are the first line is obtained a checked with the same condition then passed until the end of a file is completed then function stops returning a value.

NB: file descrriptor (fd) is an interger that the compiler uses to indentify the file in the process
functions used are as follows;
read, malloc
besides that i created utils files to operate with.
