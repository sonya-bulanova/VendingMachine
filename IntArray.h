#pragma once
#include <iostream>
class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();

    int& operator[](int index);
    IntArray& operator=(const IntArray& a);
    
    void erase();
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
};

