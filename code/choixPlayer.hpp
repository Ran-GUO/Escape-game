/**
 *choixPlayer.hpp
 *
 *@author GUO Ran
 *04/05/2020
 */
#pragma once

#include<gtkmm/button.h>
#include<gtkmm/window.h>
#include<gtkmm/box.h>
#include<gtkmm/entry.h>
#include<gtkmm/label.h>
#include<gtkmm/radiobutton.h>
#include<iostream>
#include"player.hpp"
#include"myMysql.hpp"

class ChoixPlayer:public Gtk::Window{
public:
  Player p;
  Gtk::RadioButton bRadio1,bRadio2,bRadio3;
  Gtk::Box box1,box2;
  Gtk::Button bOk;
  Gtk::Label label;

  void on_button_ok(){hide();}
  ChoixPlayer(Player p_):
    p(p_),
    box1(Gtk::ORIENTATION_VERTICAL),
    box2(Gtk::ORIENTATION_VERTICAL),
    bOk("OK"),
    bRadio1("Room1"),
    bRadio2("Room2"),
    bRadio3("Room3"),
    label("Choisez le level, si vous voulez continuer choisez le plus grand: ",true)
  {
    set_default_size(400,200);
    set_position(Gtk::WIN_POS_CENTER);
    set_title("Level of the game 'room escape'");
    switch(p.getLevel()){
    case(0):{
      box1.pack_start(label);
      box1.pack_start(bRadio1);
    
      bRadio1.set_active();
      break;
    }
    case(1):{
      bRadio2.join_group(bRadio1);

      box1.pack_start(label);
      box1.pack_start(bRadio1);
      box1.pack_start(bRadio2);
      
      bRadio2.set_active();
      break;
    }
    default:{
      bRadio2.join_group(bRadio1);
      bRadio3.join_group(bRadio1);

      box1.pack_start(label);
      box1.pack_start(bRadio1);
      box1.pack_start(bRadio2);
      box1.pack_start(bRadio3);
      
      bRadio3.set_active();
      break;
    }
  }
    bOk.signal_clicked().connect(sigc::mem_fun(*this,&ChoixPlayer::on_button_ok));
      box2.pack_start(box1);
      box2.pack_start(bOk);

      add(box2);
      show_all_children();
  }
  int getLevel(){
      if(bRadio1.get_active()){
        return 1;
      }
      else if(bRadio2.get_active()){
	return 2;
      }
      else if(bRadio3.get_active()){
	return 3;
      }
      else return 1;
  }

};
  
