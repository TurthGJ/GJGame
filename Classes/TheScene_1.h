//
//  TheScene_1.h
//  GJGame
//
//  Created by GJ on 15/4/13.
//
//

#ifndef __GJGame__TheScene_1__
#define __GJGame__TheScene_1__

#include <stdio.h>
#include "cocos2d.h"
#include "JsonImage.h"
#include "TheSingleScene_1.h"

USING_NS_CC;


class TheScene_1 : public Layer
{
public:
    Scene* createScene();
    void menubutton_1(Ref* pSender);
    void menubutton_2(Ref* pSender);
    void menubutton_3(Ref* pSender);
    void menubutton_4(Ref* pSender);
    void menubutton_5(Ref* pSender);
    void menubutton_6(Ref* pSender);
    void menubutton_7(Ref* pSender);
    void menubutton_8(Ref* pSender);
    JsonImage* image;
    
};

#endif /* defined(__GJGame__TheScene_1__) */
