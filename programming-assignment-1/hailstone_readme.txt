CSCI 103 Programming Assignment 1, Hailstone

Name: Jianing

Email Address: wujianin@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: Online resourses

================================ Questions ==================================

1. I used a while loop because we have to keep doing the operations 
until the number becomes 0;

2a. 
  input range  | minimum length | achieved by | maximum length | achieved by
-----------------------------------------------------------------------------
    50 100     |       6        |     64      |      118       |     97      
   100 200     |       7        |     128     |      124       |     171        
   200 400     |       8        |     256     |      143       |     327        

2b. They are all powers of 2. This is because powers of 2 only need the 
(divide by 2) operation, which makes them always decrease in value, while other
numbers have to multiply by 3 and add 1 at some point.

3a. X is : 703

3b. By 2a we know that the maximum length in the 200-400 range is 143, which
is less than 150. Therefore, I first tried the range 400-1000, which gave
me the maximum length 178 achieved by 871. Then I inputted 400-800 to 
narrow down the range; this gave me the maximum length 170 achiby 703.
Lastly I checked 400-702 which resulted in a maximu range 144 less than 150.
Hence, we have made sure 703 is the X.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

: