/**
 *  player.cpp
 *
 *  @author GUO Ran
 *  03/05/2020
 */
#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<sstream>

class Player{
private:
  std::string name;
  std::string password;
  int level;
public:
  Player(std::string name_, std::string password_,int level_):name(name_),password(password_),level(level_){}
  Player(){
    name="User unKnow";
    password="000000";
    level=0;
  }
  std::string getName()const{return name;}
  std::string getPassword()const{return password;}
  int getLevel()const{return level;}
  void setName(std::string str){ name=str;}
  void setPassword(std::string str){ password=str;}
  void setLevel(int i){level=i;}

  std::string toString() const{
    std::ostringstream s;
    s<<this->getName()<<"\t\t the highest level : "<<this->getLevel();
    return s.str();
  }

  friend std::ostream& operator<<(std::ostream &os,const Player &p){
    os<<"player : \t"<< p.toString();
    return os;
  }
};
  
