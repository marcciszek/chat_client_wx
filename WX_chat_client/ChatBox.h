#pragma once
#include "wx/wx.h"
#include <wx/socket.h>

class ChatBox : public wxMDIChildFrame
{
public:
    ChatBox(wxMDIParentFrame* parent, wxString sName);
    ~ChatBox();
public:

private:
    wxToolBar* ToolBar1 = nullptr;
    wxButton* ButtonConnect = nullptr;
    wxButton* ButtonDisconnect = nullptr;
    wxTextCtrl* TextNickName = nullptr;
    void Connect(wxCommandEvent&);
    void Disconnect(wxCommandEvent&);
    void OnSend(wxCommandEvent&);
    void OnSocketEvent(wxSocketEvent&);
    
    wxTextCtrl* TextRec = nullptr;
    wxTextCtrl* TextSend = nullptr;
    wxBoxSizer* FlexSizer = nullptr;
    wxSocketClient* sock = nullptr;

    wxDECLARE_EVENT_TABLE();
};
