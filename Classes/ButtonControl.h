//
//  ButtonControl.h
//  GJGame
//
//  Created by GJ on 15/4/14.
//
//

#ifndef __GJGame__ButtonControl__
#define __GJGame__ButtonControl__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"
#include "TheScene_1.h"

USING_NS_CC;
using namespace cocos2d::ui;

class ButtonControl
{
public:
    static ButtonControl* getInstance();
    Button* setButton(char* p,float posX,float posY);
    static ButtonControl* m_instance;
    
private:
   
    ButtonControl(){};
};
#endif /* defined(__GJGame__ButtonControl__) */


