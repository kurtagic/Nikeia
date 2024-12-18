# NIKEIA V0.0.1

## 1. BASIC SHIT INFO
retarded programing language by yours truly

very reduced instruction set:
`x`...int

`PRINT/_LINE` takes a string only, put it in "" or shit doesnt work

`READ` only reads an int so dont do dumb shit

`HALT`...put at the end of program so my poor guy knows when its done


use `//` for comments, comments go in their own line

when you label shit make it like `label:` and in their own line

files end with `.nka`

### 1.1 (VERY) REDUCED INTRUCTION SET

| INSTRUCTION                     | DESCRIPTION                                                                                       | 
|---------------------------------|---------------------------------------------------------------------------------------------------|
| PUSH x                          | push x to the stack                                                                               |
| POP                             | pop from stack                                                                                    |
| ADD                             | adds last 2 numbers on stack, puts result on stack                                                |
| SUB                             | subtracks the second last number on the stack from the last number on stack, puts result on stack |
| GOTO label                      | unconditional jump to label                                                                       |
| JUMP_EQL_0 label                | if number on stack is equal to 0, jump to label                                                   |
| JUMP_GRT_0 label                | if number on stack is greater than 0, jump to label                                               |
| PRINT "text_in_snake_case"      | prints string to stdio, 1 word only                                                               |
| PRINT_LINE "text_in_snake_case" | prints string + newline to stdio, 1 word only                                                     |
| READ                            | reads from stdio (int only)                                                                       |
| HALT                            | end of program, put at the end or shit doesnt work                                                |

## 1.2 RUNNING THE PROGRAM
1. compile the shit with `make`
2. usage: `./delphi file.nka`
3. hope shit works
4. profit!

## 2. EXAMPLE PROGRAM
### `even_or_odd.nka`
```
// this solution is absolutely terrible
// it scales with the absolute value of the number (bigger numbers take longer)
// O(n)

// get the input from standard i/o (int)
PRINT "number:_"
READ

// we need to deal with 3 possible scenarios (0, positive number or negative number)
JUMP_EQL_0 even
JUMP_GRT_0 loop_positive
GOTO loop_negative

// we loop until the number is 0 or less than 0.
// since we substract by 2, if the result is 0 we know the original was even,
// and if it's -1 we know it's odd.
loop_positive:
PUSH 2
SUB
JUMP_EQL_0 even
JUMP_GRT_0 loop_positive
GOTO odd

// we loop until the number is 0 or more than 0.
// since we add by 2, if the result is 0 we know the original was even,
// and if it's 1 we know it's odd.
loop_negative:
PUSH 2
ADD
JUMP_EQL_0 even
JUMP_GRT_0 odd
GOTO loop_negative

even:
PRINT_LINE "even"
HALT

odd:
PRINT_LINE "odd"
HALT
```
