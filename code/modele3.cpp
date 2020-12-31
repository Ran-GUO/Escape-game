/**
 * @author: GUO Ran
 */

#include"modele.hpp"
#include <gtkmm/widget.h>

/*std::vector<std::string> MRoom3::getImageStringButton1(){
    std::vector<std::string> s={"image/non.png","image/oui.png","image/oui.png"};
    return s;
    }*/
std::vector<std::string> MRoom3::getImageStringButton5(){
    std::vector<std::string> s={"image/room3/r1.png","image/room3/r2.png","image/room3/r3.png","image/room3/r4.png"};
    return s;
  }
  
std::vector<int> MRoom3::randomNum(int num){
    std::vector<int> temp;
    for(int i=0;i<num;++i){
      temp.push_back(i);
    }
    random_shuffle(temp.begin(),temp.end());
    return temp;
 }


void MRoom3::level_select(VRoom3 *v){
   Gtk::MessageDialog dialog(*v,"Level select",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.add_button("Room1",1);
    dialog.add_button("Room2",2);
    dialog.add_button("Room3",3);
    int result=dialog.run();
    switch(result){
    case(3):{
      Gtk::MessageDialog dialog2(*v,"Vous etes dans room3 maintenent,voulez vous le recommencer?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){
      dialog2.hide();
      this->setLevel(3);
      this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
      else {dialog2.hide(); dialog.hide();}
      break;
    }
    case(2):{
      Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 2 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){ dialog2.hide(); this->setLevel(2);this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
      else {dialog2.hide(); dialog.hide();}
      break;}
    case(1):{
       Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 1 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){ dialog2.hide(); this->setLevel(1);this->setLevelChoose(1); dialog.hide();  v->on_button_close(); }
      else {dialog2.hide();dialog.hide();}
      break;}
    }
  }

void MRoom3::b_info(VRoom3 *v){
    Gtk::MessageDialog dialog(*v,"INFO",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.add_button("player",1);
    dialog.add_button("room3",2);
    int result=dialog.run();
    if (result==1){
      Gtk::MessageDialog dialog2(*v,this->getPlayer().toString(),false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog2.run();
    }
    else{
      Gtk::MessageDialog dialog2(*v,"Bienvenue a room3.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      Gtk::Image *imgg=new Gtk::Image("image/room3/all.png");
      dialog2.set_image(*imgg);
      imgg->show();
      dialog2.run();
    }
}
