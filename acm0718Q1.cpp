// need to remember next time:
// this question requires tree implementation, which will be easier to do in Java than in C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    int currLine =1;
    int totalLine;
    string line;
    int nodeNum = 0;
    int totalDist = 0;
    int totalEdge = 0;
    int currCase = 0;
    int totalCase;
    //cout << "done declaring fields" << endl;
    while (getline(cin, line)) {
        int ** adjList;
        if (currLine == 1) {
            totalCase = atoi(line.c_str());
        }
        //into each test case aka tree:
        else {
            if (line.length() == 1) {
                // create adjacency list
                nodeNum = atoi(line.c_str());
                
                adjList = new int * [nodeNum];
                for (int i = 0;  i < nodeNum; i++) {
                    adjList[i] = new int [nodeNum];
                }
                totalEdge = 0;
                currCase++;
            }
            else {
                int distance;
                int firstpos = line.find_first_of(" ");
                int lastpos = line.find_last_of(" ");
                int row = atoi(line.substr(0,firstpos).c_str());
                int column = atoi(line.substr(firstpos+1,lastpos).c_str()); // check why this substr works
                distance = atoi(line.substr(lastpos+1).c_str());
                adjList[row][column] = distance;
                adjList[column][row] = distance;
                totalEdge++;
            }
        }
        // calculate total distance for a tree
        if ((totalEdge > 0) && ((totalEdge + 1) == nodeNum)) {
            //print list
            for (int i = 0; i< nodeNum; i++) {
                for (int j = 0; j < nodeNum; j++) {
                    cout << adjList[i][j] << " ";
                }
                cout <<endl;
            }
            //calculate distance
            for (int i =0 ; i < nodeNum; i++) {
                for (int j = i+1; j< nodeNum; j++) {
                    if (adjList[i][j] != NULL) totalDist += adjList[i][j];
                    else {
                        for (int k = i+1; k < nodeNum; k++) {
                            if (adjList[j][k] != NULL) totalDist += (adjList[j][k]+ adjList[i][k]);
                            break;
                        }
                        cout << totalDist <<endl;
                    }
                    
                }
            }
            double avg;
            avg = (double) totalDist/ totalEdge;
            cout << "total distance is " << avg <<endl;
       
        //cout << "currCase is: " << currCase <<endl;
        //cout << "total case is: " << totalCase << endl;
        //cout << "total edge is: " << totalEdge <<endl;
        //cout << "nodeNum is: " << nodeNum <<endl;
        }
        if ((currCase == totalCase) && ((totalEdge + 1) == nodeNum)) break;
        else currLine++;
    }
    return 0;
}