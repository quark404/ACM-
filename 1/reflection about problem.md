https://ac.nowcoder.com/acm/problem/265605

about this problem,we should konw that the scale of n is just less than 40

so we will think about the algorithm of meet in middle

In detail,we first solve the 1 to (n+1)/2 position：

we enumerate all the case,and for a fixed one:

we first calculate the 1 to (n+1)/2 position：

and now we need to use them to calculate the (n+1)/2+1-n

we can know that the length of (n+1)/2+1....n-1 is decide by the first (n+1)/2 position with

the right position:

just about 1 and n can decide the ans of length of n-1

1 and n-1,2 and n can decide the ans of length of n-2

so if we calculate for n to (n+1)/2+1,in each position i

the unknown i can decide by 1 and i (2 and i+1).....

and now we know about （2 and i+1）....

so the only one is 1 and i

but there still has some problem just about：

the value of first position will affect(impact,influence(n)) the ans

if the value of first position is 1 and ans=0 the i position can be 0/1

if the value of first position is 0 and the i position is ans

so can we decide the value of first position to 0?

if you note that if the value of first position is 1, it can not cause any ans to any length

so we can move the value to the last position, the ans of the different string is the same

so we can find that if there has an string that enable,the first of position must can be 0

then we can implement the problem

