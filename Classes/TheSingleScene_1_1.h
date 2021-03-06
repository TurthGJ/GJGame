//
//  TheSingleScene_1_1.h
//  GJGame
//
//  Created by GJ on 15/4/24.
//
//

#ifndef __GJGame__TheSingleScene_1_1__
#define __GJGame__TheSingleScene_1_1__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"
#include "TheSingleScene_1_2.h"
#include "JsonImage.h"

USING_NS_CC;
using namespace cocos2d :: ui;
using namespace std;

class TheSingleScene_1_1 : public Layer
{
public:
    TheSingleScene_1_1();
    ~TheSingleScene_1_1();
    Scene* createScene_1();
    void menubutton_1(Ref* pSender,ui::Widget::TouchEventType type);
//    void menubutton_2(Ref* pSender,ui::Widget::TouchEventType type);
    
    void checkimage(float dt);
    
    Sprite* sprite;
    
    JsonImage* _image;
};
#endif /* defined(__GJGame__TheSingleScene_1_1__) */
