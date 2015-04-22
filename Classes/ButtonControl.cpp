//
//  ButtonControl.cpp
//  GJGame
//
//  Created by GJ on 15/4/14.
//
//

#include "ButtonControl.h"
#include "TheScene_1.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"

USING_NS_CC;
using namespace cocos2d::ui;

ButtonControl* ButtonControl :: getInstance()
{
    if (m_instance == NULL)
    {
        m_instance = new ButtonControl();
    }
    return m_instance;
}


Button* ButtonControl::setButton(char* p,float posX,float posY)
{
    Button* button = Button :: create("button_1.png","button_1.png");
    button->setName(p);
    button->setPosition(Vec2(posX,posY));
    return button;
}
