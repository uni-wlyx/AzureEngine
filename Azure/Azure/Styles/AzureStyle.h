#ifndef AZURESTYLE_H
#define AZURESTYLE_H

#pragma once 

enum class EStyleType{
    blue,
};

class AzureStyle
{
public:
    AzureStyle();
    ~AzureStyle();

    static void SetStyle(EStyleType theme);


private:
    void SetBlueStyle();
};

#endif