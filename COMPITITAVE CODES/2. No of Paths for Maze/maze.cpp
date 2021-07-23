#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int mazePath(int maze[][C])
{
    int r,c;
    r=c=R;
    if(maze[0][0]==-1){
        return 0;
    }

    for(int i=0;i<r;i++){
        if(maze[0][i]==0){
            maze[0][i]=1;
        }else{
            break;
        }
    }


    for(int i=0;i<r;i++){
        if(maze[i][0]==0){
            maze[i][0]=1;
        }else{
            break;
        }
    }

    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(maze[i-1][j]>0){
                maze[i][j]=maze[i-1][j]+maze[i][j];
            }

            if(maze[i][j-1]>0){
                maze[i][j]=maze[i][j-1]+maze[i][j];
            }
        }
    }

    if(maze[r-1][c-1]==-1){
        return 0;
    }else{
        return maze[r-1][c-1];
    }
}

int main(){

    cout<<"Enter Maze Elements "<<R<<"X"<<C<<": -1=>Block 0=>Open"<<endl;
    int maze[R][C];

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>maze[i][j];
        }
    }

    cout<<"Possible Paths: "<<mazePath(maze)<<endl;
    return 0;
}
