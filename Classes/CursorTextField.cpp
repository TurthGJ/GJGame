//
//  CursorTextField.cpp
//  GJGame
//
//  Created by GJ on 15/4/17.
//
//

#include "CursorTextField.h"

using namespace std;


//void CursorTextField::setString(const std::string &text)
//{
//    
//    
//    static char bulletString[] = {(char)0xe2, (char)0x80, (char)0xa2, (char)0x00};
//    std::string displayText;
//    size_t length;
//    
//    if (text.length()>0)
//    {
//        _inputText = text;
//        displayText = _inputText;
//        if (_secureTextEntry)
//        {
//            displayText = "";
//            length = _inputText.length();
//            while (length)
//            {
//                displayText.append(bulletString);
//                --length;
//            }
//        }
//    }
//    else
//    {
//        _inputText = "";
//    }
//    
//    // if there is no input text, display placeholder instead
//    if (0 == _inputText.length())
//    {
//        Label::setTextColor(_colorSpaceHolder);
//        Label::setString(_placeHolder);
//    }
//    else
//    {
//        std::string  tstring;
//        tstring = string(_inputText) + string("|");
//        Label::setString(tstring.c_str());
//        Label::setTextColor(_colorText);
//        Label::setString(displayText);
//    }
//    _charCount = _calcCharCount(_inputText.c_str());
//}
//
//void CursorTextField::blick(struct timeval *start)
//{
//    DEBUG_MSG("CCTextInputAction blick %s" , m_pInputText->c_str());
//    std::string  tstring;
//    if(string(m_pInputText->c_str()) == string(""))
//        return;
//    if(m_blick == true )
//    {
//        tstring = string(m_pInputText->c_str()) + string("|");
//    }
//    else
//    {
//        tstring = string(m_pInputText->c_str()) ;
//    }
//    DEBUG_MSG("CCTextInputAction setstring %s" ,tstring.c_str());
//    CCLabelTTF::setString(tstring.c_str());
//    m_blick = !m_blick;
//}