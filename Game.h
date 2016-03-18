#include<string>
#include<iostream>
#include<Windows.h>
#include<MMSystem.h>
#include<sstream>
class Game
{
public:
    void Sound(const std::string s )
    {
        std::string tmp=s+".wav";
        std::cout<<tmp;
        PlaySound(TEXT(tmp.c_str()),NULL,SND_ASYNC);//music player'
    }
    void BgMusic(const int triggerNum)
    {
        switch(triggerNum)
        {
        case 6:
            Sound("Galaxy");
            break;

        }
    }
    void Trigger(const int triggerNum ) //¹CÀ¸Ä²µo
    {
        trigger_=triggerNum;
        switch (triggerNum)
        {
        case 6:
            Game1_();
            break;
        case 7:
            break;
        default:
            break;
        }
    }
    std::string GetTrigger()
    {
        std::stringstream ss;
        std::string s;
        ss<<trigger_;
        ss>>s;
        return s;
    }
    private:
    void Game1_()
    {
        std::cout<<"Game1";
        std::string tmp;
        while(std::cin>>tmp && tmp!="E")
        {
            std::cout<<"HAHAHA";
            std::cout<<std::endl;
        }
        Sound(" ");
        system("cls");
    }
    int trigger_=1;
};
