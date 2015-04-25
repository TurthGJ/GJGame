//
//  TheScene_1.cpp
//  GJGame
//
//  Created by GJ on 15/4/13.
//
//

#include "TheScene_1.h"
#include "TheSingleScene_1.h"
#include "cocos2d.h"
#include "JsonImage.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

TheScene_1::TheScene_1()
{

}

TheScene_1::~TheScene_1()
{
//    CC_SAFE_DELETE(thescene_1);
}

void TheScene_1::menubutton_1(Ref *pSender)
{
    thescene_1 = new TheSingleScene_1();
    if(thescene_1->createScene_1() != NULL)
    {
        auto scene_1 = TransitionCrossFade :: create(1.0f,thescene_1->createScene_1());
        Director :: getInstance()->pushScene(scene_1);
    }
}

void TheScene_1::menubutton_2(Ref *pSender)
{

}

void TheScene_1::menubutton_3(Ref *pSender)
{

}

void TheScene_1::menubutton_4(Ref *pSender)
{

}

void TheScene_1::menubutton_5(Ref *pSender)
{
    
}

void TheScene_1::menubutton_6(Ref *pSender)
{
    
}

void TheScene_1::menubutton_7(Ref *pSender)
{

}

void TheScene_1::menubutton_8(Ref *pSender)
{
    
}

Scene* TheScene_1 :: createScene()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director :: getInstance()->getVisibleSize();
    auto scene = Scene :: create();
    auto layer = LayerColor :: create(Color4B(0x48,0x3D,0x8B,0x80));
    scene->addChild(layer);
    
    auto label = Label::createWithSystemFont("实验模块", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height - 50));
    layer->addChild(label, 1);
    
    Button* button_1 = Button :: create("button_1.png","button_1.png");
    button_1->setPosition(Vec2(visibleSize.width/4,visibleSize.height * 3/4));
    button_1->setTitleText("确知信号");
    button_1->setTitleFontSize(20);
    button_1->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_1,this));
    layer->addChild(button_1,1);
    
    Button* button_2 = Button :: create("button_1.png","button_1.png");
    button_2->setPosition(Vec2(visibleSize.width * 3/4,visibleSize.height * 3/4));
    button_2->setTitleText("模拟调制系统");
    button_2->setTitleFontSize(20);
    button_2->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_2,this));
    layer->addChild(button_2,1);
    
    Button* button_3 = Button :: create("button_1.png","button_1.png");
    button_3->setPosition(Vec2(visibleSize.width/4,visibleSize.height * 7/12));
    button_3->setTitleText("数字基带传输系统");
    button_3->setTitleFontSize(20);
    button_3->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_3,this));
    layer->addChild(button_3,1);
    
    Button* button_4 = Button :: create("button_1.png","button_1.png");
    button_4->setPosition(Vec2(visibleSize.width * 3/4,visibleSize.height * 7/12));
    button_4->setTitleText("数字带通传输系统");
    button_4->setTitleFontSize(20);
    button_4->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_4,this));
    layer->addChild(button_4,1);
    
    Button* button_5 = Button :: create("button_1.png","button_1.png");
    button_5->setPosition(Vec2(visibleSize.width/4,visibleSize.height * 5/12));
    button_5->setTitleText("新型数字带通调制技术");
    button_5->setTitleFontSize(20);
    button_5->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_5,this));
    layer->addChild(button_5,1);
    
    Button* button_6 = Button :: create("button_1.png","button_1.png");
    button_6->setPosition(Vec2(visibleSize.width * 3/4,visibleSize.height * 5/12));
    button_6->setTitleText("模拟信号的数字传输");
    button_6->setTitleFontSize(20);
    button_6->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_6,this));
    layer->addChild(button_6,1);
    
    Button* button_7 = Button :: create("button_1.png","button_1.png");
    button_7->setPosition(Vec2(visibleSize.width/4,visibleSize.height/4));
    button_7->setTitleText("差错控制编码");
    button_7->setTitleFontSize(20);
    button_7->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_7,this));
    layer->addChild(button_7,1);
    
    Button* button_8 = Button :: create("button_1.png","button_1.png");
    button_8->setPosition(Vec2(visibleSize.width * 3/4,visibleSize.height/4));
    button_8->setTitleText("正交编码与伪随机序列");
    button_8->setTitleFontSize(20);
    button_8->addTouchEventListener(CC_CALLBACK_1(TheScene_1::menubutton_8,this));
    layer->addChild(button_8,1);
    return scene;
}
