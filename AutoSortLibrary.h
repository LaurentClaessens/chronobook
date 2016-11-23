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

/*

   This class is an "auto-sorted" list.
   - The append method adds the element at the right place, so that the 
        list is always sorted.
   - The elements of the list are of type Media* (or derivate class)
   - The sorting is done with respect to the value of `x.getYear`

//*/

#ifndef __AUTOSORTLIBRARY_14517__
#define __AUTOSORTLIBRARY_14517__

#include <memory>
#include "Media.h"

class Iterator;

class AutoSortLibrary
{
    private :

        class node
        {
            private:
                std::unique_ptr<Media> media;
                std::shared_ptr<node> next;

                /*
                 * Check if the node after `current` has a year later
                 * than the one passed.
                 * - `year` : the year to be checked.
                 *   If the year of `this->getNext()` is greater than `year`,
                 *   return `true`.
                 *   Else return `false`.
                 * If the next of `this` is `nullptr`, we consider
                 * that `this` is the last node with a year lower than
                 * the given one because it is the last one of the autolibrary.
                 */
            public:
                // Building a node from a `unique_ptr<Media>` will make a 
                // std::move. Thus the media will not be available from
                // outside the node.
                node(std::unique_ptr<Media> m_ptr);
                node(node& n);

                std::shared_ptr<node> getNext() const;
                void setNext(std::shared_ptr<node>);
                bool isNextLaterThan(const int year) const;
                Media getMedia() const;
                int getYear() const;
        };

        class Iterator
        {
            // The operator * returns a *pointer* to a node and not a node.
            // Rationale : when inserting a media in the collection, I'm doing
            // a loop to know where to insert the new media. Retuning a node
            // provokes the *copy* of the node.
            private :
                std::shared_ptr<AutoSortLibrary::node> punt;

            public :
                Iterator(std::shared_ptr<AutoSortLibrary::node> p);

                bool operator!= (const Iterator& other) const;
                std::shared_ptr<AutoSortLibrary::node> operator*() const;
                const Iterator& operator++();
        };

        std::shared_ptr<node> first=nullptr;
        std::shared_ptr<node> last=nullptr;
        Iterator begin() const;
        Iterator end() const;

        // return the last node whose year is before the given year.
        std::shared_ptr<node> getLastNodeBefore(const int year) const; 

    public :

        // append an element to the library.
        // - the element is added in the list at the right place
        // to remain ordered.
        // - `m_ptr` is a  `unique_ptr<Media>`, and the ownership is 
        //    automatically transfered to an other `unique_ptr<Media>` inside
        //    the new node.
        void append(std::unique_ptr<Media> m_ptr);
        void show() const;
};

#endif
