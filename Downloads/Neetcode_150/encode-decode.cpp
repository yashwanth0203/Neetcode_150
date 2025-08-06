/*We can use an encoding approach where we start with a number representing the length of the string, 
followed by a separator character (let's use # for simplicity), and then the string itself. 
To decode, we read the number until we reach a #, then use that number to read the specified number of characters
as the string.*/



class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
    vector<string> res;
    int i = 0;

    while (i < s.size()) {
        int j = i;
        while (s[j] != '#') j++;

        int length = stoi(s.substr(i, j - i));
        i = j + 1;

        res.push_back(s.substr(i, length));
        i += length; // advance i to next encoded string
    }

    return res;
}

};
