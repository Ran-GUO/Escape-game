/**
 *@author: GUO Ran
 */
#pragma once

#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<driver.h>
#include<connection.h>
#include<statement.h>
#include<fstream>
#include<prepared_statement.h>
#include"player.hpp"

class Mysql{
public:
  sql::Driver *driver;
  sql::Connection *conn;
  sql::Statement *stmt;
  sql::ResultSet *res;
  sql::PreparedStatement *prep_stmt;
  
  Mysql();
  
  static Mysql& unique_instance(){
    static Mysql server_mysql;
    return  server_mysql;
  }
  Player chercherPlayer(Player p);  
  bool isExistPlayer(Player p);
  void addPlayer(Player p);
  bool isPasswordRight(Player p);
  void updateData(Player p,int level);
  void printPlayers();
  void closeConnection(){delete conn;}
  static void exceptionCatch(sql::SQLException &e){
    std::cerr<< "# ERR:SQLException in"<<__FILE__;
    std::cerr<< "("<<__FUNCTION__<<") on line"<<__LINE__<<std::endl;
    std::cerr<< "# ERR: "<<e.what();
    std::cerr<< " (MYSQL error code: "<<e.getErrorCode();
    std::cerr<< ", SQLState: "<<e.getSQLState()<<" )"<<std::endl;
  }
};


class Properties{
private:
  std::map<std::string,std::string> prop_map;
public:
  //creation de la table de properties a partir de ficher in
  void load(std::string in){
    //ouvrir le ficher de proprietes
    std::ifstream ios(in);
    if(!ios.is_open()){
      perror(in.c_str());
      exit(EXIT_FAILURE);
    }
    //creer la table
    std::string line;
    while(ios>>line)
      prop_map[line.substr(0,line.find('='))]=line.substr(line.find('=')+1);
  }

  //renvoie la valeur de la propriete p si elle exsite,et "" sinon
  std::string getProperty(std::string p){
    return this->prop_map[p].empty()? "":this->prop_map[p];
  }
};
