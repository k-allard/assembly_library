# Assembly library

## Usage

1. Type ``make test`` command in the root directory of this project (_this will build the library, create a text file for test purposes, compile the library with main and launch ./a.out_)
2. You will see the output of tests immediately

## What is inside?

:white_check_mark: Re-implementation of following functions:

* ``strlen``
* ``strcpy``
* ``strcmp``
* ``write``
* ``read``
* ``strdup``

:white_check_mark: ``main`` that can be compiled with the library to test all the functions

:white_check_mark: errors during syscalls are handled and the variable errno is set properly (with extern ___error)
