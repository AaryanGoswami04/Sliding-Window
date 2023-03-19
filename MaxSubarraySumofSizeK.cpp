Class Solution
public:
//TC: O(N)
//SC: O(1)
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i=0, j=0;
        long sum = 0;
        long ans=0;
        
        while(j<N){
            sum += Arr[j];
            if(j-i+1 < K){
                j++;
            }
            else if(j-i+1 == K){
                ans = max(ans, sum);
                sum -= Arr[i];
                i++;
                j++;
            }
                
        }
        return ans;
    }
};
