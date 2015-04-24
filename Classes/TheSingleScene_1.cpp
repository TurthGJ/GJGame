//
//  TheSingleScene_1.cpp
//  GJGame
//
//  Created by GJ on 15/4/15.
//
//

#include "TheSingleScene_1.h"
#include "JsonImage.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
 #include "json/writer.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;
using namespace rapidjson;

TheSingleScene_1 :: TheSingleScene_1()
{

}

TheSingleScene_1 :: ~TheSingleScene_1()
{
    
}

Scene* TheSingleScene_1 :: createScene_1()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director :: getInstance()->getVisibleSize();
    auto scene = Scene :: create();
    auto layer = LayerColor :: create(Color4B(0x48,0x3D,0x8B,0x80));
    scene->addChild(layer);
    
    auto label = Label::createWithSystemFont("确知信号", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height - 50));
    layer->addChild(label, 1);
    
    auto label_1 = Label::createWithSystemFont("本模块功能：", "fonts/Marker Felt.ttf", 24);
    label_1->setPosition(Vec2(visibleSize.width/5,visibleSize.height - 150));
    layer->addChild(label_1, 1);
    
    auto label_3 = Label::createWithSystemFont("（1）典型的功率信号：周期性方波", "fonts/Marker Felt.ttf", 24);
    label_3->setPosition(Vec2(visibleSize.width/5 + 250,visibleSize.height - 150));
    layer->addChild(label_3, 1);
    
    auto label_4 = Label::createWithSystemFont("显示周期性方波的频谱及其功率谱密度的波形", "fonts/Marker Felt.ttf", 24);
    label_4->setPosition(Vec2(visibleSize.width/5 + 365,visibleSize.height - 200));
    layer->addChild(label_4, 1);
    
    auto label_5 = Label::createWithSystemFont("（2）典型的能量信号：矩形脉冲", "fonts/Marker Felt.ttf", 24);
    label_5->setPosition(Vec2(visibleSize.width/5 + 240,visibleSize.height - 250));
    layer->addChild(label_5, 1);
    
    auto label_6 = Label::createWithSystemFont("显示矩形脉冲的频谱密度及其能量谱密度的波形", "fonts/Marker Felt.ttf", 24);
    label_6->setPosition(Vec2(visibleSize.width/5 + 380,visibleSize.height - 300));
    layer->addChild(label_6, 1);
    
    auto label_7 = Label::createWithSystemFont("实验", "fonts/Marker Felt.ttf", 24);
    label_7->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2 - 100));
    layer->addChild(label_7, 1);
    
    Button* button_1 = Button :: create("button_1.png","button_1.png");
    button_1->setPosition(Vec2(visibleSize.width/4,visibleSize.height/2 - 180));
    button_1->setTitleText("实验一");
    button_1->setTitleFontSize(20);
    button_1->addTouchEventListener(CC_CALLBACK_2(TheSingleScene_1::menubutton_1,this));
    layer->addChild(button_1,1);
    
    Button* button_2 = Button :: create("button_1.png","button_1.png");
    button_2->setPosition(Vec2(visibleSize.width * 3/4,visibleSize.height/2 - 180));
    button_2->setTitleText("实验二");
    button_2->setTitleFontSize(20);
    button_2->addTouchEventListener(CC_CALLBACK_2(TheSingleScene_1::menubutton_2,this));
    layer->addChild(button_2,1);

    
    return scene;
}


void TheSingleScene_1::menubutton_1(Ref *pSender,ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::BEGAN)
    {
        thescene_1 = new TheSingleScene_1_1();
        if(thescene_1->createScene_1() != NULL)
        {
            auto scene_1 = TransitionCrossFade :: create(1.0f,thescene_1->createScene_1());
            Director :: getInstance()->pushScene(scene_1);
        }
    }
}

void TheSingleScene_1::menubutton_2(Ref *pSender,ui::Widget::TouchEventType type)
{

}






