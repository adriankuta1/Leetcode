#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*

void minTimeToVisitAllPoints(vector<vector<int>>& points) {

        //First I want a function that checks if the current point's x or y value matches the
        //target x or y value - that is, the x or y values of the next element in point[]

        int totalTime = 0;
        int currentX = points[0][0];
        int currentY = points[0][1];

        for(int i = 0; i < points.size(); i++){
            cout << "i = " << i << endl;
        }

        for(int i = 0; i < points.size()-1; i++){

            //while we aren't on the right X or Y level (i.e. can move diagonally)
            //which we prefer since it is more efficient
            while((currentX != points[i+1][0]) && (currentY != points[i+1][1])){

                //we need to divide into 4 quadrants to see which diagonal to follow

                //if left of next X
                if(currentX < points[i+1][0]){

                    //and below next Y
                    if(currentY < points[i+1][1]){

                        //then move up and to the right
                        currentX ++;
                        currentY ++;
                        totalTime ++;

                    }

                    //but if above next Y
                    if(currentY > points[i+1][1]){

                        //then move down and to the right
                        currentX ++;
                        currentY --;
                        totalTime ++;
                    }

                }

                //if right of next X
                if(currentX > points[i+1][0]){

                    //and below next Y
                    if(currentY < points[i+1][1]){

                        //then move up and to the left
                        currentX --;
                        currentY ++;
                        totalTime++;

                    }

                    //but if above next Y
                    if(currentY > points[i+1][1]){

                        //then move down and to the left
                        currentX --;
                        currentY --;
                        totalTime ++;
                    }

                }

            }

            //if X is already correct
            if(currentX == points[i+1][0]){

                //if current Y position is too low, move up, count each step
                while(currentY < points[i+1][1]){

                    currentY ++;
                    totalTime ++;

                }

                //if current Y is too high, move down, count each step
                while(currentY > points[i+1][1]){

                    currentY --;
                    totalTime ++;

                }

            }

            //if Y is already correct
            if(currentY == points[i+1][1]){

                //if current X position is too left, move right, count each step
                while(currentX < points[i+1][0]){

                    currentX ++;
                    totalTime ++;

                }

                //if current X is too right, move left, count each step
                while(currentX > points[i+1][0]){

                    currentX --;
                    totalTime ++;

                }

            }




        }

        cout << "total time = " << totalTime << endl;

    }

int main(){

    vector<vector<int>> points = {

        {4,7},
        {5,8},
        {5,6},
        {7,3},
        {11,5}

    };

    minTimeToVisitAllPoints(points);


}

*/

int betterMinTimeFunction(vector<vector<int>> points){

    int diffX = 0;
    int diffY = 0;
    int diffDiag = 0;
    int diffStraight = 0;
    int totalTime = 0;

    for(int i = 0; i < points.size()-1; i++){

        diffX += abs(points[i][0] - points[i+1][0]);
        diffY += abs(points[i][1] - points[i+1][1]);

        diffDiag = min(diffX,diffY);

        diffStraight = max(diffX,diffY) - diffDiag;

        totalTime = diffDiag + diffStraight;

    }


    return totalTime;

}

int main(){

    vector<vector<int>> points = {

        {1,1},
        {3,4},
        {-1,0}

    };

    cout << "Min time visiting all points = " << betterMinTimeFunction(points) << endl;

}