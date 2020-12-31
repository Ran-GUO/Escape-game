/**
 *  main.cpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */


#include "controleur.hpp"
#include "vue.hpp"
#include "modele.hpp"
#include <gtkmm/application.h>
#include "windowPlayer.hpp"
#include "myMysql.hpp"
#include "player.hpp"
#include "choixPlayer.hpp"

int main(int argc,char *argv[]){
  
  Mysql server_mysql=Mysql::unique_instance();
  std::cout<<"-----------------database:all players------------------"<<std::endl;
  server_mysql.printPlayers();
  std::cout<<"-------------------------------------------------------"<<std::endl;
  auto appPlayer=Gtk::Application::create(argc,argv);
  WindowPlayer *pPlayer=new WindowPlayer(&server_mysql);
  appPlayer->run(*pPlayer);
  Player p=pPlayer->getPlayer();
  p=server_mysql.chercherPlayer(p);
  std::cout<<"Info(User):"<<"this palyer is: "<<p.getName()<<"\t"<<"level = "<<p.getLevel()<<std::endl;

  auto appLevel=Gtk::Application::create(argc,argv);
  ChoixPlayer *pLevel=new ChoixPlayer(p);
  appLevel->run(*pLevel);
  int level=pLevel->getLevel();
  int result=1;
  std::cout<<"Info(User):"<<"this player choose level : "<<level<<std::endl;
  while(result==1){
    switch(level){
    case(1):{
       p=server_mysql.chercherPlayer(p);
       result=0;
       auto app1=Gtk::Application::create(argc,argv);
       MRoom1 *m1=new MRoom1(p);
       VRoom1 *v1=new VRoom1();
       CRoom1 *c1=new CRoom1(m1,v1);
       m1->addObserver(v1);
       app1->run(*v1);
       if (m1->getResultFin()==1){
       server_mysql.updateData(p,1);
       ++level;      
       result=1;
       }
       if (m1->getLevelChoose()==1){
	 level=m1->getLevel();
         result=1;
	 m1->setLevelChoose(0);
       }
       break;
     }
   case(2):{
     result=0;
     p=server_mysql.chercherPlayer(p);
     auto app2=Gtk::Application::create(argc,argv);
     MRoom2 *m2=new MRoom2(p);
     VRoom2 *v2=new VRoom2();
     CRoom2 *c2=new CRoom2(m2,v2);
     m2->addObserver(v2);
     app2->run(*v2);
     if (m2->getResultFin()==1){
     server_mysql.updateData(p,2);
     ++level;
     result=1;
     }
     if (m2->getLevelChoose()==1){
	 level=m2->getLevel();
         result=1;
	 m2->setLevelChoose(0);
       }
     break;
    }
    case(3):{
      result=0;
      p=server_mysql.chercherPlayer(p);
      auto app3=Gtk::Application::create(argc,argv);
      MRoom3 *m3=new MRoom3(p);
      VRoom3 *v3=new VRoom3();
      CRoom3 *c3=new CRoom3(m3,v3);
      m3->addObserver(v3);
      app3->run(*v3);
      if (m3->getResultFin()==1){
        server_mysql.updateData(p,3);
        ++level;
	result=1;
     }
      if (m3->getLevelChoose()==1){
	 level=m3->getLevel();
         result=1;
	 m3->setLevelChoose(0);
       }
      break;
    }
    default:{
       auto appLevel=Gtk::Application::create(argc,argv);
       Player p2=server_mysql.chercherPlayer(p);
       ChoixPlayer *pLevel=new ChoixPlayer(p2);
       appLevel->run(*pLevel);
       level=pLevel->getLevel();
    }
      
   }
  }
  return EXIT_SUCCESS;
}
// g++ vue.cpp main.cpp -o main  $(pkg-config gtkmm-3.0 --cflags --libs)
// g++ vue.cpp myMysql.cpp main.cpp -o main  $(pkg-config gtkmm-3.0 --cflags --libs) -I/usr/include/cppconn -lmysqlcppconn
// g++ vue.cpp  vue2.cpp vue3.cpp modele1.cpp modele2.cpp modele3.cpp controleur1.cpp controleur2.cpp controleur3.cpp myMysql.cpp main.cpp -o main  $(pkg-config gtkmm-3.0 --cflags --libs) -I/usr/include/cppconn -lmysqlcppconn

