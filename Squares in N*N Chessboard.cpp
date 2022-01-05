/*
Problem :
Find total number of Squares in a N*N cheesboard.

https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
*/

/*
Approach:
We can make an easy observation
When n = 1 (1 x 1 grid) we can have only 1 square = 1 square.

n = 2 (2 x 2 grid) we have, 4 small square of (1 x 1) + 1 square of (2 x 2) = 5 squares.

n = 3 (3 x 3 grid), we have, 9 squares of (1 x 1) + 4 squares of (2 x 2) + 1 square of (3 x 3) = 14 squares.

Thus we see a pattern here
Number of square of (n x n) grid
= n ^ 2 + (n - 1) ^ 2 + …. + 1

Which is sum of (k^2), where k goes from 1 to n. This turns out to be

n * (n + 1) * (2n + 1) / 6
*/

Solution :
long long squaresInChessBoard(long long N) {
        // code here
        return ((N)*(N+1)*(2*N +1))/6;
    }

Time Complexity : O(1)

Space Complexity : O(1)
