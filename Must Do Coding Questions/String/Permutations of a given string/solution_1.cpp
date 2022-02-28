class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<string> words;
        int start=0;
        string del = ".";
        int end = s.find(del,0); //find(delimeter, Position from where you want to start your search)
        while(end!=-1){
            words.push_back(s.substr(start,end-start)); // substr(index, length of substring you want to take out)
            start = end+del.size(); 
            end = s.find(del,start); // we will start searching after that index where we find delimeter 
        }
        words.push_back(s.substr(start,end-start));
        string res = "";
        for(int i=words.size()-1;i>=1;i--){
            res+=words[i];
            res+=".";
        }
        res+=words[0];
        return res;
        
    } 
};
