class Solution {
  public: vector < vector < int >> merge(vector < vector < int >> & intervals) {
    // Check if the 'intervals' vector is empty
    if (intervals.empty()) {
      // If the vector is empty, there are no intervals to merge, so return an empty vector
      return {};
    }

    // Sort the intervals based on their start times in ascending order
    sort(intervals.begin(), intervals.end());

    // Create a new vector 'merged' to store the merged intervals
    vector < vector < int >> merged;

    // Push the first interval into the 'merged' vector since there are no previous intervals to compare with
    merged.push_back(intervals[0]);

    // Iterate through the intervals starting from the second interval (index 1)
    for (int i = 1; i < intervals.size(); i++) {
      // Check if the start time of the current interval is less than or equal to the end time of the last interval in 'merged'
      if (intervals[i][0] <= merged.back()[1]) {
        // If the current interval overlaps with the last interval in 'merged', update the end time of the last interval
        // to be the maximum of the current interval's end time and the last interval's end time
        merged.back()[1] = max(merged.back()[1], intervals[i][1]);
      } else {
        // If the current interval does not overlap with the last interval in 'merged', push the current interval into 'merged'
        merged.push_back(intervals[i]);
      }
    }

    // After iterating through all intervals, the 'merged' vector contains the merged non-overlapping intervals
    return merged;
  }
};