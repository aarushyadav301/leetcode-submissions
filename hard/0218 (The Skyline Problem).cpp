struct point {
    int xpos;
    int id;
    char oc;
    int height;

    point (int x, int i, char o, int h) {
        xpos = x;
        id = i;
        oc = o;
        height = h;
    }
};

struct comparePoints {
    bool operator()(const point &a, const point &b) const {
        if (a.xpos != b.xpos) {
            return (a.xpos < b.xpos);
        }

        if (a.oc != b.oc) {
            return (a.oc > b.oc);
        }

        if (a.height != b.height) {
            return (a.height > b.height);
        }

        return (a.id > b.id);
    }
};

struct setPoints {
    bool operator()(const point &a, const point &b) const {
        if (a.height != b.height) {
            return (a.height > b.height);
        }
        if (a.xpos != b.xpos) {
            return (a.xpos < b.xpos);
        }

        if (a.oc != b.oc) {
            return (a.oc > b.oc);
        }

        return (a.id > b.id);
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Create structs for each point (xpos, open, height)
        // Sort
        // Iterate through each point
        // Add point to a heap maintaining highest points
        // If height > curHeight -> Add new key point with (xpos, height)
        // Store the id of each block
        // If curTallest block ends and newHeight < curHeight -> Add new key point with (xpos, height)

        vector<point> buildingPoints;
        for (int i = 0; i < buildings.size(); i++) {
            buildingPoints.push_back(point(buildings[i][0], i, 'o', buildings[i][2]));
            buildingPoints.push_back(point(buildings[i][1], i, 'c', buildings[i][2]));
        }

        std::sort(buildingPoints.begin(), buildingPoints.end(), comparePoints());
        std::set<point, setPoints> runningHeights;
        int tallId = -1;
        int tallest = -1;

        vector<vector<int>> ans;

        int runningMax = -1;

        for (int i = 0; i < buildingPoints.size(); i++) {
            int sP = i;
            int x = buildingPoints[i].xpos;
            while (true) {
                if (sP == buildingPoints.size() || buildingPoints[sP].xpos != x) {
                    break;
                }

                if (buildingPoints[sP].oc == 'o') {
                    runningHeights.insert(point(buildingPoints[sP].xpos, buildingPoints[sP].id, 'o', buildingPoints[sP].height));
                }
                else {
                    runningHeights.erase(point(buildings[buildingPoints[sP].id][0], buildingPoints[sP].id, 'o', buildingPoints[sP].height));
                }

                sP++;
            }
            i = sP - 1;

            int maxHeight;

            if (runningHeights.size() == 0) {
                maxHeight = 0;
            }
            else {
                maxHeight = runningHeights.begin()->height;
            }

            if (maxHeight != runningMax) {
                runningMax = maxHeight;
                ans.push_back(vector<int>{x, runningMax});
            }
        }

        return (ans);
    }
};