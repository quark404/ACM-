[G - Compress Strings (atcoder.jp)](https://atcoder.jp/contests/abc343/tasks/abc343_g)

in order to solve this problem,we need to know that every string will be followed by others string,so we should know if we connect j to the back of i how many characters we need to append, now we call it $mp_{i,j}$

this problem can solve by kmp algorithm,just like:

if we want to solve i and j,we create a new string s[j]+'#'+s[i] whose length is A, the ans is A-fail[A]

if you have learned KMP before,you will know why. 

what's more, if one string is be included by others, the $mp_{i,j}$=0

and than we use $dp_{i,j}$ to represent i status and the last string is j

so we need to enumerate all the left string to check which one can be attach next,to transform the status

 

 
