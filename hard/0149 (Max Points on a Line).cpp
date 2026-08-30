#include <iostream>
#include <cmath>
#include <map>

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        sort (points.begin(), points.end());

        int verticalBest = 1;
        int counter = 1;

        for (int i = 1; i < points.size(); i++) {
            if (points.at(i).at(0) == points.at(i - 1).at(0)) {
                counter++;
                verticalBest = max(verticalBest, counter);
            }
            else {
                counter = 1;
            }
        }

        int nonVerticalBest = 0;

        for (int i = 0; i < points.size(); i++) {
            map <double, int> slopes = {};

            for (int j = i + 1; j < points.size(); j++) {
                if (points.at(i).at(0) == points.at(j).at(0)) {
                    continue;
                }

                double curSlope = (double)((points.at(j).at(1) - points.at(i).at(1))) / (double)((points.at(j).at(0) - points.at(i).at(0)));

                if (!slopes.contains((curSlope))) {
                    slopes[(curSlope)] = 2;
                    nonVerticalBest = max(nonVerticalBest, slopes[(curSlope)]);
                    continue;
                }

                slopes[(curSlope)] = slopes[(curSlope)] + 1;
                nonVerticalBest = max(nonVerticalBest, slopes[(curSlope)]);
            }
        }

        return (max(verticalBest, nonVerticalBest));
    }
};