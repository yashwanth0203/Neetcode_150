/*Brute force : The idea is to use a hashmap to store the element-frequency pair.
 Hashmap is used to perform insertion and updation in constant time.
  Then sort the element-frequency pair in decreasing order of frequency. 
  This gives the information about each element and the number of times they 
  are present in the array. To get k elements of the array, print the first k elements of the sorted array.*/

/*Better approach : The idea is to use a hashmap to store the element-frequency pair. Then use a priority queue (Max-Heap)
 to store the frequency-element pair. The element which has maximum frequency, comes at the top of the Priority Queue. 
 Remove the top of Priority Queue k times and store the values in the result array.*/

/*Optimal approach : The idea is to utilise more space to improve the time complexity, we store the elements based on their frequencies.
 We can use the frequency of each element as index of 2D array, where each index represents a list of elements of specific frequency.
  By doing this, we reduce the need for complex sorting operations. Instead, we can efficiently traverse the buckets from highest 
  frequency to lowest and collect the top k most frequent elements.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        int maxFreq=0;
        for(pair<int,int>entry : freq)
            maxFreq = max(maxFreq,entry.second);
        vector<vector<int>>buckets(maxFreq+1);
        for(pair<int,int>entry : freq)
            buckets[entry.second].push_back(entry.first);
        vector<int>res;
        for(int i=maxFreq;i>=1;i--){
            //We have done this since there could be more than k elements for single frequency and we need to take only k.
            sort(buckets[i].begin(), buckets[i].end(),greater<int>());
            for (int num : buckets[i]) {
            res.push_back(num);
            if (res.size() == k) {
                return res;
            }
            }
        }
        return res;
    }
};
