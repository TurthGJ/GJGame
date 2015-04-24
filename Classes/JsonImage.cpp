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
#include <iostream>

using namespace cocos2d :: network;
USING_NS_CC;
using namespace std;

JsonImage :: JsonImage()
{
    image_base64 = NULL;
    plen = 0;
}

JsonImage :: ~JsonImage()
{
    
}

void JsonImage::httpconnect(const char* p)
{
    HttpRequest* request = new HttpRequest();
    HttpClient* httpClient = HttpClient::getInstance();
    request->setUrl("http://192.168.1.107:80/apigraph?_method=get_result");
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
    
    unsigned char * decode_base64_image_buffer = NULL;
    
    int decode_base64_image_buffer_length = base64Decode((const unsigned char *)load_str.c_str(),
                                                         (unsigned int) load_str.length(),
                                                         &decode_base64_image_buffer);
    
    plen = decode_base64_image_buffer_length;
    
    if (decode_base64_image_buffer_length > 0) {
        Image* img = new Image();
        bool ok = img->initWithImageData(decode_base64_image_buffer, decode_base64_image_buffer_length);
        image_base64->initWithImage(img);
        cout<< "decode image result:" << ok << endl;
    }else {
        std::cout<< "decode image failed" << endl;
    }
        
//    if(buffer_image)
//    {
//        unsigned char *pImageData = new unsigned char(len);
//        memcpy(pImageData,buffer_image,len);
//        ok = img->initWithImageData(pImageData, len);
//        image_base64->initWithImage(img);
//    }

//    printf("Http Test, dump data: ");
//    for (unsigned int i = 0 ; i < len;i++) {
//        printf("%c",*(buffer_image+i));
//        i++;
//    }
//    printf("\n");
}