<div id="header" align="center">
  <img src="https://media.giphy.com/media/ztl9x7JlhSlU4MWD6h/giphy.gif" width="200"/>
</div>

<h1 align="center">Project 1 - libft</h1>

> 42 school Yerevan project

This is a custom-made library of useful functions in __C language__. The repository includes the `Makefile` and the `libft.h` header.

<h2 align="center">
	<a href="#about_libft">About</a>
	<span> · </span>
	<a href="#index_libft">Index</a>
	<span> · </span>
	<a href="#requirements_libft">Requirements</a>
</h2>

## About_libft

This project is a __C library__ of valuable functions that are allowed to be used in future __42 school cursus__ projects. Access to this library will make the coding process for upcoming projects more effective. The aim of rewriting these functions is to get a better understanding of them and explore C language in its core. [You can find more information in the subject](https://github.com/ArmenMkrtumyan/42/blob/master/ft_printf/ft_printf_subject.pdf). As specified in the subject, all the archives are in the same folder.

## Index_libft
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

## Requirements_libft
The library is written in __C language__ and needs the `gcc` compiler, with `<stdlib.h>` and `<unistd.h>` standard libraries to run.

<div id="header" align="center">
  <img src="https://s4.gifyu.com/images/back_slash_green.gif" height="180"/>
  <img src="https://s4.gifyu.com/images/n_gif.gif" width="180"/>
</div>
 

<h1 align="center">Project 2 - get_next_line()</h1>

> 42 school Yerevan project

## About
The goal of this project is to create the function `get_next_line.c` which, when called in a loop, will read one line at a time in the __file descriptor__, until the end of the file. As stated in the subject, the program must compile with the `flag-D BUFFER_SIZE=` which will be used as the buffer size for the `read` calls in `get_next_line()`. You can find more details in [the subject of the project](https://github.com/ArmenMkrtumyan/42/blob/master/get_next_line/get_next_line_subject.pdf).

This project is an introduction to __static variables__, which will be very useful for future projects. Also, as noted earlier, we'll learn how to handle macros during compilation.

<div id="header" align="center">
  <img src="https://media.giphy.com/media/QXJd9XVrgJuDFhhcOX/giphy.gif" width="200"/>
</div>

<h1 align="center">Project 3 - ft_printf()</h1>

> 42 school Yerevan project

<h2 align="center">
	<a href="#about_printf">About</a>
	<span> · </span>
	<a href="#requirements_printf">Requirements</a>
	<span> · </span>
	<a href="#instructions_printf">Instructions</a>
</h2>

## About_printf
This repository contains all files for the __ft_printf__ project. The aim of the project is to duplicate the behavior of [`printf()`](https://es.wikipedia.org/wiki/Printf) function, part of the `stdio.h` library.
__ft_printf__ must handle the following parameters:

- `char` type variables.
- `string` type variables.
- `int` type variables.
- `unsigned int` type variables.
- hexadecimal `int` type variables (uppercase and lowercase).
- `pointer` type variables.

You can find more details in the [subject of the project](https://github.com/ArmenMkrtumyan/42/blob/master/ft_printf/ft_printf_subject.pdf).

## Requirements_printf
The functions are written in __C language__ and need the `gcc` compiler, with `<stdlib.h>`, `<stdarg.h>` and `<unistd.h>` standard libraries to run.

## Instructions_printf

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
