/**
 *controleur2.cpp
 *@author:GUO Ran
 *03/05/2020
 */
#include"controleur.hpp"

void CRoom2::on_button_boite2(){
    
    Gtk::MessageDialog dialog(*v,"Essayez ouvrir la porte pour escape from room 2!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    Gtk::Image *imgg=new Gtk::Image("image/room2/b2.jpg");
    dialog.set_image(*imgg);
    imgg->show();
     dialog.add_button("0",0);
    dialog.add_button("1",1);
    dialog.add_button("2",2);
    dialog.add_button("3",3);
    dialog.add_button("4",4);
    dialog.add_button("5",5);
    dialog.add_button("6",6);
    dialog.add_button("7",7);
    dialog.add_button("8",8);
    dialog.add_button("9",9);
  
    //dialog.add_button("ok",10);
    int result0=dialog.run();
    std::string code;
    switch(result0){
    case (0):{
      int result1=dialog.run();
	switch (result1){
	case(4):{
	       int result2=dialog.run();
	       switch (result2){
	       case(0):{
                     int result3=dialog.run();
		     switch (result3){
		     case(5):{
			 Gtk::MessageDialog dialog(*v,"Info(Room2):Reussir! Bienvenu a room 3!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                         dialog.run();
                         m->Info("Info(Room2):Reussir! Bienvenu a room 3!");
                         dialog.hide();
			 m->setResultFin(1);
                         v->on_button_close();
		         break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room2):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room2):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room2):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room2):Code faut0!");
      break;
       }
    }      
}
  
void CRoom2::on_button_boite1(){
   
    m->Info("Info(Room1):Bienvenu!");
    Gtk::MessageDialog dialog(*v,"Cher ami,cliquez les bouttons au dessous,il y a 2 drapeaux, pourriez vous m'aider les trouver? Et puis je vais vous donner une bonne trace.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);

    Gtk::Button bChoix[10];   
    std::vector<std::string> v1=m->getImageStringButton1();
    std::vector<Gtk::Image*> image={new Gtk::Image(v1[0]),new Gtk::Image(v1[1]),new Gtk::Image(v1[2])};
    
    std::vector<int> v2=m->randomNum(10);
    for(int j=0;j<10;j++){
      int i=v2[j];
      dialog.add_action_widget(bChoix[i],i);
      bChoix[i].show();
    }
    int num1=0,num2=0;
    while(num1==0 || num2==0){
    int result0=dialog.run();
    switch(result0){
      case(0):{bChoix[0].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(1):{bChoix[1].set_image(*image[1]);image[1]->show();m->Info("Info(Room2):Bravo!C'est bon!");num1=1; break;}
      case(2):{bChoix[2].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(3):{bChoix[3].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(4):{bChoix[4].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(5):{bChoix[5].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(6):{bChoix[6].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(7):{bChoix[7].set_image(*image[2]);image[2]->show();m->Info("Info(Room2):Bravo!C'est bon");num2=1; break;}
      case(8):{bChoix[8].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
      case(9):{bChoix[9].set_image(*image[0]);image[0]->show();m->Info("Info(Room2):Boum!Boum!Boum! Attention!!!"); break;}
    }
    }
   
      if (m->partie[0]==0){
      m->partie[0]=1;
      }
      else
      m->Info("Info(Room2):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
      Gtk::MessageDialog dialog2(*v,"Bonjour! Mon cher ami, je suis ne en 1789.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      dialog2.run();
      dialog.hide();
  }
void CRoom2::on_button_boite3(){
     Gtk::Image *imgg=new Gtk::Image("image/room2/b3.jpg");
    // m->permuterImage("pic/img4.jpeg");
    m->Info("Info(Room2):Bienvenu!");
    Gtk::MessageDialog dialog(*v,"entrez le code de ce boite,SVP?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.set_image(*imgg);
    imgg->show();
    
    dialog.add_button("0",0);
    dialog.add_button("1",1);
    dialog.add_button("2",2);
    dialog.add_button("3",3);
    dialog.add_button("4",4);
    dialog.add_button("5",5);
    dialog.add_button("6",6);
    dialog.add_button("7",7);
    dialog.add_button("8",8);
    dialog.add_button("9",9);
  
    //dialog.add_button("ok",10);
    int result0=dialog.run();
    std::string code;
    switch(result0){
    case (1):{
      int result1=dialog.run();
	switch (result1){
	case(7):{
	       int result2=dialog.run();
	       switch (result2){
	       case(8):{
                     int result3=dialog.run();
		     switch (result3){
		     case(9):{
			
		        if (m->partie[1]==0){
			  m->Info("Info(Room2):Code bonbonbon!");
			  m->partie[1]=1;
			 Gtk::MessageDialog dialog(*v,"Info(Room2):Correct! Vous avez trouve un telecommand,essyez de l'utilisez!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room2/tcd.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			}
			else{
			Gtk::MessageDialog dialog(*v,"Info(Room2):Vous avez deja trouve un telecommand, veuillez chercher les autres traces!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room2/tcd.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        m->Info("Info(Room2):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
			}
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room2):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room2):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room2):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room2):Code faut0!");
      break;
       }
    }   
  }
void CRoom2::on_button_boite4(){
    Gtk::Image *imgg=new Gtk::Image("image/room2/TV_2.png"); 

    m->Info("Info(Room2):Partie 4:un TV ");
    if (m->partie[1]==1){
    Gtk::MessageDialog dialog(*v,"",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.set_image(*imgg);
    imgg->show();
    dialog.run();
    if(m->partie[2]==0) m->partie[2]=1;
    m->Info("Info(Room2):Bravo!");
    }
    else{
       Gtk::MessageDialog dialog(*v,"Vous avez pas de telecommand, essayez de le chercher.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
       dialog.run();
       m->Info("Info(Room2):Vous avez pas de telecommand, essayez de le chercher. "); 
    }
	 
  }
void CRoom2::on_button_boite5(){
    
    m->Info("Info(Room2):Partie 5.");
    Gtk::MessageDialog dialog(*v,"Ah, mon cher(e) ami(e), comment allez vous?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    
    Gtk::Button bChoix[8];   
    std::vector<std::string> v1=m->getImageStringButton5();
    for(int i=0;i<8;i++){
      Gtk::Image *image=new Gtk::Image(v1[i]);
      bChoix[i].set_image(*image);
      image->show();
      
      }
    std::vector<int> v2=m->randomNum(8);
    for(int j=0;j<8;j++){
      int i=v2[j];
      dialog.add_action_widget(bChoix[i],i);
      bChoix[i].show();
    }
    int result0=dialog.run();
    switch(result0){
    case (0):{
      int result1=dialog.run();
	switch (result1){
	case(1):{
	       int result2=dialog.run();
	       switch (result2){
	       case(2):{
                     int result3=dialog.run();
		     switch (result3){
		     case(3):{
		       if (m->partie[3]==0){
                         Gtk::MessageDialog dialog(*v,"Info(Room2):Correct! Vous avez trouve un cable d'iphone,essyez de l'utilisez!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room2/cable.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			 m->Info("Info(Room2):Correct! Vous avez trouve un cable d'iphone,essyez de l'utilisez!");
			 m->partie[3]=1;
		       }
			else{
			Gtk::MessageDialog dialog(*v,"Info(Room2):Vous avez deja trouve un cable d'iphone, veuillez chercher les autres traces!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room2/cable.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        m->Info("Info(Room2):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
			}
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room2):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room2):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room2):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room2):Code faut0!");
      break;
       }
    }    
   
  }
void CRoom2::on_button_boite6(){
    Gtk::Image *imgg=new Gtk::Image("image/room2/phone_2.png"); 

    m->Info("Info(Room2):Partie 6:un Phone ");
    if (m->partie[3]==1){
    Gtk::MessageDialog dialog(*v,"",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    dialog.set_image(*imgg);
    imgg->show();
    dialog.run();
    if(m->partie[4]==0) m->partie[4]=1;
    m->Info("Info(Room2):Bravo!");
    }
    else{
       Gtk::MessageDialog dialog(*v,"Vous avez pas de cable, essayez de le chercher.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
       dialog.run();
       m->Info("Info(Room2):Vous avez pas de cable, essayez de le chercher. "); 
    }	 
}

void CRoom2::on_button_info(){
  m->b_info(this->v);
}

void CRoom2::on_button_level(){
  m->level_select(this->v);
  // m->Info("Info(Room1):Bienvenu!");
  }

void CRoom2::on_button_exit(){
    v->on_button_close();
  }
