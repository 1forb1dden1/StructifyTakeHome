#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class Intersections {
    private:
    int count;
    vector<double> values;
    vector<string> position;
    map<string, double> points;
    
    public:
    Intersections(vector<double> v, vector<string> p){
        count = 0;
        values = v;
        position = p;
        initializePoints();
    }
    Intersections(vector<string> p, vector<double> v){
        count = 0;
        values = v;
        position = p;
        initializePoints();
    }
    void setValues(vector<double> input){
        values = input;
    }
    void setPosition(vector<string> input){
        position = input;
    }
    vector<double> getValues(){
        return values;
    }
    vector<string> getPosition(){
        return position; 
    }
    void initializePoints(){
        if(position.size() != values.size()){
            cout << "Cannot initialize points: Invalid number of elements in each list";
        }  else {
            for(int i = 0; i < position.size(); i++){
                points[position[i]] = values[i];
            }
        }

        /*Check Elements in the Map*/
        for (const auto& x : points){
            cout << x.first << ": " << x.second << endl;
        }
    }
    bool isBounded(double current, double bound1, double bound2) {
        if ((current > bound1 && current < bound2) || (current < bound1 && current > bound2)) {
            return true;
        } else {
            return false;
        }
    }
    void InitializeIntersections(){
        count = 0;
        if(points.size() == 0){
            cout << "There are no points initialized.";
        } else {
            double start1 = 0;
            double end1 = 0;
            double start2 = 0;
            double end2 = 0;
            for (int i = 1; i <= points.size()/2; i++){
                start1 = points["s"+ to_string(i)];
                end1 = points["e"+ to_string(i)];

                for(int j = i+1; j <= points.size()/2; j++){
                    start2 = points["s"+ to_string(j)];
                    end2 = points["e" + to_string(j)];
                    if(isBounded(start2, start1, end1) != isBounded(end2, start1, end1)){
                        count++;
                    }
                }
            }        }
    }
    int getCount(){
        return count;
    }
};

void parseInput(const string& input, vector<double>& l1, vector<string>& l2) {
    stringstream ss(input);
    char c;
    // Read until the first opening parenthesis 
    while (c != '(') {
        ss >> c;
    }

    // Read the doubles
    while (c != ')') {
        string value = "";
        while (c != ',' && c != ')') {
            if (isdigit(c) || c == '.') {
                value += c;
            }
            ss >> c;
        }
        if(c != ')'){
            ss >> c;
        }
        if(value != ""){
            //cout << stod(value) << endl;
            l1.push_back(stod(value)); // Convert string to double
        }
    }

    // Read until Second open parenthesis
    while (c != '(') {
        ss >> c;
    }

    // Read the points
    if(c == '('){
        ss >> c;
        while (c != ')') {
            string point = "";
            while(c != ',' && c != ')'){
                point += c;
                ss >> c;
            }
            if(c != ')'){
                ss >> c; 
            }
            l2.push_back(point);
        }
    }
}


int main() {
    cout << "Example Input: {(0.78, 1.47, 1.77, 3.72),(s1, s2, e1, e2)}\nInput values for analysis: ";
    string input = "";
    getline(cin, input); // read entire line including whitespace
    vector<double> l1;
    vector<string> l2;

    parseInput(input, l1, l2);
    Intersections intersections = Intersections(l1, l2);
    intersections.InitializeIntersections();
    cout << "Total Intersection: " << intersections.getCount();
    return 0;
}