//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include <algorithm>

#include "ArrayBag.hpp"

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if
    
    return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if
    
    return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
    itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < itemCount)
    {
        if (items[searchIndex] == anEntry)
        {
            frequency++;
        }  // end if
        
        searchIndex++;
    }  // end while
    
    return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains

ArrayBag ArrayBag::operator+(const ArrayBag& bag2) const
{
    ArrayBag newBag = *this;         // make new bag with contents of this bag
    
    for (auto thing : bag2.toVector())
    {
        newBag.add(thing);          // add things from second bag to new bag
    }
    
    // Now we weed out duplicates
    auto newBagVector = newBag.toVector();
    std::vector<ItemType> duplicates;
    
    // First find all duplicates
    for (auto it = newBagVector.begin(); it != newBagVector.end(); it++)
    {
        // If a number is already a known duplicate, we don't need to check
        // and see if it's a duplicate again.
        bool itIsDuplicate = std::find(duplicates.begin(), duplicates.end(), *it) != duplicates.end();
        
        if (!itIsDuplicate)
        {
            for (auto it2 = it + 1; it2 < newBagVector.end(); it2++)
            {
                if (*it2 == *it)
                {
                    // If the number is not a known duplicate, but it exists
                    // in both bags, we add it to the duplicate list
                    duplicates.push_back(*it2);
                }
            }
        }
    }
    
    // Now remove duplicates
    for (auto dup : duplicates)
    {
        newBag.remove(dup);
    }
    
    return newBag;
}

ArrayBag ArrayBag::operator-(const ArrayBag &bag2) const
{
    ArrayBag newBag = *this; // Make new bag with contents of this bag
    
    for (auto thing : bag2.toVector())
    {
        // For every thing in bag2, we try and remove an equivalent in the
        // newBag
        newBag.remove(thing);
    }
    
    return newBag;
}

std::ostream& operator<< (std::ostream& os, const ArrayBag& bag)
{
    // This function prints the bag in an easily readable format
    auto bagVec = bag.toVector();
    
    os << '['; // Print opening bracket
    for (auto it = bagVec.begin(); it != bagVec.end(); it++)
    {
        os << *it; // Then print a number
        
        if (it + 1 != bagVec.end())
        {
            os << ", "; // If we haven't reached the end we print a comma
        }
        else
        {
            os << ']';  // Otherwise we'll print the closing bracket
        }
    }
    
    return os;
}

std::vector<ItemType> ArrayBag::toVector() const
{
    std::vector<ItemType> ArrayBagContents;
    for (int i = 0; i < itemCount; i++)
        ArrayBagContents.push_back(items[i]);
    return ArrayBagContents;
}  // end toVector

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    // if the ArrayBag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while
    
    return result;
}  // end getIndexOf
