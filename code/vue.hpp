/**
 *  vue.hpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */
#include"observer.hpp"
#pragma once

#include<gtkmm/button.h>
#include<gtkmm/window.h>
#include<gtkmm/messagedialog.h>
#include<gtkmm/box.h>
#include<gtkmm/entry.h>

#include<string>


class CRoom1;

class VRoom1: public Gtk::Window,public Observer<std::string>{
private:
  Gtk::Box box1,box2,box3,box4;
  Gtk::Button bBoite1,bBoite2,bBoite3,bBoite4,bBoite5,bBoite6,bClose,bLevel,bInfo;
  Gtk::Entry entry;
  Gtk::Image img;
public:
  VRoom1();
  ~VRoom1();
  //  Gtk::Image &getIDoor1() {return this->iDoor1;}
  //Gtk::Image &getIBoite1() {return this->iBoite1;}
  std::string getEntry() const;
  void setEntry(std::string);
  Gtk::Image &getImg() {return this->img;}
  void setImg(std::string str);
  void update(std::string str) override;
  
  void addBoite1Listener(CRoom1 *c);
  void addBoite2Listener(CRoom1 *c);
  void addBoite3Listener(CRoom1 *c);
  void addBoite4Listener(CRoom1 *c);
  void addBoite5Listener(CRoom1 *c);
  void addBoite6Listener(CRoom1 *c);
  void addInfoListener(CRoom1 *c);
  void addLevelListener(CRoom1 *c);
  void addCloseListener(CRoom1 *c);
  void on_button_close();
};

class CRoom2;

class VRoom2: public Gtk::Window,public Observer<std::string>{
private:
  Gtk::Box box1,box2,box3,box4;
  Gtk::Button bBoite1,bBoite2,bBoite3,bBoite4,bBoite5,bBoite6,bClose,bLevel,bInfo;
  Gtk::Entry entry;
  Gtk::Image img;
public:
  VRoom2();
  ~VRoom2();
  std::string getEntry() const;
  void setEntry(std::string);
  Gtk::Image &getImg() {return this->img;}
  void setImg(std::string str);
  void update(std::string str) override;
  
  void addBoite1Listener(CRoom2 *c);
  void addBoite2Listener(CRoom2 *c);
  void addBoite3Listener(CRoom2 *c);
  void addBoite4Listener(CRoom2 *c);
  void addBoite5Listener(CRoom2 *c);
  void addBoite6Listener(CRoom2 *c);
  void addInfoListener(CRoom2 *c);
  void addLevelListener(CRoom2 *c);
  // void addCodeOkListener(CRoom2 *c);
  void addCloseListener(CRoom2 *c);
  void on_button_close();
};



class CRoom3;

class VRoom3: public Gtk::Window,public Observer<std::string>{
private:
  Gtk::Box box1,box2,box3,box4;
  Gtk::Button bBoite1,bBoite2,bBoite3,bBoite4,bBoite5,bBoite6,bClose,bLevel,bInfo;
  Gtk::Entry entry;
  Gtk::Image img;
public:
  VRoom3();
  ~VRoom3();
  std::string getEntry() const;
  void setEntry(std::string);
  Gtk::Image &getImg() {return this->img;}
  void setImg(std::string str);
  void update(std::string str) override;
  
  void addBoite1Listener(CRoom3 *c);
  void addBoite2Listener(CRoom3 *c);
  void addBoite3Listener(CRoom3 *c);
  void addBoite4Listener(CRoom3 *c);
  void addBoite5Listener(CRoom3 *c);
  void addBoite6Listener(CRoom3 *c);
  void addInfoListener(CRoom3 *c);
  void addLevelListener(CRoom3 *c);
  //void addCodeOkListener(CRoom3 *c);
  void addCloseListener(CRoom3 *c);
  void on_button_close();
};

