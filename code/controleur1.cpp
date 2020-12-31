/**
 *
 *@author:GUO Ran
 *03/05/2020
 */
#include"controleur.hpp"

bool CRoom1::isFini(){
    if (m->getResultNow()==5)
      m->setResultFin(1);
    return  m->getResultFin();
  }

void CRoom1::EscapeRoom1(){
    std::cout<<"--------------------------Info(Room1):Vous avez fini "<<m->getResultNow()<<" parties maintenent. Bon courage!-----------"<<std::endl;
    if(isFini()) {
      m->Info("Info(Room1):Vous avez trouvez le cle! Cherchez la porte,SVP.");
      Gtk::MessageDialog dialog(*v,"Bravo! Vous avez trouvez le cle! Cherchez la porte,SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      dialog.run();
    }
  }
void CRoom1::on_button_boite2(){
    
    Gtk::MessageDialog dialog(*v,"Essayez de ouvrir la porte. Cliquez Ok.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
    Gtk::Image *imgg=new Gtk::Image("image/b2.jpg");
    dialog.set_image(*imgg);
    imgg->show();
    dialog.add_button("ok",1);
    int result=dialog.run();
    if(result ==1){
      if(isFini()){
      Gtk::MessageDialog dialog(*v,"Info(Room1):Reussir! Bienvenu a room 2!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      Gtk::Image *imgg2=new Gtk::Image("image/fin.png");
      dialog.set_image(*imgg2);
      imgg2->show();
      dialog.run();
      m->Info("Info(Room1):Reussir! Bienvenu a room 2!");
      dialog.hide();
      v->on_button_close();
      }
      else{
	std::string s=std::to_string(m->getResultNow()) ;
	Gtk::MessageDialog dialog(*v,"Info(Room1):Vous n'avez pas trouver le cle, Veuillez chercher les autres traces.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
	dialog.set_message("Vous n'avez pas trouver le cle, Veuillez chercher les autres traces.Vous avez trouve "+s+" pierres precieuses.", false);
        dialog.run();
	m->Info("Info(Room1):Vous n'avez pas trouver le cle, Veuillez chercher les autres traces.");
	dialog.hide();
      }
     }
  }
void CRoom1::on_button_boite1(){
    Gtk::Image *imgg=new Gtk::Image("image/b1.jpg");
    // m->permuterImage("pic/img2.jpeg");
    m->Info("Info(Room1):Bienvenu!");
    Gtk::MessageDialog dialog(*v,"Je suis le(la) proprietaire de cette chambre,Je m'appelle?",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.set_image(*imgg);
    imgg->show();
    dialog.add_button("Anne",1);
    dialog.add_button("Mark",2);
    dialog.add_button("Philippe",3);
    dialog.add_button("Luc",4);
    dialog.add_button("Camille",5);
    dialog.add_button("Howard",6);
    dialog.add_button("Antoine",7);
    dialog.add_button("Yann",7);
    int result=dialog.run();
    switch(result){
    case(4):{
       Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus bleu!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
      Gtk::Image *imgg2=new Gtk::Image("image/p1.png");
      dialog.set_image(*imgg2);
      imgg2->show();
      dialog.run();
      
      if (m->partie[0]==0){
      m->Info("Info(Room1):Correct!Je suis Luc!");
      m->ResultNowPlusPlus();
      m->partie[0]=1;
      }
      else
      m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
      EscapeRoom1();
      dialog.hide();
      break;
  }
    default:{
      Gtk::MessageDialog dialog(*v,"NON!C'est pas moi!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room1):NON!C'est pas moi!");
      dialog.hide();
      break;
    }
    }
  }
void CRoom1::on_button_boite3(){
    Gtk::Image *imgg=new Gtk::Image("image/b3.jpg");
    // m->permuterImage("pic/img4.jpeg");
    m->Info("Info(Room1):Bienvenu!");
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
	case(0):{
	       int result2=dialog.run();
	       switch (result2){
	       case(0):{
                     int result3=dialog.run();
		     switch (result3){
		     case(6):{
		        Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus rouge!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/p2.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
			
		        if (m->partie[1]==0){
			  m->Info("Info(Room1):Code bonbonbon!");
			  m->ResultNowPlusPlus();
			  m->partie[1]=1;
			}
			else
			  m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
		       
		       EscapeRoom1();
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room1):Code faut3!");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room1):Code faut2!");
		 break;
	       }
	       }
	       break;
	}
	default:{
	Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room1):Code faut1!");
	break;
	}
        }
      break;
      }
      default:{
      Gtk::MessageDialog dialog(*v,"Code faut!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room1):Code faut0!");
      break;
       }
    }  
  }
void CRoom1::on_button_boite4(){
    Gtk::Image *imgg=new Gtk::Image("image/color1.png");
    
    // m->permuterImage("pic/img1.jpeg");
    m->Info("Info(Room1):Partie 4:un jeux de memoire ");
    Gtk::MessageDialog dialog(*v,"Un jeux de memoire: pourriez vous voir cette image et le souvenez, puis cliquez next.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.set_image(*imgg);
    imgg->show();
    dialog.add_button("next",1);
    int result=dialog.run();
    if (result==1) dialog.hide();

    imgg=new Gtk::Image("image/color2.png");
    Gtk::MessageDialog dialog2(*v,"Cette couleur est dans quelle ligne et quelle colone?(On met la premiere ligne=0;la premiere colone=0.Donc dans l'image avant,il y a des lignes [[0,4]], et colones [[0,9]].)",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog2.set_image(*imgg);
    imgg->show();
    dialog2.add_button("0",0);
    dialog2.add_button("1",1);
    dialog2.add_button("2",2);
    dialog2.add_button("3",3);
    dialog2.add_button("4",4);
    dialog2.add_button("5",5);
    dialog2.add_button("6",6);
    dialog2.add_button("7",7);
    dialog2.add_button("8",8);
    dialog2.add_button("9",9);
    int result0=dialog2.run();
    switch(result0){
    case(3):{
      int result1=dialog2.run();
      switch(result1){
      case(7):{
	  Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus cyan!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
          Gtk::Image *imgg2=new Gtk::Image("image/p3.png");
          dialog.set_image(*imgg2);
          imgg2->show();
          dialog.run();
         if (m->partie[2]==0){
	    m->Info("Info(Room1):Reussir! Bravo! Vous avez une bonne memoire!");
    	    m->ResultNowPlusPlus();
	    m->partie[2]=1;
	  }
	  else
	    m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
         EscapeRoom1();

         dialog2.hide();
	 break;
      }
	default:{
	 Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
	 m->Info("Info(Room1):Faut! Ressaiyez, SVP.");
	 dialog2.hide();
	 break;
	}
      }
      break;
    }
   default:
        {
	 Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
	 m->Info("Info(Room1):Faut! Ressaiyez, SVP.");
	 dialog2.hide();
	 break;
	}
    }	    
	 
  }
void CRoom1::on_button_boite5(){
    
    m->Info("Info(Room1):Boite 5, un jeux d'oeil.");
    Gtk::MessageDialog dialog(*v,"Un jeux d'oeil : Pourriez vous choisir les 2 images qui sont identique",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    
    Gtk::Button bChoix[12];   
    std::vector<std::string> v1=m->getImageStringButton5();
    for(int i=0;i<10;i++){
      Gtk::Image *image=new Gtk::Image(v1[i]);
      bChoix[i].set_image(*image);
      image->show();
      
      }
    std::vector<int> v2=m->randomNum(10);
    for(int j=0;j<10;j++){
      int i=v2[j];
      dialog.add_action_widget(bChoix[i],i);
      bChoix[i].show();
    }
    
    int result0=dialog.run();
    switch(result0){
    case(1):{
      int result1=dialog.run();
      switch(result1){
          case(7):{
	      Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus jeune!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
              Gtk::Image *imgg2=new Gtk::Image("image/p4.png");
              dialog.set_image(*imgg2);
              imgg2->show();
              dialog.run();
              if (m->partie[3]==0){
	      m->Info("Info(Room1):C'est bon! Bravo! Vous avez des yeux brillants!");
    	      m->ResultNowPlusPlus();
	      m->partie[3]=1;
	      }
              else
	      m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
              EscapeRoom1();
	      dialog.hide();
	      break;
	  }
          default:{
	     Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
	     m->Info("Info(Room1):Faut! Ressaiyez, SVP.");
	     dialog.hide();
	     break;
	     }
        }
      break;
    }
    
   case(7):{
       int result1=dialog.run();
       switch(result1){
          case(1):{
	      Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus jeune!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
              Gtk::Image *imgg2=new Gtk::Image("image/p4.png");
              dialog.set_image(*imgg2);
              imgg2->show();
              dialog.run();
             if (m->partie[3]==0){
	     m->Info("Info(Room1):C'est bon! Bravo! Vous avez des yeux brillants!");
    	     m->ResultNowPlusPlus();
	     m->partie[3]=1;
	     }
             else
	     m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
             EscapeRoom1();
	     dialog.hide();
	     break;
	  }
         default:{
	     Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
	     m->Info("Info(Room1):Faut! Ressaiyez, SVP.");
	     dialog.hide();
	     break;
	  }
       }
       break;
   }
    default:{
         Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
         m->Info("Info(Room1):Faut! Ressaiyez, SVP.");
	 dialog.hide();
	 break;
    }
   }
  }
void CRoom1::on_button_boite6(){
     Gtk::Image *imgg=new Gtk::Image("image/charac.png");
    // m->permuterImage("pic/img1.jpeg");
    m->Info("Info(Room1):Boite 6:jeux de caractere chinois.");
    Gtk::MessageDialog dialog(*v,"Selon l'image vous avez vue, choisez les 4 characteres dans cette image dans l'ordre, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_NONE);
    dialog.set_image(*imgg);
    imgg->show();

     Gtk::Button bChoix[7];   
     std::vector<std::string> v1=m->getImageStringButton6();

    for(int i=0;i<7;i++){
      Gtk::Image *image=new Gtk::Image(v1[i]);
      bChoix[i].set_image(*image);
      image->show();
      }
    std::vector<int> v2=m->randomNum(7);
    for(int j=0;j<7;j++){
      int i=v2[j];
      dialog.add_action_widget(bChoix[i],i);
      bChoix[i].show();
    }
    
    int result0=dialog.run();
     switch(result0){
    case (6):{
      int result1=dialog.run();
	switch (result1){
	case(4):{
	       int result2=dialog.run();
	       switch (result2){
	       case(2):{
                     int result3=dialog.run();
		     switch (result3){
		     case(5):{
		        Gtk::MessageDialog dialog(*v,"Info(Room1):Correct! Vous avez trouve la prierre precieus verre!",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE);
                        Gtk::Image *imgg2=new Gtk::Image("image/p5.png");
                        dialog.set_image(*imgg2);
                        imgg2->show();
                        dialog.run();
		        if (m->partie[4]==0){
			  m->Info("Info(Room1):C'est bon! Felicitation! Vous avez connu les characteres de chinois!");
			  m->ResultNowPlusPlus();
			  m->partie[4]=1;
			}
			else
			  m->Info("Info(Room1):Vous avez deja reussi ce partie,veuillez chercher les autres traces.");
		       EscapeRoom1();
		       dialog.hide();
		       break;
		     }
		     default:{
		       Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		       m->Info("Info(Room1):Faut! Vous avez mal trouve, ressaiyez, SVP.");
		       break;
		     }
		     }
		     break;
	       }
	       default:{
		 Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
		 m->Info("Info(Room1):Faut! Vous avez mal trouve, ressaiyez, SVP.");
		 break;
	       }
	       }
	       break;
	}
	default:{
        Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
        m->Info("Info(Room1):Faut! Vous avez mal trouve, ressaiyez, SVP.");
	break;
	}
        }
      break;
      }
       default:{
      Gtk::MessageDialog dialog(*v,"Faut! Ressaiyez, SVP.",false,Gtk::MESSAGE_INFO,Gtk::BUTTONS_CLOSE); dialog.run();
      m->Info("Info(Room1):Faut! Vous avez mal trouve, ressaiyez, SVP. ");
      break;
       }
    }  
  }
void CRoom1::on_button_info(){
  m->b_info(this->v);
}
void CRoom1::on_button_level(){
  m->level_select(this->v);
  // m->Info("Info(Room1):Bienvenu!");
  }

void CRoom1::on_button_exit(){
    v->on_button_close();
  }
