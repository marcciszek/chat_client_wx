#pragma once
#include "wx/wx.h"
#include "ChatBox.h"

class main : public wxMDIParentFrame
{
public:
    main();
    ~main();


private:
    //wxToolBar* m_ToolBar = nullptr;
    wxMenuBar* m_MenuBar = nullptr;

    void OnMenuNew(wxCommandEvent& evt);
    void OnMenuSettings(wxCommandEvent& evt);
    void OnMenuExit(wxCommandEvent& evt);


    wxDECLARE_EVENT_TABLE();
};

