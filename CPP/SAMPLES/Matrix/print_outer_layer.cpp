#include<iostream>
#include<vector>


using namespace std;

void print_matrix(vector<vector<int>> matrix){
    int m = matrix.size(); //number of rows
    if(!m)
    cout<<"[]\n";
    else{
        int n = matrix[0].size(); //number of columns


        if(m==1 || n==1){
            for(int i=0; i<m;i++){
                for(int j=0; j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
            }
            cout<<"\n";
            return;
        }

        //to print outer elements, calculate start point and end point of the matrix.
        vector<int> start {0,0};
        vector<int> end{m-1, n-1};


        int row = 0;
        int column = 0;

        //1st value start[0] or end[0] represents row, and 2nd value start[1] or end[1] represents column.

        // cout<<"start:"<<"("<<start[0]<<","<<start[1]<<")\n";
        // cout<<"end:"<<"("<<end[0]<<","<<end[1]<<")\n";

        //1. row(same) and column(increase till end),
        //2. row(increase till end) and column(same).
        //3. row(same) and column(decrease till start).
        //4. row(decrease till start) and column(same).

        for(; column<=end[1]-1; column++ ){
            cout<<matrix[start[0]][column]<<" ";
        }
        // cout<<"\n";
        // cout<<"row:"<<row<<" column:"<<column<<"\n";

        for(; row<=end[0]-1; row++){
            cout<<matrix[row][column]<<" ";
        }
        // cout<<"\n";

        // cout<<"row:"<<row<<" column:"<<column<<"\n";

        for(; column>=start[1]+1; column--){
            cout<<matrix[row][column]<<" ";
        }
        // cout<<"\n";

        // cout<<"row:"<<row<<" column:"<<column<<"\n";

        for(; row>=start[0]+1; row--){
            cout<<matrix[row][column]<<" ";
        }
        cout<<"\n";

        cout<<"row:"<<row<<" column:"<<column<<"\n";

    }
}

int main(){

    vector<vector<int>> matrix {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    print_matrix(matrix);
    return 0;
}