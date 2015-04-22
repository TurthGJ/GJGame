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
    image_base64 = NULL;
    sprite = NULL;
    image = nullptr;
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
    button_2->addTouchEventListener(CC_CALLBACK_1(TheSingleScene_1::menubutton_2,this));
    layer->addChild(button_2,1);
    
    return scene;
}

Scene* TheSingleScene_1::createScene_2()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director :: getInstance()->getVisibleSize();
    auto scene = Scene :: create();
    auto layer = LayerColor :: create(Color4B(0x48,0x3D,0x8B,0x80));
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
        if(sizeof(tf->getString()) > 5)
            tf->detachWithIME();
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tf);
    
    Button* button_1 = Button :: create("button_1.png","button_1.png");
    button_1->setPosition(Vec2(visibleSize.width/2 + 150,visibleSize.height - 280));
    button_1->setTitleText("画图");
    button_1->setTitleFontSize(20);
    button_1->addTouchEventListener(CC_CALLBACK_2(TheSingleScene_1::menubutton_3,this));
    layer->addChild(button_1,1);
    
    this->schedule(schedule_selector(TheSingleScene_1::checkimage), 1.0f);
    
    return scene;
}

void TheSingleScene_1::menubutton_1(Ref *pSender,ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::BEGAN)
    {
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
        
        image->httpconnect(buffer.GetString());
    }
}

void TheSingleScene_1::menubutton_2(Ref *pSender)
{

}

void TheSingleScene_1::menubutton_3(Ref *pSender,ui::Widget::TouchEventType type)
{
//    Size visiblesize = Director :: getInstance()->getVisibleSize();
//    image->httpconnect("{'e_params':{'A':2,'T':10,'t':2},'e_id':{'g_id':EXP1,'id':'exp1'}}");
//    CCLOG("%d",image == NULL);
//    Sprite* sprite = Sprite :: createWithTexture(image->image_base64);
//    sprite->setPosition(Vec2(visiblesize.width/2,visiblesize.height/2));
//    addChild(sprite);
}

void TheSingleScene_1::checkimage(float dt)
{
    if(image->ok)
    {
        Size visiblesize = Director :: getInstance()->getVisibleSize();
        image_base64->initWithImage(image->img);
        sprite = Sprite :: createWithTexture(image_base64);
        sprite->setPosition(Vec2(visiblesize.width/4,visiblesize.height/4));
        this->addChild(sprite,10);
    }
}

//void TheSingleScene_1::drawpic(string p)
//{
//    Size visiblesize = Director :: getInstance()->getVisibleSize();
//    int len = 0;
//    unsigned char *buffer_image;
//    len = base64Decode((unsigned char*)p.c_str(), (unsigned int)p.length(), &buffer_image);
//    bool ok = img->initWithImageData(buffer_image, len);
//    if(ok)
//        image_base64->initWithImage(img);
//    sprite = Sprite :: createWithTexture(image_base64);
//    sprite->setPosition(Vec2(visiblesize.width/4,visiblesize.height/4));
//    addChild(sprite,10);
//}
