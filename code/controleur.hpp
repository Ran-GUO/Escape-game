/**
 *  controleur.hpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */
#pragma once

#include "modele.hpp"
#include "vue.hpp"
#include <string>
#include <iomanip>

class CRoom1{
private:
  MRoom1 *m;
  VRoom1 *v;
public:
  CRoom1(MRoom1 *mm,VRoom1 *vv):m(mm),v(vv){
    v->addBoite1Listener(this);
    v->addBoite2Listener(this);
    v->addBoite3Listener(this);
    v->addBoite4Listener(this);
    v->addBoite5Listener(this);
    v->addBoite6Listener(this);
    v->addInfoListener(this);
    v->addLevelListener(this);
    v->addCloseListener(this);
   
  }
  bool isFini();
  void EscapeRoom1();
  void on_button_boite2();
  void on_button_boite1();
  void on_button_boite3();
  void on_button_boite4();
  void on_button_boite5();
  void on_button_boite6();
  void on_button_level();
  void on_button_info();
  void on_button_exit();
};

class CRoom2{
private:
  MRoom2 *m;
  VRoom2 *v;
public:
  CRoom2(MRoom2 *mm,VRoom2 *vv):m(mm),v(vv){
    v->addBoite1Listener(this);
    v->addBoite2Listener(this);
    v->addBoite3Listener(this);
    v->addBoite4Listener(this);
    v->addBoite5Listener(this);
    v->addBoite6Listener(this);
    v->addLevelListener(this);
    v->addCloseListener(this);
    v->addInfoListener(this);
  }
  
  void on_button_boite2();
  void on_button_boite1();
  void on_button_boite3();
  void on_button_boite4();
  void on_button_boite5();
  void on_button_boite6();
  void on_button_info();
  void on_button_level();
  void on_button_exit();
 
};

class CRoom3{
private:
  MRoom3 *m;
  VRoom3 *v;
public:
  CRoom3(MRoom3 *mm,VRoom3 *vv):m(mm),v(vv){
    v->addBoite1Listener(this);
    v->addBoite2Listener(this);
    v->addBoite3Listener(this);
    v->addBoite4Listener(this);
    v->addBoite5Listener(this);
    v->addBoite6Listener(this);
    v->addInfoListener(this);
    v->addLevelListener(this);
    v->addCloseListener(this);
  }
  
  void on_button_boite2();
  void on_button_boite1();
  void on_button_boite3();
  void on_button_boite4();
  void on_button_boite5();
  void on_button_boite6();
  void on_button_level();
  void on_button_info();
  void on_button_exit();
 
};
