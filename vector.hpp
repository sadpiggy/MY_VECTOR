#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"
#include "utility.hpp"
#include <climits>
#include <cstddef>
#include<cstdio>
#include<cmath>
#include<iostream>
#include <cstring>
    namespace sjtu {
/**runtime_error
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */
    template<typename T>
    class vector {

    public:

        /**
         * TODO
         * a type for actions of the elements of a vector, and you should write
         *   a class named const_iterator with same interfaces.
         */
        /**
         * you can see RandomAccessIterator at CppReference for help.
         */
        class const_iterator;
        class iterator {
            friend vector<T>;
            friend const_iterator;
        private:
            T** ptr;
            int pos;
            /**
             * TODO add data members
             *   just add whatever you want.
             */
        public:

            iterator(T** other_data, int p) : ptr(other_data), pos(p) {}

            iterator(const iterator &other) : ptr(other.ptr), pos(other.pos) {}
            /**
             * return a new iterator which pointer n-next elements
             * as well as operator-
             */
           // iterator(){ptr= nullptr;pos=0;}
            //iterator(iterator& other)=default;
            //iterator(T** ptr_,int pos_):ptr(ptr_),pos(pos_){}
            //iterator(iterator&& other)noexcept {
             //   ptr=other.ptr;
               // pos=other.pos;
               // other.ptr= nullptr;
               // return *this;
            //}
            //iterator& operator=(iterator& other){this->ptr=other.ptr;this->pos=other.pos;return *this;}
            //iterator & operator =(const iterator & other) = default;


            iterator operator+(const int &n) const {
                //TODO
                return iterator(this->ptr,this->pos+n);
            }
            iterator operator-(const int &n) const {
                //TODO
                return iterator(this->ptr,this->pos-n);
            }
            // return the distance between two iterators,
            // if these two iterators point to different vectors, throw invaild_iterator.
            int operator-(const iterator &rhs) const {
                //TODO
                if(this->ptr!=rhs.ptr)throw invalid_iterator();
                return abs(this->pos-rhs.pos);
            }
            iterator& operator+=(const int &n) {
                //TODO
                this->pos+=n;
                return *this;
            }
            iterator& operator-=(const int &n) {
                //TODO
                this->pos-=n;
                return *this;
            }
            /**
             * TODO iter++
             */
            iterator operator++(int) {
                iterator other(this->ptr,this->pos);
                this->pos++;
                return other;
            }
            /**
             * TODO ++iter
             */
            iterator& operator++() {
                this->pos++;
                return *this;
            }
            /**
             * TODO iter--
             */
            iterator operator--(int) {
                iterator other(this->ptr,this->pos);
                this->pos--;
                return other;
            }
            /**
             * TODO --iter
             */
            iterator& operator--() {
                this->pos--;
                return *this;
            }
            /**
             * TODO *it
             */
            T& operator*() const{
                return *(ptr[pos]);
            }
            /**
             * a operator to check whether two iterators are same (pointing to the same memory address).
             */
            bool operator==(const iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return false;
                if(this->pos!=rhs.pos)return false;
                return true;
            }
            bool operator==(const const_iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return false;
                if(this->pos!=rhs.pos)return false;
                return true;
            }
            /**
             * some other operator for iterator.
             */
            bool operator!=(const iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return true;
                if(this->pos!=rhs.pos)return true;
                return false;
            }
            bool operator!=(const const_iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return true;
                if(this->pos!=rhs.pos)return true;
                return false;
            }

        };
        /**
         * TODO
         * has same function as iterator, just for a const object.
         */
        class const_iterator {
            friend vector<T>;
            friend iterator;
        private:
            T** ptr;
            int pos;
            /**
             * TODO add data members
             *   just add whatever you want.
             */
        public:

            const_iterator(T** other_data, int p) : ptr(other_data), pos(p) {}

            const_iterator(const const_iterator &other) : ptr(other.ptr), pos(other.pos) {}
            /**
             * return a new iterator which pointer n-next elements
             * as well as operator-
             */
           /* const_iterator(){ptr= nullptr;pos=0;}
            const_iterator(iterator& other)=default;
            const_iterator(T** ptr_,int pos_):ptr(ptr_),pos(pos_){}
            //const_iterator& operator=(const_iterator& other){this->ptr=other.ptr;this->pos=other.pos;return *this;}
            const_iterator& operator=(const_iterator const& other)=default;
            const_iterator(const_iterator&& other)noexcept {
                ptr=other.ptr;
                pos=other.pos;
                other.ptr= nullptr;
            }*/

            const_iterator operator+(const int &n) const {
                //TODO
                return const_iterator(this->ptr,this->pos+n);
            }
            const_iterator operator-(const int &n) const {
                //TODO
                return const_iterator(this->ptr,this->pos-n);
            }
            // return the distance between two iterators,
            // if these two iterators point to different vectors, throw invaild_iterator.
            int operator-(const iterator &rhs) const {
                //TODO
                if(this->ptr!=rhs.ptr)throw invalid_iterator();
                return abs(this->pos-rhs.pos);
            }
            const_iterator& operator+=(const int &n) {
                //TODO
                this->pos+=n;
                return *this;
            }
            const_iterator& operator-=(const int &n) {
                //TODO
                this->pos-=n;
                return *this;
            }
            /**
             * TODO iter++
             */
            const_iterator operator++(int) {
                const_iterator other(this->ptr,this->pos);
                this->pos++;
                return other;
            }
            /**
             * TODO ++iter
             */
            const_iterator& operator++() {
                this->pos++;
                return *this;
            }
            /**
             * TODO iter--
             */
            const_iterator operator--(int) {
                iterator other(this->ptr,this->pos);
                this->pos--;
                return other;
            }
            /**
             * TODO --iter
             */
            const_iterator& operator--() {
                this->pos--;
                return *this;
            }
            /**
             * TODO *it
             */
            T operator*() const{
                return *(ptr[pos]);
            }
            /**
             * a operator to check whether two iterators are same (pointing to the same memory address).
             */
            bool operator==(const const_iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return false;
                if(this->pos!=rhs.pos)return false;
                return true;
            }
            bool operator==(const iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return false;
                if(this->pos!=rhs.pos)return false;
                return true;
            }
            /**
             * some other operator for iterator.
             */
            bool operator!=(const const_iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return true;
                if(this->pos!=rhs.pos)return true;
                return false;
            }
            bool operator!=(const iterator &rhs) const {
                if(this->ptr!=rhs.ptr)return true;
                if(this->pos!=rhs.pos)return true;
                return false;
            }
        };
    private:
        int max_num=0;
        int cur_num=0;
        T** data= nullptr;

    public:
        /**index_out_of_bound
         * TODO Constructs
         * Atleast two: default constructor, copy constructor
         */
        vector() {data= new T*[5];max_num=5;cur_num=0;for(int i=0;i<5;i++)data[i]= nullptr;}
        /*vector(const vector &other) {
            max_num = other.max_num;
            cur_num = other.cur_num;
            if (max_num != 0)data = new T *[max_num];
            else data = nullptr;
            for (int i = 0; i < max_num; i++) { data[i] = new T(*(other.data[i])); }
        }*/
        vector(const vector &other) : max_num(other.max_num), cur_num(other.cur_num) {
            data = new T *[max_num];
            for (int i = 0; i < cur_num; i++)data[i] = new T(*(other.data[i]));
            for(int i=cur_num;i<max_num;i++)data[i]= nullptr;
            //todo memcpy? copy constructor?
        }
        vector (vector && other){
            cur_num=other.cur_num;max_num=other.max_num;
            data=other.data;
            other.data= nullptr;other.max_num=0;other.cur_num=0;
        }
        /**
         * TODO Destructor
         */
        ~vector() {
            if(data== nullptr)return;
            for(int i=0;i<cur_num;i++)
            {
                if(data[i]!= nullptr){delete data[i];data[i]= nullptr;}
            }
            delete data;////
            data= nullptr;
        }
        /**
         * TODO Assignment operator
         */
        vector &operator=(const vector &other) {
            if(this==&other)return *this;
            for(int i=0;i<max_num;i++)
            {
                if(data[i]!= nullptr){delete data[i];data[i]= nullptr;}
            }
            delete data;
            max_num=other.max_num;
            cur_num=other.cur_num;
            data=new T*[max_num];
            for(int i=0;i<cur_num;i++)
            {
               //data[i]=new T;*(data[i])=*(other.data[i]);
                data[i] = new T(*(other.data[i]));
            }
            for(int i=cur_num;i<max_num;i++)data[i]= nullptr;
            return *this;
        }

        void larger_space(){
            //std::cout<<"large";
            int max_mid=max_num;
            max_num*=2;//max_num+=5;
            T** mid=data;
            data =new T*[max_num];
            for(int i=0;i<max_num;i++)
            {
                if(i<max_mid){
                if(mid[i]!= nullptr)data[i] = new T(*(mid[i]));
                else data[i]= nullptr;
                }
                else  data[i]= nullptr;
            }
            for(int i=0;i<max_mid;i++)
            {
                if(mid[i]!= nullptr){delete mid[i];mid[i]= nullptr;}
            }
            delete mid;
        }

        /**
         * assigns specified element with bounds checking
         * throw index_out_of_bound if pos is not in [0, size)
         */
        T & at(const size_t &pos) {
            if(pos<0||pos>=max_num)throw index_out_of_bound();
            return *(data[pos]);
        }
        const T & at(const size_t &pos) const {//有什么不同吗？
            if(pos<0||pos>=max_num)throw index_out_of_bound();
            return *(data[pos]);
        }
        /**
         * assigns specified element with bounds checking
         * throw index_out_of_bound if pos is not in [0, size)
         * !!! Pay attentions
         *   In STL this operator does not check the boundary but I want you to do.
         */
        T & operator[](const size_t &pos) {
            if(pos<0||pos>=cur_num)throw index_out_of_bound();
            return *(data[pos]);
        }
        const T & operator[](const size_t &pos) const {
            if(pos<0||pos>=cur_num)throw index_out_of_bound();
            return *(data[pos]);
        }
        /**
         * access the first element.
         * throw container_is_empty if size == 0
         */
        const T & front() const {
            if(cur_num==0)throw container_is_empty();
            return *(data[0]);
        }
        /**
         * access the last element.
         * throw container_is_empty if size == 0
         */
        const T & back() const {
            if(cur_num==0)throw container_is_empty();
            return *(data[cur_num-1]);
        }
        /**
         * returns an iterator to the beginning.
         */
        iterator begin() {
            return iterator(data,0);
        }
        const_iterator cbegin() const {
            return const_iterator(data,0);
        }
        /**
         * returns an iterator to the end.
         */
        iterator end() {
            return iterator(data,cur_num);
        }
        const_iterator cend() const {
            return const_iterator(data,cur_num);
        }
        /**
         * checks whether the container is empty
         */
        bool empty() const {
            return cur_num==0;
        }
        /**
         * returns the number of elements
         */
        size_t size() const {
            return cur_num;
        }
        /**
         * clears the contents
         */
        void clear() {
            if(data== nullptr)return;
            for(int i=0;i<max_num;i++){
                if(data[i]!= nullptr){delete data[i];data[i]= nullptr;}
            }
            max_num=cur_num=0;
            delete data;
            data= nullptr;
            max_num=5;
            data=new T*[5];
            for(int i=0;i<5;i++)data[i]= nullptr;
        }
        /**
         * inserts value before pos
         * returns an iterator pointing to the inserted value.
         */
        iterator insert(iterator pos, const T &value) {//may bug//if iterator is not this”s
            if(cur_num==max_num)larger_space();
            if(pos.ptr!=data){throw invalid_iterator();}//抛出·的·先后顺序是哈？
            if(pos.pos>=cur_num||pos.pos<0)throw index_out_of_bound();
            for(int i=cur_num;i>pos.pos;i--){data[i]=data[i-1];}
            //data[pos.pos]=new T;
           // if(data[pos.pos]!= nullptr){delete data[pos.pos];}
            data[pos.pos]=new T(value);
           // *(data[pos.pos])=value;

            cur_num++;
            if(cur_num==max_num)larger_space();
            //return *this;
            return iterator(data,pos.pos+1);
        }
        /**
         * inserts value at index ind.
         * after inserting, this->at(ind) == value
         * returns an iterator pointing to the inserted value.
         * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
         */
        iterator insert(const size_t &ind, const T &value) {
            if(cur_num==max_num)larger_space();
            if(ind>cur_num||ind<0)throw index_out_of_bound();
            for(int i=cur_num;i>ind;i--){data[i]=data[i-1];}
            //data[pos.pos]=new T;
            // if(data[pos.pos]!= nullptr){delete data[pos.pos];}
            data[ind]=new T(value);
           // *(data[ind])=value;
            cur_num++;
            if(cur_num==max_num)larger_space();
            //return *this;
            return iterator(data,ind+1);
        }
        /**
         * removes the element at pos.
         * return an iterator pointing to the following element.
         * If the iterator pos refers the last element, the end() iterator is returned.
         */
        iterator erase(iterator pos) {
            if(pos.ptr!=data){throw invalid_iterator();}//抛出·的·先后顺序是哈？
            if(pos.pos>=cur_num||pos.pos<0)throw index_out_of_bound();
            delete data[pos.pos];////////////////////////////////////////////////
            for(int i=pos.pos;i<cur_num-1;i++){data[i]=data[i+1];}
            //data[pos.pos]=new T;
            // if(data[pos.pos]!= nullptr){delete data[pos.pos];}
            data[cur_num-1]== nullptr;
            //*(data[pos.pos])=value;
            cur_num--;
            //if(cur_num==max_num)larger_space();
            //return *this;
            return iterator(data,pos.pos);
        }
        /**
         * removes the element with index ind.
         * return an iterator pointing to the following element.
         * throw index_out_of_bound if ind >= size
         */
        iterator erase(const size_t &ind) {
            if(ind>=cur_num||ind<0)throw index_out_of_bound();
            delete data[ind];
            for(int i=ind;i<cur_num-1;i++){data[i-1]=data[i];}
            //delete data[cur_num-1];////////////////////////////////////////////////
            data[cur_num-1]== nullptr;
            cur_num--;
            return iterator(data,ind);
        }
        /**
         * adds an element to the end.
         */
        void push_back(const T &value) {
            //std::cout<<cur_num<<std::endl;
         //insert(cur_num-1,value);

         if(cur_num==max_num)larger_space();
         data[cur_num]=new T(value);
         //*(data[cur_num])=value;
         cur_num++;
         if(cur_num==max_num)larger_space();
        }
        /**
         * remove the last element from the end.
         * throw container_is_empty if size() == 0
         */
        void pop_back() {
            if(cur_num==0)throw  container_is_empty();
          delete  data[cur_num-1];
          data[cur_num-1]= nullptr;
          cur_num--;
        }
    };


}

#endif
