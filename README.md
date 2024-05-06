# Simple-Pascal

Simple PASCAL is a simplified version of the PASCAL programming language. It supports the following features:

## Keywords
The language has several keywords, such as `program`, `integer`, `real`, `boolean`, `char`, `var`, `to`, `downto`, `if`, `else`, `while`, `for`, `do`, `array`, `and`, `or`, `not`, `begin`, `end`, `read`, and `write`. The keywords are not case-sensitive.

## Variables and Identifiers
Variable names can be composed of letters, digits, and underscores, but must start with a letter. Variable names are not case-sensitive. All variables must be declared before use, using the `var` keyword followed by a type (`char`, `integer`, `real`, or `boolean`).

## Operators
The language supports arithmetic operators (`+`, `-`, `*`, `/`, `%`), relational operators (`=`, `<>`, `<`, `>`, `<=`, `>=`), and boolean operators (`and`, `or`, `not`).

## Statements
Basic PASCAL supports various statements, including:
- Read and write statements (`read` and `write`)
- Assignment statements (`variable_name := expression`)
- Blocks of statements (`begin ... end`)
- Conditional statements (`if-then`, `if-then-else`)
- Looping statements (`while-do`, `for-do`)

## Program Structure
A Basic PASCAL program starts with the `program` keyword followed by the program name. It then has a variable declaration section and a main program block enclosed between `begin` and `end`.

## Arrays
The language supports one-dimensional arrays with static declaration.

# Tasks Completed

## Task 1: Lexical Analysis
A LEX program has been written to break down the input program into tokens (identifiers, operators, numbers, keywords, punctuators, etc.). The output lists the valid tokens in the format `line_number lexeme token_type`.

## Task 2: Syntax Analysis
A YACC program has been written to take the tokens generated from the lexical analysis phase and check if the input program is syntactically correct. A symbol table is created with the list of tokens obtained from the input. If the input program has any syntax errors, an error message is printed; otherwise, it prints "valid input".

## Task 3: Semantic Analysis
The YACC program from Task 2 has been extended to perform semantic analysis, including type checking, detecting undeclared variables, and detecting multiple declarations of variables. Appropriate error messages are printed for any detected semantic errors.

## Task 4: Code Generation
The YACC program from Task 3 has been extended to generate intermediate code in the form of three-address code.
