#pragma once

#include "wx/wx.h"
#include "main.h"

class cApp : public wxApp
{
public:
    cApp();
    ~cApp();

private:
    main* m_frame1 = nullptr;

public:
    virtual bool OnInit();
};

