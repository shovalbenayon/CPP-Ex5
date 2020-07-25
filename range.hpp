#pragma once

#include <iostream>
#include <vector>

using namespace std;
namespace itertools{
	
	class range{
		private:
			int start, finish;

		public:
			range(int start, int finish): start(start), finish(finish){}
			~range(){}

		class iterator{
			private:
				int index;

			public:
				iterator(int i): index(i){}
 				~iterator(){}

				const int operator*() const {
                    return index;
                }
				iterator& operator++(){ //for ++iterator
                    index = index +1;
                    return *this;
                } 
				const iterator operator++(int) { //for iterator++
                    iterator tmp = *this;
                    index = index +1;
                    return *tmp;

                }
				bool operator==(const iterator& other) const{
                    return index == other.index;
                }
				bool operator!=(const iterator& other) const{
                    return index != other.index;
                }
		}; // class iterator

		iterator begin() const{
            return iterator(start);
        }
		iterator end() const{
            return iterator(finish);
        }

         typedef int value_type;

	};//class range
} //namespace itertools