//
//  TheSingleScene_1.h
//  GJGame
//
//  Created by GJ on 15/4/15.
//
//

#ifndef __GJGame__TheSingleScene_1__
#define __GJGame__TheSingleScene_1__

#include <stdio.h>
#include "cocos2d.h"
#include "JsonImage.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"


USING_NS_CC;
using namespace cocos2d :: ui;
using namespace std;

class TheSingleScene_1 : public Layer
{
public:
    TheSingleScene_1();
    ~TheSingleScene_1();
    Scene* createScene_1();
    Scene* createScene_2();
    void menubutton_1(Ref* pSender,ui::Widget::TouchEventType type);
    void menubutton_2(Ref* pSender);
    void menubutton_3(Ref* pSender,ui::Widget::TouchEventType type);
    
    void checkimage(float dt);
    
    string p;
    
    JsonImage* image;
    Sprite* sprite;
    Texture2D* image_base64;
//    void menubutton_4(Ref* pSender);
//    void menubutton_5(Ref* pSender);
//    void menubutton_6(Ref* pSender);
//    void menubutton_7(Ref* pSender);
//    void menubutton_8(Ref* pSender);
};

#endif /* defined(__GJGame__TheSingleScene_1__) */
