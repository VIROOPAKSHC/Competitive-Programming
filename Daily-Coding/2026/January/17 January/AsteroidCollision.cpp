/*
Tag: Stack, Array

Problem Statement:
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    st.push_back(asteroids[0]);
    int i=1;
    while(i<asteroids.size()){
        if(st.size()==0){
            st.push_back(asteroids[i]);
            i++;
            continue;
        }
        while(i<asteroids.size() && st.back()*asteroids[i] > 0){
            st.push_back(asteroids[i++]);
        }

        if(i>=asteroids.size()){
            return st;
        }
        
        if(st.back()<0 && asteroids[i]>0){st.push_back(asteroids[i++]); continue;}
        int prev=st.back();
        st.pop_back();
        if(abs(prev)>abs(asteroids[i])){
            st.push_back(prev);
            i++;
        }
        else if(abs(prev)==abs(asteroids[i])){
            i++;
        }
        else{
            continue;
        }
        
    }
    return st;
}

/*
My Approach:

- Take every asteroid into the array when their signs are the same
- If the asteroids have different signs but are going away from each other, add the next one
- If they are coming towards each other, look if the newly arriving one has a greater size, then it destroys the existing one and might continue its journey to earlier indices - so in that case, we do not add it until we check earlier elements as well
- If the newly arriving one has the same size, both of the new one and the top one get destroyed
- If it has a lesser size, the top one in the array stays

This is the best solution
*/