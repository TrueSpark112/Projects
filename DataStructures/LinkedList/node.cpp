#include "node.h"
template<typename T>
node<T>::node(){
  data_ = NULL;
  link_ = nullptr;
}
template<typename T>
node<T>::node(const T& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}
template<typename T>
T node<T>::data() const
{
    return data_;
}
template<typename T>
node<T>* node<T>::link()
{
    return link_;
}

//returns constant node pointer


template <typename T>
void node<T>::set_data(const T & newdata)
{
    data_ = newdata;
}
template<typename T>
void node<T>::set_link(node * newlink)
{
    link_ = newlink;
}
