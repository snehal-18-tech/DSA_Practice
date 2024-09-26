#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Function to find the indices of the two numbers that add up to the target
vector<int> twosum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_map;
    
    // Iterate through the vector
    for(int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i]; // Calculate the complement of the current number
        
        // If complement exists in the map, return the indices
        if(num_map.find(complement) != num_map.end())
        {
            return {num_map[complement], i};
        }
        
        // Store the current number and its index in the map
        num_map[nums[i]] = i;
    }
    
    return {}; // Return an empty vector if no solution is found
}

int main()
{
    int n, target;
    
    // Prompt the user to enter the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n); // Initialize the vector with 'n' elements
    
    // Take the array input from the user
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    // Take the target sum as input from the user
    cout << "Enter the target sum: ";
    cin >> target;
    
    // Call the twosum function
    vector<int> result = twosum(nums, target);
    
    // Check if a valid pair was found
    if(!result.empty())
    {
        // Output the result if a pair was found
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        // Output if no pair found
        cout << "No valid pair found." << endl;
    }
    
    return 0;
}

// output:
// Enter the number of elements in the array: 4
// Enter the elements of the array: 2 7 11 15
// Enter the target sum: 9
// Indices: 0, 1  