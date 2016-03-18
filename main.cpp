#include<iostream>
#include<Windows.h>
#include<MMSystem.h>
#include<string>
#include <sstream>
#include <stdio.h>
#include<time.h>
#include"Player.h"
#include"Map.h"
#include"Game.h"
using namespace std;
//function prototypes
void SetCursorPosition(int x,int y);
void ClearScreen(const string &ch);
//define menu system enum
enum MenuSystem
{
    SHOWMENU,MOVECURSOR,EXITPROGRAM //0,1,2
};
//main
/*
void Sound(const string s )
{
    string tmp=s+".wav";
    cout<<tmp;
    PlaySound(TEXT(tmp.c_str()),NULL,SND_ASYNC);//music player'
}
void Game1()
{
    cout<<"Game1";
    Sound("Galaxy");
    string tmp;
    while(cin>>tmp && tmp!="E")
    {
        cout<<"HAHAHA";
        cout<<endl;
    }
    Sound(" ");
    system("cls");
}
void Trigger(const int triggerNum )
{
    switch (triggerNum)
    {
    case 6:
        Game1();
        break;
    case 7:
        break;
    default:
        break;

    }
}*/
int main()
{
    /*SetCursorPosition(20,3);
    cout<< "[20,3]";*/
    //ClearScreen("#");


    int menu = SHOWMENU;
    char character = ' ';
    int input;
    bool exit  = false;

    Player player;
    Map map;
    Game game;

    cout<<"Print your name...>";
    cin>>player.name;
    system("cls");
    time_t t = time(0);
    clock();
    bool GameRun = true;
    map.mapNum=0;
    int beforeMap=0;

    int getMap = map.GetMap(map.mapNum);
    map.Position(1,1);
    int Mpos=0,Gpos=0;
    while(GameRun&&getMap)
    {

        map.SetCursorPosition(0,0);
        char tmp[64];
        cout<<"開始時間 :";
        strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) );
        puts( tmp );
        cout<<"[玩家] "<<player.name<<endl;
        cout<<"[目標]"<<" 尋找華生"<<endl;
        if(map.Keyboard()>0) Mpos=map.Keyboard(); //觸發關卡
        if(Mpos!=map.mapNum && map.GetMap(Mpos))  //換地圖
        {
            beforeMap=map.mapNum;
            map.mapNum=Mpos;
            map.Position(map.xPos,map.yPos);
            Gpos=1;
        }

        map.PrintMap();
        if(Gpos)
        {
            game.Trigger(Mpos);
            game.BgMusic(Mpos);
            Gpos=0;
        }
        if(GetAsyncKeyState(VK_SPACE)!=0)
        {
            while(GetAsyncKeyState(VK_SPACE)!=0)
            {
                map.SetCursorPosition(42,15);
                int minute=clock()/CLOCKS_PER_SEC/60;
                int second=clock()/CLOCKS_PER_SEC%60;
                std::cout<<"已經過 :: "<<minute<<" 分 "<<second<<" 秒 "<<std::endl;
                Sleep(100);
            }
            system("cls");
        }
        Sleep(0);
    }
    cin.get();
    return 0;
}

//function definitions
/*
void SetCursorPosition(int x,int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); //handle cursor buffer
    COORD pos ;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(output,pos);

}
void ClearScreen(const string &ch)
{
    for(int x=0; x<16; ++x)
    {
        for(int y=0; y<16; ++y)
        {
            SetCursorPosition(x,y);
            cout<< ch;
        }
    }
}
*/

