#ifndef __GROUP_H__
#define __GROUP_H__

#include "ObjectBase.h"
#include <vector>
#include <memory>
#include <algorithm>

class Group : public ObjectBase
{
public:
    // Construct a group from a vector of shared pointers
    explicit Group(const std::vector<std::shared_ptr<ObjectBase>>& collection)
        : ObjectBase(' ', ascii::ColoredCanvas::WHITE, ascii::ColoredCanvas::BLACK),
          m_collection(collection) {}

    // Move all objects in the group
    virtual void move(int dx, int dy) override 
    {
        for (auto& obj : m_collection) 
        {
            obj->move(dx, dy);
        }
    }

    // Resize all objects in the group
    virtual void resize(double percentage) override 
    {
        for (auto& obj : m_collection) 
        {
            obj->resize(percentage);
        }
    }

    // Rotate all objects in the group around a given point
    virtual void rotate(Point rotationCenter, double degrees) override 
    {
        for (auto& obj : m_collection) 
        {
            obj->rotate(rotationCenter, degrees);
        }
    }

    // Draw all objects in the group
    virtual void draw(ascii::ColoredCanvas& canvas) override
    {
        for (auto& obj : m_collection) 
        {
            obj->draw(canvas);
        }
    }
    virtual void changeBgColor(color newBgColor) override 
    {
        if (newBackground) // Background was changed at least once.
        {
            for(auto& obj : m_collection)
            {
                obj->changeBgColor(newBgColor);
            }
        }
    }
    // Combine two groups into a new group
    Group operator+(const Group& other) const 
    {
        std::vector<std::shared_ptr<ObjectBase>> combined = m_collection;
        combined.insert(combined.end(), other.m_collection.begin(), other.m_collection.end());
        return Group{combined};
    }

    // Add a single object to the group
    void add(std::shared_ptr<ObjectBase> obj) {
        m_collection.push_back(obj);
    }

private:
    bool newBackground = false;
    std::vector<std::shared_ptr<ObjectBase>> m_collection;
};

#endif