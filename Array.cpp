// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>
#include <stdexcept>


// Default constructor
Array::Array (void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//SOLUTION:
//Moves memeber variables to their own line
: cur_size_(0), 
max_size_(20), 
data_(new char[max_size_])
{
    
}

// Initializing constructor
Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//SOLUTION:
//Moves memeber variables to their own line
: cur_size_(0), 
max_size_(length), 
data_(new char[length])
{
    
}

// Second initializing constructor
Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//SOLUTION:
//Moves memeber variables to their own line
: cur_size_(length), 
max_size_(length), 
data_(new char[length])
{
    for (int i = 0; i < length; i++){
        data_[i] = fill;
    }
}

// Copy comstructor
Array::Array (const Array & array)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//SOLUTION:
//Moves memeber variables to their own line
: cur_size_(array.cur_size_), 
max_size_(array.max_size_)
{
    // COMMENT You need to allocate spcae for the array's data.
    
    // SOLUTION
    // Allocated space for array data
    for (int j = 0; j < cur_size_; j++){
        data_ = new char[cur_size_];
        data_[j] = array.data_[j];
    }
}

// Destructor
Array::~Array (void)
{
    delete [] data_;
}

// Assignment operation
const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Check for self assignment first.

    // COMMENT Your array will have a runtime failure if the number of elements on the
    // rhs is more than the max size of this array.
    
    // SOLUTION:
    // Checked for self assignment
    // Changed the run time to run less than max size
    
    if(this != &rhs){
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        for (int k = 0; k < max_size_; k++){
            data_[k] = rhs.data_[k];
        }
    }
    return rhs;
}

// Getting the character of a specific index
char & Array::operator [] (size_t index)
{
    // COMMENT Your check will fail at the bounds.
    
    // SOLUTION:
    // Added an else statement to capture the return statement

    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

// Overloading index return operation
const char & Array::operator [] (size_t index) const
{
    // COMMENT Your check will fail at the bounds.
    
    // SOLUTION:
    // Added an else statement to capture the return statement

    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

// Getter of an index
char Array::get (size_t index) const
{
    // COMMENT Your check will fail at the bounds.
    
    // SOLUTION:
    // Added an else statement to capture the return statement

    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// Setting a value to a specified index
void Array::set (size_t index, char value)
{
    // COMMENT size_t can never be less than 0
    
    // SOLUTION
    // index is now greater than 0

    if(index < max_size_ && index > 0){
        data_[index] = value;
        cur_size_++;
    }
}

// Resizing an array
void Array::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    
    // SOLUTION
    // in the if statement, new size is now compared greater than cur size, instead of
    // greater than or equals to cur size.
    
    if (new_size > cur_size_){
        char *temp_data_ = new char[new_size];
        for (int i = 0; i < cur_size_; i++){
            temp_data_[i] = data_[i];
        }
        max_size_ = new_size;
        cur_size_ = new_size;
        delete[] data_;
        data_ = temp_data_;
    }
    else if (cur_size_ < new_size){
        char *temp_data_2 = new char[new_size];
        for (int i = 0; i < cur_size_; i++){
            temp_data_2[i] = data_[i];
        }
        max_size_ = new_size;
        cur_size_ = new_size;
        delete[] data_;
        data_ = temp_data_2;
    }
}

// Find a character in an array
int Array::find (char ch) const
{
    for (int i = 0; i < cur_size_; i++){
        if (ch == data_[i]){
            return i;
        }
    }
    return 0;
}

// Find a character in an array from a specifed starting point
int Array::find (char ch, size_t start) const
{
    for (int i = start; i < cur_size_; i ++){
        if (ch == data_[i]){
            return i;
        }
    }
    return 0;
}

// Test array for equality
bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.
    // SOLUTION:
    // Checked for self assignment
    
    
    if(this != &rhs){
        if (cur_size_ == rhs.cur_size_){
            for (int i = 0; i < cur_size_; i++){
                if (data_[i] != rhs.data_[i]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

// Test the array for inequality
bool Array::operator != (const Array & rhs) const
{
    // COMMENT You can define operator != in terms of operator ==.
    
    // SOLUTION:
    // Defined != in terms of operator ==
    
    if(this != &rhs){
        if (cur_size_ == rhs.cur_size_){
            for (int i = 0; i < cur_size_; i++){
                if (data_[i] != rhs.data_[i]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

// FIll the content of the array
void Array::fill (char ch)
{
    for (int i = 0; i < max_size_; i++){
        data_[i] = ch;
    }
}

// Shrink the array to claim unused space
void Array::shrink (void)
{
    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation.
    
    // SOLUTION:
    // Used cur_size_ and max_size_ in comparision with new size
    
    size_t new_size_;
    char * temp_data_ = new char[new_size_];
    if (new_size_ < cur_size_ && new_size_ < max_size_){
        for (int i = 0; i < new_size_; i++){
            temp_data_[i] = data_[i];
        }
    }
    delete[] data_;
    data_ = temp_data_;
}

// Reverse the order of the contents of the array
void Array::reverse (void)
{
    char temp_data_;
    for (int i = 0; i < cur_size_/2; i++){
        temp_data_ = data_[i];
        int new_pos_ = i - 1;
        data_[i] = data_[cur_size_ - new_pos_];
        data_[cur_size_ - new_pos_] = temp_data_;
    }
}

// Return a portion of the array
Array Array::slice (size_t begin) const
{
    int mid_ = cur_size_ - begin;
    Array temp_data_(mid_);
    for (int i = 0; i < mid_; i++){
        temp_data_.set(i, data_[begin + 1]);
    }
    return temp_data_;
}

// Return a portion of the array with a specified starting and ending point
Array Array::slice (size_t begin, size_t end) const
{
    int mid_ = end - begin;
    Array temp_data_(mid_);
    if (end <= cur_size_){
        for (int i = 0; i < mid_; i++){
            temp_data_.set(i, data_[begin + i]);
        }
    }
    return temp_data_;
}