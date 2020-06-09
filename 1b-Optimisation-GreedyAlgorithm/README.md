# Cash.c

When making change, odds are you want to minimise the number of coins you're dispensing for each customer. 
For instance, if some customer is owed 41¢, the biggest first (i.e., best immediate, or local) biteThat i that can be taken is 25¢. (That bite is “best” inasmuch as it gets us closer to 0¢ faster than any other coin would.) Note that a bite of this size would whittle what was a 41¢ problem down to a 16¢ problem, since 41 - 25 = 16. That is, the remainder is a similar but smaller problem. Needless to say, another 25¢ bite would be too big (assuming the cashier prefers not to lose money), and so our greedy cashier would move on to a bite of size 10¢, leaving him or her with a 6¢ problem. At that point, greed calls for one 5¢ bite followed by one 1¢ bite, at which point the problem is solved. The customer receives one quarter, one dime, one nickel, and one penny: four coins in total.


**This programme solves the problem to decide which coins and how many of each to hand to the customer when making change, using the greedy algorithm.**

The programme first asks the user how much change is owed and prints the minimum number of coins with which that change can be made.
The programme behaves as per below: 

<img src="https://github.com/YingXie24/images/blob/master/C-1b-Optimisation-GreedyAlgorithm/GAWorks.PNG" width=80%>

While this programme is written with America's currency in mind, it also works for European Union's and Britain's currency.
So long as a cashier has enough of each coin, this largest-to-smallest approach will yield the fewest coins possible. 

<img src="https://github.com/YingXie24/images/blob/master/C-1b-Optimisation-GreedyAlgorithm/cash.PNG" width=30%>


