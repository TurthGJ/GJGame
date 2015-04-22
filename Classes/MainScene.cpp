#include "MainScene.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIButton.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Button* button = Button :: create("button_1.png","button_1.png");
    button->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2 - 150));
    button->setTitleText("进入实验");
    button->setTitleFontSize(24);
    button->addTouchEventListener(CC_CALLBACK_1(MainScene::menuCloseCallback,this));
    this->addChild(button);
    
    int len = 0;
    unsigned char *buffer_image;
    string p = "iVBORw0KGgoAAAANSUhEUgAAAeAAAAFoCAYAAACPNyggAAAABHNCSVQICAgIfAhkiAAAAAlwSFlzAAAJOgAACToB8GSSSgAAIABJREFUeJzsnXtclGX6/9+DgAwpp1YBAUMdVLARMA9ZmpRaakpm5anwkG2uu2VttWttW1rbVzOzcrNa62daq2FrZloJWhp4WsNMA7MUAhUGxAOgAYMIPL8/ZmdiFHA4DPPcD/f79eL1Yua55pnPdT2Ha+77ue/r1imKoiCRSCQSiaRVcXO1AIlEIpFI2iIyAUskEolE4gJkApZIJBKJxAXIBCyRSCQSiQuQCVgikUgkEhcgE7BEIpFIJC5AJmCJRCKRSFyATMASiUQikbgAmYAlEolEInEBMgFLJBKJROICZAKWSCQSicQFyAQskUgkEokLkAlYIpFIJBIXIBOwRCKRSCQuQCZgiUQikUhcgEzAEolEIpG4AJmAJRKJRCJxATIBSyQSiUTiAmQClkgkEonEBcgELJFIJBKJC5AJWCKRSCQSFyATsEQikUgkLkAmYIlEcKqqqlwtQSKRNAGZgCWSZrJ48WJCQ0Px8fGhd+/e7NixAwCz2cyMGTMICAigT58+LFmyhLCwMNvn3NzcyM7Otr2eMWMGzz33HAAXLlzgzjvvpHPnzvzud79j6tSpnD9/3mYbHh7OK6+8Qt++fenYsSM1NTXs27ePm266CX9/f2JiYkhNTa1T76pVq4iPj7e9joiIYOLEibbXYWFhpKenAzBp0iSCg4Px9/fnzjvvxGQyAfDxxx8zYMAAu/0uWbKECRMmAHDx4kWeeuoprrvuOoKCgpgzZw4VFRWND65EomFkApZImsHRo0d56623+O6777hw4QLbtm0jPDwcgBdeeIGcnByys7PZunUrH3zwATqdrt596XQ623ZFUXj44YfJy8vj2LFj5Ofn8+KLL9rZr1u3jqSkJEpKSigoKGDs2LE8//zzFBcX8+qrr3LPPfdw9uzZK74nLi6O3bt3A5Cfn8+lS5fYt28fANnZ2ZSVldG3b18Axo0bxy+//ILJZMLHx4e5c+fa3j969ChZWVm2/SYmJnL//fcD8PTTT5OVlcUPP/xAVlYWJpPpCv0SSVtHJmCJpBm0a9eOixcv8uOPP3Lp0iW6du1K9+7dAVi/fj3PPvssfn5+hIaG8thjj6EoSoP7s2739fXlrrvuwtPTk4CAAB599FF27dpls9PpdMydO5eQkBDat2/PmjVrGDNmDKNGjQJgxIgR9O/fny1btlzxHd26daNDhw788MMPpKamMmrUKIKDgzl69CipqanccsstNtsHHngAb29vvL29eeqpp2wavL29ueuuu0hMTAQsP0Sys7MZN24ciqLw3nvv8dprr+Hn50eHDh145plnWLduXTMiLZFoD5mAJZJmYDAYeOONN1iwYAGBgYFMmTKFgoICwNK6rN3l3LVrV4f3W1paysyZM+natSu+vr7MmDGDc+fO2dnU3veJEydYv349/v7+tr89e/Zw6tSpOvc/bNgwUlNT2blzJ3Fxcdxyyy2218OGDQMsz5affPJJunfvjq+vL7fddpudhqlTp9oScGJiInfffTeenp6cOXOG8vJybrjhBpuW0aNH19kal0jaMjIBSyTNZMqUKezatYsTJ06g0+mYN28eAMHBwZw8edJmV/t/sLQiy8vLba8LCgpsXdBLly7l5MmTfP/995w/f57Vq1dTU1Nj9/na3dldu3YlISGB4uJi29+vv/7KX//61zo1Dxs2jJSUFFJTU4mLi7N7bU3Aa9euZevWrezcuZPz58+zY8cOuxb8iBEjOHPmDD/88APr1q1jypQpAPzud79Dr9dz5MgRm5aSkhIuXLjQ6NhKJFpGJmCJpBkcO3aMHTt2cPHiRdq3b4+Xlxft2rUDYOLEiSxatIiSkhLy8vJ488037ZJmTEwMa9eupbq6muTkZHbu3GnbVlZWhl6vx8fHh1OnTvH66683qOOBBx7g888/Z9u2bVRXV1NRUUFKSopt0NTlDBs2jK+//hpFUQgKCmLIkCEkJSVRVFREbGysTYOnpyd+fn6cP3+ehQsX2u3Dw8OD++67j6eeeorz588zYsQIwDK47Pe//z2PP/44Z86cAcBkMrFt27ZGRlci0TYyAUskzeDixYs888wzdOrUieDgYM6ePcuiRYsAmD9/Ptdddx3dunVj1KhRTJs2za4FuWzZMj7//HP8/f356KOPuPvuu23bHn/8cc6fP8+1117LqFGjiI+Pb3AAV2hoKJs2bWLhwoV07tyZrl27snTp0itazVYiIiLo0KGD7Xmvn58f3bp14+abb7Z9z7Rp0+jSpQvBwcEMHDiQ22677QoNU6dOZfv27dx33324uf12O1m8eDEGg4Ebb7wRX19fRo4cybFjxxoZXYlE2+iUq40KkUgkLUJKSgoJCQnk5ua6WopEIlEBwrSAKyoqGDRoEDExMURFRfHMM8/UaTd37lwiIiKIjo7m4MGDraxSIpFIJBLHcHe1AEfx8vLim2++wdvbm6qqKoYMGcLu3bsZMmSIzWbLli1kZWWRmZnJt99+y5w5c2zzGyUSNdBQN7JEImlbCNMCBsuoUYDKykqqq6sJCAiw275582amT58OwKBBgygpKaGwsLDVdUokdREXF3fFSGiJRNJ2EaYFDFBTU0O/fv345ZdfmDNnDlFRUXbbTSaT3dzI0NBQ8vLyCAwMBMDHxwcfHx88PT0By2hNDw8PdDod1dXVKIqCu7slJNZRrWBJ+NJO2kk7aSftXGtnrXteWVlJcXExZWVlCI0iICUlJcqgQYOUb775xu79sWPHKrt377a9Hj58uHLgwAHb68jISOWjjz5S0tLSlLS0NCUzM1MpLy9XFEVRzp07p+Tl5dls09PTbf9fbrdr1y5lw4YNSlpaWoN2ju5PbXbLly9XPvroI9Xqa67dhg0blNdee021+pprt2HDBmX16tWq1dccuy+++MJ27alRX3Pt9u/fr7z77rtKWlqaKvU1127Dhg3K8uXLm7w/6737o48+Urp166aIjrCjoP/xj3+g1+t56qmnbO/94Q9/IC4ujsmTJwPQu3dvUlNTbS3gqKgojhw50iLfv3//foArCtJrAS37BtI/0ZH+iUtL+taS93NXIcwz4LNnz1JSUgJYVpn56quvbAUDrMTHx/Phhx8CsG/fPvz8/GzJVyKRSCQSNSHMM+CCggKmT59OTU0NNTU1JCQkMHz4cFasWAHA7NmzGTNmDFu2bMFgMHDNNdewatUqp2jJyMjAy8sLo9HolP27Gi8vL1dLcCrSP3HR+rWndf+0fG42BWG7oJuCFrosJBKJRKKN+7kwXdASiUQikWgJmYCbgMlkqrfIvRaQ/omNlv3Tsm8g/WtrCPMMWE3o9XpXS3Aq0j+x0bJ/WvYNpH9tDZmAm8DlFbi0hvRPbLTsn5Z9A+lfW0N2QTcBs9mM2Wx2tQynIf0TGy37p2XfQPrX1hAmAefm5nLrrbfSp08frr/+ev75z39eYZOSkoKvry+xsbHExsby0ksvOUWL1p9jSP/ERsv+adk3kP61NYSZhnTq1ClOnTpFTEwMpaWl3HDDDXz22WdERkbabFJSUnjttdfYvHlznfvQwrB1iUQikWjjfi5MCzgoKIiYmBgAOnToQGRkJPn5+VfYCfJ7QiKRSCRtHGEScG2OHz/OwYMHGTRokN37Op2OvXv3Eh0dzZgxY+r8dZSYmMj+/fvZv38/WVlZtucRRUVFdl0jGRkZtv8vt/v6669t2xuyc3R/arP78ssvbTVb1aivuXYZGRl8+umnqtXXXLuMjAx2796tWn3Nsfv0009ttmrU11y73bt38/XXX6tWX3PtMjIy+PLLL5u8P+u9OzExkYqKCkRHuFHQpaWl3HvvvSxbtowOHTrYbevXrx+5ubl4e3uTlJTE+PHjOXbsWItriIyMJCQkpMX3qxZ69eqlaf+0WubPitFopKioSJODXSIiIjR9/KKiojR53KwYjUY5FakWwjwDBrh06RJjx45l9OjRPP7441e179atGwcOHLANfdfCMwOJRCKRaON+LkwXtKIozJo1i6ioqHqTb2Fhoe0ZcFpaGoqiOGXemdZH8kn/xEbL/mnZN5D+tTWE6YLes2cPa9asoW/fvrZlCBcuXMjJkycBy2pIn3zyCe+88w7u7u54e3uzbt06p2jReheK9E9stOyfln0D6V9bQ6gu6OaihS4LiUQikWjjfi5MF7Sa0Ho1F+mf2GjZPy37BtK/toZMwE1A688xpH9io2X/tOwbSP/aGrILWiKRSCTCoYX7uWwBSyQSiUTiAmQCbgIZGRl2FVu0hvRPbLTsn5Z9A+lfW0OYLujc3FymTZvG6dOn0el0PPzww8ydO/cKu7lz55KUlIS3tzerV6+2TVkCbXRZSCQSiUQb93Nh5gF7eHjw+uuv262GNHLkSLvVkLZs2UJWVhaZmZl8++23zJkzh3379rlQtUQikUgkdSNMF7QjqyFt3ryZ6dOnAzBo0CBKSkooLCxscS1aH8kn/RMbLfunZd9A+tfWECYB16a+1ZBMJhNhYWG216GhoeTl5dnZtMRqSCUlJRQX60lPhw0bMkhPh/R0+OKLLNLSzKSnw65dRXz1lcm2zVG7Tz/NoLq67u9trVVNCgoKbP+rbTWVlrDz9NSzfXtOix43q11enuv91ev1VFRUuDzOzrDLycnBbNa3+HGz2p0751p/KyoqKCkpcXmcnWWn1+v59tuCJh+3jz7az0cf7WfxYrkakktoaDUkuHI9YJ1O1+Ia/Pz8GDs2gJ494cIF8POzvP/rr6DXg7s7XLwI1dXg7W3ZVlLimN3u3RASApf9tmhV/Pz8nFJDWy0cPx7A3/7my9ChltctcdxKSsDXF376CTZsaH2famM9dloseODr68vLLwdw8iR4erbMcbPaZWTAQw+BA+u8OA1/f39NHjcrPj4BzJxZxO23N+24WUNTWuoa/S2NMIOw4OqrIf3hD38gLi6OyZMnA9C7d29SU1MJDAwEWu6hvdlspn9/SE/X065ds3dnx+9/DzNmwM03t+x+G4P1BqDVuq0pKWZWr4bVq1vWv5oa6NsXDh9u0d02Gi0fP7PZzO9/D3Pn6hk4sGX3/a9/QWUl1DG2s9XQ8rEDOH/ezNChlntnc9HCICxhuqAdWQ0pPj6eDz/8EIB9+/bh5+dnS74ticlkorLShBMa1+h04OqfRFp/TnP6tIny8pb3Tw3HDrR9/EwmE2Vl8toTFZPJRFWVdv1rLMJ0QTuyGtKYMWPYsmULBoOBa665hlWrVjlFi8FgwNMTzd4EDAaDawU4mZAQg62bqyVxxvnQFLR8/AwGAx07ymtPVLp3N+Dl5WoV6kGYBDxkyBBqamquard8+fJWUGNBqzcBraMo6kmWksbjrOMnrz3nI689e4TpglYTGRkZVFQ4p5qLGm4CWq9Wk5WVQVGRdv3T8vHLyMiguDhDswlYy8cOnHvvFBFhWsBqwmg0Oq0bRQ03AaPR6FoBTqZbNyO/+52rVTgPLR8/o9GIr692W8BaPnYAffoYbSOeJbIFrDrUcBPQOrIbTGxkF7S4yGvPHpmAm4DJZOLSJeeM5FPDTUDrIzFPn7aMpNUqWj5+chS02Djz3ikisgu6Cej1etyc9NNFDTcBrc5BtOLpqcfDw9UqnIeWj5/12tNqAtbysQPw8mr52gkiI0wL+MEHHyQwMLDeZyQpKSn4+voSGxtLbGwsL730ktO0BAQE0K6dcypFqeEmEBAQoOlKWB07BqDXa9c/LR+/gIAAPD0DNJuAtXzsAPz8AvDw0K5/jUWYFvDMmTN59NFHmTZtWr02w4YNY/PmzU7XYjabscyIavlfq2q4CWi9Gk9Fhfl/9ba16Z+Wj5/ZbKaqCnQ6ee2JSHm58+6dIiJMC3jo0KH4+/s3aNNaVTWdWc1FDTcBrT+HOnNGPgMWFZPJUsVMqy1gLR87gPx8+Qy4NsIk4Kuh0+nYu3cv0dHRjBkzpt4aoS2xGpJer8fT03BVu6asGnLuXIbtJuCqVU0AQkJCWv17W8uuSxcD1dXmFtuf2uwMBgMBAQGq1dccO7PZzDXXGNDpWv57T5/OorLStf4GBATYtX7Vfjwaa9etm+XYNXV/1nt3YqJcDUlV9OvXj9zcXLy9vUlKSmL8+PEcO3bM1bIajRp+hWsdORVCbJx5/OS151zktWePUKshHT9+nHHjxjlUKaZbt24cOHDAbkBDS62ekZGRwfjx8MsvLT9p/sknYcQIGD26xXftMNb4arUowDvvZPDf/8KHH7a8f336wI8/tvhuG4WWj19GRgaPPw5vvWWkd++W3fdHH0F2Nvz97y2738ag5WMHsHNnBn/+Mxw40Hz/tLAakmZawIWFhXTu3BmdTkdaWhqKojhtNKGshCU24eFGsrJcrcJ5aPn4GY1GfHy0Ow1Jy8cOIDLSSMeOrlahHoRJwFOmTCE1NZWzZ88SFhbGCy+8wKVLlwDLSkiffPIJ77zzDu7u7nh7e7Nu3ToXK24aargJaB3ZDSY2shKWuMhrzx5hEnBiYmKD2//0pz/xpz/9qVW0WKq5AIS0+L7VcBOwDoqwDsTSGmfPmigtBWccPzWg5eNnGQUNOp289kQkP99EZSVo9dprLMIkYDUhK2GJjYeHrIQlKrISlti0by8rYdVGJuAmYKmE5Zx9q+EmoOVKPAAdOgRoekUWLR+/gIAAPDy0m4C1fOzAUgnL09PVKtSDZuYBtyaWSljmqxs2ATXcBMxms23+nRapqDBTVaVd/7R8/CyVsMyaTcBaPnZgrYSlXf8ai0zATUBWwhKbc+dkJSxRMZlMmM2yEpaoFBSYqKzUrn+NRXZBNwGDweC0bhQ13AQMBoNrBTiZoCADWu7p0/LxMxgMeHtrtwtay8cOIDzcwDXXuFqFehCmBXy11ZAA5s6dS0REBNHR0Rw8eLAV1bUcargJaB05FUJs5DQkcZHXnj3CJOCZM2eSnJxc7/YtW7aQlZVFZmYm7777LnPmzHGaloyMDCoqrl6Nqymo4SaQkZHhULUxUTl+PIMzZ7Trn5aPX0ZGBhcuZGg2AWv52AH89FMGpaXa9a+xCNMFPXToUI4fP17v9s2bNzN9+nQABg0aRElJCYWFhQQGBra4FlkJS2y6djVSVORqFc5Dy8fPaDTSoYN2W8BaPnYAvXpZKplJLAjTAr4aJpOJsLAw2+vQ0FDy8vKusGuJ1ZCcaXf6tOtXQ9K6naJg1wJWmz5p17CdtRuzpb/31CnXr4akdTtFgfLypu9ProakYi5fV0J32c/kkhJ46ilo397yul07cHcHNzeoroaaGmwFGioqsLVyKyvt7SorC7A0rFu+mktQEDz7LCxYcOX3OqqvuXZlZadwd4f27Q2t+r2tZWc2m7jrrkKg5VsbnTtbFtJwpb/V1Saqq4tp185fiOPRGLvS0kLc3AK45poQWvr+e+21sHEjJCe7zt+KinwUpQK9PsSlcXaW3cWLJqKjTyErYVnQzGpIf/jDH4iLi2Py5MkA9O7dm9TUVLsu6JZaPaPof/2XWp00L/0TGy37p2XfQPrXGORqSCoiPj6e5cuXM3nyZPbt24efn59Tnv+Cdi8OK9I/sdGyf1r2DaR/bQ1hEvDVVkMaM2YMW7ZswWAwcM0117Bq1SqnabE+l9Bq3Vbpn9ho2T8t+wbSv7aGMAn4aqshASxfvrwVlPy2YolWJ81L/8RGy/5p2TeQ/rU1hHoG3Fy08MxAIpFIJNq4n2tmGpJEIpFIJCIhE3AT0Hq1Gumf2GjZPy37BtK/tobsgpZIJBKJcGjhfi5bwBKJRCKRuAChEnBycjK9e/cmIiKCxYsXX7E9JSUFX19fYmNjiY2N5aWXXnKKDq2v2Sn9Exst+6dl30D619YQZhpSdXU1jzzyCF9//TUhISEMGDCA+Ph4IiMj7eyGDRvG5s2bnapF63PYpH9io2X/tOwbSP/aGsIk4LS0NAwGA+Hh4QBMnjyZTZs2XZGAW+ORttaruUj/xEbL/mnZN5D+tTWE6YKua7Wjy7sydDode/fuJTo6mjFjxtT5gL4lVvn45ZdfbK9dvbqIM+wOHz5sq9mqRn3NtTObzezfv1+1+pprZzabr+jqU5O+5tjt37/ftk2N+pprZzKZ+OWXX1Srr7l2ZrOZw4cPt+j3iowwLeDLVzaqi379+pGbm4u3tzdJSUmMHz+eY8eO2dkcPnzYtoyVv79/k7QUFBSgKIpmq7kUFhYC2v21ajKZOH36tKtlOA2TyURJSQnBwcGultLinD59GpPJpNlrr6CggIqKCnr06OFqKU7BZDJRWFjYZP+sP5yzsrI0sRyhMNOQ9u3bx4IFC0hOTgZg0aJFuLm5MW/evHo/061bNw4cOGBLJFFRUXzwwQe27QMGDHCuaIlEIpG0GLV7riZNmkR2drYL1TQfYVrA/fv3JzMzk+PHj9OlSxc+/vjjK+pDFxYW0rlzZ3Q6HWlpaSiKckUrTiZdiUQiEZPa928v60LEAiNMAnZ3d2f58uXccccdVFdXM2vWLCIjI1mxYgVgWRHpk08+4Z133sHd3R1vb2/WrVvnFC3W5w9GY8sv6K4GpH9io2X/tOwbSP/aGsJ0QbcEWqicIpFIJBJt3M+FGQUtkUgkEomWkAm4CWi9mov0T2y07J+WfQPpX1tDmGfAakLr1Vykf2KjZf+07BtI/9oaMgE3Aa3Oj7Ui/RMbLfunZd9A+tfWkF3QTcBabUirSP/ERsv+adk3kP61NYRKwFdbDQlg7ty5REREEB0dzcGDB52iQ+vPMaR/YqNl/7TsG0j/2hrCJGDrakjJyckcOXKExMREfvrpJzubLVu2kJWVRWZmJu+++y5z5sxxihaDwUBxcbFdVRYtUVxcTHFxsatlOA3pn7ho/drTun9aPjebgjAJuPZqSB4eHrbVkGqzefNmpk+fDsCgQYMoKSmx1TWWSCQSiURNCJOAHVkNqS6bvLw8O5uWWOXj66+/Jisrq8X2pza73bt32ya4q1Ffc+2ysrLYsWOHavU11y4rK4tDhw6pVl9z7D799FPbtadGfc212717N2lpaarV11y7rKwsdu/eLVdD+h/CjIJ2ZDUkuHI94Nqfy8vL46677rK9bk4tUetKHFqoR3o5Vt/qe84uOlb/ai/MoSWs/r3++usuVuIctHztgbb9s/r23nvvNevzgCZ6N4VJwCEhIeTm5tpe5+bmEhoa2qBNXl4eISEhttcXLlywe7YiF2aQSCQScdDas3FhErAjqyHFx8ezfPlyJk+ezL59+/Dz8yMwMNDORiZdiUQiEROt3b+FeQZcezWkqKgoJk2aZFsNyboi0pgxY+jevTsGg4HZs2fz9ttvu1i1RAJHjx4lJiYGHx8fli9f7mo5EolELSiSRvGf//xHiYqKUtzc3JQDBw7Y3s/JyVG8vLyUmJgYJSYmRpkzZ44LVTaN+nxTFEVZuHChYjAYlF69eilbt251kcKWY/78+UpISIjteCUlJTntux588EHliSeecNr+a5OUlKT06tVLMRgMyssvv9wq39maXHfddYrRaFRiYmKUAQMGuFpOs5k5c6bSuXNn5frrr7e9d+7cOWXEiBFKRESEMnLkSKW4uNiFCptHXf615rWndoRpAasFo9HIxo0bueWWW67YZjAYOHjwIAcPHhSy9V2fb0eOHOHjjz/myJEjJCcn88c//pGamhoXqWwZdDodTzzxhO14jRo1ymnfdeLECaKiourcVl1d3WLf48hcedHR6XSkpKRw8OBBu9HCojJz5kySk5Pt3nv55ZcZOXIkx44dY/jw4bz88ssuUtd86vKvNa89tSMTcCPp3bs3PXv2dLUMp1Cfb5s2bWLKlCl4eHgQHh6OwWDQxM1PaYWlsG+77TZSUlJ45JFH6NixI/fffz9z5sxhzJgxdOjQgdTUVPLz87nnnnvo3Lkz3bt3580337R93mw2M2PGDAICAujTpw9Lliyxm2rn5uZGdnY2YJkrbzabWblypW2u/Msvv0xMTAz+/v7cfPPNdtM3wsPDWbp0KdHR0fj5+TF58mQuXrxo275p0yZiYmLw9fXFYDCwdetW1q9fT//+/e18fOWVV7j33nudFcIraI3j1loMHToUf39/u/dq1zOYPn06n332mSuktQh1+QfaOobNQSbgFiQnJ4fY2Fji4uLYvXu3q+W0GPn5+XYjzuuagy0ib775JtHR0cyaNYuSkhKnfMeOHTsYOnQob731Fr/++iseHh4kJiby3HPPUVpayuDBgxk3bhyxsbHk5+ezfft23njjDbZt2wbACy+8QE5ODtnZ2WzdupUPPvig3il5JpOJa665xra9qqqK9evX895771FUVMTs2bOJj4/n0qVLgKUlsn79erZu3UpOTg7p6emsXr0asCTz6dOns3TpUs6fP8/OnTsJDw/nrrvuIicnh59//tn2vWvWrGHatGlOid/l6HQ6RowYQf/+/Zs8lUXtFBYW2gaPBgYGamK6zeW0xrUnAjIB18HIkSMxGo1X/H3++ef1fqZLly7k5uZy8OBBXnvtNaZOncqvv/7aiqodoym+1YWj87JdSX2+bt68mTlz5pCTk8OhQ4cIDg7mySefbDVd48ePZ/DgwQCkp6dz9uxZ/v73v+Pu7k63bt146KGHWLduHQDr16/n2Wefxc/Pj9DQUB577LF6Ww+XH5NvvvmG66+/ngEDBqDT6Zg2bRrt27dn3759Npu5c+cSFBSEv78/48aN49ChQwCsXLmSWbNmMXz4cMByfvfq1QtPT08mTpzImjVrbPrz8/MZM2ZMywapHvbs2cPBgwdJSkrirbfeYteuXa3yva5Cp9MJca01Bldee2pDmGlIrclXX33V6M94enri6ekJQL9+/ejRoweZmZn069evpeU1i6b4drX51WrFUV8feughxo0b52Q1FnQ6nV3sTpw4QX5+vl03XXV1te05fH5+vl2Xc9euXevdd0hICGVlZbbXeXl55OTk2O370qVL5Ofn216UBSXHAAAgAElEQVQHBQXZ/tfr9RQUFNg+e+edd9b5PdOnT2fq1Km89NJLrFmzhkmTJuHu3jq3kuDgYAA6derE3XffTVpaGkOHDm2V724tAgMDOXXqFEFBQRQUFNC5c2dXS2pRavvTmteeGpEt4GZQuyVy9uxZ24Ca7OxsMjMz6d69u6ukNZvavsXHx7Nu3ToqKyvJyckhMzOTgQMHulBd87EmGoCNGzdiNBpb7btrt2i6du1Kt27dbEXqi4uLuXDhAl988QVgSTgnT5602df+H8Db25vy8nLAMle+uLiYkpISKisrOXfuHH/605/s9l1aWsqkSZOuqjEsLMxW8vFybrzxRjw9PUlNTWXdunUkJCQ0OgZNoby83NarVFZWxrZt21r1uLUW8fHxtiptH3zwAePHj3exopbFldee2pAJuJFs3LiRsLAw9u3bx5133sno0aMBSE1NJTo6mtjYWO677z5WrFiBn5+fi9U2jvp8i4qKYuLEiURFRTF69Gjefvtt4bvF5s2bR9++fYmOjiY1NbXVyjZe3n08cOBAOnbsyCuvvILZbKa6uprDhw/z3XffATBx4kQWLVpESUkJeXl5vPnmm3axj4mJYe3atVRXV/P1119TU1PD2rVriYqKYvLkyWzYsIG0tDQURaGsrIwvv/yS0tLSq+qbNWsWq1atYseOHdTU1GAymTh69KjNLiEhgUcffRQvLy9uvPHGlgxRvRQWFjJ06FBiYmIYNGgQY8eO5fbbb2+V73YWU6ZM4aabbuLo0aOEhYWxatUqnn76ab766it69uzJjh07ePrpp10ts8lc7t/777/vsmtPlbhsApRE0kaIi4tTVq5cqSiKosyYMUN57rnn7Lbn5+crU6ZMUYKCghR/f39l8ODByvbt2xVFUZTy8nJl2rRpip+fn9KnTx9lyZIlSmhoqO2z3333ndKnTx+lY8eOSkJCgjJ16lS7/ScnJysD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";
    len = base64Decode((unsigned char*)p.c_str(), (unsigned int)p.length(), &buffer_image);
    Image* img = new Image();
    bool ok = img->initWithImageData(buffer_image, len);
    
    Texture2D* tex = new Texture2D();
    
    tex->initWithImage(img);
    
    Sprite* sprite1 = Sprite :: createWithTexture(tex);
    
    sprite1->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    
    this->addChild(sprite1);
    
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithSystemFont("欢迎来到通信原理仿真平台", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height - 50));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("background.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    TheScene_1* the = new TheScene_1();
    if(the->createScene() != NULL)
    {
        auto scene_1 = TransitionCrossFade :: create(1.0f,the->createScene());
        Director :: getInstance()->replaceScene(scene_1);
    }
    
}

void MainScene::onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
    if (!response) {
        return ;
    }
    //
    //    if (0 != strlen(response->getHttpRequest()->getTag())) {
    //        log("%s completed",response->getHttpRequest()->getTag());
    //    }
    //
    //    long statusCode = response->getResponseCode();
    //    char statusString[64] = {};
    //
    //    sprintf(statusString, "HTTP Status Code: %ld, tag = %s",statusCode,response->getHttpRequest()->getTag());
    //    log("response code: %ld",statusCode);
    //
    if (!response->isSucceed()) {
        log("response failed");
        log("error buffer: %s",response->getErrorBuffer());
        return ;
        
    }
    
    std::vector<char>* buffer = response->getResponseData();
    std :: string info = "";
    info = string(buffer->begin(),buffer->end());
    
    
    //    rapidjson::Document str;
    //    str.Parse<0>(info.c_str());
    //    if(str.HasParseError())
    //        CCLOG("GetParseError %s\n",str.GetParseError());
    //    rapidjson::Value& arraydata = str["data"];
    //    CCLOG("%s\n", arraydata["graph"].GetString());
    //
    //    std::string load_str;
    //    load_str =  arraydata["graph"].GetString();
    //
    //    int len = 0;
    //    unsigned char *buffer_image;
    //    len = base64Decode((unsigned char*)load_str.c_str(), (unsigned int)load_str.length(), &buffer_image);
    //
    //    Image* img = new Image();
    //    bool ok = img->initWithImageData(buffer_image, len);
    //    if(ok)
    //        image_base64->initWithImage(img);
    //
    //
    printf("Http Test, dump data: ");
    for (unsigned int i = 0 ; i < buffer->size();i++) {
        printf("%c",(*buffer)[i]);
    }
    printf("\n");
}


