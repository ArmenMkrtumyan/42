<div id="header" align="center">
  <img src="https://media.giphy.com/media/ztl9x7JlhSlU4MWD6h/giphy.gif" width="200"/>
</div>

<h1 align="center">Project 1 - libft</h1>

> 42 school Yerevan project

This repository contains all archives for the project __libft__ in the __42 school Yerevan__. It's a custom-made library of useful functions in __C language__. The repository includes the `Makefile` and the `libft.h` library.

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
</h2>

## About

This project is a __C library__ of valuable functions that are allowed to be used in future __School 42 cursus__ projects. Access to this library will make the coding process in incoming projects more effective. The aim of rewriting these functions is to get a better understanding of them and get a wide range of utilities for the next projects. [You can find more information in the subject](https://github.com/ArmenMkrtumyan/42/blob/master/libft/Libft%20-%20Subject(EN).pdf). As specified in the subject, all the archives are in the same folder.

## Index
### Functions from `<ctype.h>` library
* [`ft_isascii`](https://github.com/PublioElio/School-42-libft/blob/main/ft_isascii.c) - Test a character to see if it's a 7-bit ASCII character.
* [`ft_isalpha`](https://github.com/PublioElio/School-42-libft/blob/main/ft_isalpha.c) - Test a character to see if it's alphabetic.
* [`ft_isdigit`](https://github.com/PublioElio/School-42-libft/blob/main/ft_isdigit.c) - Test a character to see if it's a decimal digit.
* [`ft_isalnum`](https://github.com/PublioElio/School-42-libft/blob/main/ft_isalnum.c) - Test a character to see if it's alphanumeric.
* [`ft_isprint`](https://github.com/PublioElio/School-42-libft/blob/main/ft_isprint.c) - Test a character to see if it's any printable character, including a space.
* [`ft_tolower`](https://github.com/PublioElio/School-42-libft/blob/main/ft_tolower.c) - Convert a character to lowercase.
* [`ft_toupper`](https://github.com/PublioElio/School-42-libft/blob/main/ft_toupper.c) - Convert a character to uppercase.

### Functions from `<stdlib.h>` library
* [`ft_atoi`](https://github.com/PublioElio/School-42-libft/blob/main/ft_atoi.c) - Convert ASCII string to integer.
* [`ft_calloc`](https://github.com/PublioElio/School-42-libft/blob/main/ft_calloc.c) - Allocate space for an array and initializes it to 0. This function and `malloc` return a void pointer, that had no associated data type with it. A void pointer can hold an address of any type and can be typecasted to any type.

### Functions from `<strings.h>` library
* [`ft_bzero`](https://github.com/PublioElio/School-42-libft/blob/main/ft_bzero.c) - Set the first part of an object to null bytes (filling it with zeroes).
* [`ft_memset`](https://github.com/PublioElio/School-42-libft/blob/main/ft_memset.c) - Set memory to a given value.
* [`ft_memchr`](https://github.com/PublioElio/School-42-libft/blob/main/ft_memchr.c) - Find the first occurrence of a character in a buffer (locate byte in byte string).
* [`ft_memcmp`](https://github.com/PublioElio/School-42-libft/blob/main/ft_memcmp.c) - Compare the bytes in two buffers.
* [`ft_memmove`](https://github.com/PublioElio/School-42-libft/blob/main/ft_memmove.c) - Copy bytes from one buffer to another, handling overlapping memory correctly.
* [`ft_memcpy`](https://github.com/PublioElio/School-42-libft/blob/main/ft_memcpy.c) - Copy bytes from one buffer to another.

### Functions from `<string.h>` library
* [`ft_strlen`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strlen.c) - Get the length of a string.
* [`ft_strchr`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strchr.c) - Find the first occurrence of a character in a string.
* [`ft_strrchr`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strrchr.c) - Find the last occurrence of a character in a string.
* [`ft_strnstr`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strnstr.c) - Locate a substring in a string.
* [`ft_strncmp`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strncmp.c) - Compare two strings, up to a given length.
* [`ft_strdup`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strdup.c) - Create a duplicate of a string, using `malloc`.
* [`ft_strlcpy`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strlcpy.c) - Size-bounded string copy.
* [`ft_strlcat`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strlcat.c) - Size-bounded string concatenation.

### Non-standard functions
* [`ft_itoa`](https://github.com/PublioElio/School-42-libft/blob/main/ft_itoa.c) - Convert integer to ASCII string.
* [`ft_substr`](https://github.com/PublioElio/School-42-libft/blob/main/ft_substr.c) - Get a substring from string.
* [`ft_strtrim`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strtrim.c) - Trim beginning and end of string with the specified substring.
* [`ft_strjoin`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strjoin.c) - Concatenate two strings into a new string, using `calloc`.
* [`ft_split`](https://github.com/PublioElio/School-42-libft/blob/main/ft_split.c) - Split string, with specified character as a delimiter, into an array of strings.
* [`ft_strmapi`](https://github.com/PublioElio/School-42-libft/blob/main/ft_strmapi.c) - Create new string from a string modified with a specified function.
* [`ft_striteri`](https://github.com/PublioElio/School-42-libft/blob/main/ft_striteri.c) - Modify a string with a given function.
* [`ft_putchar_fd`](https://github.com/PublioElio/School-42-libft/blob/main/ft_putchar_fd.c) - Output a character to given file.
* [`ft_putstr_fd`](https://github.com/PublioElio/School-42-libft/blob/main/ft_putstr_fd.c) - Output string to given file.
* [`ft_putendl_fd`](https://github.com/PublioElio/School-42-libft/blob/main/ft_putendl_fd.c) - Output string to given file with a newline.
* [`ft_putnbr_fd`](https://github.com/PublioElio/School-42-libft/blob/main/ft_putnbr_fd.c) - Output integer to given file.

### Linked list functions *(bonus)*
* [`ft_lstnew`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstnew_bonus.c) - Create new list.
* [`ft_lstsize`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstsize_bonus.c) - Count elements of a list.
* [`ft_lstlast`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstlast_bonus.c) - Find last element of list.
* [`ft_lstadd_back`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstadd_back_bonus.c) - Add new element at end of a list.
* [`ft_lstadd_front`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstadd_front_bonus.c) - Add new element at beginning of the list.
* [`ft_lstdelone`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstdelone_bonus.c) - Delete element from list.
* [`ft_lstclear`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstclear_bonus.c) - Delete a sequence of elements of the list from a starting point.
* [`ft_lstiter`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstiter_bonus.c) - Apply function to the content of all list's elements.
* [`ft_lstmap`](https://github.com/PublioElio/School-42-libft/blob/main/ft_lstmap_bonus.c) - Apply function to the content of all list's elements into a new list.

## Requirements
The library is written in __C language__ and needs the `gcc` compiler, with `<stdlib.h>` and `<unistd.h>` standard libraries to run.

<div id="header" align="center">
  <img src="https://s4.gifyu.com/images/back_slash_green.gif" height="180"/>
  <img src="https://s4.gifyu.com/images/n_gif.gif" width="180"/>
</div>
 

<h1 align="center">Project 2 - get_next_line()</h1>

This is the repository for the 42 School Yerevan.

## About
The goal of this project is to create the function `get_next_line.c` which, when called in a loop, will read one line at a time in the __file descriptor__, until the end of the file. As stated in the subject, the program must compile with the `flag-D BUFFER_SIZE=` which will be used as the buffer size for the `read` calls in `get_next_line()`. You can find more details in [the subject of the project](https://github.com/ArmenMkrtumyan/42/blob/master/get_next_line/01_get_next_line_en.pdf).

This project is a introduction of __static variables__, which will be very useful for future projects. Also, as noted earlier, we'll learn how handle macros during compilation.

<div id="header" align="center">
  <img src="https://media.giphy.com/media/QXJd9XVrgJuDFhhcOX/giphy.gif" width="200"/>
</div>

<h1 align="center">Project 3 - printf()</h1>

This repository contains all files for the __printf__ project from School 42 Málaga cursus. The project consist in duplicate the [`printf()`](https://es.wikipedia.org/wiki/Printf) function, part of the `stdio.h` library.

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
</h2>

## About
This project consists in duplicate the behavior of the C function `printf()`. It is not necessary to implement the buffer management of the original function. It must handle the following parameters:

- `char` type variables.
- `string` type variables.
- `int` type variables.
- `unsigned int` type variables.
- hexadecimal `int` type variables (uppercase and lowercase).
- `pointer` type variables.

You will find more details in the [subject of the project](https://github.com/PublioElio/School-42-printf/blob/main/printf.es.subject.pdf).

## Index
- [Structure](#structure)
- [Formats](#formats)
	- [va_list](#va_list)
	- [Returning an integer](#returning-an-integer)
- [Auxiliary functions](#auxiliary-functions)

### Structure
The main obstacles during the execution of the project have been: handling a variable number of parameters and the function `ft_printf()` returning an `int`.

#### `va_list`
To deal with the variable number of parameters entered, the macros `va_list`, `va_start`, `va_arg` and `va_end` have been used. The `ft_printf()` function calls the `ft_fotmat()` function when it finds the `%` sign among the entered parameters, then it checks the next character in the string to call one of the functions that print the different variable types. To use this macro, the libraryt `<stdarg.h>` is included in the `ft_printf.h`.

#### Returning an integer
To handle the integer returned by `ft_printf()`, a pointer is given in the format printing functions. In this way, the function handles the number of characters printed before continuing with the string sent by parameter. Example:

```
void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++; // increasing the pointer with each character printed
}
```
### Formats
The different types of variables are printed using a function for each of the formats:

* [__`ft_putchar_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_putchar_pf.c) prints `char` type variables and is called by each of the following functions to print the character strings one by one. Also, it is where the pointer returned by the `ft_printf()` function is incremented.
* [__`ft_puthex_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_puthex_pf.c) prints hexadecimal integers,  using a string included in the `ft_printf.h` library. There is one string for uppercase and one for lowercase characters.
* [__`ft_putnbr_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_putnbr_pf.c) recursively prints an integer, handling the maximum negative value with a conditional (`if-else`) and casting the integer to characters.
* [__`ft_putptr_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_putptr_pf.c) prints a pointer, in hexadecimal format (lowercase), preceded by the string "0x".
* [__`ft_putstr_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_putstr_pf.c) prints a `char *` type variable, calling `ft_putchar_pf()` in a `while` loop. It the string is `NULL`, it returns `"(null)"`.
* [__`ft_putuint_pf()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_putuint_pf.c) prints an `unsigned int` type variable.

### Auxiliary functions
[__`ft_aux_pf.c()`__](https://github.com/PublioElio/School-42-printf/blob/main/ft_aux_pf.c) this file contains all the auxiliary functions, specifically the `ft_atoi_base` function, [made during the August pool](https://github.com/PublioElio/School42-Piscina-agosto-2022). This function will be used mainly to change the base in functions that handle hexadecimal numbers and `unsigned int` type variables.

## Requirements
The functions are written in __C language__ and need the `gcc` compiler, with `<stdlib.h>`, `<stdarg.h>` and `<unistd.h>` standard libraries to run.

## Instructions

### 1. Compiling the archives

To compile the project, go to its path and run:

For __mandatory__ functions:
```
$ make
```
### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```
$ make fclean
```

### 3. Using it in your code

To use this project in your code, simply include this header:
```
#include "ft_printf.h"
```

## Testing
This function have been tested with [Francinette](https://github.com/xicodomingues/francinette).
