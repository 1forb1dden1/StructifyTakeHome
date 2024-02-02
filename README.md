# Structify Take Home
This is my solution for the Structify Technical Take-Home assignment for the Full Stack Intern position(summer 2024).

# How to run this program
Run the executable file main.exe
Problem
We're an input string with a list of chords and we must determine the total number of intersections from that list of chords. Example Input: [(0.9, 1.3, 1.70, 2.92),(s1, e1, s2, e2)]


# Step 1: Parsing Input
Given the input values, the way I approached this problem is first break the input into two different lists.
I created a function ParseInput to create two lists

The function will take in the input string and two references to lists: L1 (Float Value List) and L2 (String List).
It will iterate through the input string until key points are met.
The first loop will search for a '(' which indicates the beginning of float values to input into L1.
Once '(' is found, the function will filter for ',' and store values until it encounters another ','.
When a ',' is encountered, a value such as "0.9" will be converted to a double and stored in L1.
Steps 4 and 5 will repeat until the end of the chord, defined as ')'.
The iterator will then process the string until it encounters '(' which indicates the beginning of the next list.
Once '(' is found, the function will begin to push the points into L2.
It will iterate and store values until encountering ','; when it does, it will push the stored values into L2 and reset the stored values to "".
This process will repeat until it has finished parsing the entire input string.

When this is completed we should be left
L1 = {0.78, 1.47, 1.77, 3.72}
L2 = {s1, s2, e1, e2}
# Step 2: Initializing a Map
Now that the data is parsed we have access two two parallel lists that contains the same number of elements. Knowing this, we can speed up the program a bit more before computing things by storing the two lists as key/value pairs in a map. This way, when we perform the computations we can access the value associated with starting/end points instantly rather than having to iterate through two lists, list1(values), list2(positions).

As a means to manage the data I created a Intersections class that contains the two lists and a map(named: points) with a InitializePoints function that will take the two lists and initialize the map to have all the points.

Check if the two lists have the same number of elements, if it does then continue otherwise there won't be enough key/value pairs for the map which in that case; stop.
Create a loop through list 2 containing the positions(s1, s2, e1, e2).
While iterating through list 2, store the elements in list2 as the key in the map and use the same index from list1 as the value.

Once this is completed we will have a map containing points
s1: 0.78
s2: 1.47
e1: 1.77
e2: 3.72
# Step 3: Computing Intersections
At this point, we have a map with all the corresponding points, and our task is to compute how many intersections there are. To determine the intersections, we need to compare each pair of line segments defined by their start and end points.

Initialize a variable count to keep track of the total number of intersections.
Check if the map points is empty. If it is, there are no points initialized, so we cannot compute intersections. In this case, there is no intersections.
Iterate through the map to compare each pair of line segments for potential intersections.
For each pair of line segments, compare the bounding points (start and end) of one segment with the bounding points of all other segments.
If the bounding points of two segments are not bounded in the same way (one is bounded while the other is not), it indicates an intersection between those two line segments.
Increment the count variable for each intersection found.
# Time Complexity
Step 1 Parsing Input: O(n) where n is the length of the input string.
Step 2 Initializing a Map: O(n) where n is the size of the list.
Step 3 Computing Intersections: O(n^2) where n is the size of the (map/2).
