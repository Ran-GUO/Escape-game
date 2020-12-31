/**
 *@author: GUO Ran
 */
#include"modele.hpp"

std::vector<std::string> MRoom2::getImageStringButton1(){
    std::vector<std::string> s={"image/non.png","image/oui.png","image/oui.png"};
    return s;
  }
std::vector<std::string> MRoom2::getImageStringButton5(){
    std::vector<std::string> s={"image/room2/c1.png","image/room2/c2.png","image/room2/c3.png","image/room2/c4.png","image/room2/c5.png","image/room2/c6.png","image/room2/c7.png","image/room2/c8.png"};
    return s;
  }
  
std::vector<int> MRoom2::randomNum(int num){
    std::vector<int> temp;
    for(int i=0;i<num;++i){
      temp.push_back(i);
    }
    random_shuffle(temp.begin(),temp.end());
    return temp;
 }

void MRoom2::level_select(VRoom2 *v){
   Gtk::MessageDialog dialog(*v,"Level select",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.add_button("Room1",1);
    dialog.add_button("Room2",2);
    dialog.add_button("Room3",3);
    int result=dialog.run();
    switch(result){
    case(2):{
      Gtk::MessageDialog dialog2(*v,"Vous etes dans room2 maintenent,voulez vous le recommencer?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){
      dialog2.hide();
      this->setLevel(2);
      this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
      else {dialog2.hide(); dialog.hide();}
      break;
    }
    case(1):{
      Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 1 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){ dialog2.hide(); this->setLevel(1);this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
      else{dialog2.hide(); dialog.hide();}
      break;}
    case(3):{
      if(this->getPlayer().getLevel()>=2) {
	 Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 3 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
         dialog2.add_button("OUI",1);
         dialog2.add_button("NON",2);
         int result2=dialog2.run();
         if (result2==1){ dialog2.hide();this->setLevel(3);this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
	 else{ dialog2.hide();dialog.hide();}
      }
      else {
	std::string s=std::to_string(this->getPlayer().getLevel());
	Gtk::MessageDialog dialog2(*v,"Votre record le plus eleve est level "+s+", vous ne deverrouillez pas encore level 3.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	dialog2.run();
      }
      break;}
    }
  }

void MRoom2::b_info(VRoom2 *v){
    Gtk::MessageDialog dialog(*v,"INFO",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.add_button("player",1);
    dialog.add_button("room2",2);
    int result=dialog.run();
    if (result==1){
      Gtk::MessageDialog dialog2(*v,this->getPlayer().toString(),false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      dialog2.run();
    }
    else{
      Gtk::MessageDialog dialog2(*v,"Bienvenue a room2, le port va ouvrir si vous entrez le mot de pass.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      Gtk::Image *imgg=new Gtk::Image("image/room2/all.jpg");
      dialog2.set_image(*imgg);
      imgg->show();
      dialog2.run();
    }
}
