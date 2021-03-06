/**
 *  vue.cpp
 *
 *  @author: GUO Ran
 *  04/05/2020
 */

#include<iostream>
#include<iomanip>
#include"vue.hpp"
#include"controleur.hpp"


VRoom3::VRoom3():
  box1(Gtk::ORIENTATION_HORIZONTAL),
  box2(Gtk::ORIENTATION_VERTICAL),
  box3(Gtk::ORIENTATION_HORIZONTAL),
  box4(Gtk::ORIENTATION_HORIZONTAL),
  //bBoite1("boite1"),
  //bBoite2("boite2"),
  //bBoite3("boite3"),
  bLevel("select level"),
  bClose("close"),
  bInfo("Info")
  //img("pic/img3.jpeg")
  
{
  set_size_request(300,200);
  set_default_size(300,200);
  set_title("Room3");

  Gtk::Image *img1=new Gtk::Image("image/room3/b1.png");
  Gtk::Image *img2=new Gtk::Image("image/room3/b2.png");
  Gtk::Image *img3=new Gtk::Image("image/room3/b3.png");
  Gtk::Image *img4=new Gtk::Image("image/room3/b4.png");
  Gtk::Image *img5=new Gtk::Image("image/room3/b5.png");
  Gtk::Image *img6=new Gtk::Image("image/room3/b6.png");
  //bouttons:
   bBoite1.set_image(*img1);
   bBoite2.set_image(*img2);
   bBoite3.set_image(*img3);
   bBoite4.set_image(*img4);
   bBoite5.set_image(*img5);
   bBoite6.set_image(*img6);
   img1->show();
   img2->show();
   img3->show();
   img4->show();
   img5->show();
   img6->show();
   
   //  bBoite1.set_image(iBoite1);
  //  bBoite2.set_image(iBoite2);
  //entry
  entry.set_max_length(100);
  entry.set_text("Bienvenu a ROOM_ESCAPE: Room 2");
  entry.select_region(0, entry.get_text_length());
  
  box1.pack_start(bBoite1);
  box1.pack_start(bBoite2);
  box1.pack_start(bBoite3);
  box4.pack_start(bBoite4);
  box4.pack_start(bBoite5);
  box4.pack_start(bBoite6); 
  
  box3.pack_start(entry);
  // box3.pack_start(bCodeOk);
  //boutton close
  bClose.set_can_default();
  bClose.grab_default();

  
  box2.add(box1);
  box2.add(box4);
  box2.add(box3);
  box2.add(bInfo);
  box2.add(bLevel);
  box2.add(bClose);
  add(box2);
 
  show_all_children();
   Gtk::MessageDialog dialog(*this,"Bienvenue a room3!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
   Gtk::Image *imgg=new Gtk::Image("image/room3/all.png");
   dialog.set_image(*imgg);
   imgg->show();
   dialog.run();
}

VRoom3::~VRoom3(){}

void VRoom3::setImg(std::string str){
  this->img.set(str);
  std::cout<<"je suis setImage:"<<str<<std::endl;
}

std::string VRoom3::getEntry() const {
  Glib::ustring text=entry.get_text();
  return text.c_str();
}

void VRoom3::setEntry(std::string str){
  Glib::ustring text =Glib::ustring::format(std::fixed,std::setprecision(2),str);
  entry.set_text(text);
}

void VRoom3::update(std::string str) {
  if (str[0]=='I' && str[1]=='n'){
    setEntry(str);
    std::cout<<"je suis update setEntry:"<<str<<std::endl;
  }
  else{
    setImg(str);
    std::cout<<"je suis update setImg:"<<str<<std::endl;
  }

}

void VRoom3::on_button_close(){hide();}
void VRoom3::addBoite1Listener(CRoom3 *c){
  bBoite1.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite1));
}
void VRoom3::addBoite2Listener(CRoom3 *c){
  bBoite2.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite2));
}
void VRoom3::addBoite3Listener(CRoom3 *c){
  bBoite3.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite3));
}
void VRoom3::addBoite4Listener(CRoom3 *c){
  bBoite4.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite4));
}
void VRoom3::addBoite5Listener(CRoom3 *c){
  bBoite5.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite5));
}
void VRoom3::addBoite6Listener(CRoom3 *c){
  bBoite6.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_boite6));
}
void VRoom3::addInfoListener(CRoom3 *c){
  bInfo.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_info));
}
void VRoom3::addLevelListener(CRoom3 *c){
  bLevel.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_level));
}
void VRoom3::addCloseListener(CRoom3 *c){
  bClose.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_exit));
}
/*
void VRoom3::addCodeOkListener(CRoom3 *c){
  bCodeOk.signal_clicked().connect(sigc::mem_fun(*c,&CRoom3::on_button_codeOk));
  }*/

