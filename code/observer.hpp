/**
 *  observer.hpp
 *
 *  @author GUO Ran
 *  05/04/2020
 */
#pragma once


template<typename T>
class Observer{
public:
  virtual void update(T info) = 0;
};
