//
//  JsonImage.h
//  GJGame
//
//  Created by GJ on 15/4/14.
//
//

#ifndef __GJGame__JsonImage__
#define __GJGame__JsonImage__

#include <stdio.h>
#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "network/HttpClient.h"
using namespace cocos2d :: network;
USING_NS_CC;

class JsonImage
{
public:
    JsonImage();
    ~JsonImage();
    void httpconnect(const char* p);
    void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);
    Texture2D* image_base64;
    Image* img;
    bool ok;
};

#endif /* defined(__GJGame__JsonImage__) */
