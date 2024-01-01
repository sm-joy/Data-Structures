#include <iostream>

/**
 * @class LIST
 * @brief A simple and efficient array implementation with dynamic size and various operations.
 *
 * The LIST class provides a dynamic array structure with a fixed maximum size, determined at compile time.
 * It incorporates a size_t variable named usedSize to optimize array operations and reduce unnecessary iterations.
 * The class includes essential functions for managing the array, such as insertion, removal, retrieval, and printing.
 * Additionally, it offers checks for array fullness and emptiness to ensure safe operations.
 *
 * @tparam DataType : The type of elements stored in the array.
 * @tparam p_size : The fixed maximum size of the array.
 */
template<typename DataType, size_t p_size>
class LIST
{
public:
    LIST():size(p_size){ list = new DataType[size]; }
    ~LIST(){ delete[] list; }

    /**
     * @return Returns the fixed maximum size of the array.
     */
    int getSize() const { return size; }

    /**
     * @return Returns true if the array is empty and false if it contains at least one item.
     */
    bool isEmpty() const { return usedSize == 0; }

    /**
     * @return Returns true if the array is full and false if it has space for additional items.
     */
    bool isFull() const { return usedSize == size; }

    /**
     * @param index : The index of the item to retrieve.
     * @return Returns the value at the specified index.
     */
    DataType get(int index) const
    {
        if (!(isEmpty()))
        {
            if (index >= 0 && index <= usedSize - 1)
                return list[index];
            else
                std::cout << "Index Out Of Range!\n";
        }
        else
            std::cout << "List Is Empty!\n";
    }

    /**
     * @brief Inserts a value at the specified index in the array.
     *
     * @param value : The value to insert.
     * @param index : The index at which to insert the value.
     */
    void insert(DataType value, int index)
    {
        if (!(isFull()))
        {
            if (index >= 0 && index <= usedSize - 1)
            {
                for (int i = index; i < usedSize; i++)
                {
                    list[i + 1] = list[i];
                }
            }

            list[index] = value;
            usedSize++;
        }
        else
            std::cout << "List Is FULL!\n";
    }

    /**
     * @brief Inserts a value at the end of the array.
     *
     * @param value : The value to insert.
     */
    void insert(DataType value)
    {
        if (!(isFull()))
        {
            list[usedSize] = value;
            usedSize++;
        }
    }

    /**
     * @brief Removes the last item from the array.
     */
    void pop()
    {
        if (!isEmpty())
        {
            list[usedSize - 1] = NULL;
            usedSize--;
        }
        else
            std::cout << "Cant Remove An Item From An Empty List!\n";
    }
    
    /**
     * @brief Removes first occurrences of a specific value from the array.
     *
     * @param value : The value to remove.
     */
    void remove(DataType value)
    {
        if (!isEmpty())
        {
            for (int i = 0; i < usedSize; i++)
            {
                if (list[i] == value)
                {
                    for (int j = i; j < usedSize - 1; j++)
                    {
                        list[j] = list[j + 1];
                    }
                    pop();
                    break;
                }
            }
        }
        else
            std::cout << "Cant Remove An Item From An Empty List!\n";
    }

    /**
    * @brief Removes the item at the specified index from the array.
    *
    * @param index : The index of the item to remove.
    */
    void removeAt(int index)
    {
        if (!isEmpty())
        {
            if (index >= 0 && index <= usedSize - 1)
            {
                for (int j = index; j < usedSize - 1; j++)
                {
                    list[j] = list[j + 1];
                }
                pop();
            }
            else
                std::cout << "Index Out Of Range!\n";
        }
        else
            std::cout << "Cant Remove An Item From An Empty List!\n";
    }

    /**
     * @brief Replaces the value at the specified index with a new value.
     *
     * @param value : The new value.
     * @param index : The index of the item to replace.
     */
    void replace(DataType value, int index)
    {
        if (!isEmpty())
        {
            if (index >= 0 && index <= usedSize - 1)
                list[index] = value;
            else
                std::cout << "Index Out Of Range!\n";
        }
        else
            std::cout << "Cant Purform Replace on and empty list!\n";
    }

    /**
     * @brief Prints the elements of the array.
     */
    void print() const
    {
        if (!isEmpty())
        {
            std::cout << "\n[ ";
            for (int i = 0; i < usedSize; i++)
            {
                std::cout << list[i];
                if (!(i == usedSize - 1))
                    std::cout << ", ";
            }
            std::cout << "]\n";
        }
        else
            std::cout << "Cant Print An Empty List\n";
    }

private:
    size_t size{}; /// The fixed maximum size of the array.
    size_t usedSize = 0; /// The current number of elements in the array.
    DataType* list; /// Pointer to the dynamically allocated array.
};


int main()
{
    LIST<int, 10> list;
    list.insert(10);
    list.print();
    list.insert(11, 1);
    list.insert(12, 1);
    list.insert(13, 1);
    list.print();
    list.remove(10);
    list.print();    
    list.removeAt(2);
    list.print();
    std::cout << list.get(0);
    return 0;
}