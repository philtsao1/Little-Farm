#include "Game.h"
#include<vector>
#include <iostream>


Tractor::Tractor(){
    x=1;
    y=1;
    size=1;
}

Tractor::Tractor(int x_val,int y_val,unsigned short size_val,Activity activity_val){
    x=x_val;
    y=y_val;
    size=size_val;
    activity=activity_val;
}

void Tractor:: set_x(int new_x){
    x=new_x;
}
int Tractor:: get_x() const{
    return x;
}

void Tractor:: set_y(int new_y){
    y=new_y;
}

int Tractor::get_y() const{
    return y;
}

void Tractor:: set_Size(unsigned short new_size){
    size=new_size;
}

unsigned short Tractor:: get_Size() const{
    return size;
}

void Tractor:: set_Activity(Activity new_activity){
    activity=new_activity;
}

Activity Tractor:: get_Activity()const {
    return activity;
}

Game::Game(unsigned int new_size){
    map_size=new_size;
}

int Game:: GetTractor(int x, int y){
    int a;
    for(int i=0;i<all.size();i++){
        a=all[i].get_Size()/2;
        if(((all[i].get_x()-a)<x) &&(x<all[i].get_x()+a)){
            if((all[i].get_y()-a<y) &&(y<all[i].get_y()+a))
                return i;
        }
    }
    return -1;
}

void Game::SelectTractor(int x, int y){
    selected.clear();
    int a;
    for(int i = 0; i < all.size(); i++){
        a=all[i].get_Size()/2;
        if(((all[i].get_x()-a)<x) &&(x<all[i].get_x()+a)){
            if((all[i].get_y()-a<y) &&(y<all[i].get_y()+a))
                selected.push_back(i);
           return;
        }
    }
}


void Game::SelectTractors(int x1,int y1,int x2,int y2){
    selected.clear();
    int a;
    for(int i=0;i<all.size();i++){
        a=all[i].get_Size()/2;
        if((all[i].get_x()+a>=x1)&&(x2>=all[i].get_x()-a)){
                if((all[i].get_y()-a<=y1)&&(y2<=all[i].get_y()+a)){
                        selected.push_back(i);
                }
            }
        }
}



void Game:: AddTractor(Tractor new_unit){
    all.push_back(new_unit);
}

bool Game:: MoveTractor(int i,int new_x, int new_y){
    
    if((((all[i].get_Size()/2)+new_x)>map_size) || ((new_x-(all[i].get_Size()/2)<0)))
        return false;
    if(new_x>map_size || new_y>map_size)
        return false;
    for(int b=0;b<all.size();b++){
        int a=all[b].get_Size()/2;
        if((all[b].get_x()-a<=new_x)&&(all[b].get_x()+a>=new_x)){
            if((all[b].get_y()-a<=new_y)&&(all[b].get_y()+a>=new_y)){
                return false;
            }
        }
    }
        all[i].set_x(new_x);
        all[i].set_y(new_y);
        return true;
}




void Game:: AssignTractorsActivity(Activity new_activity){
    int ref;
    for(int i=0; i<selected.size();i++){
        ref=selected[i];
        all[ref].set_Activity(new_activity);
    }
}

void Game:: PrintTractor(int i){
    std::cout<<all[i].get_x()<<"  ";
    std::cout<<all[i].get_y()<<"  ";
    std::cout<<all[i].get_Size()<<"  ";
    std::cout<<all[i].get_Activity()<<"  ";
    
}

void Game:: PrintSelectedTractors(){
    int ref;
    for(int i=0; i<selected.size();i++){
        ref=selected[i];
        std::cout<<ref<<std::endl;
    }
}

void Game:: PrintAllTractors(){
    for(int i=0;i<all.size();i++){
        std::cout<<all[i].get_x()<<"  ";
        std::cout<<all[i].get_y()<<"  ";
        std::cout<<all[i].get_Size()<<"  ";
        std::cout<<all[i].get_Activity()<<"  "<<std::endl;

    }
}

