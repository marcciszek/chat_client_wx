#pragma once
#include "wx/wx.h"
#include <wx/socket.h>

class ChatBox : public wxMDIChildFrame
{
public:
    ChatBox(wxMDIParentFrame* parent, wxString sName);
    ~ChatBox();
public:
    wxString AdressIp = "127.0.0.1";
    wxString AdressPort = "54000";
    wxString ClientName = "Anonymous";
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
    wxBoxSizer* FlexSizerBox = nullptr;
    wxSocketClient* sock = nullptr;

    wxDECLARE_EVENT_TABLE();
};

class SettingBox
{
public:
    SettingBox(ChatBox* parent, wxString* ip, wxString* port, wxString* name);
    ~SettingBox();
private:
    wxString* AdressIp = nullptr;
    wxString* AdressPort = nullptr;
    wxString* ClientName = nullptr;
    wxDialog* InfoInput = nullptr;
    wxStaticText* text_enterip = nullptr;
    wxStaticText* text_enterport = nullptr;
    wxStaticText* text_entername = nullptr;
    wxTextCtrl* box_enterip = nullptr;
    wxTextCtrl* box_enterport = nullptr;
    wxTextCtrl* box_enternick = nullptr;
    wxGridSizer* FlexSizerDialog = nullptr;
    wxGridSizer* FlexSizerDialog1 = nullptr;
    wxGridSizer* FlexSizerDialog2 = nullptr;
    wxButton* ButtonOK = nullptr;
    wxButton* ButtonCancel = nullptr;
    void Settings_apply(wxCommandEvent&);
    void Settings_cancel(wxCommandEvent&);

    wxDECLARE_EVENT_TABLE();
};