# CS50x

Repo for my "CS50's Introduction to Computer Science" course (on edx.org) solutions.

## Week 0
Implement any project of your choice in <a href="https://scratch.mit.edu/">Scratch</a>, be it an interactive story, game, animation, or anything else, subject only to the following requirements:

Specifications:
- Your project must have at least two sprites, at least one of which must resemble something other than a cat.
- Your project must have at least three scripts total (i.e., not necessarily three per sprite).
- Your project must use at least one condition, one loop, and one variable.
- Your project must use at least one sound.
- Your project should be more complex than most of those demonstrated in lecture (many of which, though instructive, were quite short) but it can be less complex than Ivy’s Hardest Game. As such, your project should probably use a few dozen puzzle pieces overall.

I've created a little game where you have to dodge Covid virus parts dropped by a bat. The red ones kill you right away. The white ones make you sick (and slower) and eventually will kill you too. You have to collect enough antibodies (the green parts) to gain resistance and win the game.
It took me way too much time to create this. I met the requirements very quickly, but I got addicted to my own game and wanted to add more and more features everytime :') .

Anyway, you can find the game here: https://scratch.mit.edu/projects/414254819/ .


The bat sprite, backdrop and sound effects are from <a href="https://scratch.mit.edu/">Scratch</a>. I've created the health and resistance bars myself (in Powerpoint LOL).
and grabbed the other stuff from internet:
- Covid image: https://image.freepik.com/free-vector/covid-19-coronavirus-virus-bacteria-outlined-icon-illustration_148087-193.jpg (edited by me)
- Boy character: https://www.gameart2d.com/the-boy---free-sprites.html
- Music: https://soundimage.org/looping-music/
- Game over sprite: https://www.pngkey.com/detail/u2w7r5o0o0e6i1y3_by-glen-chiacchieri-may-png-game-over-sprite/

## Week 1

- hello.c: "Modify this program in such a way that it first prompts the user for their name and then prints hello, so-and-so, where so-and-so is their actual name."
- mario.c: "The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive."
- credit.c: "Write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein." This program implements 'Luhn’s Algorithm', checks for the cardnumber length and the required first / second digits.

Credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

Checksum: 
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


