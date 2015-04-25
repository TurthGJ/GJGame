//
//  TheSingleScene_1_1.cpp
//  GJGame
//
//  Created by GJ on 15/4/24.
//
//

#include "TheSingleScene_1_1.h"
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

TheSingleScene_1_1::TheSingleScene_1_1()
{
    sprite = NULL;
}

TheSingleScene_1_1::~TheSingleScene_1_1()
{
    CC_SAFE_DELETE(_image);
}

Scene* TheSingleScene_1_1::createScene_1()
{
    _image = new JsonImage();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director :: getInstance()->getVisibleSize();
    auto scene = Scene :: create();
    auto layer = LayerColor :: create(Color4B(0x3F,0x28,0x60,0x80));
    scene->addChild(layer);
    
    auto label = Label::createWithSystemFont("功率信号的频谱特性", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(visibleSize.width/2,visibleSize.height - 50));
    layer->addChild(label, 1);
    
    auto label_1 = Label::createWithSystemFont("一.实验目的：", "fonts/Marker Felt.ttf", 16);
    label_1->setPosition(Vec2(visibleSize.width/2 + 80,visibleSize.height - 80));
    layer->addChild(label_1, 1);
    
    auto label_2 = Label::createWithSystemFont("1.了解典型功率谱信号：周期性方波", "fonts/Marker Felt.ttf", 16);
    label_2->setPosition(Vec2(visibleSize.width/2 + 160,visibleSize.height - 100));
    layer->addChild(label_2, 1);
    
    auto label_3 = Label::createWithSystemFont("2.理解周期性方波的频域特性：频谱与功率谱密度", "fonts/Marker Felt.ttf", 16);
    label_3->setPosition(Vec2(visibleSize.width/2 + 210,visibleSize.height - 120));
    layer->addChild(label_3, 1);
    
    auto label_4 = Label::createWithSystemFont("二.实验步骤及参数：", "fonts/Marker Felt.ttf", 16);
    label_4->setPosition(Vec2(visibleSize.width/2 + 105,visibleSize.height - 140));
    layer->addChild(label_4, 1);
    
    auto label_5 = Label::createWithSystemFont("1.输入周期性方波的幅度A、周期T以及脉冲宽度t", "fonts/Marker Felt.ttf", 16);
    label_5->setPosition(Vec2(visibleSize.width/2 + 205,visibleSize.height - 160));
    layer->addChild(label_5, 1);
    
    auto label_6 = Label::createWithSystemFont("2.点击画图按钮", "fonts/Marker Felt.ttf", 16);
    label_6->setPosition(Vec2(visibleSize.width/2 + 90,visibleSize.height - 180));
    layer->addChild(label_6, 1);
    
    auto label_7 = Label::createWithSystemFont("3.观察左边弹出的周期性方波的频谱以及功率谱密度", "fonts/Marker Felt.ttf", 16);
    label_7->setPosition(Vec2(visibleSize.width/2 + 217,visibleSize.height - 200));
    layer->addChild(label_7, 1);
    
    auto label_8 = Label::createWithSystemFont("4.改变参数再进行观察对比", "fonts/Marker Felt.ttf", 16);
    label_8->setPosition(Vec2(visibleSize.width/2 + 130,visibleSize.height - 220));
    layer->addChild(label_8, 1);
    
    auto label_9 = Label::createWithSystemFont("输入参数：", "fonts/Marker Felt.ttf", 16);
    label_9->setPosition(Vec2(visibleSize.width/2 + 80,visibleSize.height - 240));
    layer->addChild(label_9, 1);
    
    //    TextFieldTTF* text = TextFieldTTF :: textFieldWithPlaceHolder("abc","Arial",16);
    //    text->setPosition(Vec2(visibleSize.width/2 + 80,visibleSize.height - 260));
    //    layer->addChild(text);
    //    text->attachWithIME();
    
    TextFieldTTF *tf = TextFieldTTF::textFieldWithPlaceHolder("abc",Size(40,10),TextHAlignment :: LEFT,"Arial",16);
    //tf->setAnchorPoint(Vec2(0,0));
    tf->setPosition(visibleSize.width/2 + 80,visibleSize.height - 260);
    layer->addChild(tf);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [tf](Touch *t, Event *event)
    {
        if(tf->getBoundingBox().containsPoint(t->getLocation()))
        {
            tf->attachWithIME();
        }
        else
        {
            tf->detachWithIME();
        }
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tf);
    
    Button* button_1 = Button :: create("button_1.png","button_1.png");
    button_1->setPosition(Vec2(visibleSize.width/2 + 150,visibleSize.height - 280));
    button_1->setTitleText("画图");
    button_1->setTitleFontSize(20);
    button_1->addTouchEventListener(CC_CALLBACK_2(TheSingleScene_1_1::menubutton_1,this));
    layer->addChild(button_1,1);
    
    CCLOG("%d\n",_image == NULL);
    
    scene->schedule(schedule_selector(TheSingleScene_1_1::checkimage), 1.0f);
    
    return scene;
}

void TheSingleScene_1_1::menubutton_1(Ref *pSender,ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::BEGAN)
    {
        if(_image)
        {
            CCLOG("%d\n",_image->plen);
        }
        rapidjson::Document document;
        document.SetObject();
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        rapidjson::Value array_1(rapidjson::kArrayType);
        rapidjson::Value array_2(rapidjson::kArrayType);
        rapidjson::Value object_1(rapidjson::kObjectType);
        rapidjson::Value object_2(rapidjson::kObjectType);
        object_1.AddMember("A", 2, allocator);
        object_1.AddMember("T", 10, allocator);
        object_1.AddMember("t", 2, allocator);
        object_2.AddMember("g_id", "EXP1", allocator);
        object_2.AddMember("id", "exp1", allocator);
        document.AddMember("e_params", object_1, allocator);
        document.AddMember("e_id", object_2, allocator);
        
        StringBuffer buffer;
        rapidjson :: Writer<StringBuffer> writer(buffer);
        document.Accept(writer);
        
        _image->httpconnect(buffer.GetString());
    }
}

void TheSingleScene_1_1::checkimage(float dt)
{
//    if(_image->plen > 0)
//    {
    CCLOG("%d\n",_image == NULL);
    
//    }

//    if(_image->plen > 0)
//    {
//        Size visiblesize = Director :: getInstance()->getVisibleSize();
//        sprite = Sprite :: createWithTexture(_image->image_base64);
//        sprite->setPosition(Vec2(visiblesize.width/4,visiblesize.height/4));
//        this->createScene_1()->addChild(sprite,10);
//    }
//    else
//    {
//        CCLOG("%d\n",_image->image_base64 == NULL);
//    }
}
