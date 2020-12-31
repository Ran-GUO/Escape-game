/**
 *controleur3.cpp
 *@author:GUO Ran 
 *29/05/2020
 */
#include"controleur.hpp"

void CRoom3::on_button_boite2(){
    
    Gtk::MessageDialog dialog(*v,"Essayez ouvrir la porte pour escape from room 3!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    Gtk::Image *imgg=new Gtk::Image("image/room3/b2.png");
    dialog.set_image(*imgg);
    imgg->show();
    dialog.add_button("ok",1);
    int result=dialog.run();
    if (result==1){
       if (m->getIsGetKey()){
        Gtk::MessageDialog dialog(*v,"Info(Room3):Reussir! Vous avez fini tous les level!!! Voulez vous choisir d'autre level ou partir?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
        Gtk::Image *imgg2=new Gtk::Image("image/room3/b2.png");
        dialog.set_image(*imgg2);
        imgg2->show();
	dialog.add_button("choisit d'autre level",1);
	dialog.add_button("partir",0);
	int result2=dialog.run();
	if(result2==1){
	m->setResultFin(1);
	}
	else{
	   Gtk::MessageDialog dialog3(*v,"Au revoir! Bye!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	   dialog3.run();
	}
        m->Info("Info(Room3):Reussir! Vous avez fini tous les level!!");
	dialog.hide();
        v->on_button_close();
       }
        else{
	Gtk::MessageDialog dialog(*v,"Info(Room1):Vous n'avez pas trouver le cle, Veuillez chercher les autres traces.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
        dialog.run();
	m->Info("Info(Room1):Vous n'avez pas trouver le cle, Veuillez chercher les autres traces.");
	dialog.hide();
      }
   }
}
  
void CRoom3::on_button_boite1(){
   
    m->Info("Info(Room3):Bienvenu!");
    Gtk::MessageDialog dialog(*v,"",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    Gtk::Image *imgg=new Gtk::Image("image/room3/picture.jpg");
    dialog.set_image(*imgg);
    imgg->show();
    dialog.run();
   
      if (m->partie[0]==0){
      m->partie[0]=1;
      }
      else
      m->Info("Info(Room3):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
     
      dialog.hide();
  }

void CRoom3::on_button_boite3(){
     Gtk::Image *imgg=new Gtk::Image("image/room3/password.png");
    // m->permuterImage("pic/img4.jpeg");
    m->Info("Info(Room3):Bienvenu!");
    Gtk::MessageDialog dialog(*v,"entrez le code de ce boite,SVP?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
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
    case (2):{
      int result1=dialog.run();
	switch (result1){
	case(0):{
	       int result2=dialog.run();
	       switch (result2){
	       case(2):{
                     int result3=dialog.run();
		     switch (result3){
		     case(0):{
			
		        if (m->partie[1]==0){
			  m->Info("Info(Room3):Code bonbonbon!");
			  m->partie[1]=1;
			 Gtk::MessageDialog dialog(*v,"Info(Room3):Correct! Vous avez trouve un stick, essyez de l'utilisez!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/stick.jpg");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			}
			else{
			Gtk::MessageDialog dialog(*v,"Info(Room2):Vous avez deja trouve un stick, veuillez chercher les autres traces!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/stick.jpg");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        m->Info("Info(Room3):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
			}
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room3):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room3):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room3):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room3):Code faut0!");
      break;
       }
    }   
  }
void CRoom3::on_button_boite4(){
    Gtk::Image *imgg=new Gtk::Image("image/room3/CD.jpg"); 
    Gtk::Image *imgg2=new Gtk::Image("image/room3/b4.png"); 
    m->Info("Info(Room3):Partie 4:under a bed. ");
    if (m->partie[1]==1){
       Gtk::MessageDialog dialog(*v,"Oh, I get it!!!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
       dialog.set_image(*imgg);
       imgg->show();
       dialog.run();
       if(m->partie[2]==0) m->partie[2]=1;
       m->Info("Info(Room3):Bravo!");
    }
    else{
       Gtk::MessageDialog dialog(*v,"Comment on peut obtenir le CD? ",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
       dialog.set_image(*imgg2);
       imgg2->show();
       dialog.run();
       m->Info("Info(Room3):Comment on peut obtenir le CD? "); 
    }
	 
  }
void CRoom3::on_button_boite5(){
    
    m->Info("Info(Room3):Partie 5.");
     Gtk::Image *imgg=new Gtk::Image("image/room3/rainbow.png");
    Gtk::MessageDialog dialogg(*v,"",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_OK);
    dialogg.set_image(*imgg);
    imgg->show();
    
    Gtk::MessageDialog dialog(*v,"Ah, mon cher(e) ami(e), comment allez vous? Selectionnez des images afin de generer un image 'rainbow'",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    
    Gtk::Button bChoix[4];   
    std::vector<std::string> v1=m->getImageStringButton5();
    for(int i=0;i<4;i++){
      Gtk::Image *image=new Gtk::Image(v1[i]);
      bChoix[i].set_image(*image);
      image->show();
      
      }
    std::vector<int> v2=m->randomNum(4);
    for(int j=0;j<4;j++){
      int i=v2[j];
      dialog.add_action_widget(bChoix[i],i);
      bChoix[i].show();
    }
    if (m->partie[2]==1){
    dialogg.run();
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
                         Gtk::MessageDialog dialog(*v,"Info(Room3):Ah ha, mon ami, Je m'appelle Anne",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/rainbow.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			 m->Info("Info(Room3):Ah ha, mon ami, Je m'appelle Anne!");
			 m->partie[3]=1;
		       }
			else{
			Gtk::MessageDialog dialog(*v,"Info(Room3):Ah ha, mon ami, tu a oublie ? Je m'appelle Anne! veuillez chercher les autres traces!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/rainbow.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        m->Info("Info(Room3):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
			}
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room3):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room3):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room3):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room3):Code faut0!");
      break;
       }
    }
    }
    else{
       Gtk::MessageDialog dialog2(*v,"Vous avez pas de CD, essayez de le chercher.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
       dialog2.run();
       m->Info("Info(Room3):Vous avez pas de CD, essayez de le chercher. ");
    }
   
  }
void CRoom3::on_button_boite6(){
    Gtk::Image *imgg=new Gtk::Image("image/room3/password2.png");
    Gtk::MessageDialog dialog(*v,"wow! Il y a un coffre-fort ici!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.set_image(*imgg);
    imgg->show();
    
    dialog.add_button("C",0);
    dialog.add_button("F",1);
    dialog.add_button("N",2);
    dialog.add_button("U",3);
    dialog.add_button("R",4);
    dialog.add_button("E",5);
    dialog.add_button("O",6);
    dialog.add_button("W",7);
    dialog.add_button("A",8);
    dialog.add_button("X",9);
  
    //dialog.add_button("ok",10);
    int result0=dialog.run();
    std::string code;
    switch(result0){
    case (8):{
      int result1=dialog.run();
	switch (result1){
	case(2):{
	       int result2=dialog.run();
	       switch (result2){
	       case(2):{
                     int result3=dialog.run();
		     switch (result3){
		     case(5):{
		       if(!m->getIsGetKey()){
			 m->setIsGetKey(true);
		       }
		        if (m->partie[4]==0){
			  m->Info("Info(Room3):Code bonbonbon!");
			  m->partie[4]=1;
			 Gtk::MessageDialog dialog(*v,"Info(Room3):Correct! Vous avez trouve la cle, essyez de l'utilisez!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/key.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			}
			else{
			Gtk::MessageDialog dialog(*v,"Info(Room3):Vous avez deja trouve la cle, veuillez chercher le port!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/room3/key.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        m->Info("Info(Room3):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
			}
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room3):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room3):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room3):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room3):Code faut0!");
      break;
       }
    }   
}
void CRoom3::on_button_info(){
  m->b_info(this->v);
}

void CRoom3::on_button_level(){
    // m->permuterImage("pic/img3.jpeg");
    // m->Info("Info(Room1):Bienvenu!");
  m->level_select(this->v);
  }

void CRoom3::on_button_exit(){
    v->on_button_close();
  }
