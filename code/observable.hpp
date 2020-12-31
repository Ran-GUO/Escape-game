/**
 *  observable.hpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */
#pragma once

#include"observer.hpp"
#include<list>
#include<iostream>


template<typename T>
class Observable{
private:
  std::list<Observer<T> *> list_observers;
public:
  void notifyObservers(T info){
    for (auto obs:this->list_observers) obs->update(info);
    std::cout<<"je suis notifyObservers:"<<info<<std::endl;
  }

  void addObserver(Observer<T> * observer){
    this->list_observers.push_back(observer);
  }
};
