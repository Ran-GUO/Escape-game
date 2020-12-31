/**
 * @author GUO Ran
 */
#include"modele.hpp"

void MRoom1::level_select(VRoom1 *v){
   Gtk::MessageDialog dialog(*v,"Level select",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.add_button("Room1",1);
    dialog.add_button("Room2",2);
    dialog.add_button("Room3",3);
    int result=dialog.run();
    switch(result){
    case(1):{
      Gtk::MessageDialog dialog2(*v,"Vous etes dans room1 maintenent,voulez vous le recommencer?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
      dialog2.add_button("OUI",1);
      dialog2.add_button("NON",2);
      int result2=dialog2.run();
      if (result2==1){
      dialog2.hide();
      this->setLevel(1);
      this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
      else {dialog2.hide(); dialog.hide();}
      break;
    }
    case(2):{
      if(this->getPlayer().getLevel()>=1) {
	Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 2 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
        dialog2.add_button("OUI",1);
        dialog2.add_button("NON",2);
        int result2=dialog2.run();
        if (result2==1){ dialog2.hide(); this->setLevel(2);this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
        else{dialog2.hide();dialog.hide();}
      }
      else {
	std::string s=std::to_string(this->getPlayer().getLevel());
	Gtk::MessageDialog dialog2(*v,"Votre record le plus eleve est level "+s+", vous ne deverrouillez pas encore level 2.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	dialog2.run();
      }
      break;}
    case(3):{
      if(this->getPlayer().getLevel()>=2) {
	Gtk::MessageDialog dialog2(*v,"Vous etes sur aller a room 3 ?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE); 
        dialog2.add_button("OUI",1);
        dialog2.add_button("NON",2);
        int result2=dialog2.run();
        if (result2==1){ dialog2.hide(); this->setLevel(3);this->setLevelChoose(1); dialog.hide();  v->on_button_close();}
        else{dialog2.hide();dialog.hide();}
      }
      else {
	std::string s=std::to_string(this->getPlayer().getLevel());
	Gtk::MessageDialog dialog2(*v,"Votre record le plus eleve est level "+s+", vous ne deverrouillez pas encore level 3.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	dialog2.run();
      }
      break;}
    }
}

std::vector<std::string> MRoom1:: getImageStringButton5(){
    std::vector<std::string> s={"image/image0.png","image/image1.png","image/image2.png","image/image3.png","image/image4.png","image/image5.png","image/image6.png","image/image7.png","image/image8.png","image/image9.png","image/image10.png","image/image11.png"};
    return s;
  }

std::vector<std::string> MRoom1::getImageStringButton6(){
     std::vector<std::string> s={"image/charac0.png","image/charac1.png","image/charac2.png","image/charac3.png","image/charac4.png","image/charac5.png","image/charac6.png"};
     return s;
   }
  
std::vector<int>  MRoom1::randomNum(int num){
    std::vector<int> temp;
    for(int i=0;i<num;++i){
      temp.push_back(i);
    }
    random_shuffle(temp.begin(),temp.end());
    return temp;
 }

void MRoom1::b_info(VRoom1 *v){
    Gtk::MessageDialog dialog(*v,"INFO",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.add_button("player",1);
    dialog.add_button("room1",2);
    int result=dialog.run();
    if (result==1){
      Gtk::MessageDialog dialog2(*v,this->getPlayer().toString(),false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      dialog2.run();
    }
    else{
      Gtk::MessageDialog dialog2(*v,"Bienvenue a room1, je suis le proprietaire de ce room, j'ai perdu mes 5 pierres precieuses, Pourriez vous m'aider? Le porte va ouvrir si vous les tous trouvez.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      Gtk::Image *imgg=new Gtk::Image("image/all.jpg");
      dialog2.set_image(*imgg);
      imgg->show();
      dialog2.run();
    }
}
