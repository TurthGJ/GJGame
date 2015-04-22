//
//  JsonImage.cpp
//  GJGame
//
//  Created by GJ on 15/4/14.
//
//

#include "JsonImage.h"
#include "cocos2d.h"
#include "network/HttpClient.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "base64.h"

using namespace cocos2d :: network;
USING_NS_CC;
using namespace std;

JsonImage :: JsonImage()
{
    
}

JsonImage :: ~JsonImage()
{
    
}


void JsonImage::httpconnect(const char* p)
{
    HttpRequest* request = new HttpRequest();
    HttpClient* httpClient = HttpClient::getInstance();
    request->setUrl("http://192.168.1.109:80/apigraph?_method=get_result");
    request->setRequestType(HttpRequest::Type::POST);
    
    std::vector<std::string> headers;
    headers.push_back("'X-yunson':'baisong.com'");
    request->setHeaders(headers);
    
    const char* postData = p;
    request->setRequestData(postData ,strlen(postData));
    request->setResponseCallback(CC_CALLBACK_2(JsonImage::onHttpRequestCompleted,this));
    request->setTag("Test");
    httpClient->setTimeoutForConnect(5);
    HttpClient::getInstance()->send(request);
    
    request->release();
}


void JsonImage::onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
    if (!response) {
        return ;
    }
    
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s",response->getErrorBuffer());
        return ;
        
    }
    
    std::vector<char>* buffer = response->getResponseData();
    std :: string info = "";
    info = string(buffer->begin(),buffer->end());
    
    rapidjson::Document str;
    str.Parse<0>(info.c_str());
    if(str.HasParseError())
        CCLOG("GetParseError %s\n",str.GetParseError());
    rapidjson::Value& arraydata = str["data"];
//    CCLOG("%s\n", arraydata["graph"].GetString());
    
    std::string load_str;
    
    load_str =  arraydata["graph"].GetString();
    
    int len = 0;
    unsigned char *buffer_image = NULL;
    len = base64Decode((unsigned char*)load_str.c_str(), (unsigned int)load_str.length(), &buffer_image);
    
    CCLOG("%s\n",buffer_image);
    
    
//    ofstream f1;
//    f1.open("/Users/GJ/Downloads/a.png",ofstream::out);
//    f1<<buffer_image;
    
    if(buffer_image)
    {
        unsigned char *pImageData = new unsigned char(len);
        memcpy(pImageData,buffer_image,len);
        ok = img->initWithImageData(pImageData, len);
        image_base64->initWithImage(img);
    }

//    if(load_str.c_str() != NULL)
//    {
//        image_str = new char[100];
//    }
//    stpcpy(image_str, load_str.c_str());
    
//    Image* img = new Image();
//    bool ok = img->initWithImageData(buffer_image, len);
//    if(ok)
//        image_base64->initWithImage(img);

//    printf("Http Test, dump data: ");
//    for (unsigned int i = 0 ; i < len;i++) {
//        printf("%c",*(buffer_image+i));
//        i++;
//    }
//    printf("\n");
}