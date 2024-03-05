[codeforces.com/contest/1938/problem/G](https://codeforces.com/contest/1938/problem/G)

this problem has a very different range of value of k,which enlighten us that maybe this is the key of problem?

let's think of brute,for a line i, if we need to find the suitable j that fulfill j<i so for the $s_{i,f}$ we need to find the same character that $s_{q,f}$ ,and than the same degree of q and i update 1, and than we do this action all the time to find a qualified one, and we must know that each time we update 1 and the largest sum of value that we add is (k-1)*(i-1)+1 because in this time there must appear one that has the same degree of k,so we just need to special judge to the value of k,and the time complexity is $O(kn^2)$ 
