#include <iostream>
#include <time.h>
#include "modulo.h"

using namespace std;


enum MatrixType {Idententy, Random};


class Matrix {

private:
    float** data;
    int rows;
    int columns;

public:

    Matrix(int r, int c){
        rows = r;
        columns = c;
        data = new float*[r];
        for (int i = 0; i<r; i++){
            data[i] = new float[c];
        }
    }
    Matrix(int r, int c, float init): Matrix(r, c){

        for (int i = 0; i<r; i++){
            for (int j = 0; j<c; j++){
               data[i][j] = init;
            }
        }
    }

    Matrix(int r, int c, MatrixType type): Matrix(r,c){


        if (type == Idententy) {
            for (int i = 0; i<r; i++)
                for (int j = 0; j<c; j++)
                    data[i][j] = i == j ? 1 : 0;
        } else {
             for (int i = 0; i<r; i++)
                for (int j = 0; j<c; j++)
                    data[i][j] = 1;
        }

    }

    void print(){

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                cout<<data[i][j]<<"  ";
            }
            cout<<endl;
        }

    }

    void set(int r, int c, float v){
        data[r][c] = v;
    }
    float get(int r, int c){
        return data[r][c];
    }
    int column(){
        return columns;
    }
    int row(){
        return columns;
    }

    Matrix operator+  (Matrix t){
        Matrix m = Matrix(t.row(), t.column());
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                m.data[i][j] = data[i][j] + t.data[i][j];
            }
        }
        return m;
    }
    Matrix operator-  (Matrix t){
        Matrix m = Matrix(t.row(), t.column());
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                m.set (i,j,data[i][j] - t.get(i,j));
            }
        }
        return m;
    }
    bool operator==  (Matrix t){
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                if (data[i][j] != t.get(i,j)) return false;
            }
        }
        return true;
    }
    bool operator!=  (Matrix t){
        return !(*(this) == t);
    }

    Matrix operator*  (Matrix t){
        /////////// 2x2 * 3x3 = 2x3 //////////////
        Matrix m = Matrix(rows, t.column());
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<t.column(); j++){
                for (int k = 0; k<columns; k++){
                    m.set(i,j, m.get(i,j) + data[i][k] * t.get(k,j));
                }

            }
        }
        return m;
    }

    Matrix transpose(){
        Matrix m = Matrix(columns, rows);
        for (int i = 0; i<columns; i++){
            for (int j = 0; j<rows; j++){
                m.set(i,j, data[j][i]);
            }
        }
        return m;
    }

    bool isIdentiny(){
       for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                if((i == j && data[i][j]!=1) || (i != j && data[i][j]!=0))
                 return false;
            }
        }
        return true;
    }
    bool isIdemtopit(){
        Matrix m = *this;
        return m == (m*m);
    }
    bool isSquare(){
        return rows == columns;
    }
    bool isSymmetric(){
       for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                if(data[i][j] != data[j][i])
                 return false;
            }
        }
        return true;
    }

    bool isUpperTri(){
       for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                if(i>j && data[i][j] !=0)
                 return false;
            }
        }
        return true;
    }
    bool isLowerTri(){
       for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                if(i<j && data[i][j] !=0)
                 return false;
            }
        }
        return true;
    }
    void fill(float x){
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                data[i][j] = x;
            }
        }
        return;
    }


    void toIntMat(){

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){

                data[i][j] = (int)data[i][j];

            }
        }

        return;

    }



    Matrix operator* (float x){
        Matrix r = Matrix(rows, columns);
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                r.data[i][j] = data[i][j] * x;
            }
        }
        return r;
    }

    Matrix operator/ (float x){
        Matrix r = Matrix(rows, columns);

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                r.data[i][j] = data[i][j] / x;
            }
        }
        return r;
    }
    Matrix operator% (int x){
        Matrix r = Matrix(rows, columns);

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                r.data[i][j] = mod(int(data[i][j]),x);
            }
        }
        r.toIntMat();
        return r;
    }



    float max(){
        float m = data[0][0];
        for (int i = 0; i<columns; i++){
            for (int j = 0; j<rows; j++){
                if (m<data[i][j]) m = data[i][j];
            }
        }
        return m;
    }
    float min(){
        float m = data[0][0];
        for (int i = 0; i<columns; i++){
            for (int j = 0; j<rows; j++){
                if (m>data[i][j]) m = data[i][j];
            }
        }
        return m;
    }

    Matrix removeRowColumn (Matrix m, int removableRow, int removableColumn) {
        Matrix r = Matrix(m.rows-1, m.columns-1);

        int newRow = 0;
        int newColumn = 0;

        for (int i = 0; i<m.rows; i++){
            for (int j = 0; j<m.columns; j++){
                if (i != removableRow && j != removableColumn) {
                   r.data[newRow][newColumn] = data[i][j];
                   if (newColumn == m.columns-2){
                       newColumn = 0;
                       newRow++;
                   } else
                    newColumn ++;

                }
            }
        }

        return r;
    }

    int getDeterminantOfArgument(Matrix m){

        int r = 0;

        if (m.columns != m.rows) {
            cout<< "Error: rows != columns";
            return 0;
        }
        if (m.columns == 2)  {

            return m.data[0][0] * m.data[1][1] - m.data[1][0] * m.data[0][1];
        }

        for (int i = 0; i < m.columns; i++) {
            r += m.data[0][i] * getDeterminantOfArgument(removeRowColumn(m,0,i)) * ((i%2) == 0? 1:-1);

        }




        return r;
    }
    int determinant() {

        return getDeterminantOfArgument(*this);
    }

    Matrix adjoint(){
        Matrix r = Matrix(rows, columns);

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){

                r.data[i][j] = getDeterminantOfArgument(removeRowColumn(*this,i,j)) * (((i+j)%2) == 0? 1:-1);

            }
        }

        r = r.transpose();

        return r;

    }

    Matrix inverse(){
        Matrix r = Matrix(rows, columns, 0);
        float d = (float)determinant();

        if(!d) cout<<"Error: inverse doesn't exist!";
        else r =  adjoint() / d;

        return r;
    }



};

