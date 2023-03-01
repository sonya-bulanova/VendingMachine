#include "IntArray.h"

IntArray::IntArray(int length) :
    m_length{ length }
{
    if (length <= 0) {
        throw "Illegal size of length";
    }
    else {
        m_data = new int[length] {};
    }
}

IntArray::IntArray(const IntArray& a)
{
    // Set the size of the new array appropriately
    reallocate(a.getLength());

    // Then copy the elements
    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
}

IntArray::~IntArray()
{
    if (!m_data) {
        delete[] m_data;
    }
    // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
}

void IntArray::erase()
{
    delete[] m_data;
    // We need to make sure we set m_data to nullptr here, otherwise it will
    // be left pointing at deallocated memory!
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index)
{
    if (index >= 0 && index < m_length) {
        return m_data[index];
    }
    else {
        throw "Illegal index!";
    }

}

// reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
void IntArray::reallocate(int newLength)
{
    // First we delete any existing elements
    erase();

    // If our array is going to be empty now, return here
    if (newLength <= 0)
        return;

    // Then we have to allocate new elements
    m_data = new int[newLength];
    m_length = newLength;
}

// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
void IntArray::resize(int newLength)
{
    // if the array is already the right length, we're done
    if (newLength == m_length)
        return;

    // If we are resizing to an empty array, do that and return
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // First we have to allocate a new array
    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        // Now copy the elements one by one
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    // Now we can delete the old array because we don't need it any more
    delete[] m_data;

    // And use the new array instead!  Note that this simply makes m_data point
    // to the same address as the new array we dynamically allocated.  Because
    // data was dynamically allocated, it won't be destroyed when it goes out of scope.
    m_data = data;
    m_length = newLength;
}

IntArray& IntArray::operator=(const IntArray& a)
{
    // Self-assignment check
    if (&a == this)
        return *this;

    // Set the size of the new array appropriately
    reallocate(a.getLength());

    // Then copy the elements
    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}

void IntArray::insertBefore(int value, int index)
{
    // Sanity check our index value
    if (index >= 0 && index <= m_length) {
        // First create a new array one element larger than the old array
        int* data{ new int[m_length + 1] };

        // Copy all of the elements up to the index
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        // Insert our new element into the new array
        data[index] = value;

        // Copy all of the values after the inserted element
        for (int after{ index }; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    else {
        throw "Illegal index!";
    }
}

void IntArray::remove(int index)
{
    // Sanity check our index value
    if (index >= 0 && index < m_length) {
        // If we're removing the last element in the array, we can just erase the array and return early
        if (m_length == 1)
        {
            erase();
            return;
        }

        // First create a new array one element smaller than the old array
        int* data{ new int[m_length - 1] };

        // Copy all of the elements up to the index
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        // Copy all of the values after the removed element
        for (int after{ index + 1 }; after < m_length; ++after)
            data[after - 1] = m_data[after];

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    else {
        throw "Illegal index!";
    }
}

// A couple of additional functions just for convenience
void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }
int IntArray::getLength() const { return m_length; }
