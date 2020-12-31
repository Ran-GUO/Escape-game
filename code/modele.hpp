/**
 *  modele.hpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */
#include"observable.hpp"
#pragma once

#include<string>
#include<vector>
#include<gtkmm/image.h>
#include<gtkmm/button.h>
#include<iostream>
#include<algorithm>
#include"player.hpp"
#include"vue.hpp"


class MRoom1:public Observable<std::string>{
private:
  Gtk::Image img;
  int resultFin;
  int resultNow; // si resultNow=5,on a fini tous les partie,Reussir a escape the room;
  Player p;
  int level;
  int levelChoose;
public:
  std::vector<int> partie; //present les 5 partie on veut realiser. par exemple, si partie[1]=1,on a deja reussir le partie 1; 
  MRoom1(Player p_):p(p_){
    resultFin=0;
    resultNow=0;
    levelChoose=0;
    for (int i=0;i<5;i++) partie.push_back(0);
  }
  void ResultNowPlusPlus(){this->resultNow++;}
  void setResultNow(int i){this->resultNow=i;}
  int getResultNow(){return this->resultNow;}
  void setResultFin(int i){this->resultFin=i;}
  int getResultFin(){return this->resultFin;}
  int getLevel(){return this->level;}
  void setLevel(int i){this->level=i;}
  Player getPlayer(){return this->p;}
  int getLevelChoose(){return this->levelChoose;}
  void setLevelChoose(int i){this->levelChoose=i;}
  void level_select(VRoom1 *v);
  void b_info(VRoom1 *v);
  void Info(std::string str){ notifyObservers(str);}
  std::vector<std::string> getImageStringButton5();
  std::vector<std::string> getImageStringButton6();
  std::vector<int> randomNum(int num);
  
};


class MRoom2:public Observable<std::string>{
private:
  Gtk::Image img;
  int resultFin;
  //int resultNow; 
  Player p;
  int level;
  int levelChoose;
public:
  //
  std::vector<int> partie; //present les 5 partie on veut realiser. par exemple, si partie[1]=1,on a deja reussir le partie 1; 
  MRoom2(Player p_):p(p_){
    resultFin=0;
    levelChoose=0;
    //resultNow=0;
    for (int i=0;i<5;i++) partie.push_back(0);
  }
  
  void setResultFin(int i){this->resultFin=i;}
  int getResultFin(){return this->resultFin;}
  int getLevel(){return this->level;}
  void setLevel(int i){this->level=i;}
  Player getPlayer(){return this->p;}
  int getLevelChoose(){return this->levelChoose;}
  void setLevelChoose(int i){this->levelChoose=i;}
  void Info(std::string str){ notifyObservers(str);}
  std::vector<std::string> getImageStringButton1();
  std::vector<std::string> getImageStringButton5();
  std::vector<int> randomNum(int num);
  void level_select(VRoom2 *v);
  void b_info(VRoom2 *v);
};
  

class MRoom3:public Observable<std::string>{
private:
  Gtk::Image img;
  int resultFin;
  bool isGetKey;
  //int resultNow; 
  Player p;
  int level;
  int levelChoose;  
public:
  //
  std::vector<int> partie; //present les 5 partie on veut realiser. par exemple, si partie[1]=1,on a deja reussir le partie 1; 
  MRoom3(Player p_):p(p_){
    resultFin=0;
    levelChoose=0;
    setIsGetKey(false);
    for (int i=0;i<5;i++) partie.push_back(0);
  }

  int getLevel(){return this->level;}
  void setLevel(int i){this->level=i;}
  Player getPlayer(){return this->p;}
  int getLevelChoose(){return this->levelChoose;}
  void setLevelChoose(int i){this->levelChoose=i;}
  void setResultFin(int i){this->resultFin=i;}
  int getResultFin(){return this->resultFin;}
  void setIsGetKey(bool b){this->isGetKey=b;}
  bool getIsGetKey(){return this->isGetKey;}  
  /*    
void permuterImage(std::string str){
    notifyObservers(str);
    }*/
  void Info(std::string str){ notifyObservers(str);}
  // std::vector<std::string> getImageStringButton1();
  std::vector<std::string> getImageStringButton5();
  std::vector<int> randomNum(int num);
  void level_select(VRoom3 *v);
  void b_info(VRoom3 *v);
};
  
