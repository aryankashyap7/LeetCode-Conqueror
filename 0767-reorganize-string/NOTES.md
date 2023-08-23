}
} else {
// If the last character in the result is the same as the current character:
if (pq.empty()) {
return "";  // If there are no more characters to choose from, it's impossible to reorganize.
}
​
pair<int, char> nextFreq = pq.top();  // Get the character with the next highest frequency.
pq.pop();  // Remove it from the priority queue.
result.push_back(nextFreq.second);  // Add the next character to the result.
​
if (--nextFreq.first > 0) {
pq.push(nextFreq);  // If there are more of this character, push it back to the priority queue.
}
​
pq.push(mostFreq);  // Push the original character back to the priority queue.
}
}
​
return result;  // Return the reorganized string or an empty string if impossible.
}
};
```
​