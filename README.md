# Infix to Prefix Calculator

A C++ program that converts infix expressions to prefix notation and calculates the result.

## Overview

This calculator application allows users to:
1. Enter infix expressions
2. Convert infix expressions to prefix notation
3. Calculate the result of arithmetic operations

The program implements data structures (stack and queue) to efficiently handle the conversion and calculation processes.

## Features

- Supports the following operators:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Exponentiation (^)
  - Modulo (%)
- Input validation to ensure valid infix expressions
- User-friendly menu interface
- Decimal precision (results displayed with 2 decimal places)

## Implementation Details

The program is built using the following components:

### Data Structures
- **Stack**: Two stack implementations:
  - `StackChar`: Used for storing operators during conversion
  - `StackInt`: Used for storing numeric values during calculation
- **Queue**: Used for temporary storage during the conversion process

### Key Functions
- `infixToPrefix()`: Converts infix expressions to prefix notation
- `calculatePrefix()`: Evaluates prefix expressions to produce the final result
- `isOperator()`: Checks if a character is an operator
- `precedence()`: Determines the precedence of operators for correct order of operations

### Algorithm

The infix to prefix conversion follows these steps:
1. Reverse the infix expression
2. Process each character from right to left:
   - If operand, add to queue
   - If operator, handle according to precedence rules
   - Handle parentheses appropriately
3. After processing, pop remaining operators from stack to queue
4. Dequeue elements and form the prefix expression

The prefix calculation algorithm:
1. Process the prefix expression from right to left
2. Push operands onto the stack
3. When an operator is encountered, pop two operands and apply the operation
4. Push the result back onto the stack
5. Continue until the expression is fully processed
6. The final value in the stack is the result

## Usage

1. Run the program
2. Select an option from the menu:
   - Option 1: Enter an infix expression
   - Option 2: View the converted prefix expression
   - Option 3: Calculate and display the result
   - Option 0: Exit the program
3. Follow the prompts to enter expressions and navigate through the application

## Example

Input (infix): `5+4*2`
Converted to prefix: `+ 5 * 4 2`
Result: `13.00`

## Authors

- Fadhillah Maulana - 1303210039
- Irfan Zharauri Nanda Sudiyanto - 1303210006

## Development Environment

- CodeBlocks IDE
- GCC Compiler
- C++ Standard Libraries
