#pragma once
namespace itertools{
    struct Add{
        template <typename T> T operator ()(T a, T b) const{
            return a+b;
        }
    };

    template <typename T, typename  FUNCTION = Add>
    class accumulate{
        T container;
        FUNCTION function;
        typedef typename T::value_type value_type;
    public:
        accumulate(T cont, FUNCTION func = Add()): container(cont), function(func){}

        class iterator{
            
            // Each container have a type value
            typename T::value_type value; 
            typename T::iterator _current;
            typename T::iterator _end;
    
            FUNCTION function;
        public:
            iterator(typename T::iterator c, typename T::iterator end, FUNCTION func):_current(c), _end(end), function(func){
                 if(_current != _end) 
                    value = *c;
            }
            
            iterator& operator=(const iterator& a){
                if (this != &a) {
                    this->value = a.value;
                    this->_current = a._current;
                    this->_end = a._end;
                    this->function = a.function;
                }
                return *this;
            }

            bool operator ==(const iterator& other) {
                return (_current == other._current);
            }

            bool operator !=(const iterator& other) {
                return (_current != other._current);
                
            }

            iterator& operator ++(){
                ++_current;
                if(_current != _end)
                    value = function(value, *_current);
                return *this;
            }

            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            auto operator *(){
                return value;
            }
        };

        iterator begin() {
            return iterator(container.begin(), container.end(), function);
        }
        iterator end() {
            return iterator(container.end(), container.end(), function);
        }

    };
}