#include "Creature.h"

Creature::Creature( ) { };
Creature::~Creature( ) { };
Creature::Creature(xml_node<> *pNode)
{
    /*
    Create creature object from xml node
    */
    for(xml_node<> *cNode = pNode->first_node(); cNode; cNode=cNode->next_sibling())
    {
        if (strcmp(cNode->name(),"name") == 0)
        {
            this->name.assign(cNode->value());
        }
        else if (strcmp(cNode->name(),"status") == 0)
        {
            this->status.assign(cNode->value());
        }
        else if (strcmp(cNode->name(),"description") == 0)
        {
            this->description.assign(cNode->value());
        }
        else if (strcmp(cNode->name(),"vulnerability") == 0)
        {
            this->vulnerabilities.push_back(cNode->value());
        }
        else if (strcmp(cNode->name(),"trigger") == 0)
        {
            this->triggers.push_back(Trigger(cNode));
        }
        else if (strcmp(cNode->name(),"attack") == 0)
        {
            this->attack = Attack(cNode);
        }
    }
};
