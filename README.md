# holbertonschool-printf
Implements a custom printf for C program completed as part of the low-level
programming and algorithm track at Holberton School. The program is a partial
recreation of the C standard library function, `printf`.

## [FLowchart](https://miro.com/app/board/uXjVNM638ws=/)



## Dependencies :couple:

The `_printf` function was coded on an Ubuntu 20.04 LTS machine with `gcc` version 10.2.1.

## Usage :running:

To use the `_printf` function, assuming the above dependencies have been installed,
compile all `.c` files in the repository and include the header `main.h` with
any main function.

Example `main.c`:
```
#include "main.h"

int main(void)
{
    _printf("Hello, World!");

    return (0);
}
```

Compilation:
```
$ gcc *.c -o tester
```

Output:
```
$ ./tester
Hello, World!
$
```

## Description :speech_balloon:

The function `_printf` writes output to standard output. The function writes
under the control of a `format` string that specifies how subsequent arguments
(accessed via the variable-length argument facilities of `stdarg`) are
converted for output.

Prototype: `int _printf(const char *format, ...);`

### Return Value

Upon successful return, `_printf` returns the number of characters printed
(excluding the terminating null byte used to end output to strings). If an
output error is encountered, the function returns `-1`.

### Format of the Argument String

The `format` string argument is a constant character string composed of zero
or more directives: ordinary characters (not `%`) which are copied unchanged
to the output stream; and conversion specifications, each of which results in
fetching zero or more subsequent arguments. Conversion specification is
introduced by the character `%` and ends with a conversion specifier.

#### Conversion Specifiers

The conversion specifier (introduced by the character `%`) is a character that
specifies the type of conversion to be applied. The `_printf` function
supports the following conversion specifiers:

#### d, i
The `int` argument is converted to signed decimal notation.

Example `main.c`:
```
int main(void)
{
    _printf("%d\n", 7);
}
```
Output:
```
7
```

#### c
The `int` argument is converted to an `unsigned char`.

Example `main.c`:
```
int main(void)
{
    _printf("%c\n", 'c');
}
```
Output:
```
c
```

#### s
The `const char *` argument is expected to be a pointer to a character array
(aka. pointer to a string). Characters from the array are written starting
from the first element of the array and ending at, but not including, the
terminating null byte (`\0`).

Example `main.c`:
```
int main(void)
{
    _printf("%s\n", "Hello, World!");
}
```
Output:
```
Hello, World!
```

#### %
A `%` is written. No argument is converted. The complete conversion
specification is `%%`.

Example:
```
int main(void)
{
    _printf("%%\n");
}
```
Output:
```
%
```

## More Examples :thumbsup:

To print the address of Holberton School in the format "972 Mission St., San
Francisco, CA 94103" where *street*, *city* and *state* are pointers to strings:

Example `main.c`:
```
#include "holberton.h"

int main(void)
{
	char *street = "Mission St.", *city = "San Francisco", *state = "CA";

	_printf("%d %s, %s, %s %d\n", 972, street, city, state, 94103);
}
```
Output:
```
972 Mission St., San Francisco, CA 94103
```

To print the result of basic mathematical operations prepended by signs and
all numbers printed with a minimum precision of two digits:

Example `main.c`:
```
#include "holberton.h"

int main(void)
{
	_printf("%.2d + %.2d = %+.2d\n", 1, 2, 1 + 2);
	_printf("%d - %d = %+d\n", 10, 20, 10 - 20);
}
```
Output:
```
01 + 02 = +03
10 - 20 = -10
```

## Authors :black_nib:

* Warren Markham <[WarrenTheRabbit](https://github.com/WarrenTheRabbit)>
* Tingru Liu <[tingru0515](https://github.com/tingru0515)>
* Echezona Oji <[zonafrank](https://github.com/zonafrank)>

## License :lock:

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Acknowledgements :pray:

The `_printf` function emulates functionality of the C standard library
function `printf`. This README borrows from the Linux man page
[printf(3)](https://linux.die.net/man/3/printf).

This program was written as part of the curriculum for Holberton School.
Holberton School is a campus-based full-stack software engineering program
that prepares students for careers in the tech industry using project-based
peer learning. For more information, visit [this link](https://www.holbertonschool.com/).

<p align="center">
  <img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>
