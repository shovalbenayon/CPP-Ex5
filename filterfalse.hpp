#pragma once
#include <iostream>
#include <vector>

namespace itertools{
    template<typename T ,typename FUNTION>
    class filterfalse {
        T container;
        FUNTION function;
        typedef typename T::value_type value_type;

    public:
        filterfalse(FUNTION func, T cont): function(func), container(cont){}

        class iterator{
            typename T::iterator current;
            typename T::iterator end;
            FUNTION function;
        public:
            iterator(typename T::iterator c, typename T::iterator e, FUNTION f) : 
            current(c), end(e), function(f){
                while (current != end && function(*current))//Finds the first false
                   ++current;
            }
           

            iterator& operator=(const iterator& a){
                if(this != &a) {
                    this->current = a.current;
                    this->end = a.end;
                    this->function = a.function;
                }
                return *this;
            };
            bool operator ==(const iterator& other) {
                return current == other.current;
            }

            bool operator !=(const iterator& other) {
                return current != other.current;   
            }

            iterator& operator ++(){
                ++current;
                while (current != end && function(*current)) {
                    ++current;
                } 
                return *this;
            }

            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            auto operator *(){
                return *current;
            }

        };
        iterator begin() const{
            return iterator(container.begin(), container.end(), function);
        }
        iterator end() const {
            return iterator(container.end(), container.end(), function);
        }
    };
}