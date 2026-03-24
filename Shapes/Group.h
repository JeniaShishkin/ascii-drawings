#ifndef __GROUP_H__
#define __GROUP_H__

#include <memory>
#include <vector>
#include "ObjectBase.h"


class Group
{
private:
    Group(std::vector<std::shared_ptr<ObjectBase>> collection) : m_collection(collection) { }

public:

std::vector<std::shared_ptr<ObjectBase>> m_collection;

};


#endif