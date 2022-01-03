/* 
Problem : Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and 
the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the 
extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.

https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
*/

Approach :
Focus on the part where they do not overlap each other.There are 2 conditions :
1) One rectangle is above top edge of other rectangle. 
2) One rectangle is on left side of left edge of other rectangle.

Solution :
int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        
        //when one rectangle is on the left side left edge of the other rectangle
        if(L2[0]>R1[0] || L1[0]>R2[0])
        return 0;
        
        //when one rectangle is above top edge of other rectangle
        else if(R1[1]>L2[1] || R2[1]>L1[1])
        return 0;
        
        //else they overlap each other in some way or the other
        else
        return 1;
    }

Time Complexity : O(1)
        
Space Complexity : O(1)        
