class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<long long> vec(n+1, 0);
        //leave 0th index as it is, start from 1st..................
        vec[1] = 1;
        //three pointers initially pointing 1th ugly number...
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for(int i=2; i<n+1; i++){
            int x = vec[p2]*2;
            int y = vec[p3]*3;
            int z = vec[p5]*5;
            //now check which is minimum from x,y,z and where it come from--
            if(x < y && x < z){
                vec[i] = x;
                p2++;
            }
            else if(y < x && y < z){
                vec[i] = y;
                p3++;
            }
            else if(z < x && z < y){
                vec[i] = z;
                p5++;
            }
            else if(x == y && x < z){
                vec[i] = x;
                p2++;
                p3++;
            }
            else if(y == z && y < x){
                vec[i] = y;
                p3++;
                p5++;
            }
            else if(x == z && x < y){
                vec[i] = x;
                p2++;
                p5++;
            }
            else if(x == y && y == z && z == x){
                vec[i] = x;
                p2++;
                p3++;
                p5++;
            }

        }
        return vec[n];
        
    }
};
