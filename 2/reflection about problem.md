https://ac.nowcoder.com/acm/contest/67745/K

for this problem,we must cost P for the first people

and now we think about if we need cost P again during costing a_i to wake up b_i people?

because b_i always bigger than 0 ,so if we have a used list of a_i like:

$i_1,i_2,i_3...$ it must be true that we don't need to use P again

so we can  use the n people to do dp to calculate if we don't use P,which $dp_i$ is the cost of notifying i people

and last we enumerate how many people we use P

 
