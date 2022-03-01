class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<string> words;
        string temp="";
        for(int i=0;i<=s.length();i++){
            if(s[i]!='.'){
                temp+=s[i];
            }else{
                words.push_back(temp);
                temp = "";
            }
        }
        words.push_back(temp);
        string res = "";
        for(int i=words.size()-1;i>=1;i--){
            res+=words[i];
            res+=".";
        }
        res+=words[0];
        return res;
    } 
};
