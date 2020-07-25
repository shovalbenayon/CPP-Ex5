#pragma once
#include <iostream>
#include <vector>

namespace itertools{
    template<typename CONTAINER1, typename CONTAINER2>
    class compress {
        CONTAINER1 container;
        CONTAINER2 container_bool;
        typedef typename CONTAINER1::value_type value_type;

    public:
        compress(CONTAINER1 con1, CONTAINER2 boolCon1): container(con1), container_bool(boolCon1){}

        class iterator{
            typename CONTAINER1::iterator current;
            typename CONTAINER1::iterator end;
            typename CONTAINER2::iterator iter_bool;

        public:
            iterator(typename CONTAINER1::iterator c, typename CONTAINER1::iterator e, typename CONTAINER2::iterator bool_):
             current(c), end(e), iter_bool(bool_){
                 
                while (current != end && !(*iter_bool)){
                    ++current;
                    ++iter_bool;
                   
                }
            }

            iterator& operator=(const iterator& a){
                this->current = a.current;
                return *this;
            }

             bool operator ==(const iterator& a) {
                return current == a.current;
            }

            bool operator !=(const iterator& a) {
                return current != a.current;
                
            }

            iterator& operator ++(){
                ++current;
                ++iter_bool;
                while (current != end && !(*iter_bool)){
                    ++current;
                    ++iter_bool;
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
        iterator begin(){
            return iterator(container.begin(), container.end(), container_bool.begin());
        }
        iterator end(){
            return iterator(container.end(), container.end(), container_bool.end());
        }
    };
}