# Credit.c

Credit card numbers have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. 

The secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. 
**Using *Luhn's algorithm*, this programme determines whether a credit card is syntactically valid.**

This programme prompts the user for a credit card number and then reports whether it is a valid American Express, Mastercard or Visa card number.

Here is how the program will behave for an invalid number:
<img src="https://github.com/YingXie24/images/blob/master/C-1c-CreditCard-TranspositionDetection/invalid.PNG" width=80% >

Here is how the program will behave for a valid number:
<img src="https://github.com/YingXie24/images/blob/master/C-1c-CreditCard-TranspositionDetection/validvisa.PNG" width=80% >
