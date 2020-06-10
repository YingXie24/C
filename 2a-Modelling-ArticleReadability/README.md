# Readability.c

A human expert might read a book and make a decision on the grade for which they think the book is most appropriate. 
The characteristic of higher reading levels are longer words and longer sentences. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is design to output what a (US) grade level is needed to understand the text. 
The formula is:

*index = 0.0588 * L - 0.296 * S - 15.8*

where *L* is the  average number of letters per 100 words in the text, and *S* is the average number of sentences per 100 words in the text.

**The readability.c programme takes a text and determines its reading level.** 
For example, if user types in a line from Dr Seuss:

The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words. And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words. Plugged into the Coleman-Liau formula, and rounded to the nearest whole number, we get an answer of 3: so this passage is at a third grade reading level.
