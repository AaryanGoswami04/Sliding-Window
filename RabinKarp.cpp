/*Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".*/
////Optimized approach: TC:O(M+N); SC:O(1)
 bool rabinKarp(string& a, string& b){
        int m = a.size();
        int n = b.size(), j=0;
        int d = 256, maxi = 101, ha = 0, hb = 0, h=1; //ha and hb store hash values of for a and b respectively
        
        for (int i = 0; i < n - 1; i++) h = (h * d) % maxi;

        for (int i = 0; i < n; i++){ //calculate hash values for b and first window of size of b in a 
            ha = ((d * ha) + a[i]) % maxi;
            hb = ((d * hb) + b[i]) % maxi;
        }

        for(int i = 0; i <= m-n; i++) //Iterate over every window of size of b in a
        {
            if(ha == hb)
            {
                for(j = 0; j < n; j++){
                    if(b[j] != a[i+j]) break;
                }
                if(j == n) return 1;
            }
            if(i < m-n) //Compute hash values of next window in a, remove trailing char, include next char
            {
                ha = (d * (ha - a[i] * h) + a[i + n]) % maxi;
                if(ha < 0) ha += maxi;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int ans = 1;
        string temp = a;

        while(a.size() < b.size()){
            a += temp;
            ans++;
        }
       
        if(rabinKarp(a,b)) return ans;
        a += temp;
        if(rabinKarp(a,b)) return ans+1;

        return -1;
    }
