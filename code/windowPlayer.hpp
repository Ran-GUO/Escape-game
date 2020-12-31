/**
 *  windowPlayer.cpp
 *
 *  @author G.R
 *  03/05/2020
 */

#pragma once

#include<gtkmm/window.h>
#include<gtkmm/button.h>
#include<gtkmm/entry.h>
#include<gtkmm/box.h>
#include<gtkmm/label.h>
#include<iostream>
#include<vector>
#include"player.hpp"
#include"myMysql.hpp"



class WindowPlayer:public Gtk::Window{
private:
  Gtk::Box box1,box2,box3,box4,box5,box6;
  Gtk::Entry entry1,entry2;
  Gtk::Button bOk,bReset;
  Gtk::Label label1,label2;
  Player p;
  Mysql *server_mysql;
  void on_button_ok(){
    std::cout<<"Info(User): ok!"<<std::endl;
    p=Player(entry1.get_text(),entry2.get_text(),0);
    try{
      if(server_mysql->isExistPlayer(p)){
	if(server_mysql->isPasswordRight(p)){
	  std::cout<<"Info(User): Password ok! connection ok! Bienvenue!"<<std::endl;
	  Gtk::MessageDialog dialog(*this,"This user exist and the password is correct.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	  dialog.run();
	  hide();
	}
	else{
	   Gtk::MessageDialog dialog(*this,"This user exist but the password is incorrect!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
           dialog.run();
	   entry2.set_text("");
	}
      }
      else{
	server_mysql-> addPlayer(p);
	if(p.getName()==""){
	Gtk::MessageDialog dialog(*this,"Attention!Votre user name est vide!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
        dialog.run();
	}
	if(p.getPassword()==""){
	Gtk::MessageDialog dialog(*this,"Attention!Votre Password est vide!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
        dialog.run();
	}
	Gtk::MessageDialog dialog(*this,"This user do not exist,create a new user:\nname:'"+entry1.get_text()+"'\npassword:'"+entry2.get_text()+"'",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_OK);
        dialog.run();
	std::cout << "Info(User) player : \t"<<entry1.get_text()<<std::endl;
	std::cout << "Info(User) password : \t"<<entry2.get_text()<<std::endl;
	hide();
      }
    }
    catch(sql::SQLException &e){
      Mysql::exceptionCatch(e);
    }
  }
  void on_button_reset(){
    entry1.set_text("");
    entry2.set_text("");
  }
	
public:
  WindowPlayer(Mysql *server_mysql_):
    server_mysql(server_mysql_),
    bOk("Ok"),
    bReset("Reset"),
    box1(Gtk::ORIENTATION_VERTICAL),
    box2(Gtk::ORIENTATION_HORIZONTAL),
    box3(Gtk::ORIENTATION_HORIZONTAL),
    box4(Gtk::ORIENTATION_HORIZONTAL),
    box5(Gtk::ORIENTATION_HORIZONTAL),
    box6(Gtk::ORIENTATION_HORIZONTAL), 
    
    label1("name : ",true),
    label2("passeword : ",true){
   
    set_default_size(400,200);
    set_title("connect to escape room");
    entry1.set_max_length(50);
    entry2.set_max_length(50);

    box2.pack_start(label1);
    box3.pack_start(entry1);
    box4.pack_start(label2);
    box5.pack_start(entry2);
    box6.pack_start(bOk);
    box6.pack_start(bReset);
    bOk.set_focus_on_click();
    bOk.signal_clicked().connect(sigc::mem_fun(*this, &WindowPlayer::on_button_ok));
    bReset.signal_clicked().connect(sigc::mem_fun(*this, &WindowPlayer::on_button_reset));
    box1.pack_start(box2);
    box1.pack_start(box3);
    box1.pack_start(box4);
    box1.pack_start(box5);
    box1.pack_start(box6);
    add(box1);
    show_all_children();
  }

  Player getPlayer(){return this->p;}
};
