/*
Copyright 2016 Laurent Claessens
contact : moky.math@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
//*/

// iterator

#include <memory>
#include <iostream>

#include "AutoSortLibrary.h"
#include "Utilities.h"

AutoSortLibrary::Iterator::Iterator(std::shared_ptr<AutoSortLibrary::node> p):
    punt(p)
{}

bool AutoSortLibrary::Iterator::operator!= (const Iterator& other) const
{
    return punt != other.punt;
}

std::shared_ptr<AutoSortLibrary::node> AutoSortLibrary::Iterator::operator*() const 
{
    return punt;
}
const AutoSortLibrary::Iterator& AutoSortLibrary::Iterator::operator++()
{
    if (punt) punt=punt->getNext();
    return *this;
}


// AutoSortLibrary


AutoSortLibrary::Iterator AutoSortLibrary::begin() const
{
    return AutoSortLibrary::Iterator(first);
}
AutoSortLibrary::Iterator AutoSortLibrary::end() const
{
    return AutoSortLibrary::Iterator(nullptr);
}

bool AutoSortLibrary::node::isNextLaterThan(const int year  ) const
{
    if (auto s=getNext())
    {
        if (s->getYear() > year )
        {
            return true;
        }
    }
    else  
    {
        return true;
    }
    return false;
}

std::shared_ptr<AutoSortLibrary::node> AutoSortLibrary::getLastNodeBefore(const int year) const
{
    for (auto current_node:*this)
    {
        if (  current_node->isNextLaterThan(year)  )
        {
            return current_node;
        }
    }
};

void AutoSortLibrary::append(std::unique_ptr<Media> m_ptr)
{
    AutoSortLibrary::node new_node(std::move(m_ptr));
    auto new_node_ptr = std::make_shared<node>(new_node);

    // If the first one is nullptr, the library is empty
    if (first==nullptr)
    {
        first=new_node_ptr;
        last=new_node_ptr;
        return;
    }
    // the year of the media to be append
    auto m_year = new_node_ptr->getYear();

    if (first->getYear()>m_year)
    {
        new_node_ptr->setNext(first);
        first=new_node_ptr;
        return;
    }

    auto last_before = getLastNodeBefore(m_year);

    new_node_ptr->setNext(last_before->getNext());
    last_before->setNext(new_node_ptr);
};

void AutoSortLibrary::show() const
{
    for (auto current_node:*this)
    {
        current_node->getMedia().show();
    }
};
