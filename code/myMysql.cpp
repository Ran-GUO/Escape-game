/**
 *  myMysql.cpp
 *
 *  @author GUO Ran
 *  03/05/2020
 */

#include"myMysql.hpp"

Mysql::Mysql(){
  Properties prop=Properties();
  prop.load("mysql.prop");
  this->driver= get_driver_instance();
  this->conn = this->driver->connect(prop.getProperty("mysql.url"),
			   prop.getProperty("mysql.username"),
			   prop.getProperty("mysql.password"));
    std::cout<<"Connexion OK"<<std::endl;
    this->stmt=this->conn->createStatement();

    this->stmt->execute("Create DATABASE IF not EXISTS Escape_game");
    this->stmt->execute("use Escape_game");
    this->stmt->execute("create table if not exists players(id_ref INT PRIMARY KEY NOT NULL AUTO_INCREMENT, \
                          name VARCHAR(100), password VARCHAR(100), level INT)");
    this->prep_stmt=this->conn->prepareStatement("insert into players(name, password, level) VALUES(?,?,?)");
}
bool Mysql::isExistPlayer(Player p){
  this->res=this->stmt->executeQuery("SELECT * From players");
  while(this->res->next()){
    if(this->res->getString("name")==p.getName()){
      //std::cout<<"Info(User): Exist player "<<p.getName()<<std::endl;
      return true;
    }
  }
  // std::cout<<"Info(User): Not Exist player "<<p.getName()<<std::endl;
  return false;
}

void Mysql::addPlayer(Player p){
  if(!(this->isExistPlayer(p))){
   this-> prep_stmt->setString(1,p.getName());
   this-> prep_stmt->setString(2,p.getPassword());
   this-> prep_stmt->setInt(3,p.getLevel());
   this-> prep_stmt->execute();
}
  std::cout<<"Info(User): create player "<<p.getName()<<std::endl;
}
Player Mysql::chercherPlayer(Player p1){
  Player p("null","null",0);
  if(this->isExistPlayer(p1)) {
    this->res=this->stmt->executeQuery("SELECT * From players WHERE name='"+p1.getName()+"'");
  if(this->res->next()){
    p.setName(this->res->getString("name"));
    p.setPassword(this->res->getString("password"));
    p.setLevel(this->res->getInt("level"));
    }
  return p;
  }
}
bool Mysql::isPasswordRight(Player p){
  this->res=this->stmt->executeQuery("SELECT * FROM players");
  while(this->res->next()){
    if((this->res->getString("name")==p.getName()) && (this->res->getString("password")==p.getPassword())){
	return true;
      }
    else if((this->res->getString("name")==p.getName()) && (this->res->getString("password")!=p.getPassword())){
      return false;
    }
  }
  return false;
}

void Mysql::updateData(Player p,int level){
  this->res=this->stmt->executeQuery("Select * from players where name = '"+p.getName()+"'");
  int highLevel=0;
  if(this->res->next()){
    highLevel=this->res->getInt("level");
  }
  if (level>highLevel){
    this->stmt->executeUpdate("Update players SET level='"+std::to_string(level) +"'WHERE name='"+p.getName()+"'");
  }
}

void Mysql::printPlayers(){
   this->stmt->execute("use Escape_game");
   this->res=this->stmt->executeQuery("Select * from players");
   std::cout<<"id_ref"<<"\t"<<"name"<<"\t\t"<<"password"<<"\t"<<"level"<<std::endl;
     while (this->res->next()){
       std::cout << this->res->getInt("id_ref") << "\t";
       std::cout << this->res->getString("name") << "\t";
       std::cout << this->res->getString("password") << "\t";
       std::cout << this->res->getInt("level")<<std::endl;
     }
}




