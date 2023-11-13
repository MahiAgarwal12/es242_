#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class cube_r {
    public:
    vector<char> moves;
    char cube[6][4];

    void move_u(){
        char temp1u = cube[0][0];
        cube[0][0] = cube[1][0];
        cube[1][0] = cube[2][0];
        cube[2][0] = cube[3][0];
        cube[3][0] = temp1u;

        char temp2u = cube[0][1];
        cube[0][1] = cube[1][1];
        cube[1][1] = cube[2][1];
        cube[2][1] = cube[3][1];
        cube[3][1] = temp2u;

        char temp3u = cube[4][3];
        cube[4][3] = cube[4][1];
        cube[4][1] = cube[4][0];
        cube[4][0] = cube[4][2];
        cube[4][2] = temp3u;
    }

    void move_r(){
        char temp1r = cube[4][1];
        cube[4][1] = cube[0][1];
        cube[0][1] = cube[5][1];
        cube[5][1] = cube[2][2];
        cube[2][2] = temp1r;

        char temp2r = cube[4][3];
        cube[4][3] = cube[0][3];
        cube[0][3] = cube[5][3];
        cube[5][3] = cube[2][0];
        cube[2][0] = temp2r;

        char temp3r = cube[1][3];
        cube[1][3] = cube[1][1];
        cube[1][1] = cube[1][0];
        cube[1][0] = cube[1][2];
        cube[1][2] = temp3r;
    }

    void move_f(){
        char temp1f = cube[1][0];
        cube[1][0] = cube[4][2];
        cube[4][2] = cube[3][3];
        cube[3][3] = cube[5][1];
        cube[5][1] = temp1f;

        char temp2f = cube[1][2];
        cube[1][2] = cube[4][3];
        cube[4][3] = cube[3][1];
        cube[3][1] = cube[5][0];
        cube[5][0] = temp2f;

        char temp3f = cube[0][1];
        cube[0][1] = cube[0][0];
        cube[0][0] = cube[0][2];
        cube[0][2] = cube[0][3];
        cube[0][3] = temp3f;
    }

    void print_cube(){
        cout<< "printing cube\n";
        for (int i = 0; i < 6; i++)
        {
                cout<< cube[i][0] <<"      " ;
                cout<< cube[i][1] << endl;
                cout<< cube[i][2] <<"      ";
                cout<< cube[i][3] << endl;
                cout<< "----------\n";
        }
    }
    void print_moves(){
        for (int i = 0; i < moves.size(); i++)
        {
            cout<< moves.at(i);
        }
    }
};
queue <cube_r> cubestv;
queue <char> moves;
/*
front= face 1
right = face 2
back = face 3
left = face 4
top = face 5
bottom = face 6
*/

void init_cube(cube_r &cuber){

    cout<<"all face colours holding red at bottom blue left and white back in bottom back layer corner\n";
    for (int j = 0; j < 6; j++)
        {   string str;
            cin >>str;
            cuber.cube[j][0]=str[0];
            cuber.cube[j][1]=str[1];
            cuber.cube[j][2]=str[2];
            cuber.cube[j][3]=str[3];
        }
    cuber.print_cube();
}

int face_done(cube_r cuber, int x){
    if (cuber.cube[x][0]==cuber.cube[x][1]==cuber.cube[x][2]==cuber.cube[x][3]){
        return 1;
    }
    return 0;
}

int done(cube_r cuber){
    for (int j = 0; j < 6; j++){
        if (!face_done(cuber, j)){
            return 0;
        }
    }
    return 1;
}
int solve(cube_r &cuber){

    if (done(cuber)){
       return 1;
    }
    int n = cuber.moves.size() - 1 ;
    cout<<"$$"<<n;
    if (n>2 && cuber.moves.at(n)==cuber.moves.at(n-1)==cuber.moves.at(n-2)=='F'){
        cuber.moves.pop_back();cuber.moves.pop_back();cuber.moves.pop_back();
        cuber.moves.push_back('f');}
    else{
        cuber.move_f();
        cuber.moves.push_back('F');
        cubestv.push(cuber);
        cuber.moves.pop_back();
        cuber.move_f(); cuber.move_f(); cuber.move_f();
    }
  
    if (n>2 && cuber.moves.at(n)==cuber.moves.at(n-1)==cuber.moves.at(n-2)=='R'){
        cuber.moves.pop_back();cuber.moves.pop_back();cuber.moves.pop_back();
        cuber.moves.push_back('r');}
    else{
        cuber.move_r();
        cuber.moves.push_back('R');
        cubestv.push(cuber);
        cuber.moves.pop_back();
        cuber.move_r();cuber.move_r();cuber.move_r();
    }
  
    if (n>2 && cuber.moves.at(n)==cuber.moves.at(n-1)==cuber.moves.at(n-2)=='U'){
        cuber.moves.pop_back();cuber.moves.pop_back();cuber.moves.pop_back();
        cuber.moves.push_back('u');}
    else{
        cuber.move_u();
        cuber.moves.push_back('U');
        cubestv.push(cuber);
        cuber.moves.pop_back();
        cuber.move_u();cuber.move_u();cuber.move_u();
    }
    
    //while((!cubestv.empty()) && (!done(cuber))){
    cube_r nxtcube = cubestv.front();
    cubestv.pop();
    cout<<"1    ";
    cuber.print_moves();
    solve(nxtcube);
    cout<<"2";
    //}
    // cuber.move_r();cuber.move_r();cuber.print_cube();
    // cuber.move_u();cuber.move_u();cuber.print_cube();
    // cuber.move_f();cuber.move_f();cuber.print_cube();
    // cuber.move_u();cuber.print_cube();
    // cuber.move_f();cuber.move_f();cuber.move_f();cuber.print_cube();
    // cuber.move_r();cuber.move_r();cuber.move_r();cuber.print_cube();
    // cuber.move_u();cuber.print_cube();
    // cuber.move_r();cuber.move_r();cuber.print_cube();


    return 0;
}

int main(){
    cube_r cuber;
    init_cube(cuber);
    solve(cuber);
    cuber.print_cube();
    
    return 0;
}