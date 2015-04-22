//
//  JsonImage.cpp
//  GJGame
//
//  Created by GJ on 15/4/14.
//
//

#include <iostream>
#include "JsonImage.h"
#include "cocos2d.h"
#include "network/HttpClient.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "base64.h"

using namespace cocos2d :: network;
USING_NS_CC;
using namespace std;

string stringFrom(std::vector<char> * pVector) {
    std::stringstream oss;
    for(unsigned int i=0;i < pVector->size();i++) {
        oss<<(*pVector)[i];
    }
    string returnString =oss.str();
    return returnString;
}

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
    request->setUrl("http://img3.douban.com/lpic/s11150673.jpg");
    request->setRequestType(HttpRequest::Type::GET);
    
    request->setResponseCallback(CC_CALLBACK_2(JsonImage::onHttpRequestCompleted,this));
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
    
    std::vector<char>* responseData = response->getResponseData();
    
    string tmpString = stringFrom(responseData);
    const char * buffer=tmpString.c_str();

    char * encode_base64_image_buffer = NULL;
    int encode_base64_image_buffer_length = base64Encode((const unsigned char *) buffer,
                                                  (unsigned int) responseData->size(),
                                                  &encode_base64_image_buffer);
    std::cout << "encode_base64_image_buffer_length:" << encode_base64_image_buffer_length << endl;
    
    unsigned char * decode_base64_image_buffer = NULL;
    int decode_base64_image_buffer_length = base64Decode((const unsigned char *) encode_base64_image_buffer,
                                                         (unsigned int) encode_base64_image_buffer_length,
                                                         &decode_base64_image_buffer);
    std::cout << "decode_base64_image_buffer_length:" << decode_base64_image_buffer_length << endl;
    
    if (decode_base64_image_buffer_length > 0) {
        Image* img = new Image();
        bool ok = img->initWithImageData(decode_base64_image_buffer, decode_base64_image_buffer_length);
        std::cout<< "decode image result:" << ok << endl;
    }else {
        std::cout<< "decode image failed" << endl;
    }
    
}

