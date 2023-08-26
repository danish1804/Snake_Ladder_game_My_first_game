#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
const int width=30;
const int height=30;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup(){
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitx=rand()%width;
    fruity=rand() % height;
    score=0;
}
void draw(){
    system("cls");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
       for(int j=0;j<width+2;j++){
        if(j==0||j==width) cout<<"#";
        if(i==y&&j==x) cout<<"O";
        else if(i==fruity && j==fruitx) cout<<"x";
        else 
        {
            bool print=false;
            for(int k=0;k<ntail;k++){
                if(tailx[k]==j&&taily[k]==i){
                    cout<<"o";
                    print =true;
                    
                }
                
            }
            if(!print) cout<<" ";
            }
       
       }
       cout<<endl;
    }
    
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout <<"Score:"<<score<<endl;

}
void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'x':
                gameover=true;
                break;
        }
        
    }

}
void logic(){
        int prevx=tailx[0];
        int prevy=taily[0];
        int prevx2,prevy2;
        tailx[0]=x;
        taily[0]=y;
        for(int i=1;i<ntail;i++){
             prevx2=tailx[i];
             prevy2=taily[i];
             tailx[i]=prevx;
             taily[i]=prevy;
             prevx=prevx2;
             prevy=prevy2;
        }
      switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
      }
    if(x>=width||x<0||y>=height||y<0) gameover=true;
    if(x==fruitx&&y==fruity) {
        ntail++;
        score+=1;
        fruitx=rand()%(width-1);
        fruity=rand()%(height-1);
    }
}
int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
}