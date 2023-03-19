/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/
//TC: O(s.size()*p.size())
//SC:O(K)
    bool isAnagram(string& p, string& temp, int k, unordered_map<char,int>& freq_p,unordered_map<char,int>& freq_temp){

        for(auto &it:freq_p){
            char ch = it.first;
            if(freq_temp[ch] != it.second)
                return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
       int k = p.size(), n = s.size(), i=0, j=0;
       vector<int> res;
       unordered_map<char,int> freq_p, freq_temp; //freq_temp stores count of all chars of current window string
       string temp;

       for(auto &i:p) //stores count of all characters of p
            freq_p[i]++;

        while(j<n){
            temp.push_back(s[j]);
            freq_temp[s[j]]++;

            if(j-i+1 < k)
                j++;
                 
            else if(j-i+1 == k){
                if(isAnagram(p,temp,k,freq_p, freq_temp)) //storing the starting index of window because it is an anagram of p
                    res.push_back(i);

                temp.erase(temp.begin(),temp.begin()+1);  //excluding the first element of the window
                freq_temp[s[i]]--;

                i++;
                j++;
            }
        }
        return res;
    }
