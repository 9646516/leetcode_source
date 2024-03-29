// id:78706315
// runtime:96 ms
// memory:18.4 MB
// title:Subrectangle Queries
// translatedTitle:子矩形查询
// questionId:1572
// time:2020-06-13 22:35:28

class SubrectangleQueries {
  public:
    vector<vector<int>> V;
    SubrectangleQueries(vector<vector<int>> &rectangle) { V = rectangle; }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                V[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) { return V[row][col]; }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */