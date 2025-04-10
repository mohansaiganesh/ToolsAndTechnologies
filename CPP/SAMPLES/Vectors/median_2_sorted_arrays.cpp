class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //take minimum size nums as X and maximum size array as Y
        vector<int>& X = (nums1.size()<=nums2.size()) ? nums1 : nums2;
        vector<int>& Y = (nums1.size()>nums2.size()) ? nums1 : nums2;

        //sizes of X and Y
        int x = X.size();
        int y = Y.size();

        double res = 0.0;


        //partitionX -- number of elements left part of X have
        //partitionY -- number of elements left part of Y have

        //partitionX = 5 means, the left part should have 5 elements, right part should have size()-partitionX elements.
        //partitionX =0 means, the left part should have 0 elements, in that case we consider, INT_MIN.
        //partitionX = x means, the left part contains all the elements and right part has 0 elements, in that case we consider INT_MAX for right part element.


        int low = 0;
        int high = x;

        while(low<=high){
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 - partitionX; //(x+y+1)/2 gives number of elements to present in left part, ie, number of elements less than median.

            int maxLeftX = (partitionX==0) ? INT_MIN : X[partitionX-1];
            int maxLeftY = (partitionY==0) ? INT_MIN : Y[partitionY-1];
            int minRightX = (partitionX==x) ? INT_MAX : X[partitionX];
            int minRightY = (partitionY==y) ? INT_MAX : Y[partitionY];


            if((maxLeftX <= minRightY) && (maxLeftY <= minRightX)){
                //we found the correct split
                if((x+y)%2){ //odd
                    res =  max(maxLeftX, maxLeftY);
                }
                else{
                    res =  (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
                }
                break;
            }
            else if(maxLeftX > minRightY){
                high = partitionX-1;
            }
            else{
                low = partitionX+1;
            }

        }

        return res; 
    }
};